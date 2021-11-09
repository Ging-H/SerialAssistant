#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QSerialPort>
#include <QTranslator>
#include <QDebug>
#include <QProcess>
#include "crc.h"

#if _MSC_VER >= 1600 // VS2010版本号是1600
#pragma execution_character_set("utf-8")
#endif

/**
 * @brief SerialAssistant::SerialAssistant 构造函数
 * @param parent
 */
SerialAssistant::SerialAssistant(QMainWindow *parent) :
    QMainWindow(parent),
     ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);

    /* ui初始化 */
//    this->setWindowTitle( tr("硬石电子 - 串口助手 v2.0.1.exe") );
    ui->toolBox->setCurrentIndex(0);
    this->constructTranstor();

    /* 功能配置 */
    port = ui->serialComm->objPort();
    connect( ui->serialComm, &SerialComm::errMsg,
             this, &SerialAssistant::slots_errMsg );
    port->setReadBufferSize( rxBufSize );// 1MB
    connect(port, &QSerialPort::readyRead,
            this, &SerialAssistant::slots_serialRxCallback);

    saveFile = NULL; // 保存文件指针

    connect(this->ui->txtSingle, SIGNAL(cursorPositionChanged()),
            this, SLOT(slots_highlightLine())); // 链接高亮显示 信号->槽

    connect( ui->multiWidget, &MultiWidget::loadPath,
            [this]( QString path ){ iniPath = path; } );

    /* 定时显示 发送数据 */
    connect(&txtFlashTime,SIGNAL(timeout()),this,SLOT(slots_rxDisplayTxt()));
    txtFlashTime.start(10);
    connect(this, SIGNAL( signals_displayTxBuffer(QByteArray )),
            this,SLOT(slots_displayTxBuffer(QByteArray)),Qt::QueuedConnection);

    connect(ui->multiWidget, &MultiWidget::btnClicked,
            this, &SerialAssistant::slots_multiSend);

    /* 监控输入的文本 */
    disconnect(this->ui->txtSingle, SIGNAL(textChanged()),
               this, SLOT(on_txtSingle_textChanged()));

    this->listTerminator(ui->cbbTerminator);
    this->listVerifyStyle(ui->cbbVerifyStyle);

    this->loadDefaultConfig();// 加载默认的参数设置
    ui->progressBar->hide();
    saveArray.clear();
    saveText.clear();
}


/**
 * @brief SerialAssistant::~SerialAssistant 析构函数
 */
SerialAssistant::~SerialAssistant()
{
    delete port;
    delete ui;
}

void SerialAssistant::setTitle(QString title)
{
    title.replace(QRegExp("\\\\[^\\\\]*$"), tr("\\硬石电子-SerialAssistant") +  "v2.0.2" );

    this->setWindowTitle(title);
}

/**
 * @brief SerialAssistant::listTerminator 列出行结束符
 * @param cbbTerminator
 */
void SerialAssistant::listTerminator(QComboBox *cbbTerminator)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType< Terminator >();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        cbbTerminator->addItem(mtaEnum.key(i), mtaEnum.value(i));
    }
}
/**
 * @brief SerialAssistant::listVerifyStyle 列出校验样式
 * @param cbbVerifyStyle
 */
void SerialAssistant::listVerifyStyle(QComboBox *cbbVerifyStyle)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType< VerifyStyle >();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        cbbVerifyStyle->addItem(mtaEnum.key(i), mtaEnum.value(i));
    }
    cbbVerifyStyle->setItemText(0, tr(" insert verify"));// 计算校验码
}

/* ----------------------------------------------------- */
/* ui响应事件 */
/**
 * @brief SerialAssistant::on_textBrower_textChanged 设置光标到尾部
 */
void SerialAssistant::on_textBrower_textChanged()
{
    ui->textBrower->moveCursor(QTextCursor::End);
}

/**
 * @brief SerialAssistant::on_btnSend_clicked 发送按钮
 */
void SerialAssistant::on_btnSend_clicked()
{
    QByteArray txBuf;
    if( isPortOpen ){
        bool ok ;
        txBuf = this->stringToSend( ui->txtSingle->toPlainText(), ui->chbTxHex->isChecked(), ok);

        if(false == ok)
        {
            if(txTimer.isActive()){
                this->deleteTxTimer();
                ui->chbTimedTx->setCheckState(Qt::CheckState::Unchecked);
            }
            return;
        }

        /* 添加结束符 */
        if( terminator != NoTerminator ){
            if( terminator == CRLF_0x0D0A) {
                txBuf.append(0x0D);
                txBuf.append(0x0A);
            }else{
                txBuf.append( terminator );
            }
        }

        /* 添加校验码 */
        if(verifyStyle != AddVerifyItem){
            QByteArray tmp ;
            tmp = this->insertVerify(txBuf, verifyStyle);
            ui->txtVerify->setText( tmp.toHex(' ').toUpper() );
        }
        /* 显示发送字节数 */
        qint32 txBytes = port->write(txBuf); // 发送数据
        txCount += txBytes;
        ui->spbTxCnt->setValue(txCount);

        /* 显示发送数据 */
        if( ui->ckbTimeStamp->checkState() ){// 加时间戳
            emit signals_displayTxBuffer(txBuf);
        }
    }
}

/**
 * @brief SerialAssistant::isHexString 检查src中字符是否符合Hex规则表达式
 * @param src
 * @return
 */
bool SerialAssistant::isHexString(QString src)
{
    bool isMatch = true;
    QRegExp regExp("[a-f0-9A-F ]*");
    isMatch = regExp.exactMatch(src);
    return isMatch;
}

/**
 * @brief SerialAssistant::on_txtSingle_textChanged 监控输入文本
 */
void SerialAssistant::on_txtSingle_textChanged()
{
    if(ui->chbTxHex->isChecked() ){
        bool  isMatch = this->isHexString( ui->txtSingle->toPlainText() );
        if(!isMatch){
            QString tmp;
            disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
            tmp = ui->txtSingle->toPlainText();
            tmp.replace(QRegExp("[^a-f0-9A-F ]"), "");
            ui->txtSingle->setPlainText(tmp);
            ui->txtSingle->moveCursor(QTextCursor::End);
            QMessageBox::information(NULL, tr("unsupported input"),  tr("Only the [0~9], [a~f], [A~F], and spaces is supported"), 0, 0);
            connect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        }
    }
}

/**
 * @brief SerialAssistant::slots_errorHandler 错误信息处理
 * @param error
 */
void SerialAssistant::slots_errMsg(QString errMsg)
{
    ui->statusbar->showMessage( errMsg );
}

/**
 * @brief SerialAssistant::slots_highlightLine 发送文本框的光标位置改变 光标所在行高亮
 */
void SerialAssistant::slots_highlightLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    QTextEdit::ExtraSelection selection;

    QColor *color;
    if( isDarkStyle ){
        color = new QColor(223, 134, 30);
        selection.format.setBackground(color->lighter(60));       // 设置背景颜色和亮度
    }else{
        color = new QColor(223, 134, 30);
        selection.format.setBackground(color->lighter(200));       // 设置背景颜色和亮度
    }

    selection.format.setProperty(QTextFormat::FullWidthSelection, true); // 选择当前行所有像素(宽)
    selection.cursor = ui->txtSingle->textCursor();                      // 高亮当前行
    extraSelections.append(selection);
    ui->txtSingle->setExtraSelections(extraSelections);                  // 设置高亮
}

/**
 * @brief SerialAssistant::startTxTimer 启动定时器,用于定时发送
 */
void SerialAssistant::startTxTimer()
{
    txTimer.setTimerType(Qt::PreciseTimer );
    qint32 tmp = ui->spbTxInterval->value();
    txTimer.start(tmp);
    connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
}

/**
 * @brief SerialAssistant::deleteTxTimer 停止定时发送
 */
void SerialAssistant::deleteTxTimer()
{
    /* 停止定时器 */
    if(txTimer.isActive()){
        txTimer.stop();
        disconnect(&txTimer, SIGNAL(timeout()), this, SLOT(slots_timeOutTx()));
    }
}

/**
 * @brief SerialAssistant::slots_timeOutTx 定时发送数据
 */
void SerialAssistant::slots_timeOutTx()
{
    static qint32 i = 0;
    if(isPortOpen){
        qint32 index = ui->toolBox->currentIndex();
        switch(index ){
        case 0:
            emit this->ui->btnSend->click();// 发送单条数据,与点击"发送"按钮功能一致
            break;

        case 1:/* 轮询发送的条目 */
            for(qint32 j=i; j<ui->multiWidget->count(); j++){
                if( ui->multiWidget->groupAt(j)->ckb->isChecked() ){
                    emit ui->multiWidget->groupAt(j)->btn->clicked();
                    i = j+1;
                    break;
                }
                /* 没有搜索到需要执行的条件 */
                if( (i !=0 ) && (j == ui->multiWidget->count()-1) ){
                    j = -1; // 后续执行 j++,重新从0开始,
                    i = 0;  // 避免死循环
                }
            }
            /* 没有搜索到需要执行的条件 */
            if( i ==  ui->multiWidget->count() )
                i = 0;  // 避免死循环
            break;
        }
    }
}

/**
 * @brief SerialAssistant::slots_displayTxBuffer 显示发送的数据帧
 * @param txBuffer
 */
void SerialAssistant::slots_displayTxBuffer(QByteArray txBuffer)
{
    /* 显示发送数据 */
    // Hex显示
    if(txBuffer.isEmpty())
        return;
    if( isDisplayInHex ){
        txBuffer = txBuffer.toHex(' ').toUpper();
        txBuffer.append(' ');
    }
    txBuffer.insert(0, QTime::currentTime().toString("[hh:mm:ss.zzz]Tx\n"));

    QString strToDisplay;
    if(ui->rdbGB18030->isChecked()){
        QTextCodec *codec = QTextCodec::codecForName("GB18030");
        strToDisplay = codec->toUnicode( txBuffer );
    }else{
        strToDisplay = QString::fromUtf8(txBuffer);
    }
    ui->textBrower->appendPlainText(strToDisplay);
}

/**
 * @brief SerialAssistant::slots_multiSend  多条文本发送
 */
void SerialAssistant::slots_multiSend(qint32 index)
{
    MultiWidget *mulWidGroup = (MultiWidget *) sender();
    index--;
    if(isPortOpen){
        QString tmpString = mulWidGroup->groupAt(index)->txt->text(); // 获取按钮对应的文本
        QByteArray txBuf ;
        bool ok;
        txBuf = this->stringToSend(tmpString, ui->chbTxHex->isChecked() ,ok);
        if(false == ok)
        {
            if(txTimer.isActive()){
                this->deleteTxTimer();
                ui->chbTimedTx->setCheckState(Qt::CheckState::Unchecked);
            }
            return;
        }
        /* 添加结束符 */
        if( terminator != NoTerminator)
            txBuf.append(terminator);

        /* 添加校验码 */
        if(verifyStyle != AddVerifyItem){
            QByteArray tmp ;
            tmp = this->insertVerify(txBuf, verifyStyle);
            ui->txtVerify->setText( tmp.toHex(' ').toUpper() );
        }
        /* 发送数据,并记录发送数量 */
        qint32 txBytes = port->write(txBuf);
        txCount += txBytes;
        ui->spbTxCnt->setValue(txCount);

        /* 加时间戳显示*/
        if( isTimeStamp ){
            emit signals_displayTxBuffer(txBuf);
        }
    }
}

/* 将QString 转换成可以直接发送的QByteArray */ // "33 35" -> 0x33 0x35
QByteArray SerialAssistant::stringToSend(QString src, bool txInHex, bool &ok )
{
    QByteArray buf;
    QString tmpString ;
    ok = true;
    if( txInHex ){/* 以十六进制发送 */
        tmpString = src.remove(QRegExp("\\s"));// delete ' '
        QByteArray tmpTest = tmpString.toLatin1();// "33 35"->0x33 0x33 0x33 0x35
        if(tmpTest.length() & 0x01 ) // 奇数个字符,最后一个字符不能满足转换成Hex数据
        {
            tmpTest.remove(tmpTest.length()-1, 1); // 移除并警告
            QMessageBox::information(NULL, tr("unsupported input"),  tr("Please enter the full byte"), 0, 0);
            ok = false;
        }
        buf = QByteArray::fromHex(tmpTest); // ascii to hex(hex字符串转换成 hex数据 )//0x33 0x33 0x33 0x35 -> 0x33 0x35
    }else{
        if( ui->rdbGB18030->isChecked() ){
            QTextCodec *codec = QTextCodec::codecForName("GB18030");
            buf = codec->fromUnicode(src);
        }else{
            buf = src.toUtf8();
        }
    }
    return buf;
}
/**
 * @brief BaseSerialComm::verifyADD8 添加校验码 ADD8
 * @param buf
 * @return
 */
quint8 SerialAssistant::verifyADD8(QByteArray buf)
{
    quint8 retVal = 0;
    foreach(quint8 c, buf){
        retVal += c;
    }
    return retVal;
}
/**
 * @brief SerialAssistant::verifyXOR8 添加校验码 XOR8
 * @param buf
 * @return
 */
quint8 SerialAssistant::verifyXOR8(QByteArray buf)
{
    quint8 retVal = 0;
    foreach(quint8 c, buf){
        retVal ^= c;
    }
    return retVal;
}
/**
 * @brief SerialAssistant::verifyCRC16 添加校验码 Modbus CRC16
 * @param buf
 * @return CRC16
 */
quint16 SerialAssistant::verifyCRC16_Modbus(QByteArray buf)
{
    quint16 crc16;
    crc16 = crc16_modbus_calc((uint8_t *)buf.data(),buf.size());
    return crc16;
}

/**
 * @brief SerialAssistant::verifyCRC16_CCITT  计算校验码 CCITT
 * @param buf
 * @return CRC16
 */
quint16 SerialAssistant::verifyCRC16_CCITT(QByteArray buf)
{
    quint16 crc16;
    crc16 = crc16_ccitt_calc((uint8_t *)buf.data(),buf.size());
    return crc16;
}
/**
 * @brief SerialAssistant::verifyCRC32  计算校验码 CRC32
 * @param buf
 * @return CRC32
 */
quint32 SerialAssistant::verifyCRC32(QByteArray buf)
{
    quint32 crc32;
    crc32 = crc32_calc((uint8_t *)buf.data(),buf.size());
    return crc32;
}
/**
 * @brief SerialAssistant::verifyCrc8Ds18b20 校验码crc8 一般用于ds18b20
 * @param buf
 * @return CRC8
 */
uint8_t SerialAssistant::verifyCRC8_DS18B20(QByteArray buf)
{
    uint8_t crc8 = crc8_maxim_calc((uint8_t *)buf.data(), buf.size());
    return  crc8;
}
/**
 * @brief SerialAssistant::verifyCrc16Usb 校验码crc16,一般用于usb校验
 * @param buf
 * @return CRC16 USB
 */
uint16_t SerialAssistant::verifyCRC16_USB(QByteArray buf)
{
    uint16_t crc16 = crc16_usb_calc((uint8_t *)buf.data(), buf.size());
    return crc16;
}
/**
 * @brief SerialAssistant::verifyCrc16Ccitt_f 校验码crc16,一般用于ccitt false
 * @param buf
 * @return CRC16 CCITT False
 */
uint16_t SerialAssistant::verifyCRC16_CCITT_FALSE(QByteArray buf)
{
    uint16_t crc16 = crc16_ccitt_false_calc((uint8_t*)buf.data(), buf.size() );
    return crc16;
}

/**
 * @brief SerialAssistant::insertVerify 插入校验码
 * @param tmp
 */
QByteArray SerialAssistant::insertVerify(QByteArray &tmp, VerifyStyle style )
{
    qint32 length = tmp.size();
    qint32 start  = startVerify;
    qint32 end    = endVerify;

    if (start > length)// 起始位置错误,超出字节长度
        start = length;
    if (end > length)
        end = length;


    /* 计算待校验数据段长度和起始索引值,插入校验码索引值 */
    qint32 startIndex = start-1;
    qint32 count = (length - end) - startIndex;
    qint32 insertIndex = startIndex + count;

    if (count <= 0){
        return QByteArray();
    }
    QByteArray tmpArray = tmp.mid( startIndex, count );//待校验数据段

    switch (style){
    case ADD8:{
        uint8_t add8 = 0;
        add8 = this->verifyADD8( tmpArray );
        tmp.insert( insertIndex, add8 );
        tmpArray.clear();
        tmpArray.append(add8);
    }break;

    case NADD8:{
        uint8_t nadd8 = 0;
        nadd8 = this->verifyADD8( tmpArray );
        nadd8 = (0 - nadd8);
        tmp.insert( insertIndex, nadd8 );
        tmpArray.clear();
        tmpArray.append(nadd8);
    }break;

    case XOR8:{
        uint8_t xor8 = 0;
        xor8 = this->verifyXOR8( tmpArray );
        tmp.insert( insertIndex, xor8 );
        tmpArray.clear();
        tmpArray.append( xor8 );
    }break;

    case CRC16_MODBUS:{
        uint16_t crc16 = 0;
        crc16 = this->verifyCRC16_Modbus(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
    }break;

    case CRC16_CCITT:{
        uint16_t crc16 = 0;
        crc16 = this->verifyCRC16_CCITT(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
        }break;

    case CRC32:{
        uint32_t crc32 = 0;
        crc32 = this->verifyCRC32(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc32&0xFF) );
        tmpArray.append( (uint8_t)(crc32>>8) );
        tmpArray.append( (uint8_t)(crc32>>16) );
        tmpArray.append( (uint8_t)(crc32>>24) );

        tmp.insert( insertIndex, tmpArray);
    }break;

    case LRC:{
        uint8_t lrc16 = 0;
        lrc16 = this->verifyADD8( tmpArray );
        lrc16 = (0-lrc16);
        tmpArray.clear();
        tmpArray.append(lrc16);
        tmp.insert( insertIndex, tmpArray.toHex().toUpper() );
    }break;

    case CRC8_MAXIM_DS18B20:{
        uint8_t crc8 = 0;
        crc8 = this->verifyCRC8_DS18B20( tmpArray );
        tmpArray.clear();
        tmpArray.append(crc8);
        tmp.insert( insertIndex, tmpArray);
    }break;

    case CRC16_USB:{
        uint16_t crc16 = 0;
        crc16 = this->verifyCRC16_USB(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
    }break;

    case CRC16_CCITT_FALSE:{
        uint16_t crc16 = 0;
        crc16 = this->verifyCRC16_CCITT_FALSE(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
    }break;

    default:break;
    }
    return tmpArray;
}

/**
 * @brief SerialAssistant::on_btnSaveFile_clicked 保存接收的数据到文件
 */
void SerialAssistant::on_btnSaveFile_clicked()
{
    QString saveFilePath;
    QFileInfo fileInfo;
    /* 获取文件绝对路径 */
    if(ui->btnSaveFile->isChecked()){
        saveFilePath.clear();
        saveFilePath = QFileDialog::getSaveFileName(this, "Open File", NULL ,
                                                        "Files (*.txt *.log);;All (*.*)");
        if( NULL != saveFilePath){
            saveFile = new QFile(saveFilePath);
            saveFile->open(QIODevice::WriteOnly);
            txtStreamSave = new QTextStream(saveFile);
            fileInfo = saveFilePath;
            ui->btnSaveFile->setText(fileInfo.fileName());
            ui->textBrower->appendPlainText(tr("the new data will be save on %1,and it does not appear on the software.").arg(saveFilePath));
            ui->textBrower->appendPlainText(tr("so check the dasplay before continue."));
        }else{
            ui->btnSaveFile->setChecked(false);
        }
    }else if( NULL != saveFile) {
        saveFile->close();
        delete saveFile;
        delete txtStreamSave;
        saveFile = NULL;
        txtStreamSave = NULL;
        ui->btnSaveFile->setText(tr("save to file"));
    }
}
/*---------------------------------------------------------------------------------------------*/
// 发送文件

/**
 * @brief SerialAssistant::on_btnLoadFile_clicked 加载文件,准备发送数据
 */
void SerialAssistant::on_btnLoadFile_clicked()
{
    QString loadFilePath;
    QFileInfo fileInfo;
    /* 获取文件绝对路径 */
    if(ui->btnLoadFile->isChecked()){ // 按下加载文件
        loadFilePath.clear();         //
        loadFilePath = QFileDialog::getOpenFileName(this, tr("Open file"), NULL ,
                                                        "Files (*.txt *.bin *.hex *.log);;All (*.*)");
        if( NULL != loadFilePath){
            ui->progressBar->show();
            loadFile = new QFile(loadFilePath);
            loadFile->open(QIODevice::ReadOnly | QIODevice::ReadOnly);
            fileInfo = loadFilePath ;
            ui->btnLoadFile->setText(fileInfo.fileName());
            if(fileInfo.size() > 1024){
                ui->statusbar->showMessage(tr("The file size:") + QString::number( fileInfo.size()/1024.0f, 'f', 2)+ "KB");
            }else{
                ui->statusbar->showMessage(tr("The file size:") + QString::number( fileInfo.size() )+ "Byte" );
            }
        }else{
            ui->btnLoadFile->setChecked(false);
        }
    }else{
        if(loadFile != NULL){
            ui->progressBar->hide();
           loadFile->close();
           delete loadFile;
           loadFile = NULL;
           ui->btnLoadFile->setText(tr("Load the file"));
           ui->statusbar->clearMessage();
        }
    }
}

/**
 * @brief SerialAssistant::slots_timeOutProgressBar 进图条超时处理,更新进度条
 */
void SerialAssistant::slots_timeOutProgressBar()
{
    static qint32 i = 0;
    qint32 tmp = ui->progressBar->maximum();
    qint32  pgsBarValue = ui->progressBar->value();
    pgsBarValue += pgsBarInc;
    ui->progressBar->setValue( pgsBarValue );

    if( pgsBarValue > tmp ){
        ui->progressBar->setValue( tmp );
        if(i < 2)
            ++i;
        else{
            pgsBarInc = 0;
            i = 0;
            ui->progressBar->setValue(0);
            txTimer.stop();
            disconnect(&txTimer, SIGNAL(timeout()), this, SLOT(slots_timeOutProgressBar()));
            ui->btnTxFile->setChecked(false);
            ui->btnTxFile->setText(tr("Transfer the file"));
        }
    }
}

/**
 * @brief SerialAssistant::on_btnTxFile_clicked  发送文件
 * @param checked
 */
void SerialAssistant::on_btnTxFile_clicked(bool checked)
{
    if(checked){
        if(NULL == loadFile){
            ui->btnTxFile->setChecked(false);
            return;
        }
        if(!isPortOpen){
            ui->btnTxFile->setChecked(false);
                return;
        }
        ui->btnTxFile->setText(tr("Stop the transfer"));
        qint32 bytecnt = port->write(loadFile->readAll());  // 发送数据
        txCount += bytecnt;
        ui->spbTxCnt->setValue( txCount );//统计字节数
        loadFile->reset();                // 光标复位

        /* 进度条显示发送进度(采用定时更新) */
        qint32  baund  = port->baudRate();
        qint32  data   = port->dataBits();
        qint32  parity = 0;
        float stop = port->stopBits();
        if(stop == QSerialPort::OneAndHalfStop){
            stop = 1.5f;
        }
        port->parity() == QSerialPort::NoParity? parity = 0 : parity = 1;
        float tmp1;
        tmp1 = baund / (stop + parity + data + 1); // 1s发送的字节数
        pgsBarInc = tmp1 / (float)(1000/ pgsBarUpRate);

        ui->progressBar->setMaximum(loadFile->size());
        this->deleteTxTimer();
        txTimer.setTimerType(Qt::PreciseTimer);
        connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutProgressBar()));
        txTimer.start(pgsBarUpRate);
    }else{
        port->clear();
        pgsBarInc = 0;
        ui->progressBar->setValue(0);
        txTimer.stop();
        disconnect(&txTimer, SIGNAL(timeout()), this, SLOT(slots_timeOutProgressBar()));
        ui->btnTxFile->setChecked(false);
        ui->btnTxFile->setText(tr("Transfer the file"));
        port->close();
        port->open(QIODevice::ReadWrite);
    }
}

/**
 * @brief SerialAssistant::on_pushButton_clicked 复位接收/发送计数器
 */
void SerialAssistant::on_pushButton_clicked()
{
    rxCount = 0;
    txCount = 0;
    ui->spbRxCnt->clear();
    ui->spbTxCnt->setValue(0);
}

/*-----------------------------------------------------------------------------*/
/* 接收处理 */

/**
 * @brief SerialAssistant::slots_serialRxCallback 接收函数处理
 */
void SerialAssistant::slots_serialRxCallback()
{
    if(  isRxData == false  )
        rxTimeStamp = QTime::currentTime();
     isRxData = true;
}

/**
 * @brief SerialAssistant::insertTimeStramp 插入时间戳
 * @param tmp  在tmp前面插入接收时间戳
 */
void SerialAssistant::insertTimeStramp(QString &tmp)
{
    QString currentTime = rxTimeStamp.toString("[hh:mm:ss.zzz]Rx:\n");
    tmp.prepend( currentTime );
}

/**
 * @brief SerialAssistant::slots_rxDisplayTxt 接收显示函数
 */
void SerialAssistant::slots_rxDisplayTxt()
{
    if( isRxData){
        disconnect(port ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 接收数据回调

        QByteArray tmp = port->readAll();
        /* 读取数据,empty代表没有再接收到数据 */
        if( tmp.isEmpty() ){
            if(rxBuffer.isEmpty())return;
            tmp = rxBuffer;
            if( isDisplayInHex ){
                tmp = tmp.toHex(' ').toUpper();
                tmp.append(' ');
            }
            QString str ;

            /* 处理中文编码,对于数字和字母不影响 */
            if( ui->rdbGB18030->isChecked() ){
                QTextCodec *codec = QTextCodec::codecForName("GB18030");
                str = codec->toUnicode(tmp);
            }else {
                str = QString::fromUtf8(tmp);
            }

            /* 加入时间戳 */
            if( isTimeStamp ){
                this->insertTimeStramp( str ); // 数据首部插入时间戳

                /* 保存到文件就需要不显示在界面上 */
                if( txtStreamSave != NULL ){
                    txtStreamSave->operator<<( str +'\n');
                }else{
                    ui->textBrower->appendPlainText(str); // append 添加新段落
                }
            }else{

                if( txtStreamSave != NULL ){
                    txtStreamSave->operator<<( str );
                }else{
                    ui->textBrower->insertPlainText(str);// insert 在尾部续写
                }
            }


            rxBuffer.clear();
             isRxData = false;// 标记为false,只有在下一次触发readyRead信号的时候才会进入这里
            connect(port, SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 接收数据回调
        }else{
            rxBuffer.append(tmp);
            rxCount += tmp.size();
            if( rxCount > rxBufSize ){
                rxBuffer.clear();
                rxCount = 0;
            }
        }
    }
    ui->spbRxCnt->setValue( rxCount );
}

/**
 * @brief SerialAssistant::on_btnClear_clicked 清空接收文本框和缓存
 */
void SerialAssistant::on_btnClear_clicked()
{
    ui->spbRxCnt->clear();
    ui->spbTxCnt->setValue(0);
    ui->textBrower->clear();
    rxBuffer.clear();
    rxCount = 0;
    txCount = 0;
    if( isPortOpen ){
        port->clear();
    }
}


/*-----------------------------------------------------------*/
// 保存参数配置
/**
 * @brief SerialAssistant::closeEvent 自动保存配置
 * @param event
 */
void SerialAssistant::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    QSettings settings("default.ini", QSettings::IniFormat);
    settings.setIniCodec("GB18030");
    settings.clear();


    /* 接收配置 */
    settings.beginGroup("RxConfig");
    settings.setValue( "Hex", isDisplayInHex );
    settings.setValue( "timestamp", ui->ckbTimeStamp->isChecked() );
    settings.endGroup();

    /* 发送配置 */
    settings.beginGroup("txConfig");
    settings.setValue( "aotuterminal", ui->cbbTerminator->currentText() );
    settings.setValue( "verify", ui->cbbVerifyStyle->currentText() );
    settings.setValue( "verifybegin", ui->spbStart->value() );
    settings.setValue( "verifyend", ui->spbEnd->value() );
    settings.setValue( "Hex", ui->chbTxHex->isChecked() );
    settings.setValue( "intervalms", ui->spbTxInterval->value() );
    settings.setValue( "GB18030", ui->rdbGB18030->isChecked() );
    settings.setValue( "UTF8", ui->rdbUTF8->isChecked() );

    settings.setValue( "inipath", (const QString)iniPath);
    settings.endGroup();

    /* 应用配置 */
    settings.beginGroup("app");
    settings.setValue( "language", language );
    settings.setValue( "WinStyle", winStyle );
    settings.setValue( "QssStyle", qssStyle );
    settings.endGroup();
}

/**
 * @brief loadDefaultConfig 加载默认配置
 */
void SerialAssistant::loadDefaultConfig()
{
    QSettings settings("default.ini", QSettings::IniFormat);
    settings.setIniCodec("GB18030");

    /* 接收配置 */
    settings.beginGroup("RxConfig");

    bool isTrue = settings.value( "Hex").toBool();
    ui->chkDisplayHex->setChecked( isTrue );
    emit ui->chkDisplayHex->clicked( isTrue );

    isTrue = settings.value( "Hex").toBool();
    ui->chkDisplayHex->setChecked(isTrue);
    emit ui->chkDisplayHex->clicked( isTrue );

    isTrue = settings.value( "timestamp").toBool();
    ui->ckbTimeStamp->setChecked( isTrue );
    emit ui->ckbTimeStamp->clicked( isTrue );

    settings.endGroup();

    /* 发送配置 */
    settings.beginGroup("txConfig");
    ui->cbbTerminator->setCurrentText( settings.value( "aotuterminal").toString() );
    ui->cbbVerifyStyle->setCurrentText( settings.value( "verify").toString() );

    isTrue = settings.value("Hex").toBool() ;
    ui->chbTxHex->setChecked( isTrue );
    emit ui->chbTxHex->clicked( isTrue );

    isTrue = settings.value("GB18030").toBool();
    emit ui->rdbGB18030->clicked( settings.value("GB18030").toBool() );
    ui->rdbGB18030->setChecked( isTrue );

    isTrue = settings.value("UTF8").toBool();
    emit ui->rdbUTF8->clicked( settings.value("UTF8").toBool() );
    ui->rdbUTF8->setChecked( isTrue );

    ui->spbStart->setValue( settings.value( "verifybegin" ).toInt());
    ui->spbEnd->setValue( settings.value( "verifyend" ).toInt());
    ui->spbTxInterval->setValue( settings.value( "intervalms" ).toInt());
    iniPath = settings.value( "inipath" ).toString();
    settings.endGroup();

    startVerify = ui->spbStart->value();
    endVerify = ui->spbEnd->value();

    ui->multiWidget->loadData( iniPath );


    /* 界面语言和样式 */
    settings.beginGroup("app");
    language = (Language) settings.value( "language" ).toInt();
    winStyle = (WinStyle) settings.value( "WinStyle" ).toInt();
    qssStyle = (QssStyle) settings.value( "QssStyle" ).toInt();
    switch (language) {
    case zh_CN:
        ui->actionCN->triggered();
        break;

    case zh_TW:
        ui->actionCN_T->triggered();
        break;

    case en:
        ui->actionEnglish->triggered();
        break;
    }
    switch( winStyle ){
    case Fusion:
        ui->actionfusion->triggered();
        break;
    case Windows:
        ui->actionWindows->triggered();
        break;
    case WindowsVista:
        ui->actionWindowsVista->triggered();
        break;
    }
    switch( qssStyle ){
    case DarkStyle:
        ui->actionDarkStyle->triggered();
        break;
    case DefaultStyle:
        ui->actionDefaultStyle->triggered();
        break;
    case WindowsVista:
        ui->actionWindowsVista->triggered();
        break;
    }

    settings.endGroup();
}
/**
 * @brief SerialAssistant::on_ckbTimeStamp_clicked 插入时间戳
 * @param checked
 */
void SerialAssistant::on_ckbTimeStamp_clicked(bool checked)
{
    isTimeStamp = checked;
}
/**
 * @brief SerialAssistant::on_chkDisplayHex_clicked 数据以HEX字符串显示
 * @param checked
 */
void SerialAssistant::on_chkDisplayHex_clicked(bool checked)
{
    isDisplayInHex = checked;
}
/**
 * @brief SerialAssistant::on_chbTimedTx_clicked 定时发送数据
 * @param checked
 */
void SerialAssistant::on_chbTimedTx_clicked(bool checked)
{
    if(checked){
        if( isPortOpen ){
            this->startTxTimer();
        }
    }else if(txTimer.isActive()){
            this->deleteTxTimer();
    }
}
/**
 * @brief SerialAssistant::on_chbTxHex_clicked Hex发送复选框被勾选
 * @param checked
 */
void SerialAssistant::on_chbTxHex_clicked(bool checked)
{
    if(checked){ // 发送 hex 字节
        /* 设定输入规则 */
        QRegExp regExp("[a-f0-9A-F ]*"); // Hex 字符串
        QRegExpValidator *regExpValidator = new QRegExpValidator (regExp,this);

        // 将原有的字符保存起来
        saveText.clear();
        qint32 i = 0;
        QList<MultiWidget::WidgetGroup*> *groupList = ui->multiWidget->groupList();
        foreach ( MultiWidget::WidgetGroup* widGroup, *groupList) {
            saveText << widGroup->txt->text() ;             // 暂存数据
            widGroup->txt->setValidator(regExpValidator);   // 设置输入规则
            if( saveArray.isEmpty() ){                      //
                widGroup->txt->setText(NULL);               // 读取并显示
            }else{                                          //
                widGroup->txt->setText(saveArray.at(i++));  //
            }
        }
        saveText << ui->txtSingle->toPlainText();
        if( saveArray.isEmpty() )
            ui->txtSingle->setPlainText(NULL);
        else
            ui->txtSingle->setPlainText(saveArray.at(i));
        connect(this->ui->txtSingle, SIGNAL(textChanged()), this, SLOT(on_txtSingle_textChanged()));

    }else{// 发送 string
        disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        /* 清除所有规则 */
        saveArray.clear();
        qint32 i(0);
        QList<MultiWidget::WidgetGroup*> *groupList = ui->multiWidget->groupList();
        foreach ( MultiWidget::WidgetGroup* widGroup, *groupList) {
            widGroup->txt->setValidator(0);
            saveArray << widGroup->txt->text(); // 保存数据
            if( saveText.isEmpty() ){
                widGroup->txt->setText(NULL);   // 读取并显示
            }else{
                widGroup->txt->setText(saveText.at(i++));
            }
        }
        saveArray << ui->txtSingle->toPlainText();
        if( saveText.isEmpty() ){
            ui->txtSingle->setPlainText(NULL);
        }else{
            ui->txtSingle->setPlainText( saveText.at(i) );
        }
    }
}
/**
 * @brief SerialAssistant::on_spbTxInterval_editingFinished 定时发送的时间间隔
 */
void SerialAssistant::on_spbTxInterval_editingFinished()
{
    /* 改变定时器发送的时间间隔 */
    qint32 tmp = ui->spbTxInterval->value();
    txTimer.setInterval( tmp );
}
/**
 * @brief SerialAssistant::on_rdbGB18030_clicked 选择汉字编码格式为GB2312
 * @param checked
 */
void SerialAssistant::on_rdbGB18030_clicked(bool checked)
{
    Q_UNUSED(checked)
    cnEncoder = GBK2312;
}
/**
 * @brief SerialAssistant::on_rdbUTF8_clicked 选择汉字编码格式为utf-8
 */
void SerialAssistant::on_rdbUTF8_clicked()
{
    cnEncoder = UTF8;
}

void SerialAssistant::on_cbbTerminator_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        terminator = NoTerminator;
        break;
    case 1:
        terminator = CRLF_0x0D0A;
        break;
    case 2:
        terminator = CR_0x0D;
        break;
    case 3:
        terminator = LF_0xOA;
        break;
    }
}
/**
 * @brief SerialAssistant::on_spbStart_valueChanged 校验码的起始位置
 * @param arg1
 */
void SerialAssistant::on_spbStart_valueChanged(int arg1)
{
    startVerify = arg1;
}
/**
 * @brief SerialAssistant::on_spbEnd_valueChanged 校验码的结束位置
 * @param arg1
 */
void SerialAssistant::on_spbEnd_valueChanged(int arg1)
{
    endVerify = arg1;
}

void SerialAssistant::on_cbbVerifyStyle_currentIndexChanged(int index)
{
    verifyStyle = VerifyStyle(index);
}



void SerialAssistant::on_serialComm_openPort()
{
    isPortOpen = true;
}

void SerialAssistant::on_serialComm_closePort()
{
    isPortOpen = false;
}

void SerialAssistant::constructTranstor()
{
    if( tsSerialAssistant == NULL ){
       tsSerialAssistant = new QTranslator();
    }
    if( tfSerialComm == NULL ){
       tfSerialComm = new QTranslator();
    }
    if( tfMultiWidget == NULL ){
        tfMultiWidget = new QTranslator();
    }
}
/**
 * @brief SerialAssistant::on_actionCN_triggered 切换成简体中文
 */
void SerialAssistant::on_actionCN_triggered()
{
    this->constructTranstor();
    tsSerialAssistant->load(QLocale(), "SerialAssistant_zh_CN.qm", ".", "translations" );
    tfSerialComm->load(QLocale(), "serialcomm_zh_CN.qm",  ".", "translations" );
    tfMultiWidget->load(QLocale(), "MultiWidget_zh_CN.qm", ".", "translations" );

    qApp->installTranslator( tsSerialAssistant );
    qApp->installTranslator( tfSerialComm );
    qApp->installTranslator( tfMultiWidget );
    ui->retranslateUi(this);
    ui->serialComm->retranslateUi();
    ui->multiWidget->retranslateUi();
    language = zh_CN;
    this->setTitle(this->windowTitle());

}
/**
 * @brief SerialAssistant::on_actionEnglish_triggered 切换成英文
 */
void SerialAssistant::on_actionEnglish_triggered()
{
    this->constructTranstor();
    qApp->removeTranslator( tsSerialAssistant );
    qApp->removeTranslator( tfSerialComm );
    qApp->removeTranslator( tfMultiWidget );
    ui->retranslateUi(this);
    ui->serialComm->retranslateUi();
    ui->multiWidget->retranslateUi();

    language = en;
    this->setTitle(this->windowTitle());
}

/**
 * @brief SerialAssistant::on_actionCN_T_triggered 切换繁体中文
 */
void SerialAssistant::on_actionCN_T_triggered()
{
    this->constructTranstor();
    tsSerialAssistant->load(QLocale(), "SerialAssistant_zh_TW.qm", ".", "translations" );
    tfSerialComm->load(QLocale(), "serialcomm_zh_TW.qm",  ".", "translations" );
    tfMultiWidget->load(QLocale(), "MultiWidget_zh_TW.qm", ".", "translations" );

    qApp->installTranslator( tsSerialAssistant );
    qApp->installTranslator( tfSerialComm );
    qApp->installTranslator( tfMultiWidget );
    ui->retranslateUi(this);
    ui->serialComm->retranslateUi();
    ui->multiWidget->retranslateUi();
    language = zh_TW;
    this->setTitle(this->windowTitle());
}
/**
 * @brief SerialAssistant::on_actionfusion_triggered 切换window风格
 */
void SerialAssistant::on_actionfusion_triggered()
{
    QApplication::setStyle(QStyleFactory::create("fusion"));// fusion 风格
    winStyle = Fusion;
}

void SerialAssistant::on_actionWindows_triggered()
{
    QApplication::setStyle(QStyleFactory::create("Windows"));// window XP风格
    winStyle = Windows;
}

void SerialAssistant::on_actionWindowsVista_triggered()
{
    QApplication::setStyle(QStyleFactory::create("WindowsVista"));// window XP风格
    winStyle = WindowsVista;
}
/**
 * @brief SerialAssistant::on_actionDarkStyle_triggered 切换 qss
 */
void SerialAssistant::on_actionDarkStyle_triggered()
{
    QFile file(":/theme/blackOrange.css"); // QSS文件
    QTextStream in(&file);
    in.setCodec("UTF-8");
    file.open(QIODevice::ReadOnly);
    QString qss = in.readAll();
    qApp->setStyleSheet(qss);              // 应用
    isDarkStyle = true;
    file.close();
    file.destroyed();
    qssStyle = DarkStyle;
}

void SerialAssistant::on_actionDefaultStyle_triggered()
{
    qApp->setStyleSheet("");              // 应用
    isDarkStyle = false;
    qssStyle = DefaultStyle;
}
/**
 * @brief SerialAssistant::on_actionTips_triggered 打开帮助说明
 */
void SerialAssistant::on_actionTips_triggered()
{
    QStringList argument;
    argument << QDir::currentPath()+"/help.pdf"<<"使用说明";
    QProcess::startDetached(QDir::currentPath()+"/Reader/Reader.exe", argument);
}

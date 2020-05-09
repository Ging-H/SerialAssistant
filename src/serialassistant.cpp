#include "serialassistant.h"
#include "ui_serialassistant.h"

qint32 SerialAssistant::pgsBarInc;

/**
 * @brief SerialAssistant::SerialAssistant 构造函数
 * @param parent
 */
SerialAssistant::SerialAssistant(QWidget *parent) :
    QWidget(parent),
     ui(new Ui::SerialAssistant)
{
    ui->setupUi(this);
    QApplication::setStyle(QStyleFactory::create("fusion"));// fusion 风格
    initComboBox_Config();

    /* ui初始化 */
    QFile file(":/theme/blackOrange.css");              // QSS文件
    if (!file.open(QFile::ReadOnly)){  // 打开文件
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString qss = in.readAll();        // 读取数据
    qApp->setStyleSheet(qss);          // 应用
    btnMenu = new QMenu();
    btnMenu->addAction(ui->actionRename);
    this->setWindowTitle("硬石电子-串口调试助手 v1.0");
    ui->toolBox->setCurrentIndex(0);

    /* 功能配置 */
    currentPort = new BaseSerialComm; // 构建一个端口对象
    saveFile = NULL; // 保存文件指针
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler(QSerialPort::SerialPortError)) );
    connect(this->ui->txtSingle,SIGNAL(cursorPositionChanged()),this,SLOT(slots_highlightLine())); // 链接高亮显示 信号->槽
    currentPort->setReadBufferSize(rxBufSize);

    /* 定时显示数据 */
    connect(&txtFlashTime,SIGNAL(timeout()),this,SLOT(slots_rxDisplayTxt()));
    txtFlashTime.start(10);
    connect(this, SIGNAL( signals_displayTxBuffer(QByteArray )), this,SLOT(slots_displayTxBuffer(QByteArray)),Qt::QueuedConnection);

    /* 将多个按钮组合起来 */
    multiPushButton << ui->btnMultiPush01;
    multiPushButton << ui->btnMultiPush02;
    multiPushButton << ui->btnMultiPush03;
    multiPushButton << ui->btnMultiPush04;
    multiPushButton << ui->btnMultiPush05;
    multiPushButton << ui->btnMultiPush06;
    multiPushButton << ui->btnMultiPush07;
    multiPushButton << ui->btnMultiPush08;
    multiPushButton << ui->btnMultiPush09;
    multiPushButton << ui->btnMultiPush10;

    quint16 i=0;
    foreach (QPushButton *MultiPush, multiPushButton) {
        this->initMultiBtn( MultiPush, ++i );
    }

    /* 将多条文本组合起来 */
    multiTxtLine << ui->txtLine01;
    multiTxtLine << ui->txtLine02;
    multiTxtLine << ui->txtLine03;
    multiTxtLine << ui->txtLine04;
    multiTxtLine << ui->txtLine05;
    multiTxtLine << ui->txtLine06;
    multiTxtLine << ui->txtLine07;
    multiTxtLine << ui->txtLine08;
    multiTxtLine << ui->txtLine09;
    multiTxtLine << ui->txtLine10;

    /* 将多个CheckBox组合起来 */
    multiCheckBox << ui->chkMulti01;
    multiCheckBox << ui->chkMulti02;
    multiCheckBox << ui->chkMulti03;
    multiCheckBox << ui->chkMulti04;
    multiCheckBox << ui->chkMulti05;
    multiCheckBox << ui->chkMulti06;
    multiCheckBox << ui->chkMulti07;
    multiCheckBox << ui->chkMulti08;
    multiCheckBox << ui->chkMulti09;
    multiCheckBox << ui->chkMulti10;

    /* 监控输入的文本 */
    disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));

    this->loadDefaultConfig();// 加载默认的参数设置
}

/**
 * @brief SerialAssistant::~SerialAssistant 析构函数
 */
SerialAssistant::~SerialAssistant()
{
    if(currentPort->isOpen()){
       currentPort->close();
    }
    delete currentPort;
    delete ui;
}

/* ----------------------------------------------------- */
/* ui响应事件 */

/**
 * @brief SerialAssistant::listVerifyStyle 列出支持的校验功能
 * @param cbbVerifyStyle
 */
void SerialAssistant::listVerifyStyle(QComboBox *cbbVerifyStyle)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<SerialAssistant::VerifyStyle>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        if(i == 0){
            cbbVerifyStyle->addItem("校验码", mtaEnum.value(i));
        }else{
            cbbVerifyStyle->addItem(mtaEnum.key(i), mtaEnum.value(i));
        }
        /* 删除未知值 */
        if(mtaEnum.value(i) == SerialAssistant::VerifyStyle::UnknownStyle)
            cbbVerifyStyle->removeItem(i);
    }
    cbbVerifyStyle->setCurrentText("校验码"); // 设定默认值
}

/**
 * @brief SerialAssistant::initComboBox_Config 初始化下拉列表控件
 */
void SerialAssistant::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui -> cbbBaud    );
    BaseSerialComm::listDataBit ( ui -> cbbDataBit );
    BaseSerialComm::listVerify  ( ui -> cbbVerify  );
    BaseSerialComm::listStopBit ( ui -> cbbStopBit );
    BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    BaseSerialComm::listTerminator(ui->cbbTerminator);
    this->listVerifyStyle(ui->cbbVerifyStyle);
}

/**
 * @brief SerialAssistant::on_btnOpenPort_clicked 打开并且配置串口
 */
void SerialAssistant::on_btnOpenPort_clicked()
{
    QString tmp = ui->cbbPortNum->currentText();

    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名

    // 当前串口处于关闭状态
    if( !currentPort->isOpen() ){
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            /* 配置端口的波特率等参数 */
            configPort();
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        this->deleteTxTimer();
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开串口"));
    }
}

/**
 * @brief SerialAssistant::configPort配置端口的波特率\数据位\奇偶校验\停止位
 */
void SerialAssistant::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
    currentPort->setDataTerminalReady(false);
    currentPort->setRequestToSend(false);
    connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 接收数据回调
}

/**
 * @brief SerialAssistant::on_btnRefresh_clicked 点击刷新按钮
 */
void SerialAssistant::on_btnRefresh_clicked()
{
    if(!currentPort->isOpen()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/**
 * @brief SerialAssistant::on_chkFlowCtrlDTR_toggled DTR翻转
 * @param checked
 */
void SerialAssistant::on_chkFlowCtrlDTR_toggled(bool checked)
{
    /* 确保已经打开串口才动作 */
    if(currentPort->isOpen()){
        currentPort->setDataTerminalReady(checked);
    }
}

/**
 * @brief SerialAssistant::on_chkFlowCtrlRTS_toggled RTS翻转
 * @param checked
 */
void SerialAssistant::on_chkFlowCtrlRTS_toggled(bool checked)
{
    /* 确保已经打开串口才动作 */
    if(currentPort->isOpen()){
        currentPort->setRequestToSend(checked);
    }
}

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
    if(currentPort->isOpen()){
        bool ok ;
        txBuf = this->stringToSend(ui->txtSingle->toPlainText(),ui->chbTxHex->isChecked(),ok);
        if(false == ok)
        {
            if(txTimer.isActive()){
                this->deleteTxTimer();
                ui->chbTimedTx->setCheckState(Qt::CheckState::Unchecked);
            }
            return;
        }
        /* 添加结束符 */
        QVariant tmpVariant = ui->cbbTerminator->currentData();  // 读取控件的当前项的值
        currentPort->insertTerminator(txBuf, tmpVariant.value < BaseSerialComm::Terminator> ());
        /* 添加校验码 */
        if(ui->cbbVerifyStyle->currentIndex() != 0){
            QByteArray tmp ;
            tmp = this->insertVerify( txBuf );
            ui->txtVerify->setPlainText( tmp.toHex(' ').toUpper() );        }
        /* 显示发送字节数 */
        qint32 txBytes = currentPort->write(txBuf); // 发送数据
        txCount += txBytes;

        ui->lbltxCnt->setText(QString("%1").arg(txCount));

        /* 显示发送数据 */
        if( ui->checkBox_5->checkState() ){// 加时间戳
            emit signals_displayTxBuffer(txBuf);
        }
    }
}

/**
 * @brief SerialAssistant::on_txtSingle_textChanged 监控输入文本
 */
void SerialAssistant::on_txtSingle_textChanged()
{
    if(ui->chbTxHex->isChecked() ){
        bool  isMatch = BaseSerialComm::isHexString(ui->txtSingle->toPlainText());

        if(!isMatch){
            QString tmp;
            disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
            tmp = ui->txtSingle->toPlainText();
            tmp.replace(QRegExp("[^a-f0-9A-F ]"),"");
            ui->txtSingle->setPlainText(tmp);
            ui->txtSingle->moveCursor(QTextCursor::End);
            QMessageBox::information(NULL, tr("不支持输入"),  tr("只支持[0~9],[a~f],[A~F]和空格的输入"), 0, 0);
            connect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        }
    }
}

/**
 * @brief SerialAssistant::slots_errorHandler 错误信息处理
 * @param error
 */
void SerialAssistant::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:break;
    }
}

/**
 * @brief SerialAssistant::slots_highlightLine 发送文本框的光标位置改变 光标所在行高亮
 */
void SerialAssistant::slots_highlightLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(QColor(223, 134, 30).lighter(60));       // 设置背景颜色和亮度
    selection.format.setProperty(QTextFormat::FullWidthSelection, true); // 选择当前行所有像素(宽)
    selection.cursor = ui->txtSingle->textCursor();                      // 高亮当前行
    extraSelections.append(selection);
    ui->txtSingle->setExtraSelections(extraSelections);                  //设置高亮
}

/**
 * @brief SerialAssistant::on_chbTimedTx_clicked 定时发送点击事件
 * @param checked
 */
void SerialAssistant::on_chbTimedTx_clicked(bool checked)
{
    if(checked){
        if(currentPort->isOpen() ){
            this->startTxTimer();
        }

    }else if(txTimer.isActive()){
            this->deleteTxTimer();
    }
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
        disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
    }
}

/**
 * @brief SerialAssistant::slots_timeOutTx 定时发送数据
 */
void SerialAssistant::slots_timeOutTx()
{
    qint32 index(0);
    if(currentPort->isOpen()){
        index = ui->toolBox->currentIndex();
        switch(index ){
        case 0:
            emit this->ui->btnSend->click();// 发送单条数据,与点击"发送"按钮功能一致
            break;

        case 1:/* 轮询发送的条目 */
            static qint32 i(0);
            if(!multiCheckBox.value(i)->isChecked()){/* 轮询是否勾选发送 */
                qint32 j(0),k;
                i >=9 ? k=0: k=i+1;
                for( ; j < 9; j++){
                    if(multiCheckBox.value(k++)->isChecked()){
                        k--;
                        j--; // 用于标记没有执行完9次就退出循环
                        break;
                    }
                    if(k>=10)k=0;
                }
                if(9 != j){// 搜索到CheckedBox
                    emit multiPushButton.value(k)->clicked(true);
                    i = k+1;
                }
            }else{
                emit multiPushButton.value(i++)->clicked(true);
            }
            i>=10 ? i=0: 0;
            break;
        }
    }
}

/**
 * @brief SerialAssistant::on_spbTxInterval_editingFinished 修改定时发送的时间间隔
 */
void SerialAssistant::on_spbTxInterval_editingFinished()
{
    /* 改变定时器发送的 时间间隔 */
    if(txTimer.isActive()){
        qint32 tmp = ui->spbTxInterval->value();
        txTimer.setInterval( tmp );
    }
}

/**
 * @brief SerialAssistant::on_chbTxHex_clicked Hex发送复选框被勾选
 * @param checked
 */
void SerialAssistant::on_chbTxHex_clicked(bool checked)
{
    if(checked){
        /* 设定输入规则 */
        QRegExp regExp("[a-f0-9A-F ]*"); // Hex 字符串
        QRegExpValidator *regExpValidator = new QRegExpValidator (regExp,this);

        // 将原有的字符保存起来
        saveText.clear();
        qint32 i (0);
        foreach (QLineEdit *txtLine, multiTxtLine) {  //
            saveText << txtLine->text() ;             // 暂存数据
            txtLine->setValidator(regExpValidator);   // 设置输入规则
            if( saveArray.isEmpty() ){                //
                txtLine->setText(NULL);               // 读取并显示
            }else{                                    //
                txtLine->setText(saveArray.at(i++));  //
            }
        }
        saveText << ui->txtSingle->toPlainText();
        if( saveArray.isEmpty() )
            ui->txtSingle->setPlainText(NULL);
        else
            ui->txtSingle->setPlainText(saveArray.at(i));
        connect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));

    }else{
        disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));
        /* 清除所有规则 */
        saveArray.clear();
        qint32 i(0);
        foreach (QLineEdit *txtLine, multiTxtLine) {
            txtLine->setValidator(0);
            saveArray << txtLine->text(); // 保存数据
            if( saveText.isEmpty() ){
                txtLine->setText(NULL);   // 读取并显示
            }else{
                txtLine->setText(saveText.at(i++));
            }
        }
        saveArray << ui->txtSingle->toPlainText();
        if( saveText.isEmpty() )
            ui->txtSingle->setPlainText(NULL);
        else
            ui->txtSingle->setPlainText(saveText.at(i));
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
    if( ui->chkDisplayHex->checkState() ){
        txBuffer = txBuffer.toHex(' ').toUpper();
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
void SerialAssistant::slots_multiSend()
{
    QPushButton *btn = (QPushButton*) sender();
    if(currentPort->isOpen()){
        QString tmpString = multiTxtLine.value(btn->text().toInt()-1)->text(); // 获取对应的文本
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
        QVariant tmpVariant = ui->cbbTerminator->currentData();  // 读取控件的当前项的值
        currentPort->insertTerminator(txBuf, tmpVariant.value < BaseSerialComm::Terminator> ());
        /* 添加校验码 */
        if(ui->cbbVerifyStyle->currentIndex() != 0){
            QByteArray tmp ;
            tmp = this->insertVerify(txBuf);
            ui->txtVerify->setPlainText( tmp.toHex(' ').toUpper() );
        }
        /* 发送数据 */
        qint32 txBytes = currentPort->write(txBuf);
        /* 显示发送字节数 */
        qint32 tmp = ui->lbltxCnt->text().toInt();
        ui->lbltxCnt->setText(QString::number(tmp + txBytes));

        if( ui->checkBox_5->checkState() ){// 加时间戳
            emit signals_displayTxBuffer(txBuf);// 显示发送的数据
        }
    }
}

/* 将QString 转换成可以直接发送的QByteArray */ // "33 35" -> 0x33 0x35
QByteArray SerialAssistant::stringToSend(QString src, bool txInHex, bool &ok )
{
    QByteArray buf;
    QString tmpString ;
    ok = true;
    if(txInHex ){/* 以十六进制发送 */
        tmpString = src.remove(QRegExp("\\s"));// delete ' '
        QByteArray tmpTest = tmpString.toLatin1();// "33 35"->0x33 0x33 0x33 0x35
        if(tmpTest.length() & 0x01 ) // 奇数个字符,最后一个字符不能满足转换成Hex数据
        {
            tmpTest.remove(tmpTest.length()-1, 1); // 移除并警告
            QMessageBox::information(NULL, tr("不支持的输入"),  tr("请输入完整的字节"), 0, 0);
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
 * @brief SerialAssistant::insertVerify 插入校验码
 * @param tmp
 */
QByteArray SerialAssistant::insertVerify(QByteArray &tmp)
{
    tmp = tmp;
    qint32 length = tmp.size();
    qint32 start  = ui->spbStart->value();
    qint32 end    = ui->spbEnd->value();

    if (start > length)// 起始位置错误,超出字节长度
        start = length;
    if (end > length)
        end = length;


    /* 计算待校验数据段长度和起始索引值,插入校验码索引值 */
    qint32 startIndex = start-1;
    qint32 count = (length - end) - startIndex;
    qint32 insertIndex = startIndex + count;
    if (count <= 0)
        return QByteArray();
    VerifyStyle verifyType = (VerifyStyle)ui->cbbVerifyStyle->currentIndex();
    QByteArray tmpArray = tmp.mid( startIndex, count );//待校验数据段

    switch (verifyType){
    case ADD8:{
        uint8_t add8 = 0;
        add8 = currentPort->verifyADD8( tmpArray );
        tmp.insert( insertIndex, add8 );
        tmpArray.clear();
        tmpArray.append(add8);
    }break;

    case NADD8:{
        uint8_t nadd8 = 0;
        nadd8 = currentPort->verifyADD8( tmpArray );
        nadd8 = (0 - nadd8);
        tmp.insert( insertIndex, nadd8 );
        tmpArray.clear();
        tmpArray.append(nadd8);
    }break;

    case XOR8:{
        uint8_t xor8 = 0;
        xor8 = currentPort->verifyXOR8( tmpArray );
        tmp.insert( insertIndex, xor8 );
        tmpArray.clear();
        tmpArray.append( xor8 );
    }break;

    case CRC16_MODBUS:{
        uint16_t crc16 = 0;
        crc16 = currentPort->verifyCRC16_Modbus(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
    }
        break;

    case CRC16_CCITT:{
        uint16_t crc16 = 0;
        crc16 = currentPort->verifyCRC16_CCITT(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
        }break;

    case CRC32:{
        uint32_t crc32 = 0;
        crc32 = currentPort->verifyCRC32(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc32&0xFF) );
        tmpArray.append( (uint8_t)(crc32>>8) );
        tmpArray.append( (uint8_t)(crc32>>16) );
        tmpArray.append( (uint8_t)(crc32>>24) );

        tmp.insert( insertIndex, tmpArray);
    }break;

    case LRC:{
        uint8_t lrc16 = 0;
        lrc16 = currentPort->verifyADD8( tmpArray );
        lrc16 = (0-lrc16);
        tmpArray.clear();
        tmpArray.append(lrc16);
        tmp.insert( insertIndex, tmpArray.toHex().toUpper() );
    }break;
    case CRC8_MAXIM_DS18B20:{
        uint8_t crc8 = 0;
        crc8 = currentPort->verifyCRC8_DS18B20( tmpArray );
        tmpArray.clear();
        tmpArray.append(crc8);
        tmp.insert( insertIndex, tmpArray);
    }break;
    case CRC16_USB:{
        uint16_t crc16 = 0;
        crc16 = currentPort->verifyCRC16_USB(tmpArray) ;
        tmpArray.clear();
        tmpArray.append( (uint8_t)(crc16&0xFF) );
        tmpArray.append( (uint8_t)(crc16>>8) );
        tmp.insert( insertIndex, tmpArray);
    }break;

    case CRC16_CCITT_FALSE:{
        uint16_t crc16 = 0;
        crc16 = currentPort->verifyCRC16_CCITT_FALSE(tmpArray) ;
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
            saveFile->open(QIODevice::WriteOnly | QIODevice::WriteOnly);
            txtStreamSave = new QTextStream(saveFile);
            fileInfo = saveFilePath;
            ui->btnSaveFile->setText(fileInfo.fileName());
            ui->textBrower->appendPlainText(QString("新接收到的数据将会被保存到 %1 ,以下内容就是文件保存内容").arg(saveFilePath));
        }else{
            ui->btnSaveFile->setChecked(false);
        }
    }else if( NULL != saveFile) {
        saveFile->close();
        delete saveFile;
        delete txtStreamSave;
        saveFile = NULL;
        txtStreamSave = NULL;
        ui->btnSaveFile->setText("保存至文件");
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
        loadFilePath = QFileDialog::getOpenFileName(this, "Open File", NULL ,
                                                        "Files (*.txt *.bin *.hex *.log);;All (*.*)");
        if( NULL != loadFilePath){
            loadFile = new QFile(loadFilePath);
            loadFile->open(QIODevice::ReadOnly | QIODevice::ReadOnly);
            fileInfo = loadFilePath ;
            ui->btnLoadFile->setText(fileInfo.fileName());
            if(fileInfo.size() > 1024){
                ui->lblFileSize->setText( "文件大小:" + QString::number( fileInfo.size()/1024.0f, 'f', 2)+ "KB" );
            }else{
                ui->lblFileSize->setText( "文件大小:" + QString::number( fileInfo.size() )+ "Byte" );
            }
        }else{
            ui->btnLoadFile->setChecked(false);
        }
    }else{
        if(loadFile != NULL){
           loadFile->close();
           delete loadFile;
           loadFile = NULL;
           ui->btnLoadFile->setText(tr("加载文件"));
           ui->lblFileSize->setText( "文件大小:");
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
            disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutProgressBar()));
            ui->btnTxFile->setChecked(false);
            ui->btnTxFile->setText("传输文件");
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
        if(NULL != loadFile){
            if(!currentPort->isOpen()){
                ui->btnTxFile->setChecked(false);
                return;
            }
            ui->btnTxFile->setText("停止传输");
            currentPort->write(loadFile->readAll());  // 发送数据
            qint32 tmp = ui->lbltxCnt->text().toInt();
            ui->lbltxCnt->setText(QString::number(tmp + loadFile->size()));//统计字节数
            loadFile->reset();// 光标复位

            /* 进度条显示发送进度(采用定时更新) */
            qint32  baund  = currentPort->baudRate();
            qint32  data   = currentPort->dataBits();
            qint32  parity = 0;
            float stop = currentPort->stopBits();
            if(stop == QSerialPort::OneAndHalfStop){
                stop = 1.5f;
            }
            currentPort->parity() == QSerialPort::NoParity? parity = 0 : parity = 1;
            float tmp1;
            tmp1 = baund / (stop + parity + data + 1); // 1s发送的字节数
            pgsBarInc = tmp1 / (float)(1000/ pgsBarUpRate);

            ui->progressBar->setMaximum(loadFile->size());
            this->deleteTxTimer();
            txTimer.setTimerType(Qt::PreciseTimer);
            connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutProgressBar()));
            txTimer.start(pgsBarUpRate);
         }
    }else{
        currentPort->clear();
        pgsBarInc = 0;
        ui->progressBar->setValue(0);
        txTimer.stop();
        disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutProgressBar()));
        ui->btnTxFile->setChecked(false);
        ui->btnTxFile->setText("传输文件");
        currentPort->close();
        currentPort->open(QIODevice::ReadWrite);
    }
}

/**
 * @brief SerialAssistant::on_pushButton_clicked 复位接收/发送计数器
 */
void SerialAssistant::on_pushButton_clicked()
{
    rxCount = 0;
    txCount = 0;
    ui->lblrxCnt->setText(QString("%1").arg(rxCount));
    ui->lbltxCnt->setText(QString("%1").arg(rxCount));
}

/*-----------------------------------------------------------------------------*/
/* 接收处理 */

/**
 * @brief SerialAssistant::slots_serialRxCallback 接收函数处理
 */
void SerialAssistant::slots_serialRxCallback()
{
    rxFlag = true;
    rxTimeStamp = QTime::currentTime();
}

/**
 * @brief SerialAssistant::insertTimeStramp 插入时间戳
 * @param tmp  在tmp前面插入接收时间戳
 */
void SerialAssistant::insertTimeStramp(QByteArray &tmp)
{
    QString currentTime = rxTimeStamp.toString("[hh:mm:ss.zzz]Rx:\r\n");
    tmp.prepend( currentTime.toLocal8Bit() );
}

/**
 * @brief SerialAssistant::slots_rxDisplayTxt 接收显示函数
 */
void SerialAssistant::slots_rxDisplayTxt()
{
    if(rxFlag){
        disconnect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 接收数据回调

        QByteArray tmp = currentPort->readAll();
        /* 读取数据,empty代表没有再接收到数据 */
        if( tmp.isEmpty() ){
            if(rxBuffer.isEmpty())return;
            tmp = rxBuffer;
            if(ui->chkDisplayHex->isChecked()){
                tmp = tmp.toHex(' ').toUpper();
            }
            QString str ;
            if(ui->checkBox_5->isChecked()){
                this->insertTimeStramp( tmp );
                if( ui->rdbGB18030->isChecked() ){
                    QTextCodec *codec = QTextCodec::codecForName("GB18030");
                    str = codec->toUnicode(tmp);
                }else {
                    str = QString::fromUtf8(tmp);
                }
                ui->textBrower->appendPlainText(str);
            }else{
                if( ui->rdbGB18030->isChecked() ){
                    QTextCodec *codec = QTextCodec::codecForName("GB18030");
                    str = codec->toUnicode(tmp);
                }else {
                    str = QString::fromUtf8(tmp);
                }
                ui->textBrower->insertPlainText(str);
            }
            if( txtStreamSave != NULL ){
                txtStreamSave->operator<<( str );
            }
            rxBuffer.clear();
            rxFlag = false;// 标记为false,只有在下一次触发readyRead信号的时候才会进入这里
            connect(currentPort, SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));// 接收数据回调
        }else{
            rxBuffer.append(tmp);
            rxCount += tmp.size();
            if( rxCount > rxBufSize ){
                rxBuffer.clear();
                rxCount = 0;
            }
        }
    }
    ui->lblrxCnt->setText( QString::number(rxCount) );
}

/**
 * @brief SerialAssistant::on_btnClear_clicked 清空接收文本框和缓存
 */
void SerialAssistant::on_btnClear_clicked()
{
    ui->lblrxCnt->clear();
    ui->lbltxCnt->clear();
    ui->textBrower->clear();
    rxBuffer.clear();
    rxCount = 0;
    txCount = 0;
    ui->lblrxCnt->setText(QString("%1").arg(rxCount));
    ui->lbltxCnt->setText(QString("%1").arg(rxCount));
}

/*----------------------------------------------------------*/
// 多条发送功能规划

/**
 * @brief SerialAssistant::on_btnAddNewGroup_clicked 多条发送 添加新的控件组
 */
void SerialAssistant::on_btnAddNewGroup_clicked()
{
    QCheckBox   *multiCkb = new QCheckBox();
    QPushButton *multibtn = new QPushButton();
    QLineEdit   *multitxt = new QLineEdit();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QSplitter   *spllitter = new QSplitter();

    spllitter->addWidget( multibtn );
    spllitter->addWidget( multitxt );
    spllitter->setOrientation(Qt::Horizontal);

    QSizePolicy sizePolicyl = multibtn->sizePolicy();
    sizePolicyl.setHorizontalStretch(0);
    multibtn->setSizePolicy( sizePolicyl );
    sizePolicyl.setHorizontalStretch(10);
    multitxt->setSizePolicy( sizePolicyl );

    this->initMultiBtn( multibtn, multiGroupCount+1 );
    this->renameCkb( multiCkb, multiGroupCount+1 );
    this->renameTxt( multitxt, multiGroupCount+1 );


    multiPushButton << multibtn;
    multiTxtLine    << multitxt;
    multiCheckBox   << multiCkb;

    hBoxLayout->addWidget( multiCkb );
    hBoxLayout->addWidget( spllitter );
    hBoxLayout->setSpacing(6);
    hBoxLayout->setMargin(0);

    QWidget *pWidget = new QWidget();
    pWidget->setLayout( hBoxLayout );

    QVBoxLayout *layout = new QVBoxLayout();
    layout = (QVBoxLayout*)ui->scrollArea->widget()->layout();
    quint32 itemCount = layout->count();
    layout->insertWidget( itemCount - 5 , pWidget);

    multiGroupCount++;
}

/**
 * @brief SerialAssistant::initMultiBtn 初始化配置按钮功能
 */
void SerialAssistant::initMultiBtn( QPushButton *btn , quint16 count)
{
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(slots_multiSend()));
    btn->setText( QString::number( count ) );
    btn->setObjectName( QString("btnMultiPush%1").arg( count, 2, 10, QLatin1Char('0') ) );
    btn->setContextMenuPolicy( Qt::CustomContextMenu);
    connect(btn, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slots_showBtnRightClickMenu(const QPoint &)));
}

/**
 * @brief SerialAssistant::renameCkb
 * @param ckb
 * @param count
 */
void SerialAssistant::renameCkb( QCheckBox *ckb , quint16 count)
{
    ckb->setObjectName( QString("chkMulti%1").arg( count, 2, 10, QLatin1Char('0') ) );
}

/**
 * @brief SerialAssistant::renameTxt
 */
void SerialAssistant::renameTxt(QLineEdit *txt, quint16 count)
{
    txt->setObjectName( QString("txtLine%1").arg( count, 2, 10, QLatin1Char('0') ) );
}

/**
 * @brief SerialAssistant::slots_showBtnRightClickMenu  按钮右击弹出菜单
 * @param pos
 */
void SerialAssistant::slots_showBtnRightClickMenu(const QPoint &pos)
{
    QPoint po = pos;
    po = po;
    QPushButton *btn = (QPushButton*)sender();
    QVariant ptrBtn;
    ptrBtn.setValue(btn);
    ui->actionRename->setData( ptrBtn );
    btnMenu->exec( QCursor::pos());
}

/**
* @brief SerialAssistant::on_btnDelLastGroup_clicked 多条发送 删除一组控件
 */
void SerialAssistant::on_btnDelLastGroup_clicked()
{
    if( multiGroupCount <= 10)
        return;
    QVBoxLayout *layout = new QVBoxLayout();
    layout = (QVBoxLayout*)ui->scrollArea->widget()->layout();
    quint32 itemCount = layout->count();
    QLayoutItem *item = layout->takeAt( itemCount - 6 ); // 删除最后一组控件
    if( item != NULL ){
        delete item->widget();
        delete item;
    }
    multiCheckBox.removeLast();
    multiPushButton.removeLast();
    multiTxtLine.removeLast();
    multiGroupCount--;
}

/**
 * @brief ModbusTool::on_actionRename_triggered 菜单点击事件 重命名
 */
void SerialAssistant::on_actionRename_triggered()
{
    QVariant ptrBtn;
    ptrBtn = ui->actionRename->data();
    QPushButton* btn = ptrBtn.value<QPushButton*>();
    QDialog *renameDialog = new QDialog();
    QLineEdit *txtName = new QLineEdit();
    renameDialog->setWindowTitle("重命名");

    QHBoxLayout *layout = new QHBoxLayout();
    renameDialog->setLayout(layout);
    renameDialog->layout()->addWidget(txtName);
    renameDialog->exec();
    btn->setText(txtName->text());
    renameDialog->setAttribute(Qt::WA_DeleteOnClose);
}

/**
 * @brief SerialAssistant::on_btnSaveGroupData_clicked 多条发送 保存数据
 */
void SerialAssistant::on_btnSaveGroupData_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "保存文件",
                                                    NULL ,"init files (*.ini)");
    if(filename != NULL){
        QSettings settings(filename, QSettings::IniFormat);
        settings.setIniCodec("GBK");
        settings.clear();

        /* 数量 */
        settings.beginGroup("widgetCount");
        settings.setValue( "multiGroupCount", multiGroupCount );
        settings.endGroup();

        /* 保存按钮名字 */
        settings.beginGroup("buttonName");
        foreach (QPushButton *btn, multiPushButton) {
            settings.setValue( btn->objectName(), btn->text() );
        }
        settings.endGroup();

        /* 保存ckb状态 */
        settings.beginGroup("checkBoxState");
        foreach (QCheckBox *ckb, multiCheckBox) {
            settings.setValue( ckb->objectName(), ckb->isChecked() );
        }
        settings.endGroup();

        /* 数据文本 */
        settings.beginGroup("lineText");
        foreach (QLineEdit *txt, multiTxtLine) {
            settings.setValue( txt->objectName(), txt->text() );
        }
        settings.endGroup();
    }
}

/**
 * @brief SerialAssistant::on_btnLoadGroupData_clicked 多条发送 加载数据
 */
void SerialAssistant::on_btnLoadGroupData_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "加载文件",
                                                    NULL ,"init files (*.ini)");
    QSettings settings(filename, QSettings::IniFormat);
    settings.setIniCodec("GBK");

    /* 数量 */
    settings.beginGroup("widgetCount");
    quint16 count = settings.value( "multiGroupCount" ).toInt();
    if(count > 10){
        quint16 loopCtrl ;
        loopCtrl = count - 10;
        while(loopCtrl--){
            emit ui->btnAddNewGroup->click();
        }
    }
    settings.endGroup();

    /* 保存按钮名字 */
    settings.beginGroup("buttonName");
    foreach( QPushButton *btn, multiPushButton ){
        QString objName = btn->objectName();
        btn->setText( settings.value(objName).toString() );
    }
    settings.endGroup();

    /* 保存ckb状态 */
    settings.beginGroup("checkBoxState");
    foreach( QCheckBox *ckb, multiCheckBox ){
        QString objName = ckb->objectName();
        ckb->setChecked( settings.value(objName).toBool() );
    }
    settings.endGroup();

    /* 数据文本 */
    settings.beginGroup("lineText");
    foreach( QLineEdit *txt, multiTxtLine ){
        QString objName = txt->objectName();
        txt->setText( settings.value(objName).toString() );
    }
    settings.endGroup();
}

/*-----------------------------------------------------------*/
// 保存参数配置
/**
 * @brief SerialAssistant::closeEvent 自动保存配置
 * @param event
 */
void SerialAssistant::closeEvent(QCloseEvent *event)
{
    event = event;
    QSettings settings("default.ini", QSettings::IniFormat);
    settings.setIniCodec("GB18030");
    settings.clear();

    /* 串口通信配置 */
    settings.beginGroup("SerialConfig" );
    settings.setValue( "baud", ui->cbbBaud->currentText() );
    settings.setValue( "databit", ui->cbbDataBit->currentText() );
    settings.setValue( "verify", ui->cbbVerify->currentText() );
    settings.setValue( "stopbit", ui->cbbStopBit->currentText() );
    settings.setValue( "DTR", ui->chkFlowCtrlDTR->isChecked() );
    settings.setValue( "RTS", ui->chkFlowCtrlRTS->isChecked() );
    settings.endGroup();

    /* 接收配置 */
    settings.beginGroup("RxConfig");
    settings.setValue( "Hex", ui->chkDisplayHex->isChecked() );
    settings.setValue( "timestamp", ui->checkBox_5->isChecked() );
    settings.endGroup();

    /* 发送配置 */
    settings.beginGroup("txConfig");
    settings.setValue( "aotuterminal", ui->cbbTerminator->currentText() );
    settings.setValue( "verify", ui->cbbVerifyStyle->currentText() );
    settings.setValue( "verifybegin", ui->spbStart->value() );
    settings.setValue( "verifyend", ui->spbEnd->value() );
    settings.setValue( "Hex", ui->chbTxHex->isChecked() );
    settings.setValue( "timeInterval", ui->chbTimedTx->isChecked() );
    settings.setValue( "intervalms", ui->spbTxInterval->value() );
    settings.setValue( "GB18030", ui->rdbGB18030->isChecked() );
    settings.setValue( "UTF8", ui->rdbUTF8->isChecked() );
    settings.endGroup();
}

/**
 * @brief loadDefaultConfig 加载默认配置
 */
void SerialAssistant::loadDefaultConfig()
{
    QSettings settings("default.ini", QSettings::IniFormat);
    settings.setIniCodec("GB18030");

    /* 串口通信配置 */
    settings.beginGroup("SerialConfig" );
    ui->cbbBaud->setCurrentText( settings.value( "baud").toString() );
    ui->cbbDataBit->setCurrentText( settings.value( "databit").toString() );
    ui->cbbVerify->setCurrentText( settings.value( "verify").toString() );
    ui->cbbStopBit->setCurrentText( settings.value( "stopbit").toString() );
    ui->chkFlowCtrlDTR->setChecked( settings.value("DTR").toBool() );
    ui->chkFlowCtrlRTS->setChecked( settings.value("RTS").toBool() );
    settings.endGroup();

    /* 接收配置 */
    settings.beginGroup("RxConfig");
    ui->chkDisplayHex->setChecked(settings.value( "Hex").toBool());
    ui->checkBox_5->setChecked(settings.value( "timestamp").toBool());
    settings.endGroup();

    /* 发送配置 */
    settings.beginGroup("txConfig");
    ui->cbbTerminator->setCurrentText( settings.value( "aotuterminal").toString() );
    ui->cbbVerifyStyle->setCurrentText( settings.value( "verify").toString() );
    ui->chbTxHex->setChecked( settings.value("Hex").toBool() );
    ui->chbTimedTx->setChecked( settings.value("timeInterval").toBool() );
    ui->rdbGB18030->setChecked( settings.value("GB18030").toBool() );
    ui->rdbUTF8->setChecked( settings.value("UTF8").toBool() );
    ui->spbStart->setValue( settings.value( "verifybegin" ).toInt());
    ui->spbEnd->setValue( settings.value( "verifyend" ).toInt());
    ui->spbTxInterval->setValue( settings.value( "intervalms" ).toInt());
    settings.endGroup();
}

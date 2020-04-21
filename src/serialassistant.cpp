#include "serialassistant.h"
#include "ui_serialassistant.h"
#include <QMessageBox>
//#include <QDebug>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
#include <QStyleFactory>

qint32 SerialAssistant::pgsBarInc;   // 进度条增量

//QTime timerTest; // 可用于测试运行时间

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

    currentPort = new BaseSerialComm; // 构建一个端口对象
    saveFile = NULL; // 保存文件指针
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(slots_errorHandler(QSerialPort::SerialPortError)) );
    connect(this->ui->txtSingle,SIGNAL(cursorPositionChanged()),this,SLOT(slots_highlightLine())); // 链接高亮显示 信号->槽
    connect(this, SIGNAL(signals_rxBufIsFull()),this, SLOT(slots_rxBufIsFull()));
    currentPort->setReadBufferSize(rxBufSize);

//    connect(,SIGNAL(timeout()),this,SLOT(slots_serialRxCallback()));
    connect(&txtFlashTime,SIGNAL(timeout()),this,SLOT(slots_rxDisplayTxt()));
    txtFlashTime.start(10);



    connect(&rxTimeout,SIGNAL(timeout()),this,SLOT(slots_rxTimeOut()));
    connect(this, SIGNAL( signals_displayTxBuffer(QByteArray )), this,SLOT(slots_displayTxBuffer(QByteArray)),Qt::QueuedConnection);
    /* 将多个按钮组合起来 */
    multiPushButton.push_back(ui->btnMultiPush01);
    multiPushButton.push_back(ui->btnMultiPush02);
    multiPushButton.push_back(ui->btnMultiPush03);
    multiPushButton.push_back(ui->btnMultiPush04);
    multiPushButton.push_back(ui->btnMultiPush05);
    multiPushButton.push_back(ui->btnMultiPush06);
    multiPushButton.push_back(ui->btnMultiPush07);
    multiPushButton.push_back(ui->btnMultiPush08);
    multiPushButton.push_back(ui->btnMultiPush09);
    multiPushButton.push_back(ui->btnMultiPush10);
    foreach (QPushButton *MultiPush, multiPushButton) { // 链接点击信号到同一个函数
        connect(MultiPush,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
    }

    /* 将多条文本组合起来 */
    multiTxtLine.push_back(ui->txtLine01);
    multiTxtLine.push_back(ui->txtLine02);
    multiTxtLine.push_back(ui->txtLine03);
    multiTxtLine.push_back(ui->txtLine04);
    multiTxtLine.push_back(ui->txtLine05);
    multiTxtLine.push_back(ui->txtLine06);
    multiTxtLine.push_back(ui->txtLine07);
    multiTxtLine.push_back(ui->txtLine08);
    multiTxtLine.push_back(ui->txtLine09);
    multiTxtLine.push_back(ui->txtLine10);

    /* 将多个CheckBox组合起来 */
    multiCheckBox.push_back(ui->chkMulti01);
    multiCheckBox.push_back(ui->chkMulti02);
    multiCheckBox.push_back(ui->chkMulti03);
    multiCheckBox.push_back(ui->chkMulti04);
    multiCheckBox.push_back(ui->chkMulti05);
    multiCheckBox.push_back(ui->chkMulti06);
    multiCheckBox.push_back(ui->chkMulti07);
    multiCheckBox.push_back(ui->chkMulti08);
    multiCheckBox.push_back(ui->chkMulti09);
    multiCheckBox.push_back(ui->chkMulti10);

    /* 监控输入的文本 */
    disconnect(this->ui->txtSingle,SIGNAL(textChanged()),this,SLOT(on_txtSingle_textChanged()));


//    currentPort->setReadBufferSize(1);
//    timerTest.start();
    ui->toolBox->setCurrentIndex(0);
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
    BaseSerialComm::listVerifyStyle(ui->cbbVerifyStyle);
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
        this->deleteRxTimer();
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
//    QString tmpString;
    if(currentPort->isOpen()){
        bool ok ;
        txBuf = this->stringToSend(ui->txtSingle->toPlainText(),ui->chbTxHex->isChecked(),ok);
        if(false == ok)
        {
            if(txTimer.isActive()){
                this->deleteTxTimer();
                ui->chbTimedTx->setCheckState(Qt::CheckState::Unchecked);
//                ui->chbTimedTx->setChecked(false);
            }
            return;
        }
        /* 添加结束符 */
        QVariant tmpVariant = ui->cbbTerminator->currentData();  // 读取控件的当前项的值
        currentPort->insertTerminator(txBuf, tmpVariant.value < BaseSerialComm::Terminator> ());
        if(ui->cbbVerifyStyle->currentIndex() != 0){
            QByteArray tmp ;
//            tmp = currentPort->insertVerify(txBuf, ui->spbStart->value(),ui->spbEnd->value(),
//                                      ui->cbbVerifyStyle->currentIndex());
            ui->txtVerify->setPlainText(tmp);
        }
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


/* 监控文本 槽函数 */
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

/* 串口错误信息处理 */
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

/* 停止接收定时器 */
void SerialAssistant::deleteRxTimer()
{
    /* 停止定时器 */
    if(rxTimer.isActive()){
        disconnect(&rxTimer ,SIGNAL(timeout()),0,0);
        currentPort->setReadBufferSize(1);
        connect(currentPort ,SIGNAL(readyRead()),this,SLOT( slots_serialRxCallback()));
        rxTimer.stop();
        emit ui->btnOpenPort->clicked(false);
        emit ui->btnOpenPort->clicked(true);
    }
}



/**
 * @brief SerialAssistant::slots_highlightLine 发送文本框的光标位置改变 光标所在行高亮
 */
void SerialAssistant::slots_highlightLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;//提供一种方式显示选择的文本
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(QColor(Qt::gray).lighter(145));       // 设置背景颜色和亮度
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
/* 启动发送控制定时器 */
void SerialAssistant::startTxTimer()
{
    txTimer.setTimerType(Qt::PreciseTimer );
    qint32 tmp = ui->spbTxInterval->value();
    txTimer.start(tmp);
    connect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
}
/* 停止发送控制定时器 */
void SerialAssistant::deleteTxTimer()
{
    /* 停止定时器 */
    if(txTimer.isActive()){
        txTimer.stop();
        disconnect(&txTimer,SIGNAL(timeout()),this,SLOT(slots_timeOutTx()));
    }
}


/* 超时发送 槽函数 */
void SerialAssistant::slots_timeOutTx()
{
    qint32 index(0);
    if(currentPort->isOpen()){
        index = ui->toolBox->currentIndex();
        switch(index ){
        case 0:
            emit this->ui->btnSend->click();// 发送单条数据,与点击"发送"按钮功能一致
            break;
        case 1:
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


/* 定时发送 时间间隔改变 槽函数 */
void SerialAssistant::on_spbTxInterval_editingFinished()
{
    /* 改变定时器发送的 时间间隔 */
    if(txTimer.isActive()){
        qint32 tmp = ui->spbTxInterval->value();
        txTimer.setInterval( tmp );
    }
}

/* Hex发送点击事件 槽函数 */
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
    QString strToDisplay = QString::fromLocal8Bit(txBuffer);
    ui->textBrower->appendPlainText(strToDisplay);
}
// MultiPushButton 点击发送 槽函数
void SerialAssistant::slots_multiSend()
{
    QPushButton *btn = (QPushButton*) sender();
    if(currentPort->isOpen()){
        QString tmpString = multiTxtLine.value(btn->text().toInt()-1)->text(); // 获取对应的文本
        QByteArray txBuf ;
        bool ok;
        txBuf = this->stringToSend(tmpString, ui->chbTxHex->isChecked(),ok);
        if(false == ok)
        {
            if(txTimer.isActive()){
                this->deleteTxTimer();
                ui->chbTimedTx->setCheckState(Qt::CheckState::Unchecked);
//                ui->chbTimedTx->setChecked(false);
            }
            return;
        }

        /* 添加结束符 */
        QVariant tmpVariant = ui->cbbTerminator->currentData();  // 读取控件的当前项的值
        currentPort->insertTerminator(txBuf, tmpVariant.value < BaseSerialComm::Terminator> ());
        if(ui->cbbVerifyStyle->currentIndex() != 0){
            QByteArray tmp ;
//            tmp = currentPort->insertVerify(txBuf, ui->spbStart->value(),ui->spbEnd->value(),
//                                      ui->cbbVerifyStyle->currentIndex());
            ui->txtVerify->setPlainText(tmp);
        }
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
        buf = src.toLocal8Bit();// "33 35"->0x33 0x33 0x20 0x33 0x35
    }
    return buf;
}

/* 保存到文件 槽函数 */
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
            QMessageBox::information(NULL, tr("保存到文件"), saveFilePath, 0, 0);
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
 * @brief SerialAssistant::slots_rxBufIsFull 缓存满了,需要清空缓存
 */
void SerialAssistant::slots_rxBufIsFull()
{
    rxBuffer.clear();
}
/**
 * @brief SerialAssistant::insertTimeStramp 插入时间戳
 * @param tmp  在tmp前面插入接收时间戳
 */
void SerialAssistant::insertTimeStramp(QByteArray &tmp)
{
    QString currentTime = rxTimeStamp.toString("[hh:mm:ss.zzz]Rx:\n");
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
            //TODO:处理串口接收
            if(rxBuffer.isEmpty())return;
            tmp = rxBuffer;
            if(ui->chkDisplayHex->isChecked()){
                tmp = tmp.toHex(' ').toUpper();
            }
            if(ui->checkBox_5->isChecked()){
                this->insertTimeStramp( tmp );
                ui->textBrower->appendPlainText(QString::fromLocal8Bit(tmp));
            }else{
                ui->textBrower->insertPlainText(QString::fromLocal8Bit(tmp));
            }
            if( txtStreamSave != NULL ){
                txtStreamSave->operator <<( QString::fromLocal8Bit(tmp) );
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
/*-----------------------------------------------------------------------------*/
/* 发送处理 */

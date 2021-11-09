#include "serialcomm.h"
#include "ui_serialcomm.h"
#include <QSerialPortInfo>
#include <QModbusRtuSerialMaster>
#include <QMetaEnum>
#include <QVariant>
#include <QSerialPort>

SerialComm::SerialComm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialComm)
{
    ui->setupUi(this);
    port = new QSerialPort(this);
    connect(port, &QSerialPort::errorOccurred,[this]( QSerialPort::SerialPortError){
                emit errMsg( port->errorString() );
            });

    mbDevice = new QModbusRtuSerialMaster(this);
    connect(mbDevice, &QModbusClient::errorOccurred,[this]( QModbusDevice::Error){
                emit errMsg( port->errorString() );
            });

    /* "端口号" */
    this->cbbPortName = ui->cbbPortName;

    /* "波特率" */
    this->cbbBaudRate = ui->cbbBaudrate;
    /* "数据位" */
    this->cbbDataBit   = ui->cbbDataBit;

    /* "校验位" */
    this->cbbParity   = ui->cbbParity;
    /* "停止位" */
    this->cbbStopBit   = ui->cbbStopBit;

    /* "流控制" */
    this->cbbFlowCtrl   = ui->cbbFlowCtrl;

    /* "刷新和打开按钮" */
    this->btnReflash  = ui->btnReflash;
    this->btnOpen     = ui->btnOpen;

    /* "RTS STR" */
    this->ckbDTR = ui->ckbDTR;
    this->ckbRTS = ui->ckbRTS;

    /* Modbus Addr,timeout,rep */
    this->spbAddr    = ui->spbAddr;
    this->spbTimeout = ui->spbTimeout;
    this->spbRep     = ui->spbRep;

    ui->ckbCBR->setVisible(false);
    ui->spbCBR->setVisible(false);

    listPortName( cbbPortName );
    listBaudRate( cbbBaudRate );
    listDataBit ( cbbDataBit  );
    listStopBit ( cbbStopBit  );
    listParity  ( cbbParity   );

    ui->lblFlowCtrl->hide();
    this->cbbFlowCtrl->hide();
}

SerialComm::~SerialComm()
{
    delete ui;
}
/**
 * @brief setDTRHide 隐藏控件界面
 * @param avaliable
 */
void SerialComm::setDTRHide(bool avaliable)
{
    ui->ckbDTR->setVisible(!avaliable);
    isDTRHidden = avaliable;
}

void SerialComm::setRTSHide(bool avaliable)
{
    ui->ckbRTS->setVisible(!avaliable);
    isRTSHidden = avaliable;
}
void SerialComm::setPortNameHide(bool avaliable)
{
    ui->lblPort->setVisible(!avaliable);
    cbbPortName->setVisible(!avaliable);
    isPortnameHidden = avaliable;
}
void SerialComm::setBaudrateHide(bool avaliable)
{
    ui->lblBaudrate->setVisible(!avaliable);
    cbbBaudRate->setVisible(!avaliable);
    isBaudrateHidden = avaliable;
}
void SerialComm::setDataBitHide(bool avaliable)
{
    ui->lblDataBit->setVisible(!avaliable);
    cbbDataBit->setVisible(!avaliable);
    isDataBitHidden = avaliable;
}
void SerialComm::setParityHide(bool avaliable)
{
    ui->lblParity->setVisible(!avaliable);
    cbbParity->setVisible(!avaliable);
    isParityHidden = avaliable;
}

void SerialComm::setStopBitHide(bool avaliable)
{
    ui->lblStopBit->setVisible(!avaliable);
    cbbStopBit->setVisible(!avaliable);
    isStopBitHidden = avaliable;
}
void SerialComm::setOpenPortHide(bool avaliable)
{
    btnOpen->setVisible(!avaliable);
    isOpenPortHidden = avaliable;
}
void SerialComm::setAddrHide(bool avaliable)
{
    ui->lblAddr->setVisible(!avaliable);
    spbAddr->setVisible(!avaliable);
    isAddrHidden = avaliable;
}

void SerialComm::setTimeoutHide(bool avaliable)
{
    ui->lblTimeout->setVisible(!avaliable);
    ui->spbTimeout->setVisible(!avaliable);
    isTimeoutHidden = avaliable;
}

void SerialComm::setRepHide(bool avaliable)
{
    ui->lblRep->setVisible(!avaliable);
    ui->spbRep->setVisible(!avaliable);
    isRepHidden = avaliable;
}

/**
 * @brief SerialComm::setDefaultBaudRate 设置参数默认值
 * @param baudrate
 */
void SerialComm::setDefaultBaudRate(BaudRate baudrate)
{
    cbbBaudRate->setCurrentText(QString::number(baudrate));
    defBaudrate = baudrate;
}
void SerialComm::setEnableCBR(bool checked)
{
    ui->ckbCBR->setVisible(checked);
    ui->spbCBR->setVisible(checked);
    isEnableCBR = checked;
}

void SerialComm::setDefaultDataBits(DataBits dataBits)
{
    cbbDataBit->setCurrentText(QString::number(dataBits) );
    defDataBits = dataBits;
}
void SerialComm::setDefaultParity(Parity parity)
{
    QVariant variant ;
    variant.setValue<Parity>( parity );
    int index = cbbParity->findData(variant);
    cbbParity->setCurrentIndex(index);
    defParity = parity;
}
void SerialComm::setDefaultStopBits(StopBits stopBits)
{
    if( stopBits != OneAndHalfStop ){
        cbbStopBit->setCurrentText(QString::number(stopBits));
    }else{
        cbbStopBit->setCurrentText(QString::number(1.5));
    }
    defStopBits = stopBits;
}
/**
 * @brief SerialComm::configPort 配置串口参数
 */
void SerialComm::configPort()
{
    QString tmp = cbbPortName->currentText();
    //  Item的 text 由 "COM1 描述" 组成,使用空格作为分隔符取第一段就是端口名
    tmp = tmp.section(' ', 0, 0);
    port->setPortName( tmp );              // 设置端口号

    QVariant tmpVariant;
    /* 设置波特率 */
    if( cbbBaudRate->isEnabled() ){
        tmpVariant = cbbBaudRate->currentData();  // 读取控件的当前项的值
        port->setBaudRate(tmpVariant.value < BaudRate > ()  );
    }
    else{
        port->setBaudRate( ui->spbCBR->value()  );
    }

    /* 设置数据位 */
    tmpVariant = cbbDataBit->currentData();
    port->setDataBits( tmpVariant.value < QSerialPort::DataBits > () );

    /* 设置校验位 */
    tmpVariant = cbbParity->currentData();
    port->setParity (tmpVariant.value < QSerialPort::Parity > () );

    /* 设置停止位 */
    tmpVariant = cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(port->setStopBits (tmpVariant.value < QSerialPort::StopBits > () ) == false ){
        cbbStopBit->clear();
        listStopBit ( cbbStopBit );
        emit errMsg(tr("unsuport stop bit"));
    }
}
/**
 * @brief SerialComm::listBaudRate 在控件中列出支持的波特率
 * @param cbbBaud BaudRate
 */
void SerialComm::listBaudRate(QComboBox *cbbBaud)
{
    QMetaEnum mtaEnum = QMetaEnum::fromType<BaudRate>();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbBaud->addItem(tmp, mtaEnum.value(i));
    }
    cbbBaud->setCurrentText("115200"); // 设定默认值
}
/**
 * @brief SerialComm::listDataBit  在控件中列出支持的数据位
 * @param cbbDataBit
 */
void SerialComm::listDataBit(QComboBox *cbbDataBit)
{
    QString tmp;
    QMetaEnum mtaEnum = QMetaEnum::fromType<DataBits>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        cbbDataBit->addItem(tmp, mtaEnum.value(i));
    }
    cbbDataBit->setCurrentText("8"); // 设定默认值
}

/**
 * @brief SerialComm::listParity  列出校验控制选项
 * @param cbbParity
 */
void SerialComm::listParity(QComboBox *cbbParity)
{
    /* 获取枚举元信息,并且与下拉列表 cbbParity的item 绑定 */
    QMetaEnum mtaEnum = QMetaEnum::fromType<Parity>();
    for (int i = 0; i < mtaEnum.keyCount(); i++) { // 遍历每个枚举值,获得text和data,添加到item中
        cbbParity->addItem(mtaEnum.key(i), mtaEnum.value(i));
    }
    cbbParity->setCurrentText(tr("NoParity")); // 设定默认值
}

/**
 * @brief SerialComm::listStopBit  列出停止位
 * @param cbbStopBit
 */
void SerialComm::listStopBit(QComboBox *cbbStopBit)
{
    /* StopBits 停止位 */
    QMetaEnum mtaEnum = QMetaEnum::fromType < StopBits >();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        if(mtaEnum.value(i) == 3)
            tmp = "1.5";  // 用3表示1.5个停止位
        cbbStopBit->addItem(tmp, mtaEnum.value(i));

    }
    cbbStopBit->setCurrentText("1"); // 设定默认值
}

/**
 * @brief SerialComm::listStopBit  列出停止位
 * @param cbbStopBit
 */
void SerialComm::listFlowCtrl(QComboBox *cbbFlowCtrl)
{
    /* StopBits 停止位 */
    QMetaEnum mtaEnum = QMetaEnum::fromType < FlowControl >();
    QString tmp;
    for (int i = 0; i < mtaEnum.keyCount(); i++) {
        tmp = QString::number(mtaEnum.value(i));
        if(mtaEnum.value(i) == 3)
            tmp = "1.5";  // 用3表示1.5个停止位
        cbbFlowCtrl->addItem(tmp, mtaEnum.value(i));
    }
    cbbFlowCtrl->setCurrentText("1"); // 设定默认值
}
/**
 * @brief SerialComm::listPortNum 列出端口号
 * @param cbbPortNum
 */
void SerialComm::listPortName(QComboBox *cbbPortName)
{
    QStringList portList;
    qint32 len = 0;   // list中最大的字符宽度

    portList.clear();                                      // 清空列表
    searchPort(portList);                                  // 搜索可用的串口和描述
    if(!portList.empty()){
        cbbPortName->addItems(portList);                   // 添加到ComboBox
        foreach(const QString &item, portList)             // 遍历list每一项
        {
            if(len < item.toLocal8Bit().length() )         // 获取字符宽度
                len = item.toLocal8Bit().length();
        }
        qint32 fontSize = cbbPortName->font().pointSize(); // 获取所用字体大小
        cbbPortName->view()->setFixedWidth( len * fontSize * 0.7 ); // 调整显示宽度,字符数*字符宽度*0.75
    }
    else{
        emit errMsg(tr("can not find any port"));
    }
}

/**
 * @brief SerialComm::searchPort 搜索端口号
 * @param portList
 */
void SerialComm::searchPort(QStringList &portList)
{
    QMap <qint32, QString> listMap;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        portList << info.portName() + " " + info.description();
        qint32 key;
        QString value = portList.last();
        key = value.section(' ', 0, 0).remove("COM").toInt();
        listMap.insert(key, value);
    }
    portList.clear();
    foreach(auto it, listMap){
        portList<<it;
    }
}
/**
 * @brief SerialComm::on_btnReflash_clicked
 */
void SerialComm::on_btnReflash_clicked()
{
    if(port->isOpen() )
        return;
    cbbPortName->clear();
    this->listPortName( cbbPortName );
}
/**
 * @brief SerialComm::setModbusMode 选择通信模式
 * @param enable
 */
void SerialComm::setModbusMode(bool enable)
{
    isMBMode = enable;
    this->setDTRHide(enable);
    this->setRTSHide(enable);
    this->setAddrHide(!enable);
    this->setTimeoutHide(!enable);
    this->setRepHide(!enable);
}
/**
 * @brief SerialComm::on_ckbDTR_clicked 设置dtr控制电平
 * @param checked
 */
void SerialComm::on_ckbDTR_clicked(bool checked)
{
    if(!port->isOpen())
        return;
    port->setDataTerminalReady(checked);
}

void SerialComm::on_ckbRTS_clicked(bool checked)
{
    if(!port->isOpen()  )
        return;
    port->setRequestToSend(checked);
}

void SerialComm::on_ckbCBR_clicked(bool checked)
{
    cbbBaudRate->setEnabled(!checked);
}
/**
 * @brief SerialComm::on_btnOpen_clicked openport
 * @param checked
 */
void SerialComm::on_btnOpen_clicked(bool checked)
{
    if( checked ){
        if( isMBMode ){
            if( mbDevice->state() == QModbusDevice::ConnectedState )
                return;
            this->configPort();
            mbDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,
                port->portName());
            mbDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,
                port->parity());
            mbDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
                port->baudRate());
            mbDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,
                port->dataBits());
            mbDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,
                port->stopBits());

            mbDevice->setTimeout(ui->spbTimeout->value());
            mbDevice->setNumberOfRetries( ui->spbRep->value() );
            btnOpen->setText(tr("open port"));
            emit openPort();
            if( !mbDevice->connectDevice() ){
                emit errMsg(tr("Connect failed:") + mbDevice->errorString());
                btnOpen->setText(tr("close port"));
                emit closePort();
            }
        }else{
            if( port->isOpen() )
                return;
            this->configPort();
            btnOpen->setText( tr("close port"));
            emit openPort();
            if(!port->open(QIODevice::ReadWrite)){
                emit errMsg(tr("Connect failed:") + port->errorString());
                btnOpen->setText(tr("open port"));
                btnOpen->setChecked(false);
                emit closePort();
            }
        }
    }else{
        if( isMBMode ){
            mbDevice->disconnectDevice();
        }else{
            port->close();
        }
        btnOpen->setText(tr("open port"));
        emit closePort();
    }
}
/**
 * @brief SerialComm::retranslateUi
 */
void SerialComm::retranslateUi()
{
    ui->retranslateUi(this);
}

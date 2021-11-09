#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QWidget>
#include <QDesignerExportWidget>


namespace Ui {
class SerialComm;
}
class QComboBox;
class QSerialPort;
class QPushButton;
class QCheckBox;
class QModbusClient;
class QSpinBox;

class QDESIGNER_WIDGET_EXPORT SerialComm : public QWidget
{
    Q_OBJECT


    Q_PROPERTY(bool DTRHidden READ isDTRHide WRITE setDTRHide )
    Q_PROPERTY(bool RTSHidden READ isRTSHide WRITE setRTSHide )

    Q_PROPERTY(bool portNameHidden   READ isPortNameHide  WRITE setPortNameHide )
    Q_PROPERTY(bool baudrateHidden   READ isBaudrateHide  WRITE setBaudrateHide )
    Q_PROPERTY(bool dataBitHidden    READ isDataBitHide   WRITE setDataBitHide )
    Q_PROPERTY(bool ParityHidden     READ isParityHide    WRITE setParityHide )
    Q_PROPERTY(bool stopBitHidden    READ isStopBitHide   WRITE setStopBitHide )
    Q_PROPERTY(bool openPortyHidden  READ isOpenPortHide  WRITE setOpenPortHide )
    Q_PROPERTY(bool addrHidden       READ isAddrHide      WRITE setAddrHide )
    Q_PROPERTY(bool timeoutHidden    READ isTimeoutHide   WRITE setTimeoutHide )
    Q_PROPERTY(bool repHidden        READ isRepHide       WRITE setRepHide )


    Q_PROPERTY(BaudRate defaultBaudRate READ defaultBaudRate WRITE setDefaultBaudRate)
    Q_PROPERTY(DataBits defaultDataBits READ defaultDataBits WRITE setDefaultDataBits)
    Q_PROPERTY(Parity defaultParity READ defaultParity WRITE setDefaultParity)
    Q_PROPERTY(StopBits defaultStopBits READ defaultStopBits WRITE setDefaultStopBits)
    Q_PROPERTY(bool  enableCBR READ enableCBR WRITE setEnableCBR)

    Q_PROPERTY(bool  modbusMode READ isModbusMode WRITE setModbusMode )

public:
    explicit SerialComm(QWidget *parent = 0);
    ~SerialComm();

    enum BaudRate {
        Baud1200    = 1200,
        Baud2400    = 2400,
        Baud4800    = 4800,
        Baud9600    = 9600,
        Baud19200   = 19200,
        Baud38400   = 38400,
        Baud57600   = 57600,
        Baud115200  = 115200,
        Baud128000  = 128000,
        Baud256000  = 256000,
        Baud921600  = 921600,
        Baud1000000 = 1000000,
        Baud2000000 = 2000000,
    };
    Q_ENUM(BaudRate)

    enum DataBits {
        Data5 = 5,
        Data6 = 6,
        Data7 = 7,
        Data8 = 8,
    };
    Q_ENUM(DataBits)

    enum Parity {
        NoParity = 0,
        EvenParity = 2,
        OddParity = 3,
        SpaceParity = 4,
        MarkParity = 5,
    };
    Q_ENUM(Parity)

    enum StopBits {
        OneStop = 1,
        OneAndHalfStop = 3,
        TwoStop = 2,
    };
    Q_ENUM(StopBits)

    enum FlowControl {
        NoFlowControl,
        HardwareControl,
        SoftwareControl,
    };
    Q_ENUM(FlowControl)

    /* ui控件入口 */
    QComboBox     *uiPortName()const {return cbbPortName;}
    QComboBox     *uiBaudRate()const {return cbbBaudRate;}
    QComboBox     *uiDataBit()const {return cbbBaudRate;}
    QComboBox     *uiParity()const {return cbbParity;}
    QComboBox     *uiStopBit()const {return cbbStopBit;}
    QComboBox     *uiFlowCtrl()const {return cbbFlowCtrl;}


    QCheckBox     *uiDTR()const {return ckbDTR;}
    QCheckBox     *uiRTS()const {return ckbRTS;}

    QPushButton   *uiOpen()const {return btnOpen;}
    QPushButton   *uiReflash()const {return btnReflash;}

    QSpinBox      *uiAddr()const {return spbAddr;}
    QSpinBox      *uiTimeout()const {return spbTimeout;}
    QSpinBox      *uiRep()const {return spbRep;}

    QSerialPort   *objPort()const {return port;}
    QModbusClient *objMbDevice()const {return mbDevice;}

    bool isDTRHide()const {return isDTRHidden;}
    void setDTRHide(bool avaliable);

    bool isRTSHide()const {return isRTSHidden;}
    void setRTSHide(bool avaliable);

    bool isPortNameHide()const {return isPortnameHidden;}
    void setPortNameHide(bool avaliable);

    bool isBaudrateHide()const {return isBaudrateHidden;}
    void setBaudrateHide(bool avaliable);

    bool isDataBitHide()const {return isDataBitHidden;}
    void setDataBitHide(bool avaliable);

    bool isParityHide()const {return isParityHidden;}
    void setParityHide(bool avaliable);

    bool isStopBitHide()const {return isStopBitHidden;}
    void setStopBitHide(bool avaliable);

    bool isOpenPortHide()const {return isOpenPortHidden;}
    void setOpenPortHide(bool avaliable);

    bool isAddrHide()const { return isAddrHidden;}
    void setAddrHide(bool avaliable);

    bool isTimeoutHide()const { return isTimeoutHidden;}
    void setTimeoutHide(bool avaliable);

    bool isRepHide()const { return isRepHidden;}
    void setRepHide(bool avaliable);

    BaudRate defaultBaudRate()const {return defBaudrate;}
    void setDefaultBaudRate(BaudRate baudrate);

    DataBits defaultDataBits() const {return defDataBits;}
    void setDefaultDataBits(DataBits dataBits);

    Parity defaultParity() const {return defParity;}
    void setDefaultParity(Parity parity);

    StopBits defaultStopBits() const {return defStopBits;}
    void setDefaultStopBits(StopBits stopBits);

    bool enableCBR()const{return isEnableCBR;}
    void setEnableCBR(bool checked);

    bool isModbusMode() const {return isMBMode;}
    void setModbusMode(bool enable);

    void retranslateUi();

signals:
    void errMsg(QString);
    void openPort();
    void closePort();

public slots:

private slots:
    void on_btnReflash_clicked();

    void on_ckbDTR_clicked(bool checked);

    void on_ckbRTS_clicked(bool checked);

    void on_ckbCBR_clicked(bool checked);

    void on_btnOpen_clicked(bool checked);

private:
    Ui::SerialComm *ui;

    void listPortName(QComboBox *cbbPortName);
    void listBaudRate(QComboBox *cbbBaud);
    void listDataBit(QComboBox *cbbDataBit);
    void listParity(QComboBox *cbbParity);
    void listStopBit(QComboBox *cbbStopBit);
    void listFlowCtrl(QComboBox *cbbFlowCtrl);
    void sortPortList(QStringList &portList);
    void searchPort(QStringList &portList);

    void configPort();

    QComboBox   *cbbPortName;
    QComboBox   *cbbBaudRate;
    QComboBox   *cbbDataBit;
    QComboBox   *cbbParity;
    QComboBox   *cbbStopBit;
    QComboBox   *cbbFlowCtrl;

    QCheckBox   *ckbDTR;
    QCheckBox   *ckbRTS;

    QPushButton *btnOpen;
    QPushButton *btnReflash;

    QSpinBox  *spbAddr;
    QSpinBox  *spbTimeout;
    QSpinBox  *spbRep;

    QSerialPort   *port;
    QModbusClient *mbDevice;


    bool isDTRHidden          = false;
    bool isRTSHidden          = false;
    bool isEnableCBR          = false;
    bool isBaudrateHidden     = false;
    bool isDataBitHidden      = false;
    bool isParityHidden       = false;
    bool isStopBitHidden      = false;
    bool isPortnameHidden     = false;
    bool isOpenPortHidden     = false;
    bool isAddrHidden         = false;
    bool isTimeoutHidden      = false;
    bool isRepHidden          = false;
    bool isMBMode             = false;

    BaudRate defBaudrate = Baud115200; // default baudRate
    DataBits defDataBits = Data8;
    Parity   defParity   = NoParity;
    StopBits defStopBits = OneStop;
};

#endif // SERIALCOMM_H

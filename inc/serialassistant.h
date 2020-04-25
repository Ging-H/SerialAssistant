#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

//#include <QWidget>
#include <QSerialPortInfo>
#include "baseserialcomm.h"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
#include <QStyleFactory>


namespace Ui {
class SerialAssistant;
}

class SerialAssistant : public QWidget
{
    Q_OBJECT

public:

    enum VerifyStyle{
        AddVerifyItem      = 0,
        ADD8               = 1,
        NADD8              = 2,
        XOR8               = 3,
        CRC_Modbus         = 4,
        CRC_Xmodem         = 5,
        CRC32              = 6,
        LRC                = 7, // Longitudinal Redundancy Check
        UnknownStyle       = -1
    };
    Q_ENUM(VerifyStyle)

    explicit SerialAssistant(QWidget *parent = 0);
    ~SerialAssistant();

    static bool rxPause ;        // 暂停接收
    static qint32 const pgsBarUpRate = 100;  // 进度条的更新时间间隔
    static qint32 pgsBarInc;     // 用于进度条更新增量

    QList<QString> saveText;  // 用于临时保存文本数据
    QList<QString> saveArray; // 用于临时保存Hex数据
    QTimer txTimer; // 发送用的定时器

    QFile   *saveFile;
    QFile   *loadFile;
    QTextStream *txtStreamSave = NULL;

    BaseSerialComm *currentPort;   // 端口号
    QByteArray rxBuffer;           // 接收缓存
    qint32 rxCount = 0;            // 接收字节计数
    quint32 txCount = 0;           // 发送字节计数
    QVector < QPushButton *> multiPushButton; // 按键数组
    QVector < QLineEdit *> multiTxtLine;      // 数组
    QVector < QCheckBox *> multiCheckBox;     //

    qint32 rxBufSize = 1024*1024; // 64k buffer
    QTimer txtFlashTime;        // ui定时更新
    bool rxFlag = false ;
    QTime rxTimeStamp;          // 接收数据时间戳

    void insertTimeStramp(QByteArray &tmp);// 插入时间戳
    void initComboBox_Config();            // 初始化串口配置的下拉列表(ComboBox)
    void configPort();                     // 初始化配置串口
    void deleteTxTimer();                  // 停止发送定时器
    void startTxTimer();                   // 启动发送定时器
    QByteArray stringToSend(QString src, bool txInHex, bool &ok );
    QByteArray insertVerify(QByteArray &tmp); // 插入校验码
    void listVerifyStyle(QComboBox *cbbVerifyStyle);// 列出校验码QCombobox控件

signals:
    void signals_displayTxBuffer(QByteArray);

public slots:

    void slots_serialRxCallback();
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_highlightLine();
    void slots_timeOutTx();
    void slots_multiSend();
    void slots_timeOutProgressBar();
    void slots_displayTxBuffer(QByteArray);
    void slots_rxDisplayTxt();

private slots:
    void on_btnOpenPort_clicked();

    void on_btnRefresh_clicked();

    void on_chkFlowCtrlDTR_toggled(bool checked);

    void on_chkFlowCtrlRTS_toggled(bool checked);

    void on_btnSaveFile_clicked();

    void on_btnLoadFile_clicked();

    void on_textBrower_textChanged();

    void on_btnSend_clicked();

    void on_txtSingle_textChanged();

    void on_chbTimedTx_clicked(bool checked);

    void on_spbTxInterval_editingFinished();

    void on_chbTxHex_clicked(bool checked);

    void on_btnTxFile_clicked(bool checked);

    void on_btnClear_clicked();

    void on_pushButton_clicked();

private:
    Ui::SerialAssistant *ui;

};

#endif // SERIALASSISTANT_H

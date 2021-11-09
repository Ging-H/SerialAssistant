#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QMainWindow>

#include <QTimer>
#include <QTime>
#include <QFile>
#include <QLineEdit>
#include <QTextStream>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QMetaEnum>
#include <QFileDialog>
#include <QTextCodec>
#include <QKeyEvent>
#include <QStyleFactory>
#include <QMenu>
#include <QSettings>

namespace Ui {
class SerialAssistant;
}

class SerialComm;
class QSerialPort;
class QComboBox;
class QTranslator;
class SerialAssistant : public QMainWindow
{
    Q_OBJECT

public:

    explicit SerialAssistant(QMainWindow *parent = 0);
    ~SerialAssistant();

    enum VerifyStyle{
        AddVerifyItem      = 0,
        ADD8               = 1,
        NADD8              = 2,
        XOR8               = 3,
        LRC                = 4, // Longitudinal Redundancy Check
        CRC8_MAXIM_DS18B20 = 5,
        CRC16_USB          = 6,
        CRC16_MODBUS       = 7,
        CRC16_CCITT        = 8,
        CRC16_CCITT_FALSE  = 9,
        CRC32              = 10,
    }verifyStyle;
    Q_ENUM(VerifyStyle)

    enum  Terminator{
        NoTerminator = 0,
        CRLF_0x0D0A  = 0x0A0D, // '\n''\r',
        CR_0x0D      = 0x0D,   // '\r',
        LF_0xOA      = 0x0A,   // '\n',
    }terminator;
    Q_ENUM(Terminator)

    qint32 rxBufSize = 1024*1024; // 1M buffer

    void setTitle(QString title);


signals:
    void signals_displayTxBuffer(QByteArray);

public slots:
    void slots_serialRxCallback();
    void slots_errMsg(QString errMsg);
    void slots_highlightLine();
    void slots_timeOutTx();
    void slots_multiSend(qint32 index);
    void slots_timeOutProgressBar();
    void slots_displayTxBuffer(QByteArray);
    void slots_rxDisplayTxt();

private slots:
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

    void on_ckbTimeStamp_clicked(bool checked);

    void on_chkDisplayHex_clicked(bool checked);

    void on_rdbGB18030_clicked(bool checked);

    void on_rdbUTF8_clicked();

    void on_cbbTerminator_currentIndexChanged(int index);

    void on_spbStart_valueChanged(int arg1);

    void on_spbEnd_valueChanged(int arg1);

    void on_cbbVerifyStyle_currentIndexChanged(int index);

    void on_serialComm_openPort();

    void on_serialComm_closePort();

    void on_actionCN_triggered();

    void on_actionEnglish_triggered();

    void on_actionfusion_triggered();

    void on_actionCN_T_triggered();

    void on_actionWindows_triggered();

    void on_actionWindowsVista_triggered();

    void on_actionDarkStyle_triggered();

    void on_actionDefaultStyle_triggered();

    void on_actionTips_triggered();

protected:
    void closeEvent(QCloseEvent *event);

private:


    enum  ChineseEncoder{
        GBK2312,
        UTF8
    }cnEncoder;

    enum  Language{
        zh_CN,
        zh_TW,
        en,
    }language;

    enum  WinStyle{
        Fusion,
        Windows,
        WindowsVista,
    }winStyle;

    enum  QssStyle{
        DefaultStyle,
        DarkStyle,
    }qssStyle;


    Ui::SerialAssistant *ui;
    QSerialPort *port;             // 通信端口
    bool isPortOpen = false;       // 打开端口

    QByteArray rxBuffer;           // 接收缓存
    qint32 rxCount = 0;            // 接收字节计数
    qint32 txCount = 0;            // 发送字节计数

    bool  isRxData = false ;       // 标记接收到数据
    QTimer txtFlashTime;           // 用于显示接收的数据
    QTime rxTimeStamp;             // 接收数据时间戳

    const qint32 pgsBarUpRate = 100;  // 进度条的更新时间间隔 100ms
    qint32 pgsBarInc;              // 进度条更新增量
    QTimer txTimer;                // 更新进度条的定时器

    QList<QString> saveText ;       // 用于临时保存文本数据
    QList<QString> saveArray ;      // 用于临时保存Hex数据

    QFile   *saveFile;             // 保存至文件
    QFile   *loadFile;             // 加载文件用于发送
    QTextStream *txtStreamSave = NULL; // 保存文件

    bool isTimeStamp;              // 添加时间戳
    bool isDisplayInHex;           // Hex格式显示

    int startVerify;               // 校验码起始位置
    int endVerify;                 // 校验码结束位置

    QString iniPath;               // 多帧发送的ini文件存储位置

    bool isDarkStyle = false;      // 暗橙 style

    QTranslator *tsSerialAssistant = NULL; // 语言翻译
    QTranslator *tfSerialComm = NULL;      // 语言翻译
    QTranslator *tfMultiWidget = NULL;     // 语言翻译

    void insertTimeStramp(QString &tmp);// 插入时间戳
    void initComboBox_Config();            // 初始化串口配置的下拉列表(ComboBox)
    void configPort();                     // 初始化配置串口
    void deleteTxTimer();                  // 停止发送定时器
    void startTxTimer();                   // 启动发送定时器
    QByteArray stringToSend(QString src, bool txInHex, bool &ok ); // 整理发送数据的格式
    QByteArray insertVerify(QByteArray &tmp, VerifyStyle style = AddVerifyItem); // 插入校验码
    void listVerifyStyle(QComboBox *cbbVerifyStyle);// 列出校验码QCombobox控件
    void initMultiBtn( QPushButton *btn , quint16 count);
    void renameTxt(QLineEdit *txt, quint16 count);
    void renameCkb( QCheckBox *ckb , quint16 count);
    void loadDefaultConfig();

    bool isHexString(QString src);
    void listTerminator(QComboBox *cbbTerminator);
    quint8 verifyADD8(QByteArray buf);
    quint8 verifyXOR8(QByteArray buf);
    quint16 verifyCRC16_Modbus(QByteArray buf);
    quint16 verifyCRC16_CCITT(QByteArray buf);
    quint32 verifyCRC32(QByteArray buf);
    uint8_t verifyCRC8_DS18B20(QByteArray buf);
    uint16_t verifyCRC16_USB(QByteArray buf);
    uint16_t verifyCRC16_CCITT_FALSE(QByteArray buf);

    void constructTranstor();      // 构建翻译对象
};

#endif // SERIALASSISTANT_H

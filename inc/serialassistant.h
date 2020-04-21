#ifndef SERIALASSISTANT_H
#define SERIALASSISTANT_H

#include <QWidget>
#include <QSerialPortInfo>
#include "baseserialcomm.h"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QCheckBox>
//#include <QSharedMemory>


namespace Ui {
class SerialAssistant;
}

class SerialAssistant : public QWidget
{
    Q_OBJECT

public:
    explicit SerialAssistant(QWidget *parent = 0);
    ~SerialAssistant();

    static bool openPort;        // 打开串口
    static bool rxPause ;        // 暂停接收
    static qint32 const pgsBarUpRate = 100;  // 进度条的更新时间间隔
    static qint32 pgsBarInc;     // 用于进度条更新增量

    QList<QString> saveText;  // 用于临时保存文本数据
    QList<QString> saveArray; // 用于临时保存Hex数据
    QTimer rxTimer; // 接收用的定时器
    QTimer txTimer; // 发送用的定时器


    QFile   *saveFile;
    QFile   *loadFile;
    QTextStream *streamToSave;
    QTextStream *streamToend;
    BaseSerialComm *currentPort;   // 端口号
    QByteArray rxBuffer;
    quint32 rxCount = 0;
    quint32 txCount = 0;


    void initComboBox_Config();    // 初始化串口配置的下拉列表(ComboBox)
    void configPort();
    void deleteRxTimer();
    void startRxTimer();
    void deleteTxTimer();
    void startTxTimer();

//    QString asciiToHexString(QString src);

    bool isHexString(QString src);
    QByteArray stringToSend(QString src, bool txInHex, bool &ok );
//    QByteArray stringToSend(QString src, bool txInHex );
//    QString hexStringToAscii(QString src);

    QVector < QPushButton *> multiPushButton;
    QVector < QLineEdit *> multiTxtLine;
    QVector < QCheckBox *> multiCheckBox;
QTimer rxTimeout;
signals:
    void signals_displayTxBuffer(QByteArray);

public slots:

    void slots_serialRxCallback();
    void slots_serialRxTimeCallback();
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_highlightLine();
    void slots_timeOutTx();
    void slots_multiSend();
    void slots_timeOutProgressBar();
    void slots_displayTxBuffer(QByteArray);
    void slots_rxTimeOut();

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

    void on_checkBox_5_clicked(bool checked);

    void on_spbTxInterval_editingFinished();

    void on_chbTxHex_clicked(bool checked);

    void on_spbRxInterval_editingFinished();

    void on_btnTxFile_clicked(bool checked);

    void on_btnClear_clicked();

    void on_pushButton_clicked();


private:
    Ui::SerialAssistant *ui;
//    QTime rxTimeout;

};

#endif // SERIALASSISTANT_H

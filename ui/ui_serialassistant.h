/********************************************************************************
** Form generated from reading UI file 'serialassistant.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALASSISTANT_H
#define UI_SERIALASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialAssistant
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *QGBSerialConfig;
    QPushButton *btnOpenPort;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkFlowCtrlDTR;
    QCheckBox *chkFlowCtrlRTS;
    QGroupBox *QGBCtrlRx;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkDisplayHex;
    QCheckBox *checkBox_5;
    QPushButton *btnSaveFile;
    QPushButton *btnClear;
    QGroupBox *QGBCtrlTx;
    QSpinBox *spbTxInterval;
    QLabel *lblFileSize;
    QComboBox *cbbVerifyStyle;
    QPushButton *btnLoadFile;
    QPushButton *btnTxFile;
    QLabel *lblTerminator;
    QComboBox *cbbTerminator;
    QTextBrowser *txtVerify;
    QSpinBox *spbStart;
    QSpinBox *spbEnd;
    QCheckBox *chbTxHex;
    QCheckBox *chbTimedTx;
    QPushButton *pushButton;
    QGridLayout *gridLayout_5;
    QLabel *lbltxCnt;
    QLabel *label_2;
    QLabel *lblrxCnt;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QPlainTextEdit *textBrower;
    QToolBox *toolBox;
    QWidget *single;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *txtSingle;
    QPushButton *btnSend;
    QWidget *multi;
    QGridLayout *gridLayout_2;
    QCheckBox *chkMulti01;
    QPushButton *btnMultiPush01;
    QLineEdit *txtLine01;
    QCheckBox *chkMulti06;
    QPushButton *btnMultiPush06;
    QLineEdit *txtLine06;
    QCheckBox *chkMulti02;
    QPushButton *btnMultiPush02;
    QLineEdit *txtLine02;
    QCheckBox *chkMulti07;
    QPushButton *btnMultiPush07;
    QLineEdit *txtLine07;
    QCheckBox *chkMulti03;
    QPushButton *btnMultiPush03;
    QLineEdit *txtLine03;
    QCheckBox *chkMulti08;
    QPushButton *btnMultiPush08;
    QLineEdit *txtLine08;
    QCheckBox *chkMulti04;
    QPushButton *btnMultiPush04;
    QLineEdit *txtLine04;
    QCheckBox *chkMulti09;
    QPushButton *btnMultiPush09;
    QLineEdit *txtLine09;
    QCheckBox *chkMulti05;
    QPushButton *btnMultiPush05;
    QLineEdit *txtLine05;
    QCheckBox *chkMulti10;
    QPushButton *btnMultiPush10;
    QLineEdit *txtLine10;
    QProgressBar *progressBar;

    void setupUi(QWidget *SerialAssistant)
    {
        if (SerialAssistant->objectName().isEmpty())
            SerialAssistant->setObjectName(QStringLiteral("SerialAssistant"));
        SerialAssistant->resize(972, 652);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialAssistant->sizePolicy().hasHeightForWidth());
        SerialAssistant->setSizePolicy(sizePolicy);
        SerialAssistant->setMinimumSize(QSize(969, 652));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/res/ico/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SerialAssistant->setWindowIcon(icon);
        SerialAssistant->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(SerialAssistant);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        QGBSerialConfig = new QGroupBox(SerialAssistant);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy1);
        QGBSerialConfig->setMinimumSize(QSize(171, 211));
        QGBSerialConfig->setMaximumSize(QSize(171, 211));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setGeometry(QRect(69, 160, 91, 31));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/centrejust.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/action/action/process-stop.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon1);
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);
        formLayoutWidget = new QWidget(QGBSerialConfig);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 151, 136));
        gridLayout_3 = new QGridLayout(formLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblVerify = new QLabel(formLayoutWidget);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(formLayoutWidget);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(formLayoutWidget);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(formLayoutWidget);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(formLayoutWidget);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(formLayoutWidget);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy2);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(formLayoutWidget);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(formLayoutWidget);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(formLayoutWidget);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(formLayoutWidget);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(11, 160, 51, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/action/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);
        layoutWidget = new QWidget(QGBSerialConfig);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 190, 151, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chkFlowCtrlDTR = new QCheckBox(layoutWidget);
        chkFlowCtrlDTR->setObjectName(QStringLiteral("chkFlowCtrlDTR"));

        horizontalLayout->addWidget(chkFlowCtrlDTR);

        chkFlowCtrlRTS = new QCheckBox(layoutWidget);
        chkFlowCtrlRTS->setObjectName(QStringLiteral("chkFlowCtrlRTS"));

        horizontalLayout->addWidget(chkFlowCtrlRTS);


        verticalLayout_3->addWidget(QGBSerialConfig);

        QGBCtrlRx = new QGroupBox(SerialAssistant);
        QGBCtrlRx->setObjectName(QStringLiteral("QGBCtrlRx"));
        sizePolicy1.setHeightForWidth(QGBCtrlRx->sizePolicy().hasHeightForWidth());
        QGBCtrlRx->setSizePolicy(sizePolicy1);
        QGBCtrlRx->setMinimumSize(QSize(171, 80));
        QGBCtrlRx->setMaximumSize(QSize(171, 80));
        QGBCtrlRx->setStyleSheet(QStringLiteral(""));
        QGBCtrlRx->setFlat(false);
        QGBCtrlRx->setCheckable(false);
        layoutWidget1 = new QWidget(QGBCtrlRx);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 151, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        chkDisplayHex = new QCheckBox(layoutWidget1);
        chkDisplayHex->setObjectName(QStringLiteral("chkDisplayHex"));

        horizontalLayout_3->addWidget(chkDisplayHex);

        checkBox_5 = new QCheckBox(layoutWidget1);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_5);

        btnSaveFile = new QPushButton(QGBCtrlRx);
        btnSaveFile->setObjectName(QStringLiteral("btnSaveFile"));
        btnSaveFile->setGeometry(QRect(80, 20, 86, 26));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/action/action/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveFile->setIcon(icon3);
        btnSaveFile->setCheckable(true);
        btnClear = new QPushButton(QGBCtrlRx);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(10, 20, 61, 23));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/action/action/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon4);

        verticalLayout_3->addWidget(QGBCtrlRx);

        QGBCtrlTx = new QGroupBox(SerialAssistant);
        QGBCtrlTx->setObjectName(QStringLiteral("QGBCtrlTx"));
        sizePolicy1.setHeightForWidth(QGBCtrlTx->sizePolicy().hasHeightForWidth());
        QGBCtrlTx->setSizePolicy(sizePolicy1);
        QGBCtrlTx->setMinimumSize(QSize(171, 251));
        QGBCtrlTx->setMaximumSize(QSize(171, 251));
        QGBCtrlTx->setStyleSheet(QStringLiteral(""));
        QGBCtrlTx->setFlat(false);
        QGBCtrlTx->setCheckable(false);
        spbTxInterval = new QSpinBox(QGBCtrlTx);
        spbTxInterval->setObjectName(QStringLiteral("spbTxInterval"));
        spbTxInterval->setGeometry(QRect(10, 220, 151, 20));
        spbTxInterval->setMinimumSize(QSize(61, 18));
        spbTxInterval->setAutoFillBackground(false);
        spbTxInterval->setMinimum(20);
        spbTxInterval->setMaximum(99999);
        spbTxInterval->setValue(50);
        lblFileSize = new QLabel(QGBCtrlTx);
        lblFileSize->setObjectName(QStringLiteral("lblFileSize"));
        lblFileSize->setGeometry(QRect(10, 50, 151, 16));
        cbbVerifyStyle = new QComboBox(QGBCtrlTx);
        cbbVerifyStyle->setObjectName(QStringLiteral("cbbVerifyStyle"));
        cbbVerifyStyle->setGeometry(QRect(10, 100, 151, 22));
        btnLoadFile = new QPushButton(QGBCtrlTx);
        btnLoadFile->setObjectName(QStringLiteral("btnLoadFile"));
        btnLoadFile->setGeometry(QRect(12, 24, 61, 21));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/action/action/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadFile->setIcon(icon5);
        btnLoadFile->setCheckable(true);
        btnTxFile = new QPushButton(QGBCtrlTx);
        btnTxFile->setObjectName(QStringLiteral("btnTxFile"));
        btnTxFile->setGeometry(QRect(80, 24, 81, 21));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/action/action/mail_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTxFile->setIcon(icon6);
        btnTxFile->setIconSize(QSize(16, 16));
        btnTxFile->setCheckable(true);
        lblTerminator = new QLabel(QGBCtrlTx);
        lblTerminator->setObjectName(QStringLiteral("lblTerminator"));
        lblTerminator->setGeometry(QRect(11, 73, 51, 16));
        cbbTerminator = new QComboBox(QGBCtrlTx);
        cbbTerminator->setObjectName(QStringLiteral("cbbTerminator"));
        cbbTerminator->setGeometry(QRect(60, 70, 101, 22));
        txtVerify = new QTextBrowser(QGBCtrlTx);
        txtVerify->setObjectName(QStringLiteral("txtVerify"));
        txtVerify->setGeometry(QRect(10, 170, 151, 21));
        txtVerify->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtVerify->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        spbStart = new QSpinBox(QGBCtrlTx);
        spbStart->setObjectName(QStringLiteral("spbStart"));
        spbStart->setGeometry(QRect(10, 130, 151, 22));
        spbStart->setStyleSheet(QStringLiteral(""));
        spbStart->setMaximum(2048);
        spbStart->setValue(1);
        spbStart->setDisplayIntegerBase(10);
        spbEnd = new QSpinBox(QGBCtrlTx);
        spbEnd->setObjectName(QStringLiteral("spbEnd"));
        spbEnd->setGeometry(QRect(10, 150, 151, 22));
        spbEnd->setStyleSheet(QStringLiteral(""));
        spbEnd->setMaximum(2048);
        spbEnd->setValue(0);
        spbEnd->setDisplayIntegerBase(10);
        chbTxHex = new QCheckBox(QGBCtrlTx);
        chbTxHex->setObjectName(QStringLiteral("chbTxHex"));
        chbTxHex->setGeometry(QRect(11, 191, 67, 18));
        chbTimedTx = new QCheckBox(QGBCtrlTx);
        chbTimedTx->setObjectName(QStringLiteral("chbTimedTx"));
        chbTimedTx->setGeometry(QRect(87, 191, 73, 18));

        verticalLayout_3->addWidget(QGBCtrlTx);

        pushButton = new QPushButton(SerialAssistant);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lbltxCnt = new QLabel(SerialAssistant);
        lbltxCnt->setObjectName(QStringLiteral("lbltxCnt"));
        sizePolicy1.setHeightForWidth(lbltxCnt->sizePolicy().hasHeightForWidth());
        lbltxCnt->setSizePolicy(sizePolicy1);
        lbltxCnt->setMinimumSize(QSize(0, 12));

        gridLayout_5->addWidget(lbltxCnt, 0, 3, 1, 1);

        label_2 = new QLabel(SerialAssistant);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 12));
        label_2->setMaximumSize(QSize(16, 16777215));

        gridLayout_5->addWidget(label_2, 0, 2, 1, 1);

        lblrxCnt = new QLabel(SerialAssistant);
        lblrxCnt->setObjectName(QStringLiteral("lblrxCnt"));
        sizePolicy1.setHeightForWidth(lblrxCnt->sizePolicy().hasHeightForWidth());
        lblrxCnt->setSizePolicy(sizePolicy1);
        lblrxCnt->setMinimumSize(QSize(0, 12));

        gridLayout_5->addWidget(lblrxCnt, 0, 1, 1, 1);

        label = new QLabel(SerialAssistant);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 12));
        label->setMaximumSize(QSize(16, 16777215));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(SerialAssistant);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        textBrower = new QPlainTextEdit(splitter);
        textBrower->setObjectName(QStringLiteral("textBrower"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textBrower->sizePolicy().hasHeightForWidth());
        textBrower->setSizePolicy(sizePolicy3);
        textBrower->setMinimumSize(QSize(287, 200));
        splitter->addWidget(textBrower);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        sizePolicy2.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy2);
        toolBox->setMinimumSize(QSize(287, 200));
        toolBox->setMaximumSize(QSize(16777215, 209));
        single = new QWidget();
        single->setObjectName(QStringLiteral("single"));
        single->setGeometry(QRect(0, 0, 773, 157));
        gridLayout_4 = new QGridLayout(single);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(17, 152, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        txtSingle = new QPlainTextEdit(single);
        txtSingle->setObjectName(QStringLiteral("txtSingle"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txtSingle->sizePolicy().hasHeightForWidth());
        txtSingle->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(txtSingle, 0, 1, 2, 1);

        btnSend = new QPushButton(single);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        sizePolicy1.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy1);
        btnSend->setMinimumSize(QSize(71, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/general/general/\345\217\221\351\200\201.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSend->setIcon(icon7);
        btnSend->setIconSize(QSize(70, 50));

        gridLayout_4->addWidget(btnSend, 0, 0, 1, 1);

        toolBox->addItem(single, QString::fromUtf8("\345\215\225\346\235\241\345\217\221\351\200\201"));
        multi = new QWidget();
        multi->setObjectName(QStringLiteral("multi"));
        multi->setGeometry(QRect(0, 0, 773, 157));
        gridLayout_2 = new QGridLayout(multi);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chkMulti01 = new QCheckBox(multi);
        chkMulti01->setObjectName(QStringLiteral("chkMulti01"));

        gridLayout_2->addWidget(chkMulti01, 0, 0, 1, 1);

        btnMultiPush01 = new QPushButton(multi);
        btnMultiPush01->setObjectName(QStringLiteral("btnMultiPush01"));

        gridLayout_2->addWidget(btnMultiPush01, 0, 1, 1, 1);

        txtLine01 = new QLineEdit(multi);
        txtLine01->setObjectName(QStringLiteral("txtLine01"));

        gridLayout_2->addWidget(txtLine01, 0, 2, 1, 1);

        chkMulti06 = new QCheckBox(multi);
        chkMulti06->setObjectName(QStringLiteral("chkMulti06"));

        gridLayout_2->addWidget(chkMulti06, 0, 3, 1, 1);

        btnMultiPush06 = new QPushButton(multi);
        btnMultiPush06->setObjectName(QStringLiteral("btnMultiPush06"));

        gridLayout_2->addWidget(btnMultiPush06, 0, 4, 1, 1);

        txtLine06 = new QLineEdit(multi);
        txtLine06->setObjectName(QStringLiteral("txtLine06"));

        gridLayout_2->addWidget(txtLine06, 0, 5, 1, 1);

        chkMulti02 = new QCheckBox(multi);
        chkMulti02->setObjectName(QStringLiteral("chkMulti02"));

        gridLayout_2->addWidget(chkMulti02, 1, 0, 1, 1);

        btnMultiPush02 = new QPushButton(multi);
        btnMultiPush02->setObjectName(QStringLiteral("btnMultiPush02"));

        gridLayout_2->addWidget(btnMultiPush02, 1, 1, 1, 1);

        txtLine02 = new QLineEdit(multi);
        txtLine02->setObjectName(QStringLiteral("txtLine02"));

        gridLayout_2->addWidget(txtLine02, 1, 2, 1, 1);

        chkMulti07 = new QCheckBox(multi);
        chkMulti07->setObjectName(QStringLiteral("chkMulti07"));

        gridLayout_2->addWidget(chkMulti07, 1, 3, 1, 1);

        btnMultiPush07 = new QPushButton(multi);
        btnMultiPush07->setObjectName(QStringLiteral("btnMultiPush07"));

        gridLayout_2->addWidget(btnMultiPush07, 1, 4, 1, 1);

        txtLine07 = new QLineEdit(multi);
        txtLine07->setObjectName(QStringLiteral("txtLine07"));

        gridLayout_2->addWidget(txtLine07, 1, 5, 1, 1);

        chkMulti03 = new QCheckBox(multi);
        chkMulti03->setObjectName(QStringLiteral("chkMulti03"));

        gridLayout_2->addWidget(chkMulti03, 2, 0, 1, 1);

        btnMultiPush03 = new QPushButton(multi);
        btnMultiPush03->setObjectName(QStringLiteral("btnMultiPush03"));

        gridLayout_2->addWidget(btnMultiPush03, 2, 1, 1, 1);

        txtLine03 = new QLineEdit(multi);
        txtLine03->setObjectName(QStringLiteral("txtLine03"));

        gridLayout_2->addWidget(txtLine03, 2, 2, 1, 1);

        chkMulti08 = new QCheckBox(multi);
        chkMulti08->setObjectName(QStringLiteral("chkMulti08"));

        gridLayout_2->addWidget(chkMulti08, 2, 3, 1, 1);

        btnMultiPush08 = new QPushButton(multi);
        btnMultiPush08->setObjectName(QStringLiteral("btnMultiPush08"));

        gridLayout_2->addWidget(btnMultiPush08, 2, 4, 1, 1);

        txtLine08 = new QLineEdit(multi);
        txtLine08->setObjectName(QStringLiteral("txtLine08"));

        gridLayout_2->addWidget(txtLine08, 2, 5, 1, 1);

        chkMulti04 = new QCheckBox(multi);
        chkMulti04->setObjectName(QStringLiteral("chkMulti04"));

        gridLayout_2->addWidget(chkMulti04, 3, 0, 1, 1);

        btnMultiPush04 = new QPushButton(multi);
        btnMultiPush04->setObjectName(QStringLiteral("btnMultiPush04"));

        gridLayout_2->addWidget(btnMultiPush04, 3, 1, 1, 1);

        txtLine04 = new QLineEdit(multi);
        txtLine04->setObjectName(QStringLiteral("txtLine04"));

        gridLayout_2->addWidget(txtLine04, 3, 2, 1, 1);

        chkMulti09 = new QCheckBox(multi);
        chkMulti09->setObjectName(QStringLiteral("chkMulti09"));

        gridLayout_2->addWidget(chkMulti09, 3, 3, 1, 1);

        btnMultiPush09 = new QPushButton(multi);
        btnMultiPush09->setObjectName(QStringLiteral("btnMultiPush09"));

        gridLayout_2->addWidget(btnMultiPush09, 3, 4, 1, 1);

        txtLine09 = new QLineEdit(multi);
        txtLine09->setObjectName(QStringLiteral("txtLine09"));

        gridLayout_2->addWidget(txtLine09, 3, 5, 1, 1);

        chkMulti05 = new QCheckBox(multi);
        chkMulti05->setObjectName(QStringLiteral("chkMulti05"));

        gridLayout_2->addWidget(chkMulti05, 4, 0, 1, 1);

        btnMultiPush05 = new QPushButton(multi);
        btnMultiPush05->setObjectName(QStringLiteral("btnMultiPush05"));

        gridLayout_2->addWidget(btnMultiPush05, 4, 1, 1, 1);

        txtLine05 = new QLineEdit(multi);
        txtLine05->setObjectName(QStringLiteral("txtLine05"));

        gridLayout_2->addWidget(txtLine05, 4, 2, 1, 1);

        chkMulti10 = new QCheckBox(multi);
        chkMulti10->setObjectName(QStringLiteral("chkMulti10"));

        gridLayout_2->addWidget(chkMulti10, 4, 3, 1, 1);

        btnMultiPush10 = new QPushButton(multi);
        btnMultiPush10->setObjectName(QStringLiteral("btnMultiPush10"));

        gridLayout_2->addWidget(btnMultiPush10, 4, 4, 1, 1);

        txtLine10 = new QLineEdit(multi);
        txtLine10->setObjectName(QStringLiteral("txtLine10"));

        gridLayout_2->addWidget(txtLine10, 4, 5, 1, 1);

        toolBox->addItem(multi, QString::fromUtf8("\345\244\232\346\235\241\345\217\221\351\200\201"));
        splitter->addWidget(toolBox);

        verticalLayout->addWidget(splitter);

        progressBar = new QProgressBar(SerialAssistant);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setMaximumSize(QSize(16777215, 10));
        progressBar->setCursor(QCursor(Qt::ArrowCursor));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);

        verticalLayout->addWidget(progressBar);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        QWidget::setTabOrder(cbbPortNum, cbbBaud);
        QWidget::setTabOrder(cbbBaud, cbbDataBit);
        QWidget::setTabOrder(cbbDataBit, cbbVerify);
        QWidget::setTabOrder(cbbVerify, cbbStopBit);
        QWidget::setTabOrder(cbbStopBit, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnOpenPort);
        QWidget::setTabOrder(btnOpenPort, chkFlowCtrlDTR);
        QWidget::setTabOrder(chkFlowCtrlDTR, chkFlowCtrlRTS);
        QWidget::setTabOrder(chkFlowCtrlRTS, btnClear);
        QWidget::setTabOrder(btnClear, btnSaveFile);
        QWidget::setTabOrder(btnSaveFile, chkDisplayHex);
        QWidget::setTabOrder(chkDisplayHex, checkBox_5);
        QWidget::setTabOrder(checkBox_5, btnLoadFile);
        QWidget::setTabOrder(btnLoadFile, btnTxFile);
        QWidget::setTabOrder(btnTxFile, cbbTerminator);
        QWidget::setTabOrder(cbbTerminator, cbbVerifyStyle);
        QWidget::setTabOrder(cbbVerifyStyle, spbStart);
        QWidget::setTabOrder(spbStart, spbEnd);
        QWidget::setTabOrder(spbEnd, txtVerify);
        QWidget::setTabOrder(txtVerify, chbTxHex);
        QWidget::setTabOrder(chbTxHex, chbTimedTx);
        QWidget::setTabOrder(chbTimedTx, spbTxInterval);
        QWidget::setTabOrder(spbTxInterval, btnSend);
        QWidget::setTabOrder(btnSend, txtSingle);
        QWidget::setTabOrder(txtSingle, chkMulti01);
        QWidget::setTabOrder(chkMulti01, btnMultiPush01);
        QWidget::setTabOrder(btnMultiPush01, txtLine01);
        QWidget::setTabOrder(txtLine01, chkMulti02);
        QWidget::setTabOrder(chkMulti02, btnMultiPush02);
        QWidget::setTabOrder(btnMultiPush02, txtLine02);
        QWidget::setTabOrder(txtLine02, chkMulti03);
        QWidget::setTabOrder(chkMulti03, btnMultiPush03);
        QWidget::setTabOrder(btnMultiPush03, txtLine03);
        QWidget::setTabOrder(txtLine03, chkMulti04);
        QWidget::setTabOrder(chkMulti04, btnMultiPush04);
        QWidget::setTabOrder(btnMultiPush04, txtLine04);
        QWidget::setTabOrder(txtLine04, chkMulti05);
        QWidget::setTabOrder(chkMulti05, btnMultiPush05);
        QWidget::setTabOrder(btnMultiPush05, txtLine05);
        QWidget::setTabOrder(txtLine05, chkMulti06);
        QWidget::setTabOrder(chkMulti06, btnMultiPush06);
        QWidget::setTabOrder(btnMultiPush06, txtLine06);
        QWidget::setTabOrder(txtLine06, chkMulti07);
        QWidget::setTabOrder(chkMulti07, btnMultiPush07);
        QWidget::setTabOrder(btnMultiPush07, txtLine07);
        QWidget::setTabOrder(txtLine07, chkMulti08);
        QWidget::setTabOrder(chkMulti08, btnMultiPush08);
        QWidget::setTabOrder(btnMultiPush08, txtLine08);
        QWidget::setTabOrder(txtLine08, chkMulti09);
        QWidget::setTabOrder(chkMulti09, btnMultiPush09);
        QWidget::setTabOrder(btnMultiPush09, txtLine09);
        QWidget::setTabOrder(txtLine09, chkMulti10);
        QWidget::setTabOrder(chkMulti10, btnMultiPush10);
        QWidget::setTabOrder(btnMultiPush10, txtLine10);
        QWidget::setTabOrder(txtLine10, textBrower);

        retranslateUi(SerialAssistant);

        btnOpenPort->setDefault(false);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SerialAssistant);
    } // setupUi

    void retranslateUi(QWidget *SerialAssistant)
    {
        SerialAssistant->setWindowTitle(QApplication::translate("SerialAssistant", "SerialAssistant", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("SerialAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("SerialAssistant", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("SerialAssistant", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("SerialAssistant", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("SerialAssistant", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("SerialAssistant", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("SerialAssistant", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("SerialAssistant", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("SerialAssistant", "\345\210\267\346\226\260", Q_NULLPTR));
        chkFlowCtrlDTR->setText(QApplication::translate("SerialAssistant", "DTR", Q_NULLPTR));
        chkFlowCtrlRTS->setText(QApplication::translate("SerialAssistant", "RTS", Q_NULLPTR));
        QGBCtrlRx->setTitle(QApplication::translate("SerialAssistant", "\346\216\245\346\224\266\346\216\247\345\210\266", Q_NULLPTR));
        chkDisplayHex->setText(QApplication::translate("SerialAssistant", "Hex\346\230\276\347\244\272", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("SerialAssistant", "\345\212\240\346\227\266\351\227\264\346\210\263", Q_NULLPTR));
        btnSaveFile->setText(QApplication::translate("SerialAssistant", "\344\277\235\345\255\230\350\207\263\346\226\207\344\273\266", Q_NULLPTR));
        btnClear->setText(QApplication::translate("SerialAssistant", "\346\270\205\347\251\272", Q_NULLPTR));
        QGBCtrlTx->setTitle(QApplication::translate("SerialAssistant", "\350\207\252\345\212\250\345\217\221\351\200\201\346\216\247\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbTxInterval->setToolTip(QApplication::translate("SerialAssistant", "\346\234\200\345\260\21730ms", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbTxInterval->setSuffix(QApplication::translate("SerialAssistant", " ms", Q_NULLPTR));
        spbTxInterval->setPrefix(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201\346\227\266\351\227\264\351\227\264\351\232\224 ", Q_NULLPTR));
        lblFileSize->setText(QApplication::translate("SerialAssistant", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbbVerifyStyle->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">ADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215</p><p><span style=\" font-weight:600;\">NADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215,\347\204\266\345\220\216\345\217\226\345\217\215\345\212\2401</p><p><span style=\" font-weight:600;\">XOR8:</span>\345\260\2068\344\275\215\346\225\260\346\215\256\345\274\202\346\210\226</p><p><span style=\" font-weight:600;\">CRC16_Modbus:</span>\347\224\250\344\272\216Modbus-RTU\345\215\217\350\256\256,\350\276\223\345\207\272\345\255\227\350\212\202\345\217\215\345\272\217,\344\275\216\344\275\215\345\255\227\350\212\202\345\234\250\345\211\215,\351\253\230\344\275\215\345\255\227\350\212\202\345\234\250\345\220\216</p><p><span style=\" font-weight:600;\">CRC16_XModem:</span>\345\244\232\351\241\271\345\274\2170x1021,\347\224\250\344\272\216Xmodem\345\215\217\350\256\256</p><p><span style=\" f"
                        "ont-weight:600;\">CRC32:</span>\345\244\232\351\241\271\345\274\2170x04C11DB7 IEEE 802.3\346\240\207\345\207\206</p><p><span style=\" font-weight:600;\">LRC:</span>NADD8\347\232\204\345\255\227\347\254\246\346\250\241\345\274\217,\344\270\223\347\224\250\344\272\216\345\255\227\347\254\246\345\217\221\351\200\201\346\250\241\345\274\217,\345\217\252\344\274\232\347\273\237\350\256\241\345\255\227\347\254\246\344\270\262\344\270\255HEX\346\240\274\345\274\217\347\232\204\346\225\260\346\215\256,\346\240\241\351\252\214\347\256\227\346\263\225\344\270\216NADD8\344\270\200\350\207\264,\345\276\227\345\210\260\347\232\2041\345\255\227\350\212\202\345\206\215\345\210\206\346\213\206\346\210\220\344\270\244\344\270\252ASCII\345\255\227\347\254\246(\347\224\250\344\272\216Mosbus-ASCII)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnLoadFile->setText(QApplication::translate("SerialAssistant", "Load", Q_NULLPTR));
        btnTxFile->setText(QApplication::translate("SerialAssistant", "Send", Q_NULLPTR));
        lblTerminator->setText(QApplication::translate("SerialAssistant", "\350\207\252\345\212\250\346\267\273\345\212\240", Q_NULLPTR));
        spbStart->setSpecialValueText(QApplication::translate("SerialAssistant", "\344\270\215\350\203\275\344\275\216\344\272\2160", Q_NULLPTR));
        spbStart->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\274\200\345\247\213", Q_NULLPTR));
        spbStart->setPrefix(QApplication::translate("SerialAssistant", "\344\273\216\347\254\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbEnd->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\344\274\230\345\205\210\347\272\247\346\257\224\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>\350\246\201\344\275\216,\346\211\200\344\273\245\345\246\202\346\236\234\344\275\277\347\224\250\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>,\345\234\250<span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\346\227\266\345\200\231\351\234\200\350\246\201\350\200\203\350\231\221<span style=\" font-weight:600; text-decoration: underline;\">\347\273\223\346\235\237\347\254\246\346\211\200\345\215\240\347\224\250\347\232\204\345\255\227\350\212\202\351\225\277\345\272\246</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbEnd->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\211\215\346\217\222\345\205\245", Q_NULLPTR));
        spbEnd->setPrefix(QApplication::translate("SerialAssistant", "\345\234\250\345\200\222\346\225\260\347\254\254", Q_NULLPTR));
        chbTxHex->setText(QApplication::translate("SerialAssistant", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        chbTimedTx->setText(QApplication::translate("SerialAssistant", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SerialAssistant", "\345\244\215\344\275\215\350\256\241\346\225\260", Q_NULLPTR));
        lbltxCnt->setText(QApplication::translate("SerialAssistant", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialAssistant", "Tx:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lblrxCnt->setToolTip(QApplication::translate("SerialAssistant", "\350\266\205\350\277\20760000\345\260\206\344\274\232\346\270\205\347\251\272\346\216\245\346\224\266\347\274\223\345\255\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblrxCnt->setText(QApplication::translate("SerialAssistant", "0", Q_NULLPTR));
        label->setText(QApplication::translate("SerialAssistant", "Rx:", Q_NULLPTR));
        txtSingle->setPlainText(QApplication::translate("SerialAssistant", "\347\241\254\347\237\263\347\224\265\345\255\220 \346\220\272\346\211\213\345\220\210\344\275\234,\345\205\261\345\210\233\346\234\252\346\235\245\n"
"http://www.ing10bbs.com/\n"
"", Q_NULLPTR));
        btnSend->setText(QString());
        toolBox->setItemText(toolBox->indexOf(single), QApplication::translate("SerialAssistant", "\345\215\225\346\235\241\345\217\221\351\200\201", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti01->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti01->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush01->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush01->setText(QApplication::translate("SerialAssistant", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti06->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti06->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush06->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush06->setText(QApplication::translate("SerialAssistant", "6", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti02->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti02->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush02->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush02->setText(QApplication::translate("SerialAssistant", "2", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti07->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti07->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush07->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush07->setText(QApplication::translate("SerialAssistant", "7", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti03->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti03->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush03->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush03->setText(QApplication::translate("SerialAssistant", "3", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti08->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti08->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush08->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush08->setText(QApplication::translate("SerialAssistant", "8", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti04->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti04->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush04->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush04->setText(QApplication::translate("SerialAssistant", "4", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti09->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti09->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush09->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush09->setText(QApplication::translate("SerialAssistant", "9", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti05->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti05->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush05->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush05->setText(QApplication::translate("SerialAssistant", "5", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti10->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti10->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush10->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush10->setText(QApplication::translate("SerialAssistant", "10", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(multi), QApplication::translate("SerialAssistant", "\345\244\232\346\235\241\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialAssistant: public Ui_SerialAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALASSISTANT_H

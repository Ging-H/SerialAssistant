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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
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
    QAction *actionRename;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_6;
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
    QPushButton *btnOpenPort;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkFlowCtrlDTR;
    QCheckBox *chkFlowCtrlRTS;
    QGroupBox *QGBCtrlRx;
    QGridLayout *gridLayout_7;
    QPushButton *btnClear;
    QPushButton *btnSaveFile;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkDisplayHex;
    QCheckBox *checkBox_5;
    QGroupBox *QGBCtrlTx;
    QGridLayout *gridLayout_8;
    QPushButton *btnLoadFile;
    QPushButton *btnTxFile;
    QLabel *lblFileSize;
    QLabel *lblTerminator;
    QComboBox *cbbTerminator;
    QComboBox *cbbVerifyStyle;
    QSpinBox *spbStart;
    QSpinBox *spbEnd;
    QTextBrowser *txtVerify;
    QSplitter *splitter_2;
    QCheckBox *chbTxHex;
    QCheckBox *chbTimedTx;
    QSpinBox *spbTxInterval;
    QSplitter *splitter_3;
    QRadioButton *rdbGB18030;
    QRadioButton *rdbUTF8;
    QPushButton *pushButton;
    QGridLayout *gridLayout_5;
    QLabel *lbltxCnt;
    QLabel *label_2;
    QLabel *lblrxCnt;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QPlainTextEdit *textBrower;
    QToolBox *toolBox;
    QWidget *single;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QPlainTextEdit *txtSingle;
    QPushButton *btnSend;
    QWidget *multi;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkMulti01;
    QPushButton *btnMultiPush01;
    QLineEdit *txtLine01;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *chkMulti02;
    QPushButton *btnMultiPush02;
    QLineEdit *txtLine02;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *chkMulti03;
    QPushButton *btnMultiPush03;
    QLineEdit *txtLine03;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chkMulti04;
    QPushButton *btnMultiPush04;
    QLineEdit *txtLine04;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *chkMulti05;
    QPushButton *btnMultiPush05;
    QLineEdit *txtLine05;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *chkMulti06;
    QPushButton *btnMultiPush06;
    QLineEdit *txtLine06;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *chkMulti07;
    QPushButton *btnMultiPush07;
    QLineEdit *txtLine07;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *chkMulti08;
    QPushButton *btnMultiPush08;
    QLineEdit *txtLine08;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *chkMulti09;
    QPushButton *btnMultiPush09;
    QLineEdit *txtLine09;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *chkMulti10;
    QPushButton *btnMultiPush10;
    QLineEdit *txtLine10;
    QPushButton *btnAddNewGroup;
    QPushButton *btnDelLastGroup;
    QPushButton *btnSaveGroupData;
    QPushButton *btnLoadGroupData;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *SerialAssistant)
    {
        if (SerialAssistant->objectName().isEmpty())
            SerialAssistant->setObjectName(QStringLiteral("SerialAssistant"));
        SerialAssistant->resize(739, 627);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialAssistant->sizePolicy().hasHeightForWidth());
        SerialAssistant->setSizePolicy(sizePolicy);
        SerialAssistant->setMinimumSize(QSize(400, 627));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/res/ico/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SerialAssistant->setWindowIcon(icon);
        SerialAssistant->setStyleSheet(QStringLiteral(""));
        actionRename = new QAction(SerialAssistant);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        gridLayout_2 = new QGridLayout(SerialAssistant);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
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
        gridLayout_6 = new QGridLayout(QGBSerialConfig);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(0);
        gridLayout_6->setVerticalSpacing(3);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
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

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 2);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon1);
        btnRefresh->setIconSize(QSize(30, 30));

        gridLayout_6->addWidget(btnRefresh, 1, 0, 1, 1);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/general/general/com_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/general/general/com_connect.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon2);
        btnOpenPort->setIconSize(QSize(30, 30));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_6->addWidget(btnOpenPort, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chkFlowCtrlDTR = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlDTR->setObjectName(QStringLiteral("chkFlowCtrlDTR"));

        horizontalLayout->addWidget(chkFlowCtrlDTR);

        chkFlowCtrlRTS = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlRTS->setObjectName(QStringLiteral("chkFlowCtrlRTS"));

        horizontalLayout->addWidget(chkFlowCtrlRTS);


        gridLayout_6->addLayout(horizontalLayout, 2, 0, 1, 2);


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
        gridLayout_7 = new QGridLayout(QGBCtrlRx);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(1);
        gridLayout_7->setVerticalSpacing(4);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        btnClear = new QPushButton(QGBCtrlRx);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/action/action/edit_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon3);
        btnClear->setIconSize(QSize(30, 30));

        gridLayout_7->addWidget(btnClear, 0, 0, 1, 1);

        btnSaveFile = new QPushButton(QGBCtrlRx);
        btnSaveFile->setObjectName(QStringLiteral("btnSaveFile"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/action/action/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveFile->setIcon(icon4);
        btnSaveFile->setIconSize(QSize(30, 30));
        btnSaveFile->setCheckable(true);

        gridLayout_7->addWidget(btnSaveFile, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        chkDisplayHex = new QCheckBox(QGBCtrlRx);
        chkDisplayHex->setObjectName(QStringLiteral("chkDisplayHex"));

        horizontalLayout_3->addWidget(chkDisplayHex);

        checkBox_5 = new QCheckBox(QGBCtrlRx);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_5);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 2);


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
        gridLayout_8 = new QGridLayout(QGBCtrlTx);
        gridLayout_8->setSpacing(2);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        btnLoadFile = new QPushButton(QGBCtrlTx);
        btnLoadFile->setObjectName(QStringLiteral("btnLoadFile"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/action/action/edit_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadFile->setIcon(icon5);
        btnLoadFile->setIconSize(QSize(30, 30));
        btnLoadFile->setCheckable(true);

        gridLayout_8->addWidget(btnLoadFile, 0, 0, 1, 1);

        btnTxFile = new QPushButton(QGBCtrlTx);
        btnTxFile->setObjectName(QStringLiteral("btnTxFile"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/action/action/mail_fwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTxFile->setIcon(icon6);
        btnTxFile->setIconSize(QSize(30, 30));
        btnTxFile->setCheckable(true);

        gridLayout_8->addWidget(btnTxFile, 0, 1, 1, 1);

        lblFileSize = new QLabel(QGBCtrlTx);
        lblFileSize->setObjectName(QStringLiteral("lblFileSize"));

        gridLayout_8->addWidget(lblFileSize, 1, 0, 1, 1);

        lblTerminator = new QLabel(QGBCtrlTx);
        lblTerminator->setObjectName(QStringLiteral("lblTerminator"));

        gridLayout_8->addWidget(lblTerminator, 2, 0, 1, 1);

        cbbTerminator = new QComboBox(QGBCtrlTx);
        cbbTerminator->setObjectName(QStringLiteral("cbbTerminator"));

        gridLayout_8->addWidget(cbbTerminator, 2, 1, 1, 1);

        cbbVerifyStyle = new QComboBox(QGBCtrlTx);
        cbbVerifyStyle->setObjectName(QStringLiteral("cbbVerifyStyle"));

        gridLayout_8->addWidget(cbbVerifyStyle, 3, 0, 1, 2);

        spbStart = new QSpinBox(QGBCtrlTx);
        spbStart->setObjectName(QStringLiteral("spbStart"));
        spbStart->setStyleSheet(QStringLiteral(""));
        spbStart->setMinimum(1);
        spbStart->setMaximum(9999999);
        spbStart->setValue(1);
        spbStart->setDisplayIntegerBase(10);

        gridLayout_8->addWidget(spbStart, 4, 0, 1, 2);

        spbEnd = new QSpinBox(QGBCtrlTx);
        spbEnd->setObjectName(QStringLiteral("spbEnd"));
        spbEnd->setStyleSheet(QStringLiteral(""));
        spbEnd->setMaximum(2048);
        spbEnd->setValue(0);
        spbEnd->setDisplayIntegerBase(10);

        gridLayout_8->addWidget(spbEnd, 5, 0, 1, 2);

        txtVerify = new QTextBrowser(QGBCtrlTx);
        txtVerify->setObjectName(QStringLiteral("txtVerify"));
        txtVerify->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtVerify->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_8->addWidget(txtVerify, 6, 0, 1, 2);

        splitter_2 = new QSplitter(QGBCtrlTx);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(0);
        splitter_2->setChildrenCollapsible(false);
        chbTxHex = new QCheckBox(splitter_2);
        chbTxHex->setObjectName(QStringLiteral("chbTxHex"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(chbTxHex->sizePolicy().hasHeightForWidth());
        chbTxHex->setSizePolicy(sizePolicy3);
        splitter_2->addWidget(chbTxHex);
        chbTimedTx = new QCheckBox(splitter_2);
        chbTimedTx->setObjectName(QStringLiteral("chbTimedTx"));
        sizePolicy3.setHeightForWidth(chbTimedTx->sizePolicy().hasHeightForWidth());
        chbTimedTx->setSizePolicy(sizePolicy3);
        splitter_2->addWidget(chbTimedTx);

        gridLayout_8->addWidget(splitter_2, 7, 0, 1, 2);

        spbTxInterval = new QSpinBox(QGBCtrlTx);
        spbTxInterval->setObjectName(QStringLiteral("spbTxInterval"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spbTxInterval->sizePolicy().hasHeightForWidth());
        spbTxInterval->setSizePolicy(sizePolicy4);
        spbTxInterval->setMinimumSize(QSize(61, 22));
        spbTxInterval->setAutoFillBackground(false);
        spbTxInterval->setMinimum(20);
        spbTxInterval->setMaximum(99999);
        spbTxInterval->setValue(50);

        gridLayout_8->addWidget(spbTxInterval, 8, 0, 1, 2);

        splitter_3 = new QSplitter(QGBCtrlTx);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setHandleWidth(0);
        splitter_3->setChildrenCollapsible(false);
        rdbGB18030 = new QRadioButton(splitter_3);
        buttonGroup = new QButtonGroup(SerialAssistant);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(rdbGB18030);
        rdbGB18030->setObjectName(QStringLiteral("rdbGB18030"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(rdbGB18030->sizePolicy().hasHeightForWidth());
        rdbGB18030->setSizePolicy(sizePolicy5);
        rdbGB18030->setChecked(true);
        splitter_3->addWidget(rdbGB18030);
        rdbUTF8 = new QRadioButton(splitter_3);
        buttonGroup->addButton(rdbUTF8);
        rdbUTF8->setObjectName(QStringLiteral("rdbUTF8"));
        sizePolicy5.setHeightForWidth(rdbUTF8->sizePolicy().hasHeightForWidth());
        rdbUTF8->setSizePolicy(sizePolicy5);
        splitter_3->addWidget(rdbUTF8);

        gridLayout_8->addWidget(splitter_3, 9, 0, 1, 2);


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

        verticalSpacer_3 = new QSpacerItem(168, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(SerialAssistant);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        textBrower = new QPlainTextEdit(splitter);
        textBrower->setObjectName(QStringLiteral("textBrower"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(60);
        sizePolicy6.setHeightForWidth(textBrower->sizePolicy().hasHeightForWidth());
        textBrower->setSizePolicy(sizePolicy6);
        textBrower->setMinimumSize(QSize(287, 200));
        splitter->addWidget(textBrower);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(1);
        sizePolicy7.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy7);
        toolBox->setMinimumSize(QSize(287, 200));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        single = new QWidget();
        single->setObjectName(QStringLiteral("single"));
        single->setGeometry(QRect(0, 0, 540, 148));
        gridLayout_4 = new QGridLayout(single);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(17, 152, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        txtSingle = new QPlainTextEdit(single);
        txtSingle->setObjectName(QStringLiteral("txtSingle"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(txtSingle->sizePolicy().hasHeightForWidth());
        txtSingle->setSizePolicy(sizePolicy8);

        gridLayout_4->addWidget(txtSingle, 0, 1, 2, 1);

        btnSend = new QPushButton(single);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        sizePolicy1.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy1);
        btnSend->setMinimumSize(QSize(71, 41));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/general/general/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSend->setIcon(icon7);
        btnSend->setIconSize(QSize(30, 30));

        gridLayout_4->addWidget(btnSend, 0, 0, 1, 1);

        toolBox->addItem(single, QString::fromUtf8("\345\215\225\346\235\241\345\217\221\351\200\201"));
        multi = new QWidget();
        multi->setObjectName(QStringLiteral("multi"));
        multi->setGeometry(QRect(0, 0, 540, 148));
        gridLayout = new QGridLayout(multi);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(multi);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 506, 422));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        chkMulti01 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti01->setObjectName(QStringLiteral("chkMulti01"));

        horizontalLayout_2->addWidget(chkMulti01);

        btnMultiPush01 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush01->setObjectName(QStringLiteral("btnMultiPush01"));

        horizontalLayout_2->addWidget(btnMultiPush01);

        txtLine01 = new QLineEdit(scrollAreaWidgetContents);
        txtLine01->setObjectName(QStringLiteral("txtLine01"));

        horizontalLayout_2->addWidget(txtLine01);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        chkMulti02 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti02->setObjectName(QStringLiteral("chkMulti02"));

        horizontalLayout_4->addWidget(chkMulti02);

        btnMultiPush02 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush02->setObjectName(QStringLiteral("btnMultiPush02"));

        horizontalLayout_4->addWidget(btnMultiPush02);

        txtLine02 = new QLineEdit(scrollAreaWidgetContents);
        txtLine02->setObjectName(QStringLiteral("txtLine02"));

        horizontalLayout_4->addWidget(txtLine02);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        chkMulti03 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti03->setObjectName(QStringLiteral("chkMulti03"));

        horizontalLayout_5->addWidget(chkMulti03);

        btnMultiPush03 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush03->setObjectName(QStringLiteral("btnMultiPush03"));

        horizontalLayout_5->addWidget(btnMultiPush03);

        txtLine03 = new QLineEdit(scrollAreaWidgetContents);
        txtLine03->setObjectName(QStringLiteral("txtLine03"));

        horizontalLayout_5->addWidget(txtLine03);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        chkMulti04 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti04->setObjectName(QStringLiteral("chkMulti04"));

        horizontalLayout_6->addWidget(chkMulti04);

        btnMultiPush04 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush04->setObjectName(QStringLiteral("btnMultiPush04"));

        horizontalLayout_6->addWidget(btnMultiPush04);

        txtLine04 = new QLineEdit(scrollAreaWidgetContents);
        txtLine04->setObjectName(QStringLiteral("txtLine04"));

        horizontalLayout_6->addWidget(txtLine04);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        chkMulti05 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti05->setObjectName(QStringLiteral("chkMulti05"));

        horizontalLayout_7->addWidget(chkMulti05);

        btnMultiPush05 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush05->setObjectName(QStringLiteral("btnMultiPush05"));

        horizontalLayout_7->addWidget(btnMultiPush05);

        txtLine05 = new QLineEdit(scrollAreaWidgetContents);
        txtLine05->setObjectName(QStringLiteral("txtLine05"));

        horizontalLayout_7->addWidget(txtLine05);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        chkMulti06 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti06->setObjectName(QStringLiteral("chkMulti06"));

        horizontalLayout_8->addWidget(chkMulti06);

        btnMultiPush06 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush06->setObjectName(QStringLiteral("btnMultiPush06"));

        horizontalLayout_8->addWidget(btnMultiPush06);

        txtLine06 = new QLineEdit(scrollAreaWidgetContents);
        txtLine06->setObjectName(QStringLiteral("txtLine06"));

        horizontalLayout_8->addWidget(txtLine06);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        chkMulti07 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti07->setObjectName(QStringLiteral("chkMulti07"));

        horizontalLayout_9->addWidget(chkMulti07);

        btnMultiPush07 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush07->setObjectName(QStringLiteral("btnMultiPush07"));

        horizontalLayout_9->addWidget(btnMultiPush07);

        txtLine07 = new QLineEdit(scrollAreaWidgetContents);
        txtLine07->setObjectName(QStringLiteral("txtLine07"));

        horizontalLayout_9->addWidget(txtLine07);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        chkMulti08 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti08->setObjectName(QStringLiteral("chkMulti08"));

        horizontalLayout_10->addWidget(chkMulti08);

        btnMultiPush08 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush08->setObjectName(QStringLiteral("btnMultiPush08"));

        horizontalLayout_10->addWidget(btnMultiPush08);

        txtLine08 = new QLineEdit(scrollAreaWidgetContents);
        txtLine08->setObjectName(QStringLiteral("txtLine08"));

        horizontalLayout_10->addWidget(txtLine08);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        chkMulti09 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti09->setObjectName(QStringLiteral("chkMulti09"));

        horizontalLayout_11->addWidget(chkMulti09);

        btnMultiPush09 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush09->setObjectName(QStringLiteral("btnMultiPush09"));

        horizontalLayout_11->addWidget(btnMultiPush09);

        txtLine09 = new QLineEdit(scrollAreaWidgetContents);
        txtLine09->setObjectName(QStringLiteral("txtLine09"));

        horizontalLayout_11->addWidget(txtLine09);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        chkMulti10 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti10->setObjectName(QStringLiteral("chkMulti10"));

        horizontalLayout_12->addWidget(chkMulti10);

        btnMultiPush10 = new QPushButton(scrollAreaWidgetContents);
        btnMultiPush10->setObjectName(QStringLiteral("btnMultiPush10"));

        horizontalLayout_12->addWidget(btnMultiPush10);

        txtLine10 = new QLineEdit(scrollAreaWidgetContents);
        txtLine10->setObjectName(QStringLiteral("txtLine10"));

        horizontalLayout_12->addWidget(txtLine10);


        verticalLayout->addLayout(horizontalLayout_12);

        btnAddNewGroup = new QPushButton(scrollAreaWidgetContents);
        btnAddNewGroup->setObjectName(QStringLiteral("btnAddNewGroup"));

        verticalLayout->addWidget(btnAddNewGroup);

        btnDelLastGroup = new QPushButton(scrollAreaWidgetContents);
        btnDelLastGroup->setObjectName(QStringLiteral("btnDelLastGroup"));

        verticalLayout->addWidget(btnDelLastGroup);

        btnSaveGroupData = new QPushButton(scrollAreaWidgetContents);
        btnSaveGroupData->setObjectName(QStringLiteral("btnSaveGroupData"));

        verticalLayout->addWidget(btnSaveGroupData);

        btnLoadGroupData = new QPushButton(scrollAreaWidgetContents);
        btnLoadGroupData->setObjectName(QStringLiteral("btnLoadGroupData"));

        verticalLayout->addWidget(btnLoadGroupData);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        toolBox->addItem(multi, QString::fromUtf8("\345\244\232\346\235\241\345\217\221\351\200\201"));
        splitter->addWidget(toolBox);

        verticalLayout_2->addWidget(splitter);

        progressBar = new QProgressBar(SerialAssistant);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setMaximumSize(QSize(16777215, 10));
        progressBar->setCursor(QCursor(Qt::ArrowCursor));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

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
        QWidget::setTabOrder(chkMulti04, txtLine04);
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
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SerialAssistant);
    } // setupUi

    void retranslateUi(QWidget *SerialAssistant)
    {
        SerialAssistant->setWindowTitle(QApplication::translate("SerialAssistant", "SerialAssistant", Q_NULLPTR));
        actionRename->setText(QApplication::translate("SerialAssistant", "\351\207\215\345\221\275\345\220\215", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("SerialAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("SerialAssistant", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("SerialAssistant", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("SerialAssistant", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("SerialAssistant", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("SerialAssistant", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("SerialAssistant", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("SerialAssistant", "\345\210\267\346\226\260", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("SerialAssistant", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        chkFlowCtrlDTR->setText(QApplication::translate("SerialAssistant", "DTR", Q_NULLPTR));
        chkFlowCtrlRTS->setText(QApplication::translate("SerialAssistant", "RTS", Q_NULLPTR));
        QGBCtrlRx->setTitle(QApplication::translate("SerialAssistant", "\346\216\245\346\224\266\346\216\247\345\210\266", Q_NULLPTR));
        btnClear->setText(QApplication::translate("SerialAssistant", "\346\270\205\347\251\272", Q_NULLPTR));
        btnSaveFile->setText(QApplication::translate("SerialAssistant", "\344\277\235\345\255\230\350\207\263\346\226\207\344\273\266", Q_NULLPTR));
        chkDisplayHex->setText(QApplication::translate("SerialAssistant", "Hex\346\230\276\347\244\272", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("SerialAssistant", "\345\212\240\346\227\266\351\227\264\346\210\263", Q_NULLPTR));
        QGBCtrlTx->setTitle(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201\346\216\247\345\210\266", Q_NULLPTR));
        btnLoadFile->setText(QApplication::translate("SerialAssistant", " Load", Q_NULLPTR));
        btnTxFile->setText(QApplication::translate("SerialAssistant", " Send", Q_NULLPTR));
        lblFileSize->setText(QApplication::translate("SerialAssistant", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        lblTerminator->setText(QApplication::translate("SerialAssistant", "\350\207\252\345\212\250\346\267\273\345\212\240", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbbVerifyStyle->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">ADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215</p><p><span style=\" font-weight:600;\">NADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215,\347\204\266\345\220\216\345\217\226\345\217\215\345\212\2401</p><p><span style=\" font-weight:600;\">XOR8:</span>\345\260\2068\344\275\215\346\225\260\346\215\256\345\274\202\346\210\226</p><p><span style=\" font-weight:600;\">CRC16_Modbus:</span>\347\224\250\344\272\216Modbus-RTU\345\215\217\350\256\256,\350\276\223\345\207\272\345\255\227\350\212\202\345\217\215\345\272\217,\344\275\216\344\275\215\345\255\227\350\212\202\345\234\250\345\211\215,\351\253\230\344\275\215\345\255\227\350\212\202\345\234\250\345\220\216</p><p><span style=\" font-weight:600;\">CRC16_XModem:</span>\345\244\232\351\241\271\345\274\2170x1021,\347\224\250\344\272\216Xmodem\345\215\217\350\256\256</p><p><span style=\" f"
                        "ont-weight:600;\">CRC32:</span>\345\244\232\351\241\271\345\274\2170x04C11DB7 IEEE 802.3\346\240\207\345\207\206</p><p><span style=\" font-weight:600;\">LRC:</span>NADD8\347\232\204\345\255\227\347\254\246\346\250\241\345\274\217,\344\270\223\347\224\250\344\272\216\345\255\227\347\254\246\345\217\221\351\200\201\346\250\241\345\274\217,\345\217\252\344\274\232\347\273\237\350\256\241\345\255\227\347\254\246\344\270\262\344\270\255HEX\346\240\274\345\274\217\347\232\204\346\225\260\346\215\256,\346\240\241\351\252\214\347\256\227\346\263\225\344\270\216NADD8\344\270\200\350\207\264,\345\276\227\345\210\260\347\232\2041\345\255\227\350\212\202\345\206\215\345\210\206\346\213\206\346\210\220\344\270\244\344\270\252ASCII\345\255\227\347\254\246(\347\224\250\344\272\216Mosbus-ASCII)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spbStart->setToolTip(QApplication::translate("SerialAssistant", "\345\214\205\345\220\253\347\254\254n\344\270\252\345\255\227\347\254\246", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbStart->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\274\200\345\247\213", Q_NULLPTR));
        spbStart->setPrefix(QApplication::translate("SerialAssistant", "\344\273\216\347\254\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbEnd->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\344\274\230\345\205\210\347\272\247\346\257\224\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>\350\246\201\344\275\216,\346\211\200\344\273\245\345\246\202\346\236\234\344\275\277\347\224\250\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>,\345\234\250<span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\346\227\266\345\200\231\351\234\200\350\246\201\350\200\203\350\231\221<span style=\" font-weight:600; text-decoration: underline;\">\347\273\223\346\235\237\347\254\246\346\211\200\345\215\240\347\224\250\347\232\204\345\255\227\350\212\202\351\225\277\345\272\246</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbEnd->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\211\215\346\217\222\345\205\245", Q_NULLPTR));
        spbEnd->setPrefix(QApplication::translate("SerialAssistant", "\345\234\250\345\200\222\346\225\260\347\254\254", Q_NULLPTR));
        chbTxHex->setText(QApplication::translate("SerialAssistant", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        chbTimedTx->setText(QApplication::translate("SerialAssistant", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbTxInterval->setToolTip(QApplication::translate("SerialAssistant", "\346\234\200\345\260\21720ms", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbTxInterval->setSuffix(QApplication::translate("SerialAssistant", " ms", Q_NULLPTR));
        spbTxInterval->setPrefix(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201\346\227\266\351\227\264\351\227\264\351\232\224 ", Q_NULLPTR));
        rdbGB18030->setText(QApplication::translate("SerialAssistant", "GB18030", Q_NULLPTR));
        rdbUTF8->setText(QApplication::translate("SerialAssistant", "UTF-8", Q_NULLPTR));
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
        chkMulti02->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti02->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush02->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush02->setText(QApplication::translate("SerialAssistant", "2", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti03->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti03->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush03->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush03->setText(QApplication::translate("SerialAssistant", "3", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti04->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti04->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush04->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush04->setText(QApplication::translate("SerialAssistant", "4", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti05->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti05->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush05->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush05->setText(QApplication::translate("SerialAssistant", "5", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti06->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti06->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush06->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush06->setText(QApplication::translate("SerialAssistant", "6", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti07->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti07->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush07->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush07->setText(QApplication::translate("SerialAssistant", "7", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti08->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti08->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush08->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush08->setText(QApplication::translate("SerialAssistant", "8", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti09->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti09->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush09->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush09->setText(QApplication::translate("SerialAssistant", "9", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        chkMulti10->setToolTip(QApplication::translate("SerialAssistant", "\345\213\276\351\200\211\350\241\250\347\244\272\345\217\257\344\273\245\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chkMulti10->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMultiPush10->setToolTip(QApplication::translate("SerialAssistant", "\347\202\271\345\207\273\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMultiPush10->setText(QApplication::translate("SerialAssistant", "10", Q_NULLPTR));
        btnAddNewGroup->setText(QApplication::translate("SerialAssistant", "+", Q_NULLPTR));
        btnDelLastGroup->setText(QApplication::translate("SerialAssistant", "-", Q_NULLPTR));
        btnSaveGroupData->setText(QApplication::translate("SerialAssistant", "Save", Q_NULLPTR));
        btnLoadGroupData->setText(QApplication::translate("SerialAssistant", "Load", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(multi), QApplication::translate("SerialAssistant", "\345\244\232\346\235\241\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialAssistant: public Ui_SerialAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALASSISTANT_H

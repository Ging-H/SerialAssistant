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
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QPlainTextEdit *textBrower;
    QToolBox *toolBox;
    QWidget *single;
    QGridLayout *gridLayout_4;
    QPushButton *btnSend;
    QPlainTextEdit *txtSingle;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *multi;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkMulti01;
    QSplitter *splitter_2;
    QPushButton *btnMultiPush01;
    QLineEdit *txtLine01;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *chkMulti02;
    QSplitter *splitter_3;
    QPushButton *btnMultiPush02;
    QLineEdit *txtLine02;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *chkMulti03;
    QSplitter *splitter_4;
    QPushButton *btnMultiPush03;
    QLineEdit *txtLine03;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chkMulti04;
    QSplitter *splitter_5;
    QPushButton *btnMultiPush04;
    QLineEdit *txtLine04;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *chkMulti05;
    QSplitter *splitter_6;
    QPushButton *btnMultiPush05;
    QLineEdit *txtLine05;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *chkMulti06;
    QSplitter *splitter_7;
    QPushButton *btnMultiPush06;
    QLineEdit *txtLine06;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *chkMulti07;
    QSplitter *splitter_8;
    QPushButton *btnMultiPush07;
    QLineEdit *txtLine07;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *chkMulti08;
    QSplitter *splitter_9;
    QPushButton *btnMultiPush08;
    QLineEdit *txtLine08;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *chkMulti09;
    QSplitter *splitter_10;
    QPushButton *btnMultiPush09;
    QLineEdit *txtLine09;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *chkMulti10;
    QSplitter *splitter_11;
    QPushButton *btnMultiPush10;
    QLineEdit *txtLine10;
    QPushButton *btnAddNewGroup;
    QPushButton *btnDelLastGroup;
    QPushButton *btnSaveGroupData;
    QPushButton *btnLoadGroupData;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_5;
    QLabel *lbltxCnt;
    QLabel *label_2;
    QLabel *lblrxCnt;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_3;
    QLabel *lblPortNum;
    QComboBox *cbbPortNum;
    QLabel *lblBaudRate;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QComboBox *cbbDataBit;
    QLabel *lblVerify;
    QComboBox *cbbVerify;
    QLabel *lblStopBit;
    QComboBox *cbbStopBit;
    QPushButton *btnRefresh;
    QPushButton *btnOpenPort;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkFlowCtrlDTR;
    QCheckBox *chkFlowCtrlRTS;
    QGroupBox *QGBCtrlRx;
    QGridLayout *gridLayout_6;
    QPushButton *btnClear;
    QPushButton *btnSaveFile;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkDisplayHex;
    QCheckBox *checkBox_5;
    QGroupBox *QGBCtrlTx;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *btnLoadFile;
    QPushButton *btnTxFile;
    QLabel *lblFileSize;
    QGridLayout *gridLayout_7;
    QSpinBox *spbEnd;
    QTextBrowser *txtVerify;
    QSpinBox *spbStart;
    QHBoxLayout *horizontalLayout_15;
    QLabel *lblTerminator;
    QComboBox *cbbTerminator;
    QComboBox *cbbVerifyStyle;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *chbTxHex;
    QCheckBox *chbTimedTx;
    QSpinBox *spbTxInterval;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *rdbGB18030;
    QRadioButton *rdbUTF8;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *SerialAssistant)
    {
        if (SerialAssistant->objectName().isEmpty())
            SerialAssistant->setObjectName(QStringLiteral("SerialAssistant"));
        SerialAssistant->resize(988, 627);
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(SerialAssistant);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        textBrower = new QPlainTextEdit(splitter);
        textBrower->setObjectName(QStringLiteral("textBrower"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(60);
        sizePolicy1.setHeightForWidth(textBrower->sizePolicy().hasHeightForWidth());
        textBrower->setSizePolicy(sizePolicy1);
        textBrower->setMinimumSize(QSize(287, 200));
        splitter->addWidget(textBrower);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy2);
        toolBox->setMinimumSize(QSize(287, 200));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        single = new QWidget();
        single->setObjectName(QStringLiteral("single"));
        single->setGeometry(QRect(0, 0, 791, 152));
        gridLayout_4 = new QGridLayout(single);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        btnSend = new QPushButton(single);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy3);
        btnSend->setMinimumSize(QSize(71, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/general/general/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnSend->setIcon(icon1);
        btnSend->setIconSize(QSize(30, 30));

        gridLayout_4->addWidget(btnSend, 0, 0, 1, 1);

        txtSingle = new QPlainTextEdit(single);
        txtSingle->setObjectName(QStringLiteral("txtSingle"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txtSingle->sizePolicy().hasHeightForWidth());
        txtSingle->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(txtSingle, 0, 1, 4, 1);

        label_4 = new QLabel(single);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setLineWidth(-1);
        label_4->setOpenExternalLinks(true);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(single);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setLineWidth(-1);
        label_3->setOpenExternalLinks(true);

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(17, 152, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 3, 0, 1, 1);

        toolBox->addItem(single, QString::fromUtf8("\345\215\225\346\235\241\345\217\221\351\200\201"));
        multi = new QWidget();
        multi->setObjectName(QStringLiteral("multi"));
        multi->setGeometry(QRect(0, 0, 791, 152));
        gridLayout = new QGridLayout(multi);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(multi);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -290, 757, 422));
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

        splitter_2 = new QSplitter(scrollAreaWidgetContents);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        btnMultiPush01 = new QPushButton(splitter_2);
        btnMultiPush01->setObjectName(QStringLiteral("btnMultiPush01"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnMultiPush01->sizePolicy().hasHeightForWidth());
        btnMultiPush01->setSizePolicy(sizePolicy5);
        splitter_2->addWidget(btnMultiPush01);
        txtLine01 = new QLineEdit(splitter_2);
        txtLine01->setObjectName(QStringLiteral("txtLine01"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(10);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(txtLine01->sizePolicy().hasHeightForWidth());
        txtLine01->setSizePolicy(sizePolicy6);
        splitter_2->addWidget(txtLine01);

        horizontalLayout_2->addWidget(splitter_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        chkMulti02 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti02->setObjectName(QStringLiteral("chkMulti02"));

        horizontalLayout_4->addWidget(chkMulti02);

        splitter_3 = new QSplitter(scrollAreaWidgetContents);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        btnMultiPush02 = new QPushButton(splitter_3);
        btnMultiPush02->setObjectName(QStringLiteral("btnMultiPush02"));
        sizePolicy5.setHeightForWidth(btnMultiPush02->sizePolicy().hasHeightForWidth());
        btnMultiPush02->setSizePolicy(sizePolicy5);
        splitter_3->addWidget(btnMultiPush02);
        txtLine02 = new QLineEdit(splitter_3);
        txtLine02->setObjectName(QStringLiteral("txtLine02"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(10);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(txtLine02->sizePolicy().hasHeightForWidth());
        txtLine02->setSizePolicy(sizePolicy7);
        splitter_3->addWidget(txtLine02);

        horizontalLayout_4->addWidget(splitter_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        chkMulti03 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti03->setObjectName(QStringLiteral("chkMulti03"));

        horizontalLayout_5->addWidget(chkMulti03);

        splitter_4 = new QSplitter(scrollAreaWidgetContents);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        btnMultiPush03 = new QPushButton(splitter_4);
        btnMultiPush03->setObjectName(QStringLiteral("btnMultiPush03"));
        splitter_4->addWidget(btnMultiPush03);
        txtLine03 = new QLineEdit(splitter_4);
        txtLine03->setObjectName(QStringLiteral("txtLine03"));
        sizePolicy7.setHeightForWidth(txtLine03->sizePolicy().hasHeightForWidth());
        txtLine03->setSizePolicy(sizePolicy7);
        splitter_4->addWidget(txtLine03);

        horizontalLayout_5->addWidget(splitter_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        chkMulti04 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti04->setObjectName(QStringLiteral("chkMulti04"));

        horizontalLayout_6->addWidget(chkMulti04);

        splitter_5 = new QSplitter(scrollAreaWidgetContents);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        btnMultiPush04 = new QPushButton(splitter_5);
        btnMultiPush04->setObjectName(QStringLiteral("btnMultiPush04"));
        splitter_5->addWidget(btnMultiPush04);
        txtLine04 = new QLineEdit(splitter_5);
        txtLine04->setObjectName(QStringLiteral("txtLine04"));
        sizePolicy7.setHeightForWidth(txtLine04->sizePolicy().hasHeightForWidth());
        txtLine04->setSizePolicy(sizePolicy7);
        splitter_5->addWidget(txtLine04);

        horizontalLayout_6->addWidget(splitter_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        chkMulti05 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti05->setObjectName(QStringLiteral("chkMulti05"));

        horizontalLayout_7->addWidget(chkMulti05);

        splitter_6 = new QSplitter(scrollAreaWidgetContents);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        btnMultiPush05 = new QPushButton(splitter_6);
        btnMultiPush05->setObjectName(QStringLiteral("btnMultiPush05"));
        splitter_6->addWidget(btnMultiPush05);
        txtLine05 = new QLineEdit(splitter_6);
        txtLine05->setObjectName(QStringLiteral("txtLine05"));
        sizePolicy7.setHeightForWidth(txtLine05->sizePolicy().hasHeightForWidth());
        txtLine05->setSizePolicy(sizePolicy7);
        splitter_6->addWidget(txtLine05);

        horizontalLayout_7->addWidget(splitter_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        chkMulti06 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti06->setObjectName(QStringLiteral("chkMulti06"));

        horizontalLayout_8->addWidget(chkMulti06);

        splitter_7 = new QSplitter(scrollAreaWidgetContents);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        btnMultiPush06 = new QPushButton(splitter_7);
        btnMultiPush06->setObjectName(QStringLiteral("btnMultiPush06"));
        splitter_7->addWidget(btnMultiPush06);
        txtLine06 = new QLineEdit(splitter_7);
        txtLine06->setObjectName(QStringLiteral("txtLine06"));
        sizePolicy7.setHeightForWidth(txtLine06->sizePolicy().hasHeightForWidth());
        txtLine06->setSizePolicy(sizePolicy7);
        splitter_7->addWidget(txtLine06);

        horizontalLayout_8->addWidget(splitter_7);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        chkMulti07 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti07->setObjectName(QStringLiteral("chkMulti07"));

        horizontalLayout_9->addWidget(chkMulti07);

        splitter_8 = new QSplitter(scrollAreaWidgetContents);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setOrientation(Qt::Horizontal);
        btnMultiPush07 = new QPushButton(splitter_8);
        btnMultiPush07->setObjectName(QStringLiteral("btnMultiPush07"));
        splitter_8->addWidget(btnMultiPush07);
        txtLine07 = new QLineEdit(splitter_8);
        txtLine07->setObjectName(QStringLiteral("txtLine07"));
        sizePolicy7.setHeightForWidth(txtLine07->sizePolicy().hasHeightForWidth());
        txtLine07->setSizePolicy(sizePolicy7);
        splitter_8->addWidget(txtLine07);

        horizontalLayout_9->addWidget(splitter_8);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        chkMulti08 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti08->setObjectName(QStringLiteral("chkMulti08"));

        horizontalLayout_10->addWidget(chkMulti08);

        splitter_9 = new QSplitter(scrollAreaWidgetContents);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Horizontal);
        btnMultiPush08 = new QPushButton(splitter_9);
        btnMultiPush08->setObjectName(QStringLiteral("btnMultiPush08"));
        splitter_9->addWidget(btnMultiPush08);
        txtLine08 = new QLineEdit(splitter_9);
        txtLine08->setObjectName(QStringLiteral("txtLine08"));
        sizePolicy7.setHeightForWidth(txtLine08->sizePolicy().hasHeightForWidth());
        txtLine08->setSizePolicy(sizePolicy7);
        splitter_9->addWidget(txtLine08);

        horizontalLayout_10->addWidget(splitter_9);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        chkMulti09 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti09->setObjectName(QStringLiteral("chkMulti09"));

        horizontalLayout_11->addWidget(chkMulti09);

        splitter_10 = new QSplitter(scrollAreaWidgetContents);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setOrientation(Qt::Horizontal);
        btnMultiPush09 = new QPushButton(splitter_10);
        btnMultiPush09->setObjectName(QStringLiteral("btnMultiPush09"));
        splitter_10->addWidget(btnMultiPush09);
        txtLine09 = new QLineEdit(splitter_10);
        txtLine09->setObjectName(QStringLiteral("txtLine09"));
        sizePolicy7.setHeightForWidth(txtLine09->sizePolicy().hasHeightForWidth());
        txtLine09->setSizePolicy(sizePolicy7);
        splitter_10->addWidget(txtLine09);

        horizontalLayout_11->addWidget(splitter_10);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        chkMulti10 = new QCheckBox(scrollAreaWidgetContents);
        chkMulti10->setObjectName(QStringLiteral("chkMulti10"));

        horizontalLayout_12->addWidget(chkMulti10);

        splitter_11 = new QSplitter(scrollAreaWidgetContents);
        splitter_11->setObjectName(QStringLiteral("splitter_11"));
        splitter_11->setOrientation(Qt::Horizontal);
        btnMultiPush10 = new QPushButton(splitter_11);
        btnMultiPush10->setObjectName(QStringLiteral("btnMultiPush10"));
        splitter_11->addWidget(btnMultiPush10);
        txtLine10 = new QLineEdit(splitter_11);
        txtLine10->setObjectName(QStringLiteral("txtLine10"));
        sizePolicy7.setHeightForWidth(txtLine10->sizePolicy().hasHeightForWidth());
        txtLine10->setSizePolicy(sizePolicy7);
        splitter_11->addWidget(txtLine10);

        horizontalLayout_12->addWidget(splitter_11);


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


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 6, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lbltxCnt = new QLabel(SerialAssistant);
        lbltxCnt->setObjectName(QStringLiteral("lbltxCnt"));
        sizePolicy3.setHeightForWidth(lbltxCnt->sizePolicy().hasHeightForWidth());
        lbltxCnt->setSizePolicy(sizePolicy3);
        lbltxCnt->setMinimumSize(QSize(0, 12));

        gridLayout_5->addWidget(lbltxCnt, 0, 3, 1, 1);

        label_2 = new QLabel(SerialAssistant);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMinimumSize(QSize(0, 12));
        label_2->setMaximumSize(QSize(16, 16777215));

        gridLayout_5->addWidget(label_2, 0, 2, 1, 1);

        lblrxCnt = new QLabel(SerialAssistant);
        lblrxCnt->setObjectName(QStringLiteral("lblrxCnt"));
        sizePolicy3.setHeightForWidth(lblrxCnt->sizePolicy().hasHeightForWidth());
        lblrxCnt->setSizePolicy(sizePolicy3);
        lblrxCnt->setMinimumSize(QSize(0, 12));

        gridLayout_5->addWidget(lblrxCnt, 0, 1, 1, 1);

        label = new QLabel(SerialAssistant);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(0, 12));
        label->setMaximumSize(QSize(16, 16777215));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(93, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 5, 0, 1, 1);

        pushButton = new QPushButton(SerialAssistant);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        QGBSerialConfig = new QGroupBox(SerialAssistant);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        sizePolicy3.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy3);
        QGBSerialConfig->setMinimumSize(QSize(171, 211));
        QGBSerialConfig->setMaximumSize(QSize(171, 211));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        gridLayout_9 = new QGridLayout(QGBSerialConfig);
        gridLayout_9->setSpacing(2);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(3, 3, 3, 3);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        gridLayout_3->setVerticalSpacing(3);
        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(lblPortNum->sizePolicy().hasHeightForWidth());
        lblPortNum->setSizePolicy(sizePolicy8);

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(3);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy9);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(3);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(cbbBaud->sizePolicy().hasHeightForWidth());
        cbbBaud->setSizePolicy(sizePolicy10);
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        sizePolicy10.setHeightForWidth(cbbDataBit->sizePolicy().hasHeightForWidth());
        cbbDataBit->setSizePolicy(sizePolicy10);
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        sizePolicy10.setHeightForWidth(cbbVerify->sizePolicy().hasHeightForWidth());
        cbbVerify->setSizePolicy(sizePolicy10);
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        sizePolicy10.setHeightForWidth(cbbStopBit->sizePolicy().hasHeightForWidth());
        cbbStopBit->setSizePolicy(sizePolicy10);
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_3, 0, 0, 1, 2);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy11);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/action/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);
        btnRefresh->setIconSize(QSize(30, 25));

        gridLayout_9->addWidget(btnRefresh, 1, 0, 1, 1);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        QSizePolicy sizePolicy12(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy12.setHorizontalStretch(5);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(btnOpenPort->sizePolicy().hasHeightForWidth());
        btnOpenPort->setSizePolicy(sizePolicy12);
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/general/general/com_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/general/general/com_connect.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon3);
        btnOpenPort->setIconSize(QSize(30, 25));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_9->addWidget(btnOpenPort, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        chkFlowCtrlDTR = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlDTR->setObjectName(QStringLiteral("chkFlowCtrlDTR"));
        QSizePolicy sizePolicy13(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy13.setHorizontalStretch(1);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(chkFlowCtrlDTR->sizePolicy().hasHeightForWidth());
        chkFlowCtrlDTR->setSizePolicy(sizePolicy13);

        horizontalLayout_3->addWidget(chkFlowCtrlDTR);

        chkFlowCtrlRTS = new QCheckBox(QGBSerialConfig);
        chkFlowCtrlRTS->setObjectName(QStringLiteral("chkFlowCtrlRTS"));
        sizePolicy13.setHeightForWidth(chkFlowCtrlRTS->sizePolicy().hasHeightForWidth());
        chkFlowCtrlRTS->setSizePolicy(sizePolicy13);

        horizontalLayout_3->addWidget(chkFlowCtrlRTS);


        gridLayout_9->addLayout(horizontalLayout_3, 2, 0, 1, 2);


        gridLayout_2->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        QGBCtrlRx = new QGroupBox(SerialAssistant);
        QGBCtrlRx->setObjectName(QStringLiteral("QGBCtrlRx"));
        sizePolicy3.setHeightForWidth(QGBCtrlRx->sizePolicy().hasHeightForWidth());
        QGBCtrlRx->setSizePolicy(sizePolicy3);
        QGBCtrlRx->setMinimumSize(QSize(171, 80));
        QGBCtrlRx->setMaximumSize(QSize(171, 80));
        QGBCtrlRx->setStyleSheet(QStringLiteral(""));
        QGBCtrlRx->setFlat(false);
        QGBCtrlRx->setCheckable(false);
        gridLayout_6 = new QGridLayout(QGBCtrlRx);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        btnClear = new QPushButton(QGBCtrlRx);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        sizePolicy13.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy13);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/action/action/edit_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon4);
        btnClear->setIconSize(QSize(30, 20));

        gridLayout_6->addWidget(btnClear, 0, 0, 1, 1);

        btnSaveFile = new QPushButton(QGBCtrlRx);
        btnSaveFile->setObjectName(QStringLiteral("btnSaveFile"));
        QSizePolicy sizePolicy14(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy14.setHorizontalStretch(3);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(btnSaveFile->sizePolicy().hasHeightForWidth());
        btnSaveFile->setSizePolicy(sizePolicy14);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/action/action/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveFile->setIcon(icon5);
        btnSaveFile->setIconSize(QSize(30, 20));
        btnSaveFile->setCheckable(true);

        gridLayout_6->addWidget(btnSaveFile, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chkDisplayHex = new QCheckBox(QGBCtrlRx);
        chkDisplayHex->setObjectName(QStringLiteral("chkDisplayHex"));
        sizePolicy13.setHeightForWidth(chkDisplayHex->sizePolicy().hasHeightForWidth());
        chkDisplayHex->setSizePolicy(sizePolicy13);

        horizontalLayout->addWidget(chkDisplayHex);

        checkBox_5 = new QCheckBox(QGBCtrlRx);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        sizePolicy13.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy13);
        checkBox_5->setChecked(true);

        horizontalLayout->addWidget(checkBox_5);


        gridLayout_6->addLayout(horizontalLayout, 1, 0, 1, 2);


        gridLayout_2->addWidget(QGBCtrlRx, 1, 0, 1, 1);

        QGBCtrlTx = new QGroupBox(SerialAssistant);
        QGBCtrlTx->setObjectName(QStringLiteral("QGBCtrlTx"));
        sizePolicy3.setHeightForWidth(QGBCtrlTx->sizePolicy().hasHeightForWidth());
        QGBCtrlTx->setSizePolicy(sizePolicy3);
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
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, -1, -1, 0);
        btnLoadFile = new QPushButton(QGBCtrlTx);
        btnLoadFile->setObjectName(QStringLiteral("btnLoadFile"));
        sizePolicy13.setHeightForWidth(btnLoadFile->sizePolicy().hasHeightForWidth());
        btnLoadFile->setSizePolicy(sizePolicy13);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/action/action/edit_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoadFile->setIcon(icon6);
        btnLoadFile->setIconSize(QSize(30, 19));
        btnLoadFile->setCheckable(true);

        horizontalLayout_16->addWidget(btnLoadFile);

        btnTxFile = new QPushButton(QGBCtrlTx);
        btnTxFile->setObjectName(QStringLiteral("btnTxFile"));
        sizePolicy13.setHeightForWidth(btnTxFile->sizePolicy().hasHeightForWidth());
        btnTxFile->setSizePolicy(sizePolicy13);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/action/action/mail_fwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTxFile->setIcon(icon7);
        btnTxFile->setIconSize(QSize(30, 19));
        btnTxFile->setCheckable(true);

        horizontalLayout_16->addWidget(btnTxFile);


        gridLayout_8->addLayout(horizontalLayout_16, 0, 0, 1, 1);

        lblFileSize = new QLabel(QGBCtrlTx);
        lblFileSize->setObjectName(QStringLiteral("lblFileSize"));

        gridLayout_8->addWidget(lblFileSize, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        spbEnd = new QSpinBox(QGBCtrlTx);
        spbEnd->setObjectName(QStringLiteral("spbEnd"));
        QSizePolicy sizePolicy15(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(spbEnd->sizePolicy().hasHeightForWidth());
        spbEnd->setSizePolicy(sizePolicy15);
        spbEnd->setStyleSheet(QStringLiteral(""));
        spbEnd->setMaximum(2048);
        spbEnd->setValue(0);
        spbEnd->setDisplayIntegerBase(10);

        gridLayout_7->addWidget(spbEnd, 3, 0, 1, 1);

        txtVerify = new QTextBrowser(QGBCtrlTx);
        txtVerify->setObjectName(QStringLiteral("txtVerify"));
        QSizePolicy sizePolicy16(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy16.setHorizontalStretch(0);
        sizePolicy16.setVerticalStretch(0);
        sizePolicy16.setHeightForWidth(txtVerify->sizePolicy().hasHeightForWidth());
        txtVerify->setSizePolicy(sizePolicy16);
        txtVerify->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtVerify->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_7->addWidget(txtVerify, 5, 0, 1, 1);

        spbStart = new QSpinBox(QGBCtrlTx);
        spbStart->setObjectName(QStringLiteral("spbStart"));
        sizePolicy15.setHeightForWidth(spbStart->sizePolicy().hasHeightForWidth());
        spbStart->setSizePolicy(sizePolicy15);
        spbStart->setStyleSheet(QStringLiteral(""));
        spbStart->setMinimum(1);
        spbStart->setMaximum(9999999);
        spbStart->setValue(1);
        spbStart->setDisplayIntegerBase(10);

        gridLayout_7->addWidget(spbStart, 2, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(3);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        lblTerminator = new QLabel(QGBCtrlTx);
        lblTerminator->setObjectName(QStringLiteral("lblTerminator"));
        sizePolicy8.setHeightForWidth(lblTerminator->sizePolicy().hasHeightForWidth());
        lblTerminator->setSizePolicy(sizePolicy8);

        horizontalLayout_15->addWidget(lblTerminator);

        cbbTerminator = new QComboBox(QGBCtrlTx);
        cbbTerminator->setObjectName(QStringLiteral("cbbTerminator"));
        QSizePolicy sizePolicy17(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy17.setHorizontalStretch(3);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(cbbTerminator->sizePolicy().hasHeightForWidth());
        cbbTerminator->setSizePolicy(sizePolicy17);

        horizontalLayout_15->addWidget(cbbTerminator);


        gridLayout_7->addLayout(horizontalLayout_15, 0, 0, 1, 1);

        cbbVerifyStyle = new QComboBox(QGBCtrlTx);
        cbbVerifyStyle->setObjectName(QStringLiteral("cbbVerifyStyle"));
        QSizePolicy sizePolicy18(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy18.setHorizontalStretch(0);
        sizePolicy18.setVerticalStretch(0);
        sizePolicy18.setHeightForWidth(cbbVerifyStyle->sizePolicy().hasHeightForWidth());
        cbbVerifyStyle->setSizePolicy(sizePolicy18);

        gridLayout_7->addWidget(cbbVerifyStyle, 4, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 2, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        chbTxHex = new QCheckBox(QGBCtrlTx);
        chbTxHex->setObjectName(QStringLiteral("chbTxHex"));
        sizePolicy11.setHeightForWidth(chbTxHex->sizePolicy().hasHeightForWidth());
        chbTxHex->setSizePolicy(sizePolicy11);

        horizontalLayout_14->addWidget(chbTxHex);

        chbTimedTx = new QCheckBox(QGBCtrlTx);
        chbTimedTx->setObjectName(QStringLiteral("chbTimedTx"));
        sizePolicy11.setHeightForWidth(chbTimedTx->sizePolicy().hasHeightForWidth());
        chbTimedTx->setSizePolicy(sizePolicy11);

        horizontalLayout_14->addWidget(chbTimedTx);


        gridLayout_8->addLayout(horizontalLayout_14, 3, 0, 1, 1);

        spbTxInterval = new QSpinBox(QGBCtrlTx);
        spbTxInterval->setObjectName(QStringLiteral("spbTxInterval"));
        QSizePolicy sizePolicy19(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy19.setHorizontalStretch(0);
        sizePolicy19.setVerticalStretch(0);
        sizePolicy19.setHeightForWidth(spbTxInterval->sizePolicy().hasHeightForWidth());
        spbTxInterval->setSizePolicy(sizePolicy19);
        spbTxInterval->setMinimumSize(QSize(61, 22));
        spbTxInterval->setAutoFillBackground(false);
        spbTxInterval->setMinimum(20);
        spbTxInterval->setMaximum(99999);
        spbTxInterval->setValue(50);

        gridLayout_8->addWidget(spbTxInterval, 4, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        rdbGB18030 = new QRadioButton(QGBCtrlTx);
        buttonGroup = new QButtonGroup(SerialAssistant);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(rdbGB18030);
        rdbGB18030->setObjectName(QStringLiteral("rdbGB18030"));
        sizePolicy11.setHeightForWidth(rdbGB18030->sizePolicy().hasHeightForWidth());
        rdbGB18030->setSizePolicy(sizePolicy11);
        rdbGB18030->setChecked(true);

        horizontalLayout_13->addWidget(rdbGB18030);

        rdbUTF8 = new QRadioButton(QGBCtrlTx);
        buttonGroup->addButton(rdbUTF8);
        rdbUTF8->setObjectName(QStringLiteral("rdbUTF8"));
        sizePolicy11.setHeightForWidth(rdbUTF8->sizePolicy().hasHeightForWidth());
        rdbUTF8->setSizePolicy(sizePolicy11);

        horizontalLayout_13->addWidget(rdbUTF8);


        gridLayout_8->addLayout(horizontalLayout_13, 5, 0, 1, 1);


        gridLayout_2->addWidget(QGBCtrlTx, 2, 0, 1, 1);

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
        QWidget::setTabOrder(cbbTerminator, spbStart);
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

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(4);
        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(SerialAssistant);
    } // setupUi

    void retranslateUi(QWidget *SerialAssistant)
    {
        SerialAssistant->setWindowTitle(QApplication::translate("SerialAssistant", "SerialAssistant", Q_NULLPTR));
        actionRename->setText(QApplication::translate("SerialAssistant", "\351\207\215\345\221\275\345\220\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnSend->setToolTip(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnSend->setText(QString());
        txtSingle->setPlainText(QApplication::translate("SerialAssistant", "\347\241\254\347\237\263\347\224\265\345\255\220 \346\220\272\346\211\213\345\220\210\344\275\234,\345\205\261\345\210\233\346\234\252\346\235\245\n"
"http://www.ing10bbs.com/\n"
"", Q_NULLPTR));
        label_4->setText(QApplication::translate("SerialAssistant", "<html>\n"
"  <head/>\n"
"    <body>\n"
"      <p>\n"
"        <a href=\"http://www.ing10bbs.com/forum.php\">\n"
"          <span style=\" font-size:10pt; text-decoration: underline;               color:#3da5ff;\">\345\274\200\346\272\220\350\265\204\346\226\231\344\270\213\350\275\275\n"
"          </span>\n"
"        </a>\n"
"      </p>\n"
"    </body>\n"
"</html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("SerialAssistant", "<html><head/><body><p><a href=\"https://shop149744403.taobao.com/\"><span style=\" font-size:10pt; text-decoration: underline; color:#3da5ff;\">\345\274\200\345\217\221\346\235\277\350\264\255\344\271\260\351\223\276\346\216\245</span></a></p></body></html>", Q_NULLPTR));
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
        lbltxCnt->setText(QApplication::translate("SerialAssistant", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialAssistant", "Tx:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lblrxCnt->setToolTip(QApplication::translate("SerialAssistant", "\350\266\205\350\277\20760000\345\260\206\344\274\232\346\270\205\347\251\272\346\216\245\346\224\266\347\274\223\345\255\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblrxCnt->setText(QApplication::translate("SerialAssistant", "0", Q_NULLPTR));
        label->setText(QApplication::translate("SerialAssistant", "Rx:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SerialAssistant", "\345\244\215\344\275\215\350\256\241\346\225\260", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("SerialAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("SerialAssistant", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("SerialAssistant", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("SerialAssistant", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("SerialAssistant", "\346\240\241\351\252\214", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("SerialAssistant", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
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
        btnLoadFile->setText(QApplication::translate("SerialAssistant", "\345\212\240\350\275\275\346\226\207\344\273\266", Q_NULLPTR));
        btnTxFile->setText(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        lblFileSize->setText(QApplication::translate("SerialAssistant", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbEnd->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\344\274\230\345\205\210\347\272\247\346\257\224\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>\350\246\201\344\275\216,\346\211\200\344\273\245\345\246\202\346\236\234\344\275\277\347\224\250\350\207\252\345\212\250\346\267\273\345\212\240<span style=\" font-weight:600;\">\347\273\223\346\235\237\347\254\246</span>,\345\234\250<span style=\" font-weight:600;\">\346\217\222\345\205\245\346\240\241\351\252\214\347\240\201</span>\347\232\204\346\227\266\345\200\231\351\234\200\350\246\201\350\200\203\350\231\221<span style=\" font-weight:600; text-decoration: underline;\">\347\273\223\346\235\237\347\254\246\346\211\200\345\215\240\347\224\250\347\232\204\345\255\227\350\212\202\351\225\277\345\272\246</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbEnd->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\211\215\346\217\222\345\205\245", Q_NULLPTR));
        spbEnd->setPrefix(QApplication::translate("SerialAssistant", "\345\234\250\345\200\222\346\225\260\347\254\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbStart->setToolTip(QApplication::translate("SerialAssistant", "\345\214\205\345\220\253\347\254\254n\344\270\252\345\255\227\347\254\246", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbStart->setSuffix(QApplication::translate("SerialAssistant", "\344\270\252\345\255\227\347\254\246\345\274\200\345\247\213", Q_NULLPTR));
        spbStart->setPrefix(QApplication::translate("SerialAssistant", "\344\273\216\347\254\254", Q_NULLPTR));
        lblTerminator->setText(QApplication::translate("SerialAssistant", "\350\207\252\345\212\250\346\267\273\345\212\240", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbbVerifyStyle->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p><span style=\" font-weight:600;\">ADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215</p><p><span style=\" font-weight:600;\">NADD8:</span>\345\260\206\346\225\260\346\215\256\347\264\257\345\212\240,\345\217\226\344\275\2168\344\275\215,\347\204\266\345\220\216\345\217\226\345\217\215\345\212\2401\357\274\2100-ADD8\357\274\211</p><p><span style=\" font-weight:600;\">XOR8:</span>\345\260\2068\344\275\215\346\225\260\346\215\256\345\274\202\346\210\226</p><p><span style=\" font-weight:600;\">CRC16_Modbus:</span>\347\224\250\344\272\216Modbus-RTU\345\215\217\350\256\256,\350\276\223\345\207\272\345\255\227\350\212\202\345\217\215\345\272\217,\344\275\216\344\275\215\345\255\227\350\212\202\345\234\250\345\211\215,\351\253\230\344\275\215\345\255\227\350\212\202\345\234\250\345\220\216</p><p><span style=\" font-weight:600;\">CRC16_CCITT:</span>\345\244\232\351\241\271\345\274\2170x1021,\345\270\270\347\224\250\347\232\204CRC\346\240\241"
                        "\351\252\214\344\271\213\344\270\200</p><p><span style=\" font-weight:600;\">CRC16_CCITT_FALSE:</span>\345\244\232\351\241\271\345\274\2170x1021,\345\270\270\347\224\250\347\232\204CRC\346\240\241\351\252\214\344\271\213\344\270\200</p><p><span style=\" font-weight:600;\">CRC16_USB:</span>\347\224\250\344\272\216USB\351\200\232\344\277\241\345\215\217\350\256\256</p><p><span style=\" font-weight:600;\">CRC32:</span>\345\244\232\351\241\271\345\274\2170x04C11DB7 IEEE 802.3\346\240\207\345\207\206</p><p><span style=\" font-weight:600;\">LRC:</span>NADD8\347\232\204\345\255\227\347\254\246\346\250\241\345\274\217,\344\270\223\347\224\250\344\272\216\345\255\227\347\254\246\345\217\221\351\200\201\346\250\241\345\274\217,\345\217\252\344\274\232\347\273\237\350\256\241\345\255\227\347\254\246\344\270\262\344\270\255HEX\346\240\274\345\274\217\347\232\204\346\225\260\346\215\256,\346\240\241\351\252\214\347\256\227\346\263\225\344\270\216NADD8\344\270\200\350\207\264,\345\276\227\345\210\260\347\232\2041\345\255\227"
                        "\350\212\202\345\206\215\345\210\206\346\213\206\346\210\220\344\270\244\344\270\252ASCII\345\255\227\347\254\246(\347\224\250\344\272\216Mosbus-ASCII)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        chbTxHex->setText(QApplication::translate("SerialAssistant", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        chbTimedTx->setText(QApplication::translate("SerialAssistant", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spbTxInterval->setToolTip(QApplication::translate("SerialAssistant", "\346\234\200\345\260\21720ms", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        spbTxInterval->setSuffix(QApplication::translate("SerialAssistant", " ms", Q_NULLPTR));
        spbTxInterval->setPrefix(QApplication::translate("SerialAssistant", "\345\217\221\351\200\201\346\227\266\351\227\264\351\227\264\351\232\224 ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rdbGB18030->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p>\351\200\211\346\213\251\344\270\255\346\226\207\347\274\226\347\240\201\357\274\214\345\217\257\351\200\211utf-8\345\222\214GB18030\357\274\214GB18030\345\205\274\345\256\271GBK\357\274\214GB2312\343\200\202window\347\263\273\347\273\237\347\232\204936\345\215\263GB2312\343\200\202</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rdbGB18030->setText(QApplication::translate("SerialAssistant", "GB18030", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rdbUTF8->setToolTip(QApplication::translate("SerialAssistant", "<html><head/><body><p>\351\200\211\346\213\251\344\270\255\346\226\207\347\274\226\347\240\201\357\274\214\345\217\257\351\200\211utf-8\345\222\214GB18030\357\274\214GB18030\345\205\274\345\256\271GBK\357\274\214GB2312\343\200\202window\347\263\273\347\273\237\347\232\204936\345\215\263GB2312\343\200\202</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rdbUTF8->setText(QApplication::translate("SerialAssistant", "UTF-8", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialAssistant: public Ui_SerialAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALASSISTANT_H

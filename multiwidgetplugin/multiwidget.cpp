#include "multiwidget.h"
#include "ui_multiwidget.h"
#include <QMenu>
#include <QTextCodec>
#include <QFileDialog>
#include <QSettings>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

/* MSVC编译器编译中文会出现乱码 */
#if _MSC_VER >=1600 // VS2010版本号是1600
#pragma execution_character_set("utf-8")
#endif

MultiWidget::MultiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiWidget)
{
    ui->setupUi(this);
    initGroupList();

    connect(ui->pushButton_3, &QPushButton::clicked,
            this, &MultiWidget::addGroup  );

    connect(ui->pushButton_4, &QPushButton::clicked,
            this, &MultiWidget::subGroup );

    connect(ui->btnSave, &QPushButton::clicked,
            this, &MultiWidget::saveClicked);

//    connect(ui->btnLoad, &QPushButton::clicked,
//            [this](){
//        emit this->loadClicked(  );
//    }
//            );

    connect(ui->ckbSelectAll, &QPushButton::toggled,
            this, &MultiWidget::seleactAll);

}

MultiWidget::~MultiWidget()
{
    delete ui;
}

/**
 * @brief MultiWidget::addWidgetGroup 添加WidgetGroup
 *  层级关系:   ScrollArea->scrollAreaWidgetContents->layout->widget1(group)
 *                                                         ->widget2(group)
 *                                                         ->widget3(group)
 *
 *             widge1->layout->widget1(ckb)
 *                           ->widget1(btn)
 *                           ->widget1(txt)
 */
void MultiWidget::addWidgetGroup()
{
    /* 删除最后的Spacer */
    QVBoxLayout *scrollLayout = (QVBoxLayout*)ui->scrollAreaWidgetContents->layout();
    QLayoutItem *item = scrollLayout->takeAt(scrollLayout->count()-1);

    if( item != NULL){
        delete item->widget();
        delete item;
    }

    /* 创建三个控件 */
    QLabel      *lbl = new QLabel();
    QCheckBox   *ckb = new QCheckBox();
    QComboBox   *cbb = new QComboBox();
    QPushButton *btn = new QPushButton();
    QLineEdit   *txt = new QLineEdit();

    /* 绑定为Group */
    QHBoxLayout *GroupLayout = new QHBoxLayout();
    GroupLayout->addWidget( lbl );
    GroupLayout->addWidget( ckb );
    GroupLayout->addWidget( cbb );
    GroupLayout->addWidget( btn );
    GroupLayout->addWidget( txt );
    GroupLayout->setContentsMargins(0,0,0,0);
    GroupLayout->setSpacing(6);

    /* 添加到widget */
    QWidget *group = new QWidget();
    group->setLayout( GroupLayout );

    /* 将WidgetGroup添加到ScrollArea */
    scrollLayout->addWidget( group );
    scrollLayout->addStretch();
    m_count++;


    /* 设置btn参数 */
    btn->setText(QString::number(m_count));
    btn->setContextMenuPolicy(Qt::CustomContextMenu); // 右击触发请求菜单事件
    connect( btn, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slots_showBtnRightClickMenu(const QPoint &)));

    QVariant var_arg( m_count );
    btn->setProperty("index", var_arg);
    connect( btn,  &QPushButton::clicked,
             [=](){ emit btnClicked( btn->property("index").toInt() ); }
            );

    /* 设置cbb参数 */
    cbb->setEditable( true );

    /* 设置lbl参数 */
    lbl->setText( QString::number(m_count)) ;

    /* 是否需要隐藏  */
    btn->setVisible(isPushButtonVisable());
    cbb->setVisible(isComboboxVisable());
    ckb->setVisible(isCheckBoxVisable());
    txt->setVisible(isLineEditVisable());

    /* 将控件添加到List中以供调用 */
    WidgetGroup *tmpGroup = new WidgetGroup();
    tmpGroup->ckb = ckb;
    tmpGroup->cbb = cbb;
    tmpGroup->btn = btn;
    tmpGroup->txt = txt;
    m_groupList->append( tmpGroup );
}

/**
 * @brief MultiWidget::subWidgetGroup 删除WidgetGroup
 */
void MultiWidget::subWidgetGroup()
{
    if( m_count <= 0 )
        return ;
    /* 删除一个WidgetGroup */
    QVBoxLayout *scrollLayout = (QVBoxLayout*)ui->scrollAreaWidgetContents->layout();
    QLayoutItem *item = scrollLayout->takeAt(scrollLayout->count()-2);

    if( item != NULL){
        delete item->widget();
        delete item;
        m_count--;
        m_groupList->removeLast();
    }
}
/**
 * @brief MultiWidget::appendGroup 添加WidgetGroup
 */
void MultiWidget::initGroupList()
{
    addWidgetGroup();
    addWidgetGroup();
}
/**
 * @brief MultiWidget::on_pushButton_3_clicked 新增一组控件
 */
void MultiWidget::on_pushButton_3_clicked()
{
    addWidgetGroup();
}
/**
 * @brief MultiWidget::on_pushButton_4_clicked 减少一组控件
 */
void MultiWidget::on_pushButton_4_clicked()
{
    subWidgetGroup();
}
/**
 * @brief MultiWidget::clear 删除所有控件组
 */
void MultiWidget::clear()
{
    while( m_count ){
        subWidgetGroup();
    }
}
/**
 * @brief MultiWidget::on_ckbSelectAll_toggled 全选或者取消全选
 * @param checked
 */
void MultiWidget::on_ckbSelectAll_toggled(bool checked)
{
    for( qint32 i=0; i<m_groupList->size(); i++ ){
        m_groupList->at(i)->ckb->setChecked(checked);
    }
}
/**
 * @brief MultiWidget::slots_showBtnRightClickMenu 右击弹出菜单
 * @param pos
 */
void MultiWidget::slots_showBtnRightClickMenu(const QPoint &pos)
{
    Q_UNUSED(pos)
    /* 记录右击的按钮 */
    QPushButton *btn = qobject_cast< QPushButton *>( sender() );
    QVariant var;
    var.setValue(btn);
    ui->actionRename->setData( var );

    /* 在鼠标位置弹出菜单 */
    QMenu *btnMenu = new QMenu();
    btnMenu->addAction(ui->actionRename);
    btnMenu->exec(QCursor::pos());
}

/**
 * @brief MultiWidget::on_actionRename_triggered 重命名动作触发
 */
void MultiWidget::on_actionRename_triggered()
{
    /* 获取点击菜单的按钮指针 */
    QVariant var;
    var = ui->actionRename->data();
    QPushButton* btn = var.value<QPushButton*>();

    QLineEdit *nameEdit = new QLineEdit();
    nameEdit->setParent(btn);
    nameEdit->setText( btn->text() );
    nameEdit->resize( btn->size() );
    nameEdit->setContextMenuPolicy(Qt::NoContextMenu);// 不禁止右击事件会导致崩溃
    nameEdit->show();
    nameEdit->setFocus();
    nameEdit->selectAll();
    nameEdit->installEventFilter(this);

    /* 利用action记录当前创建的控件地址 */
    nameEdit->setObjectName("Rename");
    var.setValue(nameEdit);
    ui->actionRename->setData( var );

    connect(nameEdit, SIGNAL(returnPressed()),this,SLOT(slots_returnPressed()));
    /* 禁用右键,防止重复右击 */
    disconnect(btn, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slots_showBtnRightClickMenu(const QPoint &)));
}

/**
 * @brief MultiWidget::eventFilter 事件过滤器,focus out
 * @param watched
 * @param event
 * @return
 */
bool MultiWidget::eventFilter(QObject *watched, QEvent *event)
{
    QLineEdit *txt = qobject_cast<QLineEdit*>(watched);
    if( event->type() == QEvent::FocusOut){
        QString text = txt->text();
        QPushButton* btn = (QPushButton*)txt->parentWidget();
        btn->setText( text );
        txt->deleteLater();

        quint32 i = 1;
        foreach( WidgetGroup *tmp, *m_groupList ){
            if(tmp->btn == btn){
                QString shorcut = "Shift+%1";
                btn->setShortcut( QKeySequence(shorcut.arg(i)));
            }
            i++;
        }

        /* 重新使能右击 */
        connect(btn, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slots_showBtnRightClickMenu(const QPoint &)));
    }
    return false;
}
/**
 * @brief slots_returnPressed  按下回车
 */
void MultiWidget::slots_returnPressed()
{
    QLineEdit *txt = qobject_cast< QLineEdit *>(sender());
    if( txt ){
        this->setFocus();
    }
}

/**
 * @brief MultiWidget::on_btnSave_clicked 保存按钮
 */
void MultiWidget::on_btnSave_clicked()
{
    emit saveClicked();
    QString filePath = QFileDialog::getSaveFileName(nullptr, tr("Save"), QString(), "*.ini", nullptr);
    this->saveData(filePath);
}
/**
 * @brief MultiWidget::on_btnLoad_clicked 加载按钮
 */
void MultiWidget::on_btnLoad_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr,QString(),QString(),"*.ini",nullptr);
    this->loadData(filePath);
}
/**
 * @brief MultiWidget::saveData 保存数据,可用于关闭应用自动保存
 * @param filePath
 */
void MultiWidget::saveData(QString filePath)
{
    if( filePath != NULL ){
        qint32 count = m_groupList->count();
        if( count != 0 ){
            QSettings iniFile(filePath, QSettings::IniFormat);
            iniFile.clear();
            iniFile.beginWriteArray("widgetGroup");
            for(qint32 i=0; i<count; i++){
                iniFile.setArrayIndex(i);
                iniFile.setValue("ckb", m_groupList->at(i)->ckb->checkState());
                iniFile.setValue("btn", m_groupList->at(i)->btn->text());
                iniFile.setValue("txt", m_groupList->at(i)->txt->text());
            }
            iniFile.endArray();
        }
    }
}
/**
 * @brief MultiWidget::loadData 加载数据,可用于开启应用的时候自动加载
 * @param filePath
 */
void MultiWidget::loadData(QString filePath)
{
    if(filePath != NULL){
        QSettings iniFile(filePath, QSettings::IniFormat);
        iniFile.beginReadArray("widgetGroup");
        qint32 count = iniFile.value("size").toInt();
        this->clear();
        for(qint32 i=0; i<count; i++){
            iniFile.setArrayIndex(i);
            addWidgetGroup();
            bool checked   = iniFile.value("ckb").toBool();
            QString btnTxt = iniFile.value("btn").toString();
            QString txt    = iniFile.value("txt").toString();
            m_groupList->at(i)->ckb->setChecked(checked);
            m_groupList->at(i)->btn->setText(btnTxt);
            m_groupList->at(i)->txt->setText(txt);
        }
        iniFile.endArray();
        emit loadPath( filePath );
    }
}
/**
 * @brief setGroup 设定控件组的数量
 * @param count
 */
void MultiWidget::setGroup(qint32 count)
{
    if( count < 0 )
        return;
    if(m_count == count)
        return;
    else{
        while( m_count < count ){
            addWidgetGroup();
        }
        while( m_count > count ){
            subWidgetGroup();
        }
    }
}
/**
 * @brief MultiWidget::setCheckBoxVisable 隐藏ckb
 */
void MultiWidget::setCheckBoxVisable(bool checked)
{
    foreach (WidgetGroup *wid,  *m_groupList)
        wid->ckb->setVisible(checked);
    m_ckbvisable = checked;
}

void MultiWidget::setLineEditVisable(bool checked)
{
    foreach (WidgetGroup *wid,  *m_groupList)
        wid->txt->setVisible(checked);
    m_txtvisable = checked;
}


void MultiWidget::setPushButtonVisable(bool checked)
{
    foreach (WidgetGroup *wid,  *m_groupList)
        wid->btn->setVisible(checked);
    m_btnvisable = checked;
}

void MultiWidget::setComboboxVisable(bool checked)
{
    foreach (WidgetGroup *wid,  *m_groupList)
        wid->cbb->setVisible(checked);
    m_cbbvisable = checked;
}

void MultiWidget::setHideWid(bool wid)
{
    ui->btnLoad->setVisible(wid);
    ui->btnSave->setVisible(wid);
    ui->ckbSelectAll->setVisible(wid);
    ui->pushButton_3->setVisible(wid);
    ui->pushButton_4->setVisible(wid);
    m_widgetHide = wid;
}
/**
 * @brief findButton
 * @param btn
 * @return
 */
int MultiWidget::findButton(QPushButton *btn)
{
    foreach (WidgetGroup *wid, *m_groupList) {
        if( wid->btn == btn ){
            return m_groupList->indexOf(wid);
        }
    }
    return -1; // error
}
/**
 * @brief findCheckBox
 * @param ckb
 * @return
 */
int MultiWidget::findCheckBox(QCheckBox *ckb)
{
    foreach (WidgetGroup *wid, *m_groupList) {
        if( wid->ckb == ckb ){
            return m_groupList->indexOf(wid);
        }
    }
    return -1; // error
}
/**
 * @brief findLineEdit
 * @param txt
 * @return
 */
int MultiWidget::findLineEdit(QLineEdit *txt)
{
    foreach (WidgetGroup *wid, *m_groupList) {
        if( wid->txt == txt ){
            return m_groupList->indexOf(wid);
        }
    }
    return -1; // error
}
int MultiWidget::findComboBox(QComboBox *cbb)
{
    foreach (WidgetGroup *wid, *m_groupList) {
        if( wid->cbb == cbb ){
            return m_groupList->indexOf(wid);
        }
    }
    return -1; // error
}

/**
 * @brief MultiWidget::retranslateUi
 */
void MultiWidget::retranslateUi()
{
    ui->retranslateUi(this);
}

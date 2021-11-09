#ifndef MULTIWIDGET_H
#define MULTIWIDGET_H

#include <QWidget>
#include <QDesignerExportWidget>



namespace Ui {
class MultiWidget;
}
class QCheckBox;
class QPushButton;
class QLineEdit;
class QComboBox;
class QLabel;

class QDESIGNER_WIDGET_EXPORT MultiWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(qint32 groupCount    READ count WRITE setGroup)
    Q_PROPERTY(bool    checkBoxVisable READ isCheckBoxVisable WRITE setCheckBoxVisable)
    Q_PROPERTY(bool    pushbuttonVisable READ isPushButtonVisable WRITE setPushButtonVisable)
    Q_PROPERTY(bool    comboboxVisable READ isComboboxVisable WRITE setComboboxVisable)
    Q_PROPERTY(bool    lineeditVisable READ isLineEditVisable WRITE setLineEditVisable)
    Q_PROPERTY(bool    hideWid READ isHideWid WRITE setHideWid)

public:
    explicit MultiWidget(QWidget *parent = 0);
    ~MultiWidget();

    struct WidgetGroup {
        QLabel       *lbl;
        QCheckBox    *ckb;
        QComboBox    *cbb;
        QPushButton  *btn;
        QLineEdit    *txt;
    };

    qint32 count() const {return m_count;}
    void setGroup(qint32 count);

    bool isCheckBoxVisable() {return m_ckbvisable;}
    void setCheckBoxVisable(bool);

    bool isPushButtonVisable() {return m_btnvisable;}
    void setPushButtonVisable(bool);

    bool isComboboxVisable() {return m_cbbvisable;}
    void setComboboxVisable(bool);

    bool isLineEditVisable() {return m_txtvisable;}
    void setLineEditVisable(bool);

    bool isHideWid() {return m_widgetHide;}
    void setHideWid(bool);

    QList<WidgetGroup*> *groupList() const { return m_groupList; }
    WidgetGroup* groupAt(qint32 index){
        if(index>=0){
            return m_groupList->at(index);
        }else{
            return NULL;
        }
    }
    int findButton(QPushButton *btn);
    int findCheckBox(QCheckBox *ckb);
    int findLineEdit(QLineEdit *txt);
    int findComboBox(QComboBox *cbb);

    void addWidgetGroup();
    void subWidgetGroup();

    void clear();

    /* 可用于自动保存和加载数据 */
    void saveData(QString filePath); // "D:/123.ini"
    void loadData(QString filePath); // "D:/123.ini"

    void retranslateUi();

signals:
    void addGroup();
    void subGroup();
    void btnClicked(qint32 index);
    void saveClicked();
    void loadPath(QString path);
    void seleactAll(bool checked);

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_ckbSelectAll_toggled(bool checked);

    void on_actionRename_triggered();

    void slots_showBtnRightClickMenu(const QPoint &pos);

    bool eventFilter(QObject *, QEvent *event);

    void on_btnSave_clicked();

    void on_btnLoad_clicked();

    void slots_returnPressed();

private:
    Ui::MultiWidget *ui;
    qint32 m_count = 0;
    bool m_ckbvisable = true;
    bool m_txtvisable = true;
    bool m_btnvisable = true;
    bool m_cbbvisable = true;
    bool m_widgetHide = false;

    QList<WidgetGroup*> *m_groupList = new QList<WidgetGroup*>;
    void initGroupList();
};

#endif // MULTIWIDGET_H


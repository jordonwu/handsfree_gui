#ifndef BUTTON_LISTWIDGETITEM_H
#define BUTTON_LISTWIDGETITEM_H

#include <QWidget>

namespace Ui {
class ButtonListWidgetItem;
}

class ButtonListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonListWidgetItem(QWidget *parent = 0);
    explicit ButtonListWidgetItem(const QString &text ,const QString &icon = NULL, QWidget *parent = 0) ;
    ~ButtonListWidgetItem();
    void enable_changeText(bool enable){
        this->_enable_change_text = enable ;
    }
    void set_LabelText(const QString &text) ;
    void enable_AddButton(bool need) ;
    void enable_DelButton(bool need) ;
    void enable_EditButton(bool need) ;
signals:
    void addButtonClicked() ;
    void delButtonClicked(ButtonListWidgetItem *me) ;
    void editButtonClicked() ;
protected:
    void enterEvent(QEvent *e) ;
    void leaveEvent(QEvent *e) ;
private slots:
    void on_pushbutton_add_clicked(){emit addButtonClicked();}
    void on_pushbutton_del_clicked(){emit delButtonClicked(this);}
    void on_pushbutton_edit_clicked() ;
private:
    void init_SignalSlot() ;
    void hideAllButton() ;

private:
    Ui::ButtonListWidgetItem *ui;

    bool _enable_change_text ;
    bool _enable_add_button ;
    bool _enable_del_button ;
    bool _enable_edit_button ;
};

#endif // BUTTON_LISTWIDGETITEM_H

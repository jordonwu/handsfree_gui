#ifndef SERIAL_WIDGET_H
#define SERIAL_WIDGET_H

#include <QWidget>
class ThreadRead ;
namespace Ui {
class SerialWidget;
}
class SlidingMoudle ;
class QListWidgetItem ;
class SerialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialWidget(QWidget *parent = 0);
    ~SerialWidget();
    void startRobot() ;
private slots:
    void on_pushbutton_list_clicked() ;
    void on_pushbutton_start_clicked() ;
    void on_pushbutton_stop_clicked() ;
private:
    void init_SignalSlot() ;
    void init_Widgets() ;
    QListWidgetItem* push_NewListItem(const QString &item_text ,
                                    const QString &icon_name = NULL) ;
private:
    Ui::SerialWidget *ui;

    QString _current_opened_usb ;
    SlidingMoudle *_sliding_moudle ;
    QListWidgetItem *_list_item_open ;
    QListWidgetItem *_list_item_close ;
    QListWidgetItem *_list_item_set_protocal ;
    QListWidgetItem *_list_item_set_customize ;

    ThreadRead *_thread_serial ;
};

#endif // SERIAL_WIDGET_H

#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H
#include <QWidget>
#include <QStack>
#include <QDebug>
namespace Ui {
class MainWidget;
}

class SlidingMoudle ;
class InformationWidget ;
class ControlWidget ;
class AboutWidget ;
class SerialWidget ;
class ParamWidget ;
class VisualizationWidget ;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
protected:
    void keyPressEvent(QKeyEvent *e) ;
    void keyReleaseEvent(QKeyEvent *e) ;
private slots:
    void on_pushbutton_control_clicked() ;
    void on_pushbutton_about_click() ;
    void on_pushbutton_back_click() ;
    void on_pushbutton_foward_click() ;
    void on_sliding_widget_done() ;
private:
    void init_Widgets() ;
    void init_PushButton() ;
    void init_SignalSlot() ;

private:
    Ui::MainWidget *ui;

    ControlWidget *_widget_control ;
    AboutWidget *_widget_about ;
    SerialWidget *_widget_serial ;
    ParamWidget *_widget_param ;
    VisualizationWidget *_widget_visualization ;
    InformationWidget *_widget_information ;

    QStack<QWidget *> *_stack_widget_back ;
    QStack<QWidget *> *_stack_widget_foward ;

    SlidingMoudle *_slide_moudle ;
    QWidget *_widget_current_slide ;
    QWidget *_widget_target_slide;
};

#endif // MAIN_WIDGET_H

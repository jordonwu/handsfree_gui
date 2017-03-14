#include "main_widget/main_widget.h"
#include "util/sliding/sliding_moudle.h"

#include "control_widget/control_widget.h"
#include "about_widget/about_widget.h"
#include "serial_widget/serial_widget.h"
#include "param_widget/param_widget.h"
#include "visualization_widget/visualization_widget.h"
#include "information_widget/information_widget.h"

#include <QDebug>
#include "ui_main_widget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->init_PushButton();
    this->init_Widgets();
    this->init_SignalSlot();
}

MainWidget::~MainWidget()
{
    delete ui;
    delete _slide_moudle ;
    delete _stack_widget_back ;
    delete _stack_widget_foward ;
}

void MainWidget::keyPressEvent(QKeyEvent *e)
{
    if(this->_widget_current_slide==this->_widget_control){
        this->_widget_control->keyPressEvent(e);
    }
}

void MainWidget::keyReleaseEvent(QKeyEvent *e)
{
    if(this->_widget_current_slide==this->_widget_control){
        this->_widget_control->keyReleaseEvent(e);
    }
}

void MainWidget::on_pushbutton_control_clicked()
{
    this->_widget_target_slide = this->_widget_control ;
    this->_widget_current_slide = ui->widget_pushbutton ;
    this->_slide_moudle->slideComponent(this->_widget_current_slide,
                                                        this->_widget_target_slide,
                                                        RIGHT2LEFT);
    this->_stack_widget_back->append(this->_widget_current_slide);
}

void MainWidget::on_pushbutton_about_click()
{
    this->_widget_target_slide = this->_widget_about ;
    this->_widget_current_slide = ui->widget_pushbutton ;
    this->_slide_moudle->slideComponent(this->_widget_current_slide,
                                        this->_widget_target_slide,
                                        RIGHT2LEFT);

    this->_stack_widget_back->append(this->_widget_current_slide);
}

void MainWidget::on_pushbutton_back_click()
{
    this->_widget_target_slide = this->_stack_widget_back->pop() ;
    if(this->_stack_widget_back->empty())ui->pushButton_back->setEnabled(false);
    this->_stack_widget_foward->push(this->_widget_current_slide);
    this->_slide_moudle->slideComponent(this->_widget_current_slide,
                                        this->_widget_target_slide,
                                        LEFT2RIGHT);
}

void MainWidget::on_pushbutton_foward_click()
{
    this->_widget_target_slide = this->_stack_widget_foward->pop() ;
    if(this->_stack_widget_foward->empty())ui->pushButton_foward->setEnabled(false);
    this->_stack_widget_back->push(this->_widget_current_slide);
    this->_slide_moudle->slideComponent(this->_widget_current_slide,
                                        this->_widget_target_slide,
                                        RIGHT2LEFT);
}

void MainWidget::on_sliding_widget_done()
{
    this->_widget_current_slide = this->_widget_target_slide ;
    if(!this->_stack_widget_back->empty())ui->pushButton_back->setEnabled(true);
    if(!this->_stack_widget_foward->empty())ui->pushButton_foward->setEnabled(true);
}

void MainWidget::init_Widgets()
{
    this->_stack_widget_back = new QStack<QWidget *>() ;
    this->_stack_widget_foward = new QStack<QWidget *>() ;

    this->_slide_moudle = new SlidingMoudle() ;
    this->_slide_moudle->setDuration(500);
    this->_slide_moudle->setContainerSize(this->size());

    this->_widget_about = new AboutWidget(this) ;
    this->_widget_about->hide();
    this->_widget_control = new ControlWidget(this) ;
    this->_widget_control->hide();

    this->_widget_serial = new SerialWidget() ;
    this->_widget_param = new ParamWidget() ;
    this->_widget_visualization = new VisualizationWidget() ;
    this->_widget_information = new InformationWidget() ;
}

void MainWidget::init_PushButton()
{
    ui->pushButton_back->setEnabled(false);
    ui->pushButton_foward->setEnabled(false);

    ui->pushButton_about->setImageLabelIcon(QString(":/main_page/main_image/github.png"));
    ui->pushButton_about->setTitleText(QString(tr("About Us")));
    ui->pushButton_about->setIntroduceText(QString(tr("learn more about"
                                                      "HandsFree and nwpu"
                                                      "dancing robot!")));



    ui->pushButton_network->setImageLabelIcon(QString(":/main_page/main_image/network.png"));
    ui->pushButton_network->setTitleText(QString(tr("Network Debug")));
    ui->pushButton_network->setIntroduceText(QString(tr("connect the micro "
                                                        "computer via network,"
                                                        "then all the message will"
                                                        "be sended by TCP/IP")));

    ui->pushButton_plot->setImageLabelIcon(QString(":/main_page/main_image/plot.png"));
    ui->pushButton_plot->setTitleText(QString(tr("Visualization")));
    ui->pushButton_plot->setIntroduceText(QString(tr("show some data "
                                                     "in the coordinate "
                                                     "graph,and you can"
                                                     "choose the x-axis "
                                                     "type , y-axis "
                                                     "type, and the scale")));

    ui->pushButton_protocal->setImageLabelIcon(QString(":/main_page/main_image/protocal.png"));
    ui->pushButton_protocal->setTitleText(QString(tr("Protocal")));
    ui->pushButton_protocal->setIntroduceText(QString(tr("DIY some protocal"
                                                         "by yourself and "
                                                         "save them")));

    ui->pushButton_serial->setImageLabelIcon(QString(":/main_page/main_image/serial.png"));
    ui->pushButton_serial->setTitleText(QString(tr("Serial Debug")));
    ui->pushButton_serial->setIntroduceText(QString(tr("connect the micro"
                                                       "computer via serial,"
                                                       "then all message will"
                                                       "be sended by serial")));


    ui->pushButton_setting->setImageLabelIcon(QString(":/main_page/main_image/setting.png"));
    ui->pushButton_setting->setTitleText(QString(tr("Parameter")));
    ui->pushButton_setting->setIntroduceText(QString(tr("reset some "
                                                        "parameter of micro"
                                                        "computer")));

    ui->pushButton_state->setImageLabelIcon(QString(":/main_page/main_image/information.png"));
    ui->pushButton_state->setTitleText(QString(tr("Information")));
    ui->pushButton_state->setIntroduceText(QString(tr("display some "
                                                      "information from"
                                                      "micro computer")));

    ui->pushButton_control->setImageLabelIcon(QString(":/main_page/main_image/control.png"));
    ui->pushButton_control->setTitleText(QString(tr("Control")));
    ui->pushButton_control->setIntroduceText(QString(tr("use your DIY-protocal"
                                                     "and keyborad to control"
                                                     "your robot!")));
}

void MainWidget::init_SignalSlot()
{
    connect(ui->pushButton_setting,SIGNAL(clicked(bool)),
            this->_widget_param , SLOT(show()));

    connect(ui->pushButton_serial,SIGNAL(clicked(bool)),
            this->_widget_serial,SLOT(show())) ;

    connect(ui->pushButton_plot,SIGNAL(clicked(bool)),
            this->_widget_visualization,SLOT(show())) ;

    connect(ui->pushButton_state,SIGNAL(clicked(bool)),
            this->_widget_information,SLOT(show())) ;

    connect(ui->pushButton_about,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_about_click())) ;

    connect(ui->pushButton_control,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_control_clicked())) ;

    connect(ui->pushButton_back,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_back_click())) ;

    connect(ui->pushButton_foward,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_foward_click())) ;



    connect(this->_slide_moudle,SIGNAL(moveFinished()),
            this,SLOT(on_sliding_widget_done())) ;
}

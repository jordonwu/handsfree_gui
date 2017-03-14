#include "serial_widget/serial_widget.h"
#include "util/sliding/sliding_moudle.h"
#include "ui_serial_widget.h"
#include "robot/read_thread.h"
#include <QPropertyAnimation>
#include <robot/robot_hardware.h>
#include <QListWidgetItem>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include "robot/robot_hardware.h"
SerialWidget::SerialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialWidget)
{
    ui->setupUi(this);
    this->_thread_serial = RobotHardware::getReadThread() ;
    this->init_Widgets();
    this->init_SignalSlot();
}

SerialWidget::~SerialWidget()
{
    delete ui;
    delete _list_item_close ;
    delete _list_item_open ;
    delete _list_item_set_customize ;
    delete _list_item_set_protocal ;
}

void SerialWidget::startRobot()
{

    QString usb_name = ui->comboBox_port_name->currentText() ;
    if(usb_name.isEmpty())return ;
    QRegExp linux_reg("^ttyUSB\\d\\d?$") ; //for linux usb
    QRegExp windows_reg("^com\\d\\d?$") ; //for windows usb
    QString target_serial_name = "serial://";
    if(linux_reg.exactMatch(usb_name)){
        target_serial_name += "/dev/"+usb_name ;
    }
    else if(windows_reg.exactMatch(usb_name)){
        target_serial_name += usb_name ;
    }
    //not be initialized
    if(false==RobotHardware::isRobotOpened()){
<<<<<<< HEAD
        RobotHardware::launchRobot(target_serial_name.toStdString()) ;
    }
    else{
=======
        qDebug()<<"hi" ;
        RobotHardware::launchRobot(target_serial_name.toStdString()) ;
    }
    else{
        qDebug()<<"not NULL" ;
>>>>>>> d60962d2de6b646d5237592c98a4d25838e6b546
        //close the robot first
        RobotHardware::closeRobot(); ;
        RobotHardware::launchRobot(target_serial_name.toStdString()) ;
    }
}

void SerialWidget::init_SignalSlot()
{
    connect(ui->pushButton_list,SIGNAL(clicked(bool)),
                this,SLOT(on_pushbutton_list_clicked())) ;

    connect(ui->pushButton_start,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_start_clicked())) ;
    connect(ui->pushButton_stop,SIGNAL(clicked(bool)),
            this, SLOT(on_pushbutton_stop_clicked())) ;
}

void SerialWidget::init_Widgets()
{
    this->_sliding_moudle = new SlidingMoudle() ;

    /*-------------------------init list widget item-------------------------------*/
    //the sort is very import
    this->_list_item_open = this->push_NewListItem(QString(tr("Open")),QString(":/serial_widget/serial_widget_image/start_serial.png")) ;
    this->_list_item_close = this->push_NewListItem(QString(tr("Close")),QString(":/serial_widget/serial_widget_image/close_serial.png")) ;
    this->_list_item_set_customize = this->push_NewListItem(QString(tr("Customize")),QString(":/serial_widget/serial_widget_image/use_costumize.png")) ;
    this->_list_item_set_protocal = this->push_NewListItem(QString(tr("protocal")),QString(":/serial_widget/serial_widget_image/use_protocal.png")) ;
    /*------------------------------init over-----------------------------------------*/

}

QListWidgetItem* SerialWidget::push_NewListItem(const QString &item_text, const QString &icon_name)
{
        QListWidgetItem *new_item = new QListWidgetItem(QIcon(icon_name),item_text,ui->listWidget_right) ;
        new_item->setSizeHint(QSize(80,60));
        new_item->setTextAlignment(Qt::AlignVCenter);
        return new_item ;
}

void SerialWidget::on_pushbutton_list_clicked()
{
    int now_widget_x = ui->widget_right->pos().x() ;
    int now_widget_y = ui->widget_right->pos().y() ;
    static bool is_left_out = false ;
    if(!is_left_out){
        is_left_out = true ;
        this->_sliding_moudle->slideComponent(ui->widget_right,QPoint(now_widget_x-150,now_widget_y));
    }
    else{
        is_left_out = false ;
        ui->listWidget_right->setCurrentItem(NULL);
        this->_sliding_moudle->slideComponent(ui->widget_right,QPoint(now_widget_x+150,now_widget_y));
    }
}

void SerialWidget::on_pushbutton_start_clicked()
{
    if(this->_current_opened_usb.isEmpty()||
      this->_current_opened_usb!=ui->comboBox_port_name->currentText())
    {
        qDebug()<<"start robot" ;
        this->startRobot();
        this->_current_opened_usb = ui->comboBox_port_name->currentText() ;
    }
    else{
        //qDebug()<<"start" ;
        RobotHardware::getRobotHardWare()->startTransport();
    }
    this->_thread_serial->start();
}

void SerialWidget::on_pushbutton_stop_clicked()
{
       // qDebug()<<"stop" ;
        RobotHardware::getRobotHardWare()->stopTransport();
}

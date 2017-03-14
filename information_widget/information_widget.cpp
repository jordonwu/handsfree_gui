#include "information_widget.h"
#include "ui_information_widget.h"
#include <QStandardItemModel>

#include "robot/command.h"
#include "robot/read_thread.h"
#include "robot/robot_hardware.h"
#include "robot/measure_list.h"
#include "robot/robot_commands.h"

InformationWidget::InformationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InformationWidget)
{
    ui->setupUi(this);
    this->_available_measure_list = RobotCommands::getRobotCommands()->getAvailableMeasureDate() ;
    this->init_param_widget();
    this->init_sigslot();
    ui->treeWidget_param->setColumnWidth(0,(ui->treeWidget_param->width()-3)*3/5);
    ui->treeWidget_param->setColumnWidth(1,ui->treeWidget_param->width()*2/5);
}

InformationWidget::~InformationWidget()
{
    delete ui;
    size_t list_size = this->_vc_measure_commands.size() ;
    for(size_t i = 0 ; i < list_size;i++)delete this->_vc_measure_commands[i];
}

void InformationWidget::on_newmsg_get()
{
    size_t size = this->_vc_measure_commands.size() ;
    for(size_t i = 0 ; i < size ; i++)this->_vc_measure_commands[i]->update() ;
}

void InformationWidget::init_param_widget()
{
    size_t list_size = this->_available_measure_list.size() ;
    for(size_t i = 0 ; i < list_size ; i++){
        this->_vc_measure_commands.push_back(
                    RobotCommands::getRobotCommands()->getMeasureFactory(this->_available_measure_list[i])
                    ->createNewCommand(this->_available_measure_list[i],ui->treeWidget_param)
                    );
    }

}

void InformationWidget::init_sigslot()
{
    connect(RobotHardware::getReadThread(),SIGNAL(newMsgGet()),
            this, SLOT(on_newmsg_get()));

}


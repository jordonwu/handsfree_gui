#include "control_widget.h"
#include "ui_control_widget.h"
#include "util/widget/button_listwidgetitem.h"
#include "util/widget/availablecommand_list.h"
#include "robot/robot_commands.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget),
    _is_setting_joystick(false),
    _button_id_on_setting(-1)
{
    ui->setupUi(this);
 //   ui->stackedWidget->setEnableShake(true);
    this->_command_list = new AvailableCommandList(RobotCommands::getRobotCommands()->getAvailableExpectData()) ;
    this->_vc_joystick_command.resize(Joystick::BUTTON_NUM,NULL);
    this->init_view();
    this->init_signalSlots();
}

ControlWidget::~ControlWidget()
{
    delete ui;
    delete _command_list ;
    delete _default_item ;
    delete _default_listwidgetitem ;
    delete _default_treewidget ;
    size_t size = this->_vc_button_item.size() ;
    for(size_t i = 0 ; i < size ; i++){
        ButtonListWidgetItem *button_item = this->_vc_button_item[i] ;
        QTreeWidget *tree_widget = this->_map_tree_widget[button_item] ;
        QListWidgetItem *treewidget_item = this->_map_listwidget_item[button_item] ;
        CommandAvailable *command = this->_map_commands[button_item] ;
        delete button_item ;
        delete tree_widget ;
        delete treewidget_item ;
        delete command ;
    }
}

void ControlWidget::keyPressEvent(QKeyEvent *e)
{
    ui->joystick->keyPressEvent(e);
}

void ControlWidget::keyReleaseEvent(QKeyEvent *e)
{
    ui->joystick->keyReleaseEvent(e);
}

void ControlWidget::addNewCommands()
{
    //to change the display point of listwidget to the mid of this widget
    int mid_x = this->pos().x() + this->width()/2  ;
    int mid_y = this->pos().y() + this->height()/2 ;
    this->_command_list->move(mid_x,mid_y);

    this->_is_setting_joystick = false ; //listwidget is not call by joystick , need not to reset _vc_joystick_command

    //ExtendedSelection means that user could change multi item at one time
    this->_command_list->setItemSelectMode(QAbstractItemView::ExtendedSelection);
    this->_command_list->show() ;
}

void ControlWidget::setJoysitckButton(int id)
{
    this->_is_setting_joystick = true ;
    this->_button_id_on_setting = id ;
    //SingleSelection means that user could only change one item at one time
    this->_command_list->setItemSelectMode(QAbstractItemView::SingleSelection);
    this->_command_list->show() ;
}

void ControlWidget::joystickButtonPressed(int id)
{
    //to send command to robot
    if(this->_vc_joystick_command[id])this->_vc_joystick_command[id]->update();
}

void ControlWidget::on_commandslist_confirm_clicked(QStringList param_list)
{
    CommandAvailable *command  ;
    size_t size = param_list.size() ;
    for(size_t i = 0 ; i < size ; i++){
        QListWidgetItem *listwidget_item = new QListWidgetItem() ;
        QTreeWidget *command_treewidget = new QTreeWidget() ;
        command_treewidget->resize(ui->stackedWidget->size());
        ButtonListWidgetItem *button_item = new ButtonListWidgetItem(param_list[i]) ;
        button_item->enable_DelButton(true);
        button_item->enable_EditButton(true);
        button_item->enable_changeText(true);

        //set treewidget
       command = RobotCommands::getRobotCommands()->getExpectFactory(param_list[i])
                ->createNewCommand(param_list[i],command_treewidget) ;

       listwidget_item->setSizeHint(QSize(ui->listWidget_commands->width(),50));
       ui->listWidget_commands->insertItem(0,listwidget_item);
       ui->listWidget_commands->setItemWidget(listwidget_item,button_item);
       ui->stackedWidget->insertWidget(0,command_treewidget) ;

       connect(button_item,SIGNAL(delButtonClicked(ButtonListWidgetItem*)),
               this,SLOT(on_buttonitem_delete_clicked(ButtonListWidgetItem*))) ;

       this->_vc_button_item.push_back(button_item);
       this->_map_commands.insert(button_item,command) ;
       this->_map_listwidget_item.insert(button_item,listwidget_item) ;
       this->_map_tree_widget.insert(button_item,command_treewidget) ;
    }


    //when we are setting joystick , there must be only one selected item
    if(this->_is_setting_joystick){
        CommandAvailable *origin_command = this->_vc_joystick_command[this->_button_id_on_setting];
        this->_vc_joystick_command[this->_button_id_on_setting] = command;
        //some bug here
    }
}

void ControlWidget::on_buttonitem_delete_clicked(ButtonListWidgetItem *delete_target)
{
    CommandAvailable *delete_command = this->_map_commands[delete_target] ;
    QTreeWidget *delete_treewidget = this->_map_tree_widget[delete_target] ;
    QListWidgetItem *delete_listwidget_item = this->_map_listwidget_item[delete_target] ;


    disconnect(delete_target,SIGNAL(delButtonClicked(ButtonListWidgetItem*)),
               this,SLOT(on_buttonitem_delete_clicked(ButtonListWidgetItem*))) ;
    this->_vc_button_item.removeOne(delete_target) ;
    this->_map_commands.remove(delete_target) ;
    this->_map_listwidget_item.remove(delete_target) ;
    this->_map_tree_widget.remove(delete_target) ;
    ui->listWidget_commands->removeItemWidget(delete_listwidget_item);
    ui->stackedWidget->removeWidget(delete_treewidget);
    delete delete_target ;
    delete delete_command ;
    delete delete_listwidget_item ;
    delete delete_treewidget ;
}

void ControlWidget::init_view()
{
    this->_default_item = new ButtonListWidgetItem(tr("add some command")) ;
    this->_default_item->enable_AddButton(true);

    this->_default_listwidgetitem = new QListWidgetItem() ;
    this->_default_listwidgetitem->setSizeHint(QSize(ui->listWidget_commands->width(),50));
    ui->listWidget_commands->addItem(this->_default_listwidgetitem);

    ui->listWidget_commands->setItemWidget(this->_default_listwidgetitem,this->_default_item);

    this->_default_treewidget = new DefaultCommandWidget() ;
    ui->stackedWidget->addWidget(this->_default_treewidget) ;

}

void ControlWidget::init_signalSlots()
{
    connect(ui->listWidget_commands,SIGNAL(currentRowChanged(int)),
            ui->stackedWidget , SLOT(setCurrentIndex(int))) ;

    connect(this->_default_item,SIGNAL(addButtonClicked()),
            this,SLOT(addNewCommands())) ;

    connect(this->_command_list,SIGNAL(itemsConfirm(QStringList)),
            this, SLOT(on_commandslist_confirm_clicked(QStringList))) ;

    connect(ui->joystick,SIGNAL(buttonClicked(int)),
            this, SLOT(setJoysitckButton(int))) ;

    connect(ui->joystick,SIGNAL(buttonPressed(int)),
            this , SLOT(joystickButtonPressed(int))) ;
}


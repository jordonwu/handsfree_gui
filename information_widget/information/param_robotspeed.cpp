#include "param_robotspeed.h"
#include <QLabel>
#include <QProgressBar>

ParamRobotSpeed::ParamRobotSpeed(QTreeWidget *target_widget, QObject *parent):
    ParamItem(target_widget,parent)
{
    this->_item_top = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                   0,
                                                   tr("robot_speed")) ;

    this->_info_speed_x = new QLabel(tr("0 m/s")) ;
    this->_info_speed_y = new QLabel(tr("0 m/s")) ;
    this->_info_speed_w = new QLabel(tr("0 r/s")) ;

    this->_item_speed_x = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                       0,tr("X"),
                                                       1,this->_info_speed_x,
                                                       this->_item_top) ;
    this->_item_speed_y = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                       0,tr("Y"),
                                                       1,this->_info_speed_y,
                                                       this->_item_top) ;
    this->_item_speed_w = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                       0,tr("W"),
                                                       1,this->_info_speed_w,
                                                       this->_item_top) ;

}

ParamRobotSpeed::~ParamRobotSpeed()
{
    delete _info_speed_w ;
    delete _info_speed_x ;
    delete _info_speed_y ;

    delete _item_speed_w ;
    delete _item_speed_x ;
    delete _info_speed_y ;
}

void ParamRobotSpeed::update()
{

}



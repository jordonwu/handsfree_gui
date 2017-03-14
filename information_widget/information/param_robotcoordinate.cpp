#include "param_robotcoordinate.h"
#include <QLabel>
#include <QProgressBar>

ParamRobotCoordinate::ParamRobotCoordinate(QTreeWidget *target_widget, QObject *parent):
    ParamItem(target_widget,parent)
{
    this->_item_top = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                   0,
                                                   tr("robot_coordinate")) ;

    this->_info_coordinate_x = new QLabel(tr("0 m")) ;
    this->_info_coordinate_y = new QLabel(tr("0 m")) ;
    this->_info_coordinate_w = new QLabel(tr("0 r")) ;

    this->_item_coordinate_x = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                            0,tr("X"),
                                                            1,this->_info_coordinate_x,
                                                            this->_item_top) ;
    this->_item_coordinate_y = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                            0,tr("Y"),
                                                            1,this->_info_coordinate_y,
                                                            this->_item_top) ;
    this->_item_coordinate_w = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                            0,tr("W"),
                                                            1,this->_info_coordinate_w,
                                                            this->_item_top) ;

}

ParamRobotCoordinate::~ParamRobotCoordinate()
{
    delete _info_coordinate_w ;
    delete _info_coordinate_x ;
    delete _info_coordinate_y ;

    delete _item_coordinate_w ;
    delete _item_coordinate_x ;
    delete _info_coordinate_y ;
}

void ParamRobotCoordinate::update()
{

}


#include "param_moterspeed.h"
#include <QLabel>
#include <QProgressBar>
ParamMoterSpeed::ParamMoterSpeed(QTreeWidget *target_widget, QObject *parent):
    ParamItem(target_widget,parent)
{
    this->_item_top = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                   0,
                                                   tr("moter_speed")) ;

    this->_info_speed_x1 = new QLabel(tr("0 r/s")) ;
    this->_info_speed_x2 = new QLabel(tr("0 r/s")) ;
    this->_info_speed_x3 = new QLabel(tr("0 r/s")) ;

    this->_item_speed_x1 = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                        0,tr("X1"),
                                                        1,this->_info_speed_x1,
                                                        this->_item_top) ;
    this->_item_speed_x2 = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                        0,tr("X2"),
                                                        1,this->_info_speed_x2,
                                                        this->_item_top) ;
    this->_item_speed_x3 = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                        0,tr("X3"),
                                                        1,this->_info_speed_x3,
                                                        this->_item_top) ;
}

ParamMoterSpeed::~ParamMoterSpeed()
{
    delete _info_speed_x1 ;
    delete _info_speed_x2 ;
    delete _info_speed_x3 ;

    delete _item_speed_x1 ;
    delete _item_speed_x2 ;
    delete _info_speed_x3 ;
}

void ParamMoterSpeed::update()
{

}

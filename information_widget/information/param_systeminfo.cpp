#include "param_systeminfo.h"
#include "util/factory/treeitem_factory.h"
#include <QLabel>
#include <QProgressBar>
ParamSystemInfo::ParamSystemInfo(QTreeWidget* target_widget,QObject *parent = 0):
    ParamItem(target_widget,parent)
{
    this->_item_top = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                   0,
                                                   tr("system_info")) ;

    this->_info_cpu_temperature = new QLabel(tr("no temperature")) ;
    this->_info_cpu_usage = new QProgressBar() ;
    this->_info_power_info = new QProgressBar() ;

    this->_item_cpu_temperature = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                               0,tr("temperature"),
                                                               1,this->_info_cpu_temperature,
                                                               this->_item_top) ;
    this->_item_cpu_usage = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                         0,tr("usage"),
                                                         1,this->_info_cpu_usage,
                                                         this->_item_top) ;
    this->_item_power_info = TreeItemFactory::makeNewItem(this->_target_treewidget,
                                                          0,tr("power"),
                                                          1,this->_info_power_info,
                                                          this->_item_top) ;
}

ParamSystemInfo::~ParamSystemInfo()
{
    delete _info_cpu_temperature ;
    delete _info_power_info ;
    delete _info_cpu_usage ;

    delete _item_cpu_temperature ;
    delete _item_power_info ;
    delete _item_cpu_usage ;
}

void ParamSystemInfo::update()
{

}

#ifndef PARAMSYSTEMINFO_H
#define PARAMSYSTEMINFO_H

#include <QObject>
#include "paramitem.h"

class QLabel ;
class QProgressBar ;
class ParamSystemInfo : public ParamItem
{
public:
    ParamSystemInfo(QTreeWidget *target_widget, QObject *parent);
    ~ParamSystemInfo() ;
    virtual void update() ;
private:
    QTreeWidgetItem* _item_cpu_temperature ;
    QTreeWidgetItem* _item_power_info ;
    QTreeWidgetItem* _item_cpu_usage ;

    QLabel* _info_cpu_temperature ;
    QProgressBar* _info_power_info ;
    QProgressBar* _info_cpu_usage ;
};

#endif // PARAMSYSTEMINFO_H

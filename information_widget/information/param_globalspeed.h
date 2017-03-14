#ifndef PARAMGLOBALSPEED_H
#define PARAMGLOBALSPEED_H

#include <QObject>
#include "paramitem.h"
class QLabel ;
class QProgressBar ;
class ParamGlobalSpeed : public ParamItem
{
public:
    ParamGlobalSpeed(QTreeWidget* target_widget,QObject *parent = 0);
    ~ParamGlobalSpeed();
    virtual void update() ;
private:
    QTreeWidgetItem* _item_speed_x;
    QTreeWidgetItem* _item_speed_y ;
    QTreeWidgetItem* _item_speed_w ;

    QLabel* _info_speed_x ;
    QLabel* _info_speed_y ;
    QLabel* _info_speed_w ;
};

#endif // PARAMGLOBALSPEED_H

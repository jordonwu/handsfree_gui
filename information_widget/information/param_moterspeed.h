#ifndef PARAMMOTERSPEED_H
#define PARAMMOTERSPEED_H

#include <QObject>
#include "paramitem.h"
class QLabel ;
class QProgressBar ;
class ParamMoterSpeed : public ParamItem
{
public:
    ParamMoterSpeed(QTreeWidget* target_widget,QObject *parent = 0);
    ~ParamMoterSpeed() ;
    virtual void update() ;
private:
    QTreeWidgetItem* _item_speed_x1;
    QTreeWidgetItem* _item_speed_x2 ;
    QTreeWidgetItem* _item_speed_x3 ;

    QLabel* _info_speed_x1 ;
    QLabel* _info_speed_x2 ;
    QLabel* _info_speed_x3 ;
};

#endif // PARAMMOTERSPEED_H

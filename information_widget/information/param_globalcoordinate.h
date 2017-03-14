#ifndef PARAMGLOBALCOORDINATE_H
#define PARAMGLOBALCOORDINATE_H

#include <QObject>
#include "paramitem.h"
class QLabel ;
class QProgressBar ;
class ParamGlobalCoordinate : public ParamItem
{
public:
    ParamGlobalCoordinate(QTreeWidget* target_widget,QObject *parent = 0);
    ~ParamGlobalCoordinate() ;
    virtual void update() ;
private:
    QTreeWidgetItem* _item_coordinate_x ;
    QTreeWidgetItem* _item_coordinate_y ;
    QTreeWidgetItem* _item_coordinate_w ;

    QLabel* _info_coordinate_x ;
    QLabel* _info_coordinate_y ;
    QLabel* _info_coordinate_w ;
};

#endif // PARAMGLOBALCOORDINATE_H

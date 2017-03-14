#ifndef PARAMROBOTCOORDINATE_H
#define PARAMROBOTCOORDINATE_H

#include <QObject>
#include "paramitem.h"

class QLabel ;
class QProgressBar ;
class ParamRobotCoordinate : public ParamItem
{
public:
    ParamRobotCoordinate(QTreeWidget* target_widget,QObject *parent = 0);
    ~ParamRobotCoordinate() ;
    virtual void update() ;
private:
    QTreeWidgetItem* _item_coordinate_x ;
    QTreeWidgetItem* _item_coordinate_y ;
    QTreeWidgetItem* _item_coordinate_w ;

    QLabel* _info_coordinate_x ;
    QLabel* _info_coordinate_y ;
    QLabel* _info_coordinate_w ;
};

#endif // PARAMROBOTCOORDINATE_H

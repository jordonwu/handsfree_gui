#ifndef PARAMITEM_H
#define PARAMITEM_H

#include <QObject>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <util/factory/treeitem_factory.h>
class ParamItem : public QObject
{
    Q_OBJECT
public:
    explicit ParamItem(QTreeWidget* target_widget,QObject *parent = 0):
        QObject(parent)
    {
        this->_target_treewidget = target_widget ;
    }
    virtual ~ParamItem(){
        delete _target_treewidget ;
        delete _item_top ;
    }
    virtual QTreeWidgetItem* getTopItem(){
        return this->_item_top ;
    }
    virtual void update() = 0 ;
signals:

public slots:
protected:
    QTreeWidget* _target_treewidget ;
    QTreeWidgetItem* _item_top ;
};

#endif // PARAMITEM_H

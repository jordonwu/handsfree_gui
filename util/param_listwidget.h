#ifndef PARAMLISTWIDGET_H
#define PARAMLISTWIDGET_H

#include <QObject>
#include <QVector>
#include <QTreeWidget>
class ParamListWidget : public QTreeWidget
{
public:
    ParamListWidget(QWidget *parent = 0 );
    ~ParamListWidget() ;

protected:
private:
    void init_view() ;
private:
    int _item_size ;
    int _item_index ;
    QVector<QTreeWidgetItem *> _vector_tree_item ;
    QVector<QFrame *> _vector_line ;
};

#endif // PARAMLISTWIDGET_H

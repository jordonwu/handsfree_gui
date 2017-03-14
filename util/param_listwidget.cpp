#include "param_listwidget.h"
#include "util/factory/linefactory.h"
#include <QSpinBox>
ParamListWidget::ParamListWidget(QWidget *parent):
    _item_index(0),
    _item_size(17)
{
    this->init_view();
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
}

ParamListWidget::~ParamListWidget()
{

}

void ParamListWidget::init_view()
{
    QStringList head_string ;
    head_string<<tr("param name")<<tr("value") ;
    this->setHeaderLabels(head_string);
    this->setColumnCount(2);
    this->setIndentation(0);
    for(size_t i = 0 ; i < this->_item_size ; i++){
        QTreeWidgetItem *item = new QTreeWidgetItem() ;
        item->setDisabled(true);
        item->setTextAlignment(0,Qt::AlignCenter);
        if(0==i%2){
            item->setBackgroundColor(0,QColor("#F0F0F0"));
            item->setBackgroundColor(1,QColor("#F0F0F0"));
        }
        else{
            item->setBackgroundColor(0,QColor("#FFFFF0"));
            item->setBackgroundColor(1,QColor("#FFFFF0"));
            item->setExpanded(false);

        }
        this->addTopLevelItem(item) ;
        QFrame *mid_line = LineFactory::getNewLine(QFrame::VLine,QSize(1,this->columnWidth(0))) ;
        this->setItemWidget(item,1,mid_line);
        this->_vector_line.push_back(mid_line);
        this->_vector_tree_item.push_back(item);
    }
}


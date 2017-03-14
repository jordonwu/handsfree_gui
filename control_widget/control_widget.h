#ifndef CONTROL_WIDGET_H
#define CONTROL_WIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <vector>
#include "util/factory/linefactory.h"
#include <QTreeWidget>

class CommandAvailable ;
class AvailableCommandList ;
class QListWidgetItem ;
class ButtonListWidgetItem ;
class DefaultCommandWidget ;

namespace Ui {
class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = 0);
    ~ControlWidget();
    void keyPressEvent(QKeyEvent *e) ;
    void keyReleaseEvent(QKeyEvent *e) ;
public slots:
    void addNewCommands() ;
    void setJoysitckButton(int id) ;
    void joystickButtonPressed(int id) ;
private slots:
    void on_commandslist_confirm_clicked(QStringList param_list) ;
    void on_buttonitem_delete_clicked(ButtonListWidgetItem *delete_target) ;
protected:
private:
    void init_view() ;
    void init_signalSlots() ;
private:
    Ui::ControlWidget *ui;
    //this item could not be deleted by user
    QListWidgetItem *_default_listwidgetitem ;
    ButtonListWidgetItem *_default_item ;
    DefaultCommandWidget* _default_treewidget ;
    AvailableCommandList *_command_list ;

    QVector<ButtonListWidgetItem *> _vc_button_item ;
    QMap<ButtonListWidgetItem *,QListWidgetItem *> _map_listwidget_item ;
    QMap<ButtonListWidgetItem *,QTreeWidget *> _map_tree_widget ;
    QMap<ButtonListWidgetItem *,CommandAvailable *> _map_commands ;

    std::vector<CommandAvailable *> _vc_joystick_command ;

    int _button_id_on_setting ;
    bool _is_setting_joystick ;
};



/*---------------------------------------------------------------------------------*/
//show this when no param
class DefaultCommandWidget:public QTreeWidget
{
    Q_OBJECT
public:
    DefaultCommandWidget(QWidget *parent = 0 ):
        QTreeWidget(parent),
        _item_index(0),
        _item_size(9)
    {
        this->init_view();
    }
    ~DefaultCommandWidget(){
        size_t size = this->_vector_line.size() ;
        for(size_t i = 0 ; i < size ; i++)delete this->_vector_line[i] ;
        size = this->_vector_tree_item.size() ;
        for(size_t i = 0 ; i < size ; i++)delete this->_vector_tree_item[i] ;
    }
protected:
private:
    void init_view(){
        QStringList head_string ;
        head_string<<tr("param")<<tr("value") ;
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
            }
            this->addTopLevelItem(item) ;
            //draw a mid line
            QFrame *mid_line = LineFactory::getNewLine(QFrame::VLine,QSize(1,this->columnWidth(0))) ;
            this->setItemWidget(item,1,mid_line);
            this->_vector_line.push_back(mid_line);
            this->_vector_tree_item.push_back(item);
        }
    }
private:
    int _item_size ;
    int _item_index ;
    QVector<QTreeWidgetItem *> _vector_tree_item ;
    QVector<QFrame *> _vector_line ;

};

#endif // CONTROL_WIDGET_H

#ifndef INFORMATION_WIDGET_H
#define INFORMATION_WIDGET_H

#include <QWidget>
#include <vector>

<<<<<<< HEAD
class QTreeWidgetItem ;
class  CommandAvailable ;
namespace Ui {
class InformationWidget;
}
=======
class  CommandAvailable ;
class ParamItem ;
class QStandardItemModel ;
namespace Ui {
class InformationWidget;
}
class QTreeWidgetItem ;
>>>>>>> d60962d2de6b646d5237592c98a4d25838e6b546
class InformationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InformationWidget(QWidget *parent = 0);
    ~InformationWidget();
public slots:
    void on_newmsg_get() ;
private:
    void init_param_widget() ;
    void init_sigslot() ;
private:
    Ui::InformationWidget *ui;
    QStringList _available_measure_list ;
    std::vector<CommandAvailable *> _vc_measure_commands ;

};

#endif // INFORMATION_WIDGET_H

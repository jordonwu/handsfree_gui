#ifndef PARAM_WIDGET_H
#define PARAM_WIDGET_H

#include <QWidget>
#include <QList>

namespace Ui {
class ParamWidget;
}
class QListWidgetItem ;
class ButtonListWidgetItem ;
class ParamWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParamWidget(QWidget *parent = 0);
    ~ParamWidget();

private:
    Ui::ParamWidget *ui;
};

#endif // PARAM_WIDGET_H

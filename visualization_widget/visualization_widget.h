#ifndef VISUALIZATION_WIDGET_H
#define VISUALIZATION_WIDGET_H

#include <QWidget>

namespace Ui {
class VisualizationWidget;
}

class VisualizationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizationWidget(QWidget *parent = 0);
    ~VisualizationWidget();
public slots:
    void on_pushbutton_control_clicked() ;
private:
    void init_SignalSlot() ;
private:
    Ui::VisualizationWidget *ui;

    bool _is_data_run ;
};

#endif // VISUALIZATION_WIDGET_H

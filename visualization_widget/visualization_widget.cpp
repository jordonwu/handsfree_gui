#include "visualization_widget.h"
#include "ui_visualization_widget.h"

VisualizationWidget::VisualizationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizationWidget),
    _is_data_run(true)
{
    ui->setupUi(this);
    this->init_SignalSlot();
}

VisualizationWidget::~VisualizationWidget()
{
    delete ui;
}

void VisualizationWidget::on_pushbutton_control_clicked()
{
    if(this->_is_data_run)ui->pushButton_control->setIcon(QIcon(":/visualization_widget/visualization_widget/stop.png"));
    else ui->pushButton_control->setIcon(QIcon(":/visualization_widget/visualization_widget/start.png"));
    this->_is_data_run = !this->_is_data_run ;
}

void VisualizationWidget::init_SignalSlot()
{
    connect(ui->pushButton_control,SIGNAL(clicked(bool)),
            this,SLOT(on_pushbutton_control_clicked())) ;
    connect(ui->radioButton_legend,SIGNAL(toggled(bool)),
            ui->widget_plot,SLOT(changeLegendState(bool))) ;
}

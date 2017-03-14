#include "param_widget.h"
#include "ui_param_widget.h"
#include <util/widget/button_listwidgetitem.h>
#include <QLabel>
#include <QListWidgetItem>
#include <QDebug>
#include <QFileDialog>

ParamWidget::ParamWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamWidget)
{
    ui->setupUi(this);
}

ParamWidget::~ParamWidget()
{

}


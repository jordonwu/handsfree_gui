#include "about_widget/about_widget.h"
#include "ui_about_widget.h"
#include <handsfree_hw/hf_hw.h>
AboutWidget::AboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);
}

AboutWidget::~AboutWidget()
{
    delete ui;
}

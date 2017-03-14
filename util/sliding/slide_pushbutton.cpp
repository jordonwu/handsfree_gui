#include "util/sliding/slide_pushbutton.h"
#include "ui_slide_pushbutton.h"

#include <QStylePainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDebug>

SlidePushButton::SlidePushButton(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::SlidePushButton)
{
    ui->setupUi(this);
    this->init_Animation();
    this->init_SignalSlot();
    ui->label_introduce->hide();
    ui->line_split->hide();
    this->_layout_top_height = ui->verticalLayout_top->sizeHint().height() ;
    this->setFlat(true);
}

SlidePushButton::~SlidePushButton()
{
    delete _animation_image ;
    delete _animation_introduce ;
    delete _animation_enter_group ;
    delete _animation_leave_group ;
    delete ui;
}

void SlidePushButton::setImageLabelIcon(const QString &icon_name)
{
    ui->label_image->setPixmap(QPixmap(icon_name));
}

void SlidePushButton::setIntroduceText(const QString &introduce_text)
{
    ui->label_introduce->setText(introduce_text);
}

void SlidePushButton::setTitleText(const QString &title_text, const QColor &color)
{
    ui->label_name->setText(title_text);
    QPalette p;
    p.setColor(QPalette::WindowText,color);
    ui->label_name->setPalette(p);
}

void SlidePushButton::setTitleText(const QString &title_text)
{
    ui->label_name->setText(title_text);
}

void SlidePushButton::setTitleColor(const QColor &color)
{
    QPalette p;
    p.setColor(QPalette::WindowText,color);
    ui->label_name->setPalette(p);
}

void SlidePushButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e) ;
    this->setFlat(false);
    ui->line_split->show() ;
    ui->label_introduce->show();
    this->_animation_introduce->setStartValue(ui->label_introduce->size().height());
    this->_animation_introduce->setEndValue(this->_layout_top_height);

    this->_animation_image->setStartValue(ui->label_image->size().height());
    this->_animation_image->setEndValue(0);

    this->_animation_enter_group->addAnimation(this->_animation_image);
    this->_animation_enter_group->addAnimation(this->_animation_introduce);
    this->_animation_enter_group->start();

}

void SlidePushButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e) ;
    this->setFlat(true);
    ui->label_introduce->hide();

    ui->label_image->show();
    this->_animation_enter_group->stop();
    this->_animation_introduce->setStartValue(ui->label_introduce->size().height());
    this->_animation_introduce->setEndValue(0);

    this->_animation_image->setStartValue(ui->label_image->size().height());
    this->_animation_image->setEndValue(this->_layout_top_height);
    this->_animation_leave_group->addAnimation(this->_animation_image);
    this->_animation_leave_group->addAnimation(this->_animation_introduce);
    this->_animation_leave_group->start();
}

void SlidePushButton::init_Animation()
{
   this->_animation_image = new QPropertyAnimation(ui->label_image,"minimumHeight");
   this->_animation_introduce = new QPropertyAnimation(ui->label_introduce,"minimumHeight") ;
   this->_animation_image->setDuration(100);
   this->_animation_introduce->setDuration(100);

   this->_animation_enter_group = new QParallelAnimationGroup(this) ;
   this->_animation_leave_group = new QParallelAnimationGroup(this) ;
}

void SlidePushButton::init_SignalSlot()
{
    connect(this->_animation_enter_group,SIGNAL(finished()),this,SLOT(onEnterAnimationDone())) ;
    connect(this->_animation_leave_group,SIGNAL(finished()),this,SLOT(onLeaveAnimationDone())) ;
}

void SlidePushButton::onEnterAnimationDone()
{
    ui->label_image->hide();
    ui->line_split->hide();
}

void SlidePushButton::onLeaveAnimationDone()
{
    ui->line_split->hide();
    ui->label_introduce->hide();
}


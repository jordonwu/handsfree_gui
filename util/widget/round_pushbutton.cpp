#include "round_pushbutton.h"
#include <QPainter>
#include <QLabel>
#include <QLayout>
#include <QStyleOption>
#include <QDebug>

RoundPushButton::RoundPushButton(QWidget *parent):
    QPushButton(parent)
{
    this->init_value();
}

RoundPushButton::RoundPushButton(const QString &text, int radius,QWidget *parent):
    QPushButton(parent)
{
    this->init_value();
    this->setText(text);
    this->setRadius(radius);
}

RoundPushButton::RoundPushButton(const QString &text, QIcon &icon,int radius, QWidget *parent):
    QPushButton(parent)
{
    this->init_value();
    this->setText(text);
    this->setIcon(icon);
    this->setRadius(radius);
}

RoundPushButton::~RoundPushButton()
{
    delete _layout_mid ;
    delete _layout_main ;
    delete _label_text ;
    delete _label_icon ;
}

void RoundPushButton::on_pushbutton_setting()
{
    this->_current_state = Set ;
    update();
}

void RoundPushButton::setText(const QString &text)
{
    this->_button_text = text ;
    this->_label_text->setText(this->_button_text);
    QPushButton::setText(text) ;
}

void RoundPushButton::setIcon(const QIcon &icon)
{
    this->_button_icon = icon ;
    this->_label_icon->setPixmap(this->_button_icon.pixmap(this->iconSize()));
    this->_label_icon->setScaledContents(true);
    QPushButton::setIcon(icon) ;
}

void RoundPushButton::init_value()
{
    this->_is_layout_set = false ;
    this->_current_state = Leave ;
    this->_normal_color = QColor(238 , 238 , 238) ;
    this->_normal_border_color = QColor(183 , 183 , 183) ;

    this->_hover_color = QColor(228 , 240 , 250) ;
    this->_hover_border_color = QColor(15 , 150 , 255) ;

    this->_pressed_color = QColor(204 , 228 , 247) ;
    this->_pressed_border_color = QColor(1 , 84 , 153) ;

    this->_unable_color = Qt::white ;
    this->_setting_border_color = Qt::red ;
    this->_opacity = 1.0 ;
    this->_button_radius = 0.0 ;

    this->_label_icon = new QLabel(this) ;
    this->_label_text = new QLabel(this) ;
    this->_layout_main  = new QVBoxLayout() ;
    this->_layout_mid = new QHBoxLayout() ;
    this->setProperty("hover",false) ;
    this->setProperty("nohover",true) ;
}

void RoundPushButton::init_widget()
{
    this->_is_layout_set = true ;
    if(!this->_button_text.isEmpty()){
        this->_label_text->setScaledContents(true);
        this->_label_text->setText(this->_button_text);
        if(!this->_button_icon.isNull()){
            this->_label_icon->resize(this->iconSize());
            this->_label_icon->setPixmap(this->_button_icon.pixmap(this->iconSize()));
            this->_label_icon->setScaledContents(true);
            this->_layout_mid->addWidget(this->_label_icon);
     }
        this->_layout_mid->addWidget(this->_label_text);
    }else if(!this->_button_icon.isNull()){
        this->_label_icon->resize(this->iconSize());
        this->_label_icon->setPixmap(this->_button_icon.pixmap(this->iconSize()));
        this->_label_icon->setScaledContents(true);
        this->_layout_mid->addWidget(this->_label_icon);
    }
    this->_layout_main->setAlignment(Qt::AlignCenter) ;
    this->_layout_main->addLayout(this->_layout_mid);
    this->setLayout(this->_layout_main);
}

void RoundPushButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e) ;
    QPainter button_painter(this) ;
    QPainterPath round_path ;
    button_painter.setRenderHint(QPainter::Antialiasing);
    QColor background_color ;
    QColor border_color ;
    int pen_width = 1 ;
    if(this->isEnabled()){
        switch (this->_current_state) {
        case Leave:
        case Release:
            background_color = this->_normal_color ;
            border_color = this->_normal_border_color ;
            break;
         case Hover:
            background_color = this->_hover_color;
            border_color = this->_hover_border_color ;
            break ;
        case Press:
            background_color = this->_pressed_color ;
            border_color = this->_pressed_border_color ;
            break;
        case Set:
            background_color = this->_hover_color ;
            border_color = Qt::green ;
            pen_width = 2 ;
        }
    }
    else{
        background_color = this->_unable_color ;
    }

    QSize current_size = this->size() ;
    int current_width = current_size.width() ;
    int current_height = current_size.height() ;
    if(this->_button_radius!=0)this->resize(this->_button_radius+pen_width , this->_button_radius+pen_width);
    if(this->_button_radius==0)this->_button_radius = current_width>current_height?current_height:current_width ;
    round_path.addEllipse(0,0,this->_button_radius,this->_button_radius) ;
    button_painter.setClipPath(round_path);
    button_painter.setPen(QPen(QBrush(border_color),pen_width));
    button_painter.setBrush(QBrush(background_color));
    button_painter.drawPath(round_path);

    if(!this->_is_layout_set)this->init_widget();
    QStyleOption opt ;
    opt.init(this);
    this->style()->unpolish(this);
     this->style()->polish(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&button_painter,this);
}

void RoundPushButton::enterEvent(QEvent *e)
{
    this->setProperty("hover",true) ;
    this->setProperty("nohover",false) ;
    this->_current_state = Hover ;
    this->update();
    QPushButton::enterEvent(e) ;
}

void RoundPushButton::leaveEvent(QEvent *e)
{
    this->setProperty("hover",false) ;
    this->setProperty("nohover",true) ;
    this->_current_state = Leave ;
    this->update();
    QPushButton::leaveEvent(e) ;
}

void RoundPushButton::mousePressEvent(QMouseEvent *e)
{
    this->setProperty("hover",true) ;
    this->setProperty("nohover",false) ;
    this->_current_state = Press ;
    this->update();
    QPushButton::mousePressEvent(e) ;
}

void RoundPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->setProperty("hover",true) ;
    this->setProperty("nohover",false) ;
    this->_current_state = Release ;
    this->update();
    QPushButton::mouseReleaseEvent(e) ;
}

QPoint RoundPushButton::getUiPosition()
{
    return this->pos() ;
}



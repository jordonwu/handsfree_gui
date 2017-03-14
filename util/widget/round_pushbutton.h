#ifndef ROUNDPUSHBUTTON_H
#define ROUNDPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QLayout>

class QLabel ;
class QColor ;
class QHBoxLayout ;
class QVBoxLayout ;

class RoundPushButton : public QPushButton
{
    Q_OBJECT
public:
    RoundPushButton(QWidget *parent = 0);
    RoundPushButton(const QString &text ,int radius = 0 , QWidget *parent = 0 ) ;
    RoundPushButton(const QString &text , QIcon &icon ,int radius = 0, QWidget *parent = 0 ) ;
    ~RoundPushButton() ;
public slots:
    void on_pushbutton_setting() ;
public:
    inline void setNormalColor(const QColor &color){this->_normal_color=color;}
    inline void setNormalBorderColor(const QColor &color){this->_normal_border_color = color;}

    inline void setHoverColor(const QColor &color){this->_hover_color = color;}
    inline void setHoverBorderColor(const QColor &color){this->_hover_border_color = color;}

    inline void setPressedColor(const QColor &color){this->_pressed_color = color ;}
    inline void setPressedBorderColor(const QColor &color){this->_pressed_border_color = color;}

    inline void setUnableColor(const QColor &color){this->_unable_color = color;}
    inline void setSettingColor(const QColor &color){this->_setting_border_color = color;}
    inline void setOpacity(const qreal &opacity){this->_opacity = opacity;}
    inline void setRadius(const int radius){this->_button_radius = radius;}
    void setText(const QString &text);
    void setIcon(const QIcon &icon);

protected:
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    typedef enum {Hover,Leave,Press,Release,Set}ButtonState ;

    QPoint getUiPosition() ;
    void init_value() ;
    void init_widget() ;
private:
    ButtonState  _current_state ;
    bool _is_layout_set ;

    QColor _normal_color ;
    QColor _normal_border_color ;

    QColor _hover_color ;
    QColor _hover_border_color ;

    QColor _unable_color ;

    QColor _pressed_color ;
    QColor _pressed_border_color ;

    QColor _setting_border_color ;
    QIcon _button_icon ;
    QString _button_text ;

    QHBoxLayout *_layout_mid ;
    QVBoxLayout *_layout_main ;
    QLabel *_label_text  ;
    QLabel *_label_icon ;
    qreal _opacity ;
    int _button_radius ;
};

#endif // ROUNDPUSHBUTTON_H

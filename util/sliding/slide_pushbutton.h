#ifndef SLIDE_PUSHBUTTON_H
#define SLIDE_PUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

namespace Ui {
class SlidePushButton;
}



class SlidePushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit SlidePushButton(QWidget *parent = 0);
    ~SlidePushButton();
    void setImageLabelIcon(const QString &icon_name)  ;
    void setIntroduceText(const QString &introduce_text) ;
    void setTitleText(const QString &title_text,const QColor &color) ;
    void setTitleText(const QString &title_text) ;
    void setTitleColor(const QColor &color) ;
private:
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void init_Animation() ;
    void init_SignalSlot() ;
private slots:
    void onEnterAnimationDone() ;
    void onLeaveAnimationDone() ;

private:
    Ui::SlidePushButton *ui;
    QPropertyAnimation *_animation_image ;
    QPropertyAnimation *_animation_introduce ;
    QParallelAnimationGroup *_animation_enter_group ;
    QParallelAnimationGroup *_animation_leave_group ;


    int _layout_top_height ;
};

#endif // SLIDE_PUSHBUTTON_H

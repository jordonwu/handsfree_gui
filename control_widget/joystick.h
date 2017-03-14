#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QWidget>
#include <QRect>
#include <QHash>

class Joystick : public QWidget
{
    Q_OBJECT
public:
    typedef enum Button{
        UP = 0 ,
        LEFT = 1 ,
        RIGHT = 2,
        DOWN = 3 ,
        A = 4 ,
        B = 5 ,
        X = 6 ,
        Y = 7 ,
        START = 8 ,
        STOP = 9,
        BUTTON_NUM = 10
    }Button ;

    typedef enum ActionType{
        PRESSED=0,
        CLICKED=1
    }ActionType ;
public:
    explicit Joystick(QWidget *parent = 0);
    ~Joystick();
    void keyPressEvent(QKeyEvent *e) ;
    void keyReleaseEvent(QKeyEvent *e);
signals:
    void hasButtonClicked(int id,Joystick::ActionType action) ;
    void buttonClicked(int id) ;
    void buttonPressed(int id) ;

//    void buttonUpClicked(int id) ;
//    void buttonDownClicked(int id) ;
//    void buttonLeftClicked(int id) ;
//    void buttonRightClicked(int id) ;

//    void buttonStopClicked(int id) ;
//    void buttonStartClicked(int id) ;

//    void buttonAClicked(int id) ;
//    void buttonBClicked(int id) ;
//    void buttonXClicked(int id) ;
//    void buttonYClicked(int id) ;

//    void buttonUpPressed(int id) ;
//    void buttonDownPressed(int id) ;
//    void buttonLeftPressed(int id) ;
//    void buttonRightPressed(int id) ;

//    void buttonStopPressed(int id) ;
//    void buttonStartPressed(int id) ;

//    void buttonAPressed(int id) ;
//    void buttonBPressed(int id) ;
//    void buttonXPressed(int id) ;
//    void buttonYPressed(int id) ;
public slots:
    void do_buttonUpClicked(int id,Joystick::ActionType action){
        if(id==UP){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonDownClicked(int id,Joystick::ActionType action){
        if(id==Joystick::DOWN){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonLeftClicked(int id,Joystick::ActionType action){
        if(id==Joystick::LEFT){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonRightClicked(int id,Joystick::ActionType action){
        if(id==Joystick::RIGHT){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }

    void do_buttonStopClicked(int id,Joystick::ActionType action){
        if(id==Joystick::STOP){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id) ;
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonStartClicked(int id,Joystick::ActionType action){
        if(id==Joystick::START){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }

    void do_buttonAClicked(int id,Joystick::ActionType action){
        if(id==A){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonBClicked(int id,Joystick::ActionType action){
        if(id==B){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED) emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonXClicked(int id,Joystick::ActionType action){
        if(id==X){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED)emit buttonClicked(id);
            else emit buttonPressed(id);
        }
        update();
    }
    void do_buttonYClicked(int id,Joystick::ActionType action){
        if(id==Y){
            this->_is_button_pressed[id] = true ;
            if(action==Joystick::CLICKED)emit buttonClicked(id);
            emit buttonPressed(id);
        }
        update();
    }
private:
    void init_SigSlot() ;
    void paintEvent(QPaintEvent *e) ;
    void mousePressEvent(QMouseEvent *e)  ;
    void mouseReleaseEvent(QMouseEvent *e);

    void setBrushColor(Joystick::Button button,const QRectF &button_rect,QPainter &paint) ;
    inline QRectF ellipse2Rect(const QPointF &center_point , double radius) ;
    inline void setAllButtonUnpressed(){
        for(int i = 0 ; i < Joystick::BUTTON_NUM ; i++){
            this->_is_button_pressed[i] = false ;
        }
    }
private:

    bool _is_button_pressed[Joystick::BUTTON_NUM] ;
    QHash<Joystick::Button,QRectF> _map_button ;

};

#endif // JOYSTICK_H

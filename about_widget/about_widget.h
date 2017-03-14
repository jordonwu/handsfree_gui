#ifndef ABOUT_WIDGET_H
#define ABOUT_WIDGET_H

#include <QWidget>

namespace Ui {
class AboutWidget;
}

class AboutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = 0);
    ~AboutWidget();

private:
    Ui::AboutWidget *ui;
};

#endif // ABOUT_WIDGET_H

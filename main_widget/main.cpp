#include "main_widget/main_widget.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.setWindowIcon(QIcon(":/main_page/main_image/exe.png"));
    w.show();

    return a.exec();
}

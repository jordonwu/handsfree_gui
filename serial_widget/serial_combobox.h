#ifndef SERIALCOMBOBOX_H
#define SERIALCOMBOBOX_H

#include <QObject>
#include <QComboBox>
#include <QGroupBox>
class SerialComboBox : public QComboBox
{
public:
    SerialComboBox(QGroupBox *&group);
    void showPopup();
public slots:
    void refresh_usb_list() ;
};

#endif // SERIALCOMBOBOX_H

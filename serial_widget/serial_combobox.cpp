#include "serial_combobox.h"
#include <QtSerialPort/QSerialPortInfo>
SerialComboBox::SerialComboBox(QGroupBox *&group):
    QComboBox(group)
{

    this->refresh_usb_list();
}

void SerialComboBox::showPopup()
{
    this->refresh_usb_list();
    QComboBox::showPopup();
}

void SerialComboBox::refresh_usb_list()
{
    this->clear();
    QStringList list_port_name ;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        list_port_name.append(info.portName());
    }
    this->addItems(list_port_name);

}


#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Serial Maanger Constructed";
    _connectStatus = false;


    qDebug() << "Detecting the available ports";
    //print the available ports, and here we need to update qml combox
    for(const QSerialPortInfo &port_info : QSerialPortInfo::availablePorts()){
        qDebug() << "Port: " << port_info.portName();
        _detectedComs.append(port_info.portName());

    }
}

QStringList SerialManager::detectedComs() const
{
    return _detectedComs;
}

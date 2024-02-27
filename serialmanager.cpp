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

QString SerialManager::comName() const
{
    return _comName;
}

void SerialManager::setComName(const QString &newComName)
{
    if (_comName == newComName)
        return;
    _comName = newComName;
    emit comNameChanged();
}

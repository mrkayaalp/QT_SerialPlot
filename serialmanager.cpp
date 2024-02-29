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

QList<qint32> SerialManager::supportedBauds() const
{
    return _supportedBauds;
}

qint32 SerialManager::baudRate() const
{
    return _baudRate;
}

void SerialManager::setBaudRate(qint32 newBaudRate)
{
    if (_baudRate == newBaudRate)
        return;
    _baudRate = newBaudRate;
    emit baudRateChanged();
}

bool SerialManager::connectStatus() const
{
    return _connectStatus;
}

void SerialManager::setConnectStatus(bool newConnectStatus)
{
    if(newConnectStatus != _connectStatus){
        // if false we have to connect else disconnect
        if(_connectStatus == false){
            _serial.setBaudRate( baudRate());
            _serial.setDataBits(QSerialPort::Data8);
            _serial.setParity( QSerialPort::NoParity );
            _serial.setStopBits( QSerialPort::OneStop );
            _serial.setFlowControl( QSerialPort::NoFlowControl );
            _serial.setPortName( _comName );

            if(_serial.open(QIODevice::ReadWrite)){
                //if you cac open serial port and..
                qDebug() << "Serial Port Opened Successfully";
                _serial.write("Rose is here sir!!\r\n");
                _connectStatus = true;
            }
            else{
                _connectStatus = false;
                qDebug() << "Unable to open the Selected Serial Port" << _serial.error();

            }
        }
        else{
            _connectStatus = false;
            qDebug() << "Disconnecting...";
            _serial.close();
        }
    }
    emit connectStatusChanged( _connectStatus );
}

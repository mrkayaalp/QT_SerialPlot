#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QPointF>


class SerialManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList detectedComs READ detectedComs CONSTANT)
public:
    explicit SerialManager(QObject *parent = nullptr);

    QStringList detectedComs() const;

signals:

private:
    QSerialPort _serial;
    QStringList _detectedComs;
    bool _connectStatus;
};

#endif // SERIALMANAGER_H

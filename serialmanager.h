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
    Q_PROPERTY(QString comName READ comName WRITE setComName NOTIFY comNameChanged)
public:
    explicit SerialManager(QObject *parent = nullptr);

    QStringList detectedComs() const;

    QString comName() const;
    Q_INVOKABLE void setComName(const QString &newComName);

signals:

    void comNameChanged();

private:
    QSerialPort _serial;
    QStringList _detectedComs;
    QString _comName;
    bool _connectStatus;
};

#endif // SERIALMANAGER_H

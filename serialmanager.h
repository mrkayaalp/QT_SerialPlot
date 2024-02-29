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

    Q_PROPERTY(QList<qint32> supportedBauds READ supportedBauds CONSTANT)
    Q_PROPERTY(qint32 baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged )

    Q_PROPERTY(bool connectStatus READ connectStatus WRITE setConnectStatus NOTIFY connectStatusChanged)
public:
    explicit SerialManager(QObject *parent = nullptr);

    QStringList detectedComs() const;
    QString comName() const;
    Q_INVOKABLE void setComName(const QString &newComName);

    QList<qint32> supportedBauds() const;
    qint32 baudRate() const;
    Q_INVOKABLE void setBaudRate(qint32 newBaudRate);

    bool connectStatus() const;


signals:

    void comNameChanged();

    void baudRateChanged();

    void connectStatusChanged( bool currentStatus );

public slots:
    Q_INVOKABLE void setConnectStatus(bool newConnectStatus);



private:
    QSerialPort _serial;

    //Detected COM Names
    QStringList _detectedComs;
    QString _comName;

    //Baud Rates TO:DO suppoted Baud Rate not working
    QList<qint32> _supportedBauds;
    qint32 _baudRate;

    //For COM connection status
    bool _connectStatus;
};

#endif // SERIALMANAGER_H

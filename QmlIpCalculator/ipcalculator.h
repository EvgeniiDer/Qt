#ifndef IPCALCULATOR_H
#define IPCALCULATOR_H

#include <QObject>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QHostAddress>
#include <QtNetwork>

class IpCalculator : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString ipAddress READ getIpAddress WRITE setIpAddress NOTIFY ipAddressChanged FINAL)
    Q_PROPERTY(QString subnetMask READ getSubnetMask WRITE setSubnetMask NOTIFY subnetMaskChanged FINAL)
    Q_PROPERTY(int prefixLength READ getPrefixLength WRITE setPrefixLength NOTIFY prefixLengthChanged FINAL)
    Q_PROPERTY(QString info READ getInfo WRITE setInfo NOTIFY infoChanged FINAL)

public:
    explicit IpCalculator(QObject *parent = nullptr);

    QString getIpAddress()const
    {
        return m_ipAddress;
    }
    void setIpAddress(const QString& ip);

    QString getSubnetMask()const
    {
        return m_subnetMask;
    }
    void setSubnetMask(const QString& mask);

    int getPrefixLength()const
    {
        return m_prefixLength;
    }
    void setPrefixLength(int length);

    QString getInfo()
    {
        return m_info;
    }
    void setInfo(const QString& info);
public slots:
    void calculateInfo();
signals:
    void ipAddressChanged();
    void subnetMaskChanged();
    void prefixLengthChanged();
    void infoChanged();
private:
    QString m_ipAddress;
    QString m_subnetMask;
    int m_prefixLength;
    QString m_info;

    void updateSubnetMaskFromPrefix();
    void updatePrefixFromSubnetMask();
    QString calculateNetworkAddress()const;
    QString calculateBroadcastAddress()const;
    quint32 calculateNumberOfAddresses()const;
    quint32 calculateNumberOfUsableAddress()const;

};

#endif // IPCALCULATOR_H

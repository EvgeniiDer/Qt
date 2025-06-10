#include "ipcalculator.h"

IpCalculator::IpCalculator(QObject * parent) : QObject(parent), m_ipAddress("192.168.1.1"),
    m_subnetMask("255.255.255.0"), m_prefixLength(24)
{

}
void IpCalculator::calculateInfo()
{
    QString networkAddress = calculateNetworkAddress();
    QString broadcastAddress = calculateBroadcastAddress();
    quint32 numberOfAddresses = calculateNumberOfAddresses();
    quint32 numberOfUsbaleAddresses = calculateNumberOfUsableAddress();

    QString infoText = QString("Network Address: %1\n"
                               "Broadcast Address: %2\n"
                               "Total Addresses: %3\n"
                               "Usable Addresses: %4")
                           .arg(networkAddress)
                           .arg(broadcastAddress)
                           .arg(numberOfAddresses)
                           .arg(numberOfUsbaleAddresses);
    setInfo(infoText);
}
void IpCalculator::setInfo(const QString& info)
{
    if(m_info != info)
    {
        m_info = info;
        emit infoChanged();// signal
    }
}
void IpCalculator::setIpAddress(const QString& ip)
{
    if(m_ipAddress != ip)
    {
        m_ipAddress = ip;
        emit ipAddressChanged();
    }
}
//Метод отвечате за Изменение Маски подсети которая веедт к изменению Префикса
void IpCalculator::setSubnetMask(const QString& mask)
{
    if(m_subnetMask != mask)
    {
        m_subnetMask = mask;
        emit subnetMaskChanged();
        updatePrefixFromSubnetMask();
    }
}
//Метод отвеает за Изменение Префикса которая ведет к изменению Маски подсети
void IpCalculator::setPrefixLength(int length)
{
    if (m_prefixLength != length) {
        m_prefixLength = length;
        emit prefixLengthChanged();
        updateSubnetMaskFromPrefix();
    }

}
// Вычислене ногово Префикса
void IpCalculator::updatePrefixFromSubnetMask()
{
    quint32 mask = QHostAddress(m_subnetMask).toIPv4Address();
    int prefix = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(mask & (1 << (31 - i)))
        {
            // Операция 'mask & (маска для бита)' вернет ненулевое значение (истина)
            // ТОЛЬКО ЕСЛИ соответствующий бит в `mask` тоже равен 1.
            // Если бит равен 1, увеличиваем наш счетчик.
            //  Проверяем каждый бит, начиная со старшего
            prefix++;
        }
        else{
            break;
        }
    }
    setPrefixLength(prefix);
}
//Вычесление новой Маски
void IpCalculator::updateSubnetMaskFromPrefix()
{
    quint32 mask = 0;
    for(int i = 0; i < m_prefixLength; ++i)
    {
        /*(1 << (31 - i)) — Маска для одного бита
        1 в двоичном виде это 00...0001.
        Оператор << — это побитовый сдвиг влево. Он сдвигает все биты числа налево на указанное количество позиций.
        31 - i — это позиция бита. В 32-битном числе int биты нумеруются от 0 (младший) до 31 (старший). Если ваш цикл for (int i = 0; ...) идёт от меньшего к большему, то 31 - i позволяет итерироваться по битам от старшего к младшему.
        При i = 0, сдвиг будет на 31. Результат: 1000...0000 (единица в 31-й позиции).
        При i = 1, сдвиг будет на 30. Результат: 0100...0000 (единица в 30-й позиции).

        При i = 31, сдвиг будет на 0. Результат: 0000...0001 (единица в 0-й позиции).
        |= — Побитовое ИЛИ с присваиванием
        Это сокращенная запись для mask = mask \ ....
        Оператор \ (побитовое ИЛИ) работает так: если хотя бы в одном из операндов на данной позиции стоит 1, то в результате тоже будет 1.
        0 \ 0 = 0
        0 \ 1 = 1
        1 \ 0 = 1
        1 \ 1 = 1
        Ключевое свойство: операция X | 0 не меняет X, а X | 1 всегда даёт 1.
        Когда мы делаем mask | (маска с одним битом), мы "зажигаем" (устанавливаем в 1) соответствующий бит в mask, при этом все остальные биты, которые были 0 в маске-однобитке, остаются в mask без изменений.*/
        mask |= (1 << (31 - i));
    }
    setSubnetMask(QHostAddress(mask).toString());
}
// Вычисление Адреса Сети
QString IpCalculator::calculateNetworkAddress() const // Адрес Сети
{
    quint32 ip = QHostAddress(m_ipAddress).toIPv4Address();
    quint32 mask = QHostAddress(m_subnetMask).toIPv4Address();
    quint32 network = ip & mask; // Побитовая операции И (Если бит маски и ip равны 1 true в остальных случаях false)
    return QHostAddress(network).toString();
}
// В Каких случаях нужен широковещательный адресс!!(Если адрес сети — это первый адрес в диапазоне, то Broadcast Address — это последний адрес в диапазоне)
// Получение IP-адреса (протокол DHCP): Когда вы подключаете новое устройство к сети (например, ноутбук к Wi-Fi), у него еще нет IP-адреса.
//Оно не знает, с кем говорить. Поэтому оно отправляет broadcast-сообщение на всю сеть с криком: "Я новенький! Кто-нибудь может дать мне IP-адрес?".
//DHCP-сервер (обычно это ваш роутер) слышит этот крик и отвечает уже лично этому устройству, предлагая ему свободный адрес.
// Обнаружение устройств и служб (протокол ARP): Ваш компьютер знает IP-адрес другого компьютера в сети, но не знает его физический MAC-адрес.
//Он отправляет broadcast-сообщение: "У кого IP-адрес 192.168.1.5? Пожалуйста, сообщите мне свой MAC-адрес!". Компьютер с этим IP-адресом отвечает.
QString IpCalculator::calculateBroadcastAddress()const//Широковещательный адрес
{
    quint32 ip = QHostAddress(m_ipAddress).toIPv4Address();
    quint32 mask = QHostAddress(m_subnetMask).toIPv4Address();
    quint32 broadcast = ip | ~mask; //\ (OR) Этот оператор сравнивает два бита. Результат будет 1, если хотя бы один из исходных битов равен 1, ~mask инверсия или побитовое НЕ
    return QHostAddress(broadcast).toString();
}
//Эта функция вычисляет общее количество всех возможных адресов в подсети, включая два служебных.(Широковещательнй и Адрес Сети)
quint32 IpCalculator::calculateNumberOfAddresses()const
{
    return 1U << (32 - m_prefixLength);//побитывый сдвиг в лево по форумлу N << X = N * 2^X где N = 1 * 2 ^ (32 - m_prefixLength)
}
//Вычисление Адресов в которых уже удалены Широковещательный адрес и Адрес Сети
quint32 IpCalculator::calculateNumberOfUsableAddress()const
{
    quint32 totalAddresses = calculateNumberOfAddresses();
    return totalAddresses > 1? totalAddresses - 2 : 0;
}

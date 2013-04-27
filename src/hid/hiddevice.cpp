#include "hiddevice.h"
#include "hidapi/hiddevice_hidapi_p.h"

QTX_BEGIN_NAMESPACE


HidDevice::HidDevice(QObject * parent /* = 0 */)
    : QObject(parent),
      d_ptr(new HidDevicePrivate(this))
{
}

HidDevice::~HidDevice()
{
    if (d_ptr) {
        delete d_ptr;
        d_ptr = 0;
    }
}

bool HidDevice::open(quint8 bus, quint8 address)
{
    qDebug() << "HidDevice::open";
    qDebug() << "  bus: " << bus;
    qDebug() << "  address: " << address;
    
    Q_D(HidDevice);
    return d->open(bus, address);
}


HidDevicePrivateData::HidDevicePrivateData(HidDevice *q)
    : q_ptr(q)
{
}

HidDevicePrivateData::~HidDevicePrivateData()
{
    q_ptr = 0;
}


QTX_END_NAMESPACE

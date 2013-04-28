#include "hiddevice.h"
#include "hidapi/hiddevice_hidapi_p.h"

QTX_BEGIN_NAMESPACE


HidDevice::HidDevice(QObject * parent /* = 0 */)
    : QIODevice(parent),
      d_ptr(new HidDevicePrivate(this))
{
}

HidDevice::HidDevice(quint16 vid, quint16 pid, QObject * parent /* = 0 */)
    : QIODevice(parent),
      d_ptr(new HidDevicePrivate(this))
{
    d_ptr->vendorId = vid;
    d_ptr->productId = pid;
}

HidDevice::~HidDevice()
{
    if (d_ptr) {
        delete d_ptr;
        d_ptr = 0;
    }
}

bool HidDevice::open(OpenMode mode)
{
    Q_UNUSED(mode)
    
    Q_D(HidDevice);
    return d->open();
}

qint64 HidDevice::writeReport(const QByteArray & data, char reportId /* = 0 */)
{
    Q_D(HidDevice);
    return d->writeReport(data, reportId);
}

void HidDevice::setMaxInputReportSize(qint64 size)
{
    Q_D(HidDevice);
    d->maxInputReportSize = size;
}

qint64 HidDevice::readData(char * data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    
    return -1;
}

qint64 HidDevice::writeData(const char * data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    
    return -1;
}


HidDevicePrivateData::HidDevicePrivateData(HidDevice *q)
    : vendorId(0),
      productId(0),
      maxInputReportSize(64),
      q_ptr(q)
{
}

HidDevicePrivateData::~HidDevicePrivateData()
{
    q_ptr = 0;
}


QTX_END_NAMESPACE

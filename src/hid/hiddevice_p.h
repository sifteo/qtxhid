#ifndef QTXHID_HIDDEVICE_P_H
#define QTXHID_HIDDEVICE_P_H

#include "hiddevice.h"

QTX_BEGIN_NAMESPACE


class HidDevicePrivateData
{
public:
    HidDevicePrivateData(HidDevice *q);
    virtual ~HidDevicePrivateData();
    
public:
    quint16 vendorId;
    quint16 productId;
    quint64 maxInputReportSize;
    QByteArray lastReportReceived;
    HidDevice *q_ptr;
    Q_DECLARE_PUBLIC(HidDevice);
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_P_H

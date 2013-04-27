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
    HidDevice *q_ptr;
    Q_DECLARE_PUBLIC(HidDevice);
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_P_H

#ifndef QTXHID_HIDDEVICE_HIDAPI_P_H
#define QTXHID_HIDDEVICE_HIDAPI_P_H

#include "../hiddevice_p.h"

QTX_BEGIN_NAMESPACE


class HidDevicePrivate : public HidDevicePrivateData
{
public:
    HidDevicePrivate(HidDevice *q);
    virtual ~HidDevicePrivate();
    
    bool open(quint8 bus, quint8 address);
    
public:
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_HIDAPI_P_H

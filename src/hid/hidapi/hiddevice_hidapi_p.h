#ifndef QTXHID_HIDDEVICE_HIDAPI_P_H
#define QTXHID_HIDDEVICE_HIDAPI_P_H

#include "../hiddevice_p.h"
#include "hidapireaderthread.h"
#include <hidapi.h>

QTX_BEGIN_NAMESPACE


class HidDevicePrivate : public HidDevicePrivateData
{
public:
    HidDevicePrivate(HidDevice *q);
    virtual ~HidDevicePrivate();
    
    bool open();
    qint64 writeReport(const QByteArray & data, char reportId = 0);
    
public:
    hid_device *handle;
    HidApiReaderThread *readerThread;
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_HIDAPI_P_H

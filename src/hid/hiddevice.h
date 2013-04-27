#ifndef QTXHID_HIDDEVICE_H
#define QTXHID_HIDDEVICE_H

#include "hidglobal.h"
#include <QtCore>

QTX_BEGIN_NAMESPACE


class HidDevicePrivate;

class HidDevice : public QObject
{
    Q_OBJECT
    
public:
    HidDevice(QObject * parent = 0);
    virtual ~HidDevice();
    
    bool open(quint8 bus, quint8 address);
        
protected:
    HidDevicePrivate *d_ptr;
private:
    Q_DECLARE_PRIVATE(HidDevice);
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_H

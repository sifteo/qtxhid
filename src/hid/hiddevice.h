#ifndef QTXHID_HIDDEVICE_H
#define QTXHID_HIDDEVICE_H

#include "hidglobal.h"
#include <QtCore>

QTX_BEGIN_NAMESPACE


class HidDevice : public QObject
{
    Q_OBJECT
    
public:
    HidDevice(QObject * parent = 0);
    virtual ~HidDevice();
        
private:
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_H

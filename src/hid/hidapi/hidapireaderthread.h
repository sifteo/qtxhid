#ifndef QTXHID_HIDAPIREADERTHREAD_H
#define QTXHID_HIDAPIREADERTHREAD_H

#include "hidglobal.h"
#include <QtCore>
#include <hidapi.h>

QTX_BEGIN_NAMESPACE


class HidApiReaderThread : public QThread
{
public:
    HidApiReaderThread(hid_device *handle, QObject * parent = 0);
    virtual ~HidApiReaderThread();
    
    void run();
    
private:
    hid_device *mHandle;
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDAPIREADERTHREAD_H
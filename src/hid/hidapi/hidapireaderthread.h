#ifndef QTXHID_HIDAPIREADERTHREAD_H
#define QTXHID_HIDAPIREADERTHREAD_H

#include "hidglobal.h"
#include <QtCore>
#include <hidapi.h>

QTX_BEGIN_NAMESPACE


class HidApiReaderThread : public QThread
{
    Q_OBJECT
    
public:
    HidApiReaderThread(hid_device *handle, quint64 bufferSize, QObject * parent = 0);
    virtual ~HidApiReaderThread();
    
    void run();
    
signals:
    void reportRead(const QByteArray & data);
    
private:
    hid_device *mHandle;
    quint64 mBufferSize;
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDAPIREADERTHREAD_H

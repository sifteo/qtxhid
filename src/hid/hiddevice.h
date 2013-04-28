#ifndef QTXHID_HIDDEVICE_H
#define QTXHID_HIDDEVICE_H

#include "hidglobal.h"
#include <QtCore>

QTX_BEGIN_NAMESPACE


class HidDevicePrivate;

class HidDevice : public QIODevice
{
    Q_OBJECT
    
public:
    HidDevice(QObject * parent = 0);
    HidDevice(quint16 vid, quint16 pid, QObject * parent = 0);
    virtual ~HidDevice();
    
    bool open(OpenMode mode);
    qint64 writeReport(const QByteArray & data, char reportId = 0);
    
    void setMaxInputReportSize(qint64 size);
    
protected:
    qint64 readData(char * data, qint64 maxSize);
    qint64 writeData(const char * data, qint64 maxSize);
        
protected:
    HidDevicePrivate *d_ptr;
private:
    Q_DECLARE_PRIVATE(HidDevice);
};


QTX_END_NAMESPACE

#endif // QTXHID_HIDDEVICE_H

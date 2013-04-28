#include "hidapireaderthread.h"

QTX_BEGIN_NAMESPACE


HidApiReaderThread::HidApiReaderThread(hid_device *handle, QObject * parent /* = 0 */)
    : QThread(parent),
      mHandle(handle)
{
}

HidApiReaderThread::~HidApiReaderThread()
{
}

void HidApiReaderThread::run()
{
    qDebug() << "HidApiReaderThread::run";
    
    unsigned char buf[64];
    int res;
    
    while (1) {
        memset(buf, 0, 64);
        res = hid_read(mHandle, buf, 64);
        if (-1 == res)
        {
            printf( "error %d\n", res);
            return;
        }

        printf( "received %d bytes\n", res);

        for (int i = 0; i < res; i++)
            printf("Byte %d: %02x ", i+1, buf[i]);
        //printf( "%02x ", buf[0]);
        fflush(stdout);
    }
}


QTX_END_NAMESPACE

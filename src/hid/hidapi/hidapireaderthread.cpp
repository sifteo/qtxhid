#include "hidapireaderthread.h"

QTX_BEGIN_NAMESPACE


HidApiReaderThread::HidApiReaderThread(hid_device *handle, quint64 bufferSize, QObject * parent /* = 0 */)
    : QThread(parent),
      mHandle(handle),
      mBufferSize(bufferSize)
{
}

HidApiReaderThread::~HidApiReaderThread()
{
}

void HidApiReaderThread::run()
{
    qDebug() << "HidApiReaderThread::run";
    qDebug() << "  thread: " << QThread::currentThread();
    qDebug() << "  bufferSize: " << mBufferSize;
    
    unsigned char *buf = (unsigned char *)malloc(mBufferSize);
    int res;
    
    while (1) {
        memset(buf, 0, mBufferSize);
        res = hid_read(mHandle, buf, mBufferSize);
        if (-1 == res)
        {
            printf( "error %d\n", res);
            return;
        }

        printf( "received %d bytes\n", res);

        for (int i = 0; i < res; i++)
            printf("Byte %d: %02x ", i+1, buf[i]);
        //printf( "%02x ", buf[0]);
        printf( "\n");
        fflush(stdout);
    }
    
    free(buf);
}


QTX_END_NAMESPACE

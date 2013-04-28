#include "hiddevice_hidapi_p.h"
#include <hidapi.h>

QTX_BEGIN_NAMESPACE


HidDevicePrivate::HidDevicePrivate(HidDevice *q)
    : HidDevicePrivateData(q),
      handle(0),
      readerThread(0)
{
}

HidDevicePrivate::~HidDevicePrivate()
{
}

bool HidDevicePrivate::open()
{
    qDebug() << "HidDevicePrivate::open";
    
    /*
    // Enumerate and print the HID devices on the system
    struct hid_device_info *devs, *cur_dev;
    
    devs = hid_enumerate(0x0, 0x0);
    cur_dev = devs;	
    while (cur_dev) {
        printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls",
            cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
        printf("\n");
        printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
        printf("  Product:      %ls\n", cur_dev->product_string);
        printf("\n");
        cur_dev = cur_dev->next;
    }
    hid_free_enumeration(devs);
    */
    
    handle = hid_open(vendorId, productId, NULL);
    qDebug() << "  handle: " << handle;
    
    // Enable blocking (disable non-blocking).  Reads and writes will be
    // buffered and performed in a separate thread so as not to impact
    // performance of the calling thread.
    hid_set_nonblocking(handle, 0);
    
    readerThread = new HidApiReaderThread(handle, q_ptr);
    readerThread->start();
    
    return true;
}

qint64 HidDevicePrivate::writeReport(const QByteArray & data, char reportId /* = 0 */)
{
    qDebug() << "HidDevicePrivate::writeReport";
    qDebug() << "  size: " << data.size();
    
    QByteArray buffer(data);
    buffer.prepend(reportId);
    int res = hid_write(handle, (const unsigned char *)buffer.data(), buffer.size());
    
    if (-1 != res && 0 == reportId) {
        res--;
    }
    
    qDebug() << "  res: " << res;
    return res;
}


QTX_END_NAMESPACE

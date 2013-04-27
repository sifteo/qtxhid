#include "hiddevice_hidapi_p.h"
#include <hidapi.h>

QTX_BEGIN_NAMESPACE


HidDevicePrivate::HidDevicePrivate(HidDevice *q)
    : HidDevicePrivateData(q)
{
}

HidDevicePrivate::~HidDevicePrivate()
{
}

bool HidDevicePrivate::open(quint8 bus, quint8 address)
{
    qDebug() << "HidDevicePrivate::open";
    qDebug() << "  bus: " << bus;
    qDebug() << "  address: " << address;
    
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
    
    return true;
}


QTX_END_NAMESPACE

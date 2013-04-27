HEADERS += \
    $$PWD/hiddevice_p.h \
    $$PWD/hiddevice.h \
    
SOURCES += \
    $$PWD/hiddevice.cpp


# TODO: Make this conditional on the platform/backend
HEADERS += \
    $$PWD/hidapi/hiddevice_hidapi_p.h

SOURCES += \
    $$PWD/hidapi/hiddevice_hidapi.cpp \
    $$PWD/../../vendor/src/hidapi/mac/hid.c

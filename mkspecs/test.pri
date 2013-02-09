include(features/qtx_testcase.prf)


INCLUDEPATH += ../../../src/hid \
               ../../../vendor/include

LIBS += -L../../../lib

LIBS += -lQtxHid

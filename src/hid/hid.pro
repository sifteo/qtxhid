include(../../modules/qtx_hid.pri)
include(../../mkspecs/features/qtx_config.prf)
include(../../mkspecs/features/qtx_module.prf)


include(hid.pri)

# TODO: Make this conditional on the platform/backend
INCLUDEPATH += \
    ../../vendor/src/hidapi/hidapi

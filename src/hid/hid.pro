include(../../modules/qtx_hid.pri)
include(../../mkspecs/features/qtx_config.prf)
include(../../mkspecs/features/qtx_module.prf)


include(hid.pri)

INCLUDEPATH += \
    ../../vendor/include

macx {
    # LIBS += $$(PWD)/../../vendor/lib/osx/x86_64/libyajl_s.a
}

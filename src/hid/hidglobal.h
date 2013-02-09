#ifndef QTXHID_GLOBAL_H
#define QTXHID_GLOBAL_H

#ifdef QTX_ENABLE_NAMESPACE

#ifndef QTX_NAMESPACE
#  define QTX_NAMESPACE Qtx
#endif
#ifndef QTX_USE_NAMESPACE
#  define QTX_USE_NAMESPACE using namespace ::QTX_NAMESPACE;
#endif
#ifndef QTX_BEGIN_NAMESPACE
#  define QTX_BEGIN_NAMESPACE namespace QTX_NAMESPACE {
#endif
#ifndef QTX_END_NAMESPACE
#  define QTX_END_NAMESPACE }
#endif

#else

#ifndef QTX_NAMESPACE
#  define QTX_NAMESPACE
#endif
#ifndef QTX_USE_NAMESPACE
#  define QTX_USE_NAMESPACE
#endif
#ifndef QTX_BEGIN_NAMESPACE
#  define QTX_BEGIN_NAMESPACE
#endif
#ifndef QTX_END_NAMESPACE
#  define QTX_END_NAMESPACE
#endif

#endif

#endif /* QTXHID_GLOBAL_H */

#include "tquickloader.h"

#include "theme/tthememanager.h"
#include "tquick.h"

#include <tquickinfo.h>

void TQuickLoader::load(QQmlEngine *pEngine)
{
    TQuick::getInstance()->registerTypes(TQUICK_NAME);
    TQuick::getInstance()->initializeEngine(pEngine, TQUICK_NAME);
}

QString TQuickLoader::version()
{
    return TQuick::getInstance()->version();
}

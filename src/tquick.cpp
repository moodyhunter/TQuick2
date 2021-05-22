/****************************************************************************
**
** Library: TQuick
**
** MIT License
**
** Copyright (c) 2019 toou http://www.toou.net
** Copyright (c) 2020 chengxuewen <1398831004@qq.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
*all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
**
****************************************************************************/

#include "tquick.h"

#include "controls/gadget/tcolor.h"
#include "controls/gadget/tgadgetbackground.h"
#include "controls/gadget/tgadgetborder.h"
#include "controls/gadget/tgadgeticon.h"
#include "controls/gadget/tgadgetitem.h"
#include "controls/gadget/tgadgetlabel.h"
#include "controls/gadget/tgadgetscrollbar.h"
#include "controls/interface/tdialogitem.h"
#include "controls/interface/ttoastitem.h"
#include "theme/tthemebinder.h"
#include "theme/tthememanager.h"
#include "tquickglobal.h"
#include "tquickworld.h"

#include <QDebug>
#include <QFontDatabase>
#include <QMutex>
#include <QMutexLocker>
#include <QQmlContext>
#include <tquickinfo.h>

class TQuickPrivate
{
    Q_DECLARE_PUBLIC(TQuick)
  public:
    TQuickPrivate()
    {
    }

    TQuick *q_ptr;

    TQuickWorld *m_pWorld = nullptr;
    QQmlEngine *m_pEngine = nullptr;
    QQuickWindow *m_pRoot = nullptr;
    Qt::CursorShape m_eMouseAreaCurrsor = Qt::ArrowCursor;
};

static TQuick *sg_pInstance = nullptr;

TQuick::~TQuick()
{
}

QObject *TQuick::qmlSingletonTypeProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return TQuick::getInstance();
}

TQuick *TQuick::getInstance()
{
    static QMutex mutex;
    QMutexLocker mutexLocker(&mutex);
    if (nullptr == sg_pInstance)
    {
        sg_pInstance = new TQuick;
    }
    return sg_pInstance;
}

QString TQuick::version() const
{
    return TQUICK_COMPAT_VERSION;
}

QString TQuick::awesomeFromKey(const QString &strKey)
{
    if (!strKey.isEmpty())
    {
        int iIndex = TQuick_Awesome::staticMetaObject.indexOfEnumerator("TQuickAwesomeType");
        return QChar(TQuick_Awesome::staticMetaObject.enumerator(iIndex).keysToValue(strKey.toStdString().c_str()));
    }
    return QString();
}

QString TQuick::awesomeFromValue(int type)
{
    return QChar(type);
}

QStringList TQuick::awesomelist()
{
    QMetaEnum enumType = TQuick_Awesome::staticMetaObject.enumerator(TQuick_Awesome::staticMetaObject.indexOfEnumerator("TQuickAwesomeType"));
    QStringList list;
    for (int i = 0; i < enumType.keyCount(); ++i)
    {
        list.append(enumType.key(i)); // enumType.value(i)
    }
    return list;
}

void TQuick::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String(TQUICK_NAME));
    Q_INIT_RESOURCE(TQuick);

    int iMajor = QString(TQUICK_LIB_VERSION_MAJOR).toInt();
    int iMinor = QString(TQUICK_LIB_VERSION_MINOR).toInt();

    qmlRegisterSingletonType<TQuick>(uri, iMajor, iMinor, "TQuick2", TQuick::qmlSingletonTypeProvider);
    qmlRegisterSingletonType<TThemeManager>(uri, iMajor, iMinor, "TThemeManager", TThemeManager::qmlSingletonTypeProvider);
    qmlRegisterSingletonType<TColor>(uri, iMajor, iMinor, "TColor", TColor::qmlSingletonTypeProvider);

    qmlRegisterType<TGadgetLabel>(uri, iMajor, iMinor, "TGadgetLabel");
    qmlRegisterType<TGadgetBorder>(uri, iMajor, iMinor, "TGadgetBorder");
    qmlRegisterType<TGadgetBackground>(uri, iMajor, iMinor, "TGadgetBackground");
    qmlRegisterType<TGadgetIcon>(uri, iMajor, iMinor, "TGadgetIcon");
    qmlRegisterType<TGadgetScrollbar>(uri, iMajor, iMinor, "TGadgetScrollbar");
    qmlRegisterType<TGadgetItem>(uri, iMajor, iMinor, "TGadgetItem");

    qmlRegisterType<TQuickWorld>(uri, iMajor, iMinor, "TQuickWorld");
    qmlRegisterType<TThemeBinder>(uri, iMajor, iMinor, "TThemeBinder");
    qmlRegisterType<TToastItem>(uri, iMajor, iMinor, "TToastItem");
    qmlRegisterType<TDialogItem>(uri, iMajor, iMinor, "TDialogItem");

    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TObject.qml"), uri, iMajor, iMinor, "TObject");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TMouseArea.qml"), uri, iMajor, iMinor, "TMouseArea");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TFlickable.qml"), uri, iMajor, iMinor, "TFlickable");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TScrollbarV.qml"), uri, iMajor, iMinor, "TScrollbarV");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TScrollbarH.qml"), uri, iMajor, iMinor, "TScrollbarH");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TFpsMonitor.qml"), uri, iMajor, iMinor, "TFpsMonitor");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TRectangle.qml"), uri, iMajor, iMinor, "TRectangle");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TLabel.qml"), uri, iMajor, iMinor, "TLabel");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TImage.qml"), uri, iMajor, iMinor, "TImage");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TDividerLine.qml"), uri, iMajor, iMinor, "TDividerLine");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TBadge.qml"), uri, iMajor, iMinor, "TBadge");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TTag.qml"), uri, iMajor, iMinor, "TTag");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TAwesomeIcon.qml"), uri, iMajor, iMinor, "TAwesomeIcon");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TSVGIcon.qml"), uri, iMajor, iMinor, "TSVGIcon");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TButton.qml"), uri, iMajor, iMinor, "TButton");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TIcon.qml"), uri, iMajor, iMinor, "TIcon");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TIconButton.qml"), uri, iMajor, iMinor, "TIconButton");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TInputField.qml"), uri, iMajor, iMinor, "TInputField");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TAvatar.qml"), uri, iMajor, iMinor, "TAvatar");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TPagination.qml"), uri, iMajor, iMinor, "TPagination");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TImageButton.qml"), uri, iMajor, iMinor, "TImageButton");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TBusyIndicator.qml"), uri, iMajor, iMinor, "TBusyIndicator");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TRadioBox.qml"), uri, iMajor, iMinor, "TRadioBox");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TRadioBoxGroup.qml"), uri, iMajor, iMinor, "TRadioBoxGroup");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TCheckBox.qml"), uri, iMajor, iMinor, "TCheckBox");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TCarousel.qml"), uri, iMajor, iMinor, "TCarousel");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TCarouselElement.qml"), uri, iMajor, iMinor, "TCarouselElement");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TPopup.qml"), uri, iMajor, iMinor, "TPopup");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TSwitch.qml"), uri, iMajor, iMinor, "TSwitch");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TProgressBar.qml"), uri, iMajor, iMinor, "TProgressBar");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TNavigationBar.qml"), uri, iMajor, iMinor, "TNavigationBar");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TNavigationElement.qml"), uri, iMajor, iMinor, "TNavigationElement");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TDialogBasic.qml"), uri, iMajor, iMinor, "TDialogBasic");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TDialog.qml"), uri, iMajor, iMinor, "TDialog");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TDialogButton.qml"), uri, iMajor, iMinor, "TDialogButton");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TPopover.qml"), uri, iMajor, iMinor, "TPopover");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TPopoverMenu.qml"), uri, iMajor, iMinor, "TPopoverMenu");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TPopoverElement.qml"), uri, iMajor, iMinor, "TPopoverElement");
    qmlRegisterType(QUrl("qrc:/TQuick2/qml/TMask.qml"), uri, iMajor, iMinor, "TMask");

    qmlRegisterSingletonType(QUrl("qrc:/TQuick2/qml/TToast.qml"), uri, iMajor, iMinor, "TToast");

    qmlRegisterUncreatableMetaObject(TQuick_State::staticMetaObject, "TQuick2", iMajor, iMinor, "TStateType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(TQuick_Icon::staticMetaObject, "TQuick2", iMajor, iMinor, "TIconType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(TQuick_Awesome::staticMetaObject, "TQuick2", iMajor, iMinor, "TAwesomeType", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(TQuick_Time::staticMetaObject, "TQuick2", iMajor, iMinor, "TTimePreset", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(TQuick_PixelSize::staticMetaObject, "TQuick2", iMajor, iMinor, "TPixelSizePreset", "Access to enums & flags only");
    qmlRegisterUncreatableMetaObject(TQuick_Position::staticMetaObject, "TQuick2", iMajor, iMinor, "TPosition", "Access to enums & flags only");
}

void TQuick::initializeEngine(QQmlEngine *pEngine, const char *uri)
{
    Q_UNUSED(pEngine)
    Q_UNUSED(uri)
    d_ptr->m_pEngine = pEngine;
    QFontDatabase::addApplicationFont("qrc:/TQuick2/resource/font/fontawesome-webfont.ttf");
    pEngine->rootContext()->setContextProperty("rootWindow", nullptr);
}

void TQuick::initQuickRoot(QQuickWindow *pRoot)
{
    if (nullptr != d_ptr->m_pRoot)
    {
        return;
    }
    d_ptr->m_pRoot = pRoot;
    d_ptr->m_pEngine->rootContext()->setContextProperty("rootWindow", pRoot);
}

void TQuick::initWorld(TQuickWorld *pWorld)
{
    d_ptr->m_pWorld = pWorld;
}

void TQuick::setStartupTheme(const QString &strName)
{
    TThemeManager::getInstance()->setStartupTheme(strName);
}

void TQuick::addThemeDir(const QString &strDir)
{
    TThemeManager::getInstance()->addThemeDir(strDir);
}

void TQuick::addTheme(const QString &strPath)
{
    TThemeManager::getInstance()->addTheme(strPath);
}

int TQuick::mouseAreaCursorShape()
{
    return (int) d_ptr->m_eMouseAreaCurrsor;
}

void TQuick::setMouseAreaCursorShape(const Qt::CursorShape &eCursor)
{
    d_ptr->m_eMouseAreaCurrsor = eCursor;
}

TQuick::TQuick() : d_ptr(new TQuickPrivate)
{
}

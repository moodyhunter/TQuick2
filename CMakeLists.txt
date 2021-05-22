cmake_minimum_required(VERSION 3.19)
project(TQuick2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(TQUICK_LIB_VERSION_MAJOR "2")
set(TQUICK_LIB_VERSION_MINOR "0")
set(TQUICK_LIB_VERSION_MICRO "0")
set(TQUICK_LIB_VERSION_STAGE "alpha")
set(TQUICK_LIB_VERSION_BRANCH "dev")
set(TQUICK_LIB_VERSION_NUMBER "${TQUICK_LIB_VERSION_MAJOR}.${TQUICK_LIB_VERSION_MINOR}.${TQUICK_LIB_VERSION_MICRO}")
set(TQUICK_LIB_VERSION_DISPLAY  "${TQUICK_LIB_VERSION_NUMBER}_${TQUICK_LIB_VERSION_STAGE}")
set(TQUICK_COMPAT_VERSION "${TQUICK_LIB_VERSION_MAJOR}.${TQUICK_LIB_VERSION_MINOR}")
set(TQUICK_COPYRIGHT_YEAR "2021")
set(TQUICK_NAME "TQuick2")
configure_file(${CMAKE_CURRENT_LIST_DIR}/src/tquickinfo.h.in ${CMAKE_CURRENT_BINARY_DIR}/tquickinfo.h)

find_package(Qt6 6.1.0 COMPONENTS Core Gui Qml Quick REQUIRED)

qt6_add_resources(TQuickQRC ${CMAKE_CURRENT_LIST_DIR}/src/TQuick.qrc)

set(SOURCES
    ${TQuickQRC}
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tcolor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tcolor.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetbackground.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetbackground.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetborder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetborder.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgeticon.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgeticon.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetitem.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetlabel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetlabel.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetscrollbar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/gadget/tgadgetscrollbar.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/interface/tdialogitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/interface/tdialogitem.h
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/interface/ttoastitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/controls/interface/ttoastitem.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemebinder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemebinder.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemeconstant.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemeconstant.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemefileparser.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemehandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemehandler.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemejsonfileparser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthemejsonfileparser.h
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthememanager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/theme/tthememanager.h
    ${CMAKE_CURRENT_LIST_DIR}/src/tquick.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/tquick.h
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickglobal.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickglobal.h
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickloader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickloader.h
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickqmlplugin.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickqmlplugin.h
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickworld.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/tquickworld.h)

set(QMLS
    qml/TAvatar.qml
    qml/TAwesomeIcon.qml
    qml/TBadge.qml
    qml/TBusyIndicator.qml
    qml/TButton.qml
    qml/TCarousel.qml
    qml/TCarouselElement.qml
    qml/TCheckBox.qml
    qml/TDialog.qml
    qml/TDialogBasic.qml
    qml/TDialogButton.qml
    qml/TDividerLine.qml
    qml/TFlickable.qml
    qml/TFpsMonitor.qml
    qml/TIcon.qml
    qml/TIconButton.qml
    qml/TImage.qml
    qml/TImageButton.qml
    qml/TInputField.qml
    qml/TLabel.qml
    qml/TMask.qml
    qml/TMouseArea.qml
    qml/TNavigationBar.qml
    qml/TNavigationElement.qml
    qml/TObject.qml
    qml/TPagination.qml
    qml/TPopover.qml
    qml/TPopoverElement.qml
    qml/TPopoverMenu.qml
    qml/TPopup.qml
    qml/TProgressBar.qml
    qml/TRadioBox.qml
    qml/TRadioBoxGroup.qml
    qml/TRectangle.qml
    qml/TSVGIcon.qml
    qml/TScrollbarH.qml
    qml/TScrollbarV.qml
    qml/TSwitch.qml
    qml/TTag.qml
    qml/TToast.qml)

qt6_add_qml_module(TQuick2
    GENERATE_QMLTYPES
    INSTALL_QMLTYPES
    VERSION "${TQUICK_COMPAT_VERSION}"
    CLASS_NAME "TQuickQmlPlugin"
    URI "${TQUICK_NAME}"
    SOURCES "${SOURCES}"
    RESOURCE_PREFIX "/"
    QML_FILES "${QMLS}"
    INSTALL_DIRECTORY "TQuick2")

qt6_import_qml_plugins(TQuick2
    PATH_TO_SCAN ${CMAKE_CURRENT_LIST_DIR}/qml)

#link_directories(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(TQuick2 PRIVATE Qt::Core Qt::Qml Qt::Gui Qt::Quick)
add_library(TQuick2::TQuick2 ALIAS TQuick2)

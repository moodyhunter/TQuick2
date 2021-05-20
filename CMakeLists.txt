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
configure_file(${CMAKE_SOURCE_DIR}/src/tquickinfo.h.in ${CMAKE_BINARY_DIR}/tquickinfo.h)


find_package(Qt6 6.1.0 COMPONENTS Core Gui Quick REQUIRED)

qt6_add_resources(TQuickQRC ${CMAKE_SOURCE_DIR}/src/TQuick.qrc)

set(SOURCES
    ${TQuickQRC}
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tcolor.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tcolor.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetbackground.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetbackground.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetborder.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetborder.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgeticon.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgeticon.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetitem.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetitem.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetlabel.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetlabel.h
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetscrollbar.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/gadget/tgadgetscrollbar.h
    ${CMAKE_SOURCE_DIR}/src/controls/interface/tdialogitem.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/interface/tdialogitem.h
    ${CMAKE_SOURCE_DIR}/src/controls/interface/ttoastitem.cpp
    ${CMAKE_SOURCE_DIR}/src/controls/interface/ttoastitem.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthemebinder.cpp
    ${CMAKE_SOURCE_DIR}/src/theme/tthemebinder.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthemeconstant.cpp
    ${CMAKE_SOURCE_DIR}/src/theme/tthemeconstant.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthemefileparser.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthemehandler.cpp
    ${CMAKE_SOURCE_DIR}/src/theme/tthemehandler.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthemejsonfileparser.cpp
    ${CMAKE_SOURCE_DIR}/src/theme/tthemejsonfileparser.h
    ${CMAKE_SOURCE_DIR}/src/theme/tthememanager.cpp
    ${CMAKE_SOURCE_DIR}/src/theme/tthememanager.h
    ${CMAKE_SOURCE_DIR}/src/tquick.cpp
    ${CMAKE_SOURCE_DIR}/src/tquick.h
    ${CMAKE_SOURCE_DIR}/src/tquickglobal.cpp
    ${CMAKE_SOURCE_DIR}/src/tquickglobal.h
    ${CMAKE_SOURCE_DIR}/src/tquickloader.cpp
    ${CMAKE_SOURCE_DIR}/src/tquickloader.h
    ${CMAKE_SOURCE_DIR}/src/tquickqmlplugin.cpp
    ${CMAKE_SOURCE_DIR}/src/tquickqmlplugin.h
    ${CMAKE_SOURCE_DIR}/src/tquickworld.cpp
    ${CMAKE_SOURCE_DIR}/src/tquickworld.h)


set(QMLS
    controls/TAvatar.qml
    controls/TAwesomeIcon.qml
    controls/TBadge.qml
    controls/TBusyIndicator.qml
    controls/TButton.qml
    controls/TCarousel.qml
    controls/TCarouselElement.qml
    controls/TCheckBox.qml
    controls/TDialog.qml
    controls/TDialogBasic.qml
    controls/TDialogButton.qml
    controls/TDividerLine.qml
    controls/TFlickable.qml
    controls/TFpsMonitor.qml
    controls/TIcon.qml
    controls/TIconButton.qml
    controls/TImage.qml
    controls/TImageButton.qml
    controls/TInputField.qml
    controls/TLabel.qml
    controls/TMask.qml
    controls/TMouseArea.qml
    controls/TNavigationBar.qml
    controls/TNavigationElement.qml
    controls/TObject.qml
    controls/TPagination.qml
    controls/TPopover.qml
    controls/TPopoverElement.qml
    controls/TPopoverMenu.qml
    controls/TPopup.qml
    controls/TProgressBar.qml
    controls/TRadioBox.qml
    controls/TRadioBoxGroup.qml
    controls/TRectangle.qml
    controls/TSVGIcon.qml
    controls/TScrollbarH.qml
    controls/TScrollbarV.qml
    controls/TSwitch.qml
    controls/TTag.qml
    controls/TToast.qml)

link_directories(${CMAKE_SOURCE_DIR}/src)

set(BUILD_SHARED_LIBS ON)

qt6_add_qml_module(TQuick2
    GENERATE_QMLTYPES
    VERSION ${TQUICK_COMPAT_VERSION}
    CLASSNAME TQuickPlugin
    URI ${TQUICK_NAME}
    SOURCES ${SOURCES}
    RESOURCE_PREFIX "/"
    QML_FILES ${QMLS}
    INSTALL_DIRECTORY ${TQUICK_NAME})

target_link_libraries(TQuick2 PRIVATE Qt::Core Qt::Gui Qt::Quick)

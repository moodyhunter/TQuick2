cmake_minimum_required(VERSION 3.19)
project(TQuick2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(BUILD_SHARED_LIBS ON)

set(TQUICK_LIB_VERSION_MAJOR    "2")
set(TQUICK_LIB_VERSION_MINOR    "0")
set(TQUICK_LIB_VERSION_MICRO    "0")
set(TQUICK_LIB_VERSION_STAGE    "alpha")
set(TQUICK_LIB_VERSION_BRANCH   "dev")
set(TQUICK_LIB_VERSION_NUMBER   "${TQUICK_LIB_VERSION_MAJOR}.${TQUICK_LIB_VERSION_MINOR}.${TQUICK_LIB_VERSION_MICRO}")
set(TQUICK_LIB_VERSION_DISPLAY  "${TQUICK_LIB_VERSION_NUMBER}_${TQUICK_LIB_VERSION_STAGE}")
set(TQUICK_COMPAT_VERSION "${TQUICK_LIB_VERSION_MAJOR}.${TQUICK_LIB_VERSION_MINOR}")
set(TQUICK_COPYRIGHT_YEAR "2021")
set(TQUICK_NAME "TQuick2")

configure_file(${CMAKE_CURRENT_LIST_DIR}/src/tquickinfo.h.in ${CMAKE_CURRENT_BINARY_DIR}/tquickinfo.h)

find_package(Qt6 6.2 COMPONENTS Core Gui Qml Quick REQUIRED)

qt6_add_resources(TQuickQRC ${CMAKE_CURRENT_LIST_DIR}/src/TQuick.qrc)

qt6_add_qml_module(TQuick2
    VERSION "${TQUICK_COMPAT_VERSION}"
    URI "TQuick2"
    NO_PLUGIN_OPTIONAL
    NO_GENERATE_PLUGIN_SOURCE
    PLUGIN_TARGET "TQuickPlugin" # Although qt6_add_qml_module handles this correctly, a lower-case "plugin" does not look good.
    SOURCES
        src/controls/gadget/tcolor.h
        src/controls/gadget/tgadgetbackground.h
        src/controls/gadget/tgadgetborder.h
        src/controls/gadget/tgadgeticon.h
        src/controls/gadget/tgadgetitem.h
        src/controls/gadget/tgadgetlabel.h
        src/controls/gadget/tgadgetscrollbar.h
        src/controls/interface/tdialogitem.h
        src/controls/interface/ttoastitem.h
        src/theme/tthemebinder.h
        src/theme/tthemeconstant.h
        src/theme/tthemefileparser.h
        src/theme/tthemehandler.h
        src/theme/tthemejsonfileparser.h
        src/theme/tthememanager.h
        src/tquick.h
        src/tquickglobal.h
        src/tquickloader.h
        src/tquickworld.h
        ${TQuickQRC}
        src/theme/tthememanager.cpp
        src/controls/gadget/tcolor.cpp
        src/controls/gadget/tgadgetbackground.cpp
        src/controls/gadget/tgadgetborder.cpp
        src/controls/gadget/tgadgeticon.cpp
        src/controls/gadget/tgadgetitem.cpp
        src/controls/gadget/tgadgetlabel.cpp
        src/controls/gadget/tgadgetscrollbar.cpp
        src/controls/interface/tdialogitem.cpp
        src/controls/interface/ttoastitem.cpp
        src/theme/tthemebinder.cpp
        src/theme/tthemeconstant.cpp
        src/theme/tthemehandler.cpp
        src/theme/tthemejsonfileparser.cpp
        src/tquick.cpp
        src/tquickworld.cpp
        src/tquickglobal.cpp
        src/tquickloader.cpp
    QML_FILES
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
        qml/TToast.qml
    RESOURCE_PREFIX
        "/"
    OUTPUT_DIRECTORY
        ${CMAKE_CURRENT_BINARY_DIR}/imports/TQuick2
    )

target_sources(TQuickPlugin PRIVATE src/tquickqmlplugin.cpp src/tquickqmlplugin.h)
target_link_directories(TQuickPlugin PUBLIC TQuick2)

install(TARGETS TQuick2 COMPONENT development)

target_link_libraries(TQuick2 PUBLIC Qt::Core Qt::Qml Qt::Gui Qt::Quick)

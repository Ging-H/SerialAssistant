#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T14:15:51
#
#-------------------------------------------------

QT       += core gui serialport uiplugin


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialAssistant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/serialassistant.cpp \
        src/crc.c


HEADERS += \
        inc/serialassistant.h \
        inc/crc.h

FORMS += \
        ui/serialassistant.ui

RESOURCES += res/images.qrc

RC_ICONS = res/general/ing10.ico

# 生成ui.h路径
#UI_DIR +=  ./inc
#

# 头文件包含路径
INCLUDEPATH += $$PWD/inc \
               $$PWD/serialcommplugin \
               $$PWD/multiwidgetplugin

# 依赖文件所在路径
serial      = $$PWD/serialcommplugin
multiwidget = $$PWD/multiwidgetplugin

# 可执行文件.exe 路径
DESTDIR = $$PWD/exe


# 复制依赖文件到.exe目录下
mingw {
    serialcommplugin.path   = $$DESTDIR
    serialcommplugin.files += $$serial/mingw/*.dll

    multiwidgetplugin.path   = $$DESTDIR
    multiwidgetplugin.files += $$multiwidget/mingw/*.dll

    INSTALLS  += serialcommplugin multiwidgetplugin

    LIBS  +=  $$serial/mingw/libserialcommplugin.a \       # MinGW编译
              $$multiwidget/mingw/libmultiwidgetplugin.a   # MinGW编译
}else{
# 复制serialcommplugin.dll文件
    serialcommplugin.path   = $$DESTDIR
    serialcommplugin.files += $$serial/msvc2015/*.dll

# 复制multiwidgetplugin.dll文件
    multiwidgetplugin.path   = $$DESTDIR
    multiwidgetplugin.files += $$multiwidget/msvc2015/*.dll

# 复制其他的*.dll文件
    other.path   = $$DESTDIR
    other.files += $$serial/*.dll

    INSTALLS  += serialcommplugin multiwidgetplugin other

    LIBS  +=  $$serial/msvc2015/serialcommplugin.lib \        # msvc编译
              $$multiwidget/msvc2015/multiwidgetplugin.lib   # msvc编译
}
# 复制默认的ini文件到 ./exe
initfile.path = $$DESTDIR/
initfile.files += $$PWD/default.ini
INSTALLS  += initfile

# 复制翻译文件
serialqm.path   = $$DESTDIR/translations
serialqm.files += $$serial/*.qm

multiwidgetqm.path   = $$DESTDIR/translations
multiwidgetqm.files += $$multiwidget/*.qm

serialcommqm.path   = $$DESTDIR/translations
serialcommqm.files += $$PWD/res/*.qm

INSTALLS  += serialqm multiwidgetqm serialcommqm

# 翻译文件
TRANSLATIONS += res/SerialAssistant_zh_CN.ts \
                res/SerialAssistant_zh_TW.ts \


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    functest.cpp

HEADERS += \
    functest.hpp

QMAKE_CXXFLAGS += -std=c++11

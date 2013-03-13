TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


unix|win32: LIBS += -llapack



unix|win32: LIBS += -lblas

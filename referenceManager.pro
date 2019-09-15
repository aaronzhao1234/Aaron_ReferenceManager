TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    referenceManager.cpp \
    pugixml/pugixml.cpp \
    outputreference.cpp \
    ieee_book.cpp \
    ieee_book_chapter.cpp

HEADERS += \
    pugixml/pugiconfig.hpp \
    pugixml/pugixml.hpp \
    outputreference.h \
    ieee_book.h \
    ieee_book_chapter.h

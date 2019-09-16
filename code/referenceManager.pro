TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ieee_journal.cpp \
    ieee_report.cpp \
    ieee_standard.cpp \
    ieee_web.cpp \
    referenceManager.cpp \
    pugixml/pugixml.cpp \
    outputreference.cpp \
    ieee_book.cpp \
    ieee_book_chapter.cpp

HEADERS += \
    ieee_journal.h \
    ieee_report.h \
    ieee_standard.h \
    ieee_web.h \
    pugixml/pugiconfig.hpp \
    pugixml/pugixml.hpp \
    outputreference.h \
    ieee_book.h \
    ieee_book_chapter.h

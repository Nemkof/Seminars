TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        TinyXML/tinystr.cpp \
        TinyXML/tinyxml.cpp \
        TinyXML/tinyxmlerror.cpp \
        TinyXML/tinyxmlparser.cpp \
        main.cpp



    LIBS += -LC:\myQT\projects\SFML-2.6.1\lib
    LIBS += -LC:\myQT\projects\SFML-2.6.1\bin

    CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main
    CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lsfml-main

    INCLUDEPATH += C:\myQT\projects\SFML-2.6.1\include
    DEPENDPATH += C:\myQT\projects\SFML-2.6.1\include

HEADERS += \
    TinyXML/tinystr.h \
    TinyXML/tinyxml.h \
    level.h


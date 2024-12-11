QT += widgets

HEADERS       = mainwindow.h \
    anymapfilehandler.h
SOURCES       = mainwindow.cpp \
                anymapfilehandler.cpp \
                main.cpp

# install
target.path = /build
INSTALLS += target

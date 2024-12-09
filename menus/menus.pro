QT += widgets

HEADERS       = mainwindow.h \
    AnyMap.h \
    pbm.h \
    pgm.h \
    ppm.h
SOURCES       = mainwindow.cpp \
                anymap.cpp \
                main.cpp \
                pbm.cpp \
                pgm.cpp \
                ppm.cpp

# install
target.path = /build
INSTALLS += target

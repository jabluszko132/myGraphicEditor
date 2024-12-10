QT += widgets

HEADERS       = mainwindow.h \
    pbm.h \
    pgm.h \
    ppm.h
SOURCES       = mainwindow.cpp \
                main.cpp \
                pbm.cpp \
                pgm.cpp \
                ppm.cpp

# install
target.path = /build
INSTALLS += target

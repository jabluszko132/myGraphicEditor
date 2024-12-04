QT += widgets

HEADERS       = mainwindow.h \
    AnyMap.h \
    pbm.h \
    pgm.h
SOURCES       = mainwindow.cpp \
                anymap.cpp \
                main.cpp \
                pbm.cpp \
                pgm.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/menus
INSTALLS += target

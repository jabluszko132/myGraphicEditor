#ifndef ANYMAPFILEHANDLER_H
#define ANYMAPFILEHANDLER_H

#include <QFile>
#include <QTextStream>
#include <QPixmap>


class AnyMapFileHandler
{
private:
    static inline void appendFromSToWhiteOrCom(QTextStream &s, QString &pixmap, QString &buffer);
public:
    static QImage* load(QFile *file);

    static QImage* newP1(int width, int height);
    static QImage* newP2(int width, int height);
    static QImage* newP3(int width, int height);
    static QImage* newP4(int width, int height);
    static QImage* newP5(int width, int height);
    static QImage* newP6(int width, int height);
};

#endif // ANYMAPFILEHANDLER_H

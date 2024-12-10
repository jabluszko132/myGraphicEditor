#ifndef PPM_H
#define PPM_H

#include <QString>
#include <qfile.h>
#include <qtextstream.h>

class PPM
{
public:
    int width;
    int height;
    const QString header{"ppm"};
    const std::byte colorMaxVal{255};
    std::byte*** map; //order of colors in top lvl of the array is RGB
    static PPM fromFile(QFile *s);
    void save(QFile *s);
    PPM(int width, int height);
    PPM(int width, int height, std::byte*** map);
    ~PPM();
};

#endif // PPM_H

#ifndef PGM_H
#define PGM_H


#include <qfile.h>
#include <qtextstream.h>

class PGM{
public:
    int width;
    int height;
    const QString header{"pgm"};
    const std::byte colorMaxVal{255};
    std::byte** map;
    static PGM fromFile(QFile *file);
    void save(QFile *file);
    PGM(int width, int height);
    PGM(int width, int height, std::byte** map);
    ~PGM();
};

#endif // PGM_H

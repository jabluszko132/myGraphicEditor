#ifndef PBM_H
#define PBM_H

#include <qfile.h>
#include <qtextstream.h>

class PBM
{
public:
    int width;
    int height;
    const std::string header{"pbm"};
    bool** map;
    static PBM fromFile(QFile *file);
    void save(QFile *file);
    PBM(int width, int height);
    PBM(int width, int height, bool** map);
    ~PBM();
};

#endif // PBM_H

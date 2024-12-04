#ifndef PGM_H
#define PGM_H

#include "AnyMap.h"

class PGM : public AnyMap
{
public:
    int width;
    int height;
    const std::string header;
    bool** map;
    static PGM fromFile(std::ofstream s);

    PGM();
};

#endif // PGM_H

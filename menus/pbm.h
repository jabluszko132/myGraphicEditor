#ifndef PBM_H
#define PBM_H

#include "AnyMap.h"

class PBM : public AnyMap
{
public:
    int width;
    int height;
    const std::string header;
    bool** map;
    static PBM fromFile(std::ofstream s);
    PBM(int width, int height);
    PBM(int width, int height, bool** map);
    ~PBM();
};

#endif // PBM_H

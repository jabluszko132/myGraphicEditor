#ifndef PGM_H
#define PGM_H

#include "AnyMap.h"

class PGM : public AnyMap<std::byte>
{
public:
    int width;
    int height;
    const std::string header;
    const std::byte colorMaxVal{255};
    std::byte** map;
    static PGM fromFile(std::ifstream s);
    void save(std::ofstream s);
    PGM(int width, int height);
    PGM(int width, int height, std::byte** map);
    ~PGM();
};

#endif // PGM_H

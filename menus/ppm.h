#ifndef PPM_H
#define PPM_H

#include <string>
#include <fstream>

class PPM
{
public:
    int width;
    int height;
    const std::string header;
    const std::byte colorMaxVal{255};
    std::byte*** map; //order of colors in top lvl of the array is RGB
    static PPM fromFile(std::ifstream s);
    void save(std::ofstream s);
    PPM(int width, int height);
    PPM(int width, int height, std::byte*** map);
    ~PPM();
};

#endif // PPM_H

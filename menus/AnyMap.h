#ifndef ANYMAP_H
#define ANYMAP_H

#include <fstream>
template<typename T>
class AnyMap
{
public:
    int width;
    int height;
    T** map;
    virtual void save(std::ofstream s);
    AnyMap(int width, int height);
    AnyMap(int width, int height, T** map);
    virtual ~AnyMap();
};

#endif // ANYMAP_H

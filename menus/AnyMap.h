#ifndef ANYMAP_H
#define ANYMAP_H

template<typename T>
class AnyMap
{
public:
    int width;
    int height;
    T** map;
    virtual void save(std::ifstream s);
    AnyMap(int width, int height);
    AnyMap(int width, int height, T** map);
    virtual ~AnyMap();
};

#endif // ANYMAP_H

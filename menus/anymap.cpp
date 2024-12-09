#include "anymap.h"

template<typename T>
AnyMap<T>::AnyMap(){}

template<typename T>
AnyMap<T>::AnyMap(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new T*[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new T[width];
    }
}


template<>
AnyMap<bool>::AnyMap(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new bool*[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new bool[width];
    }
}

template<>
AnyMap<std::byte>::AnyMap(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new std::byte*[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new std::byte[width];
    }
}



template<typename T>
AnyMap<T>::AnyMap(int width, int height, T** map){
    this->width = width;
    this->height = height;
    this->map = map;
}


template<>
AnyMap<bool>::AnyMap(int width, int height, bool** map){
    this->width = width;
    this->height = height;
    this->map = map;
}

template<>
AnyMap<std::byte>::AnyMap(int width, int height, std::byte** map){
    this->width = width;
    this->height = height;
    this->map = map;
}

template<>
AnyMap<bool>::~AnyMap(){
    for(int i = 0;i < this->height; i++){
        delete [] this->map[i];
    }
    delete [] this->map;
}

template<>
AnyMap<std::byte>::~AnyMap(){
    for(int i = 0;i < this->height; i++){
        delete [] this->map[i];
    }
    delete [] this->map;
}

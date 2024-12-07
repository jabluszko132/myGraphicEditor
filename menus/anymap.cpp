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


template<typename T>
AnyMap<T>::AnyMap(int width, int height, T** map){
    this->width = width;
    this->height = height;
    this->map = map;
}


template<typename T>
AnyMap<T>::~AnyMap(){
    for(int i = 0;i < this->height; i++){
        delete [] this->map[i];
    }
    delete [] this->map;
}

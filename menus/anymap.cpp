#include "anymap.h"

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
    this->map = new T*[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new T[width];
        for(int j = 0; j < width; j++){
            this->map[i][j] = map[i][j];
        }
    }
}


template<typename T>
AnyMap<T>::~AnyMap(){
    for(int i = 0;i < this->height; i++){
        for(int j = 0;j < this->width; j++){
            delete this->map[i][j];
        }
        delete this->map[i];
    }
    delete this->map;
}

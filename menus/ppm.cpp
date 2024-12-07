#include "ppm.h"


PPM::PPM(int width, int height){
    this->width = width;
    this->height = height;
    this->map = new std::byte**[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new std::byte*[width];
        for(int j = 0; j < width; j++){
            this->map[i][j] = new std::byte[3];
        }
    }
}

PPM::PPM(int width, int height, std::byte*** map){
    this->width = width;
    this->height = height;
    this->map = map;
}

PPM::~PPM(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            delete [] this->map[i][j];
        }
        delete [] this->map[i];
    }
    delete [] this->map;
}



PPM PPM::fromFile(std::ifstream s){

    std::string buffer;
    int whitespacePos, prevWhitespacePos;

    std::string header;
    int width, height;
    while(std::getline(s, buffer) && buffer[0] == '#'); //comment lines begin with #
    std::getline(s,buffer); //skips the header
    while(std::getline(s, buffer) && buffer[0] == '#'); //comment lines begin with #

    whitespacePos = buffer.find(' ');
    height = std::stoi(buffer.substr(0, whitespacePos - 1));
    width = std::stoi(buffer.substr(buffer.find(whitespacePos + 1, buffer.length())));

    std::byte*** map = new std::byte**[height];
    int colorIter;
    for(int i = 0; i < height; i++){
        while(std::getline(s, buffer) && buffer[0] == '#'); //comment lines begin with #
        map[i] = new std::byte*[width];
        prevWhitespacePos = 0;
        colorIter = 0;
        for(int j = 0; j < width; j++){ //because last position terminates in \n not space
            for(int k = prevWhitespacePos + 1; k < buffer.length(); k++){
                if(buffer[k] == ' ' || buffer[k] == '\t' || buffer[k] == '\n'){
                    whitespacePos = k;
                    break;
                }
            }
            map[i][j][colorIter++] = (std::byte)(std::stoi(buffer.substr(prevWhitespacePos + 1, whitespacePos + 1)));
            prevWhitespacePos = whitespacePos;
        }
    }

    return PPM(width, height, map);
}

void PPM::save(std::ofstream s){
    s<<this->header<<'\n';
    s<<this->width<<' '<<this->height<<'\n';
    s<<(int)this->colorMaxVal;
    for(int i = 0;i < this->height; i++){
        for(int j = 0;j < this->width; j++){
            for(int k = 0; k < 3; k++){
                s<<(int)this->map[i][j][k]<<' ';
            }
        }
        s<<'\n';
    }
}

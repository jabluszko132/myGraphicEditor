#include "pbm.h"


PBM::PBM(int width, int height): base(width,height){}
PBM::PBM(int width, int height, bool** map): base(width, height, map) {}
PBM::~PBM(){}

void PBM::save(std::ifstream s){
    s<<this->header<<'\n';
    s<<this->width<<' '<<this->width<<'\n';
    for(int i = 0;i < this->height; i++){
        for(int j = 0;j < this->width; j++){
            s<<this->map[i][j]<<' ';
        }
        s<<'\n';
    }
}

static void PBM::fromFile(std::ofstream s){

    std::string buffer;
    int whitespacePos;

    std::string header;
    int width, height;

    while(std::getline(s,buffer) && buffer[0] == '#'); //comment lines begin with #
    std::getline(s,buffer); //skips the header
    while(std::getline(s,buffer) && buffer[0] == '#'); //comment lines begin with #

    whitespacePos = buffer.find(' ');
    height = std::stoi(buffer.substr(0,whitespacePos- 1));
    width = std::stoi(buffer.substr(buffer.find(whitespacePos+ 1, buffer.length)));

    bool** map = new bool*[height];

    for(int i = 0; i < height; i++){
        map[i] = new bool[width];
        whitespacePos = 1;
        for(int j = 0; j < width; j++){ //because last position terminates in \n not space
            map[i][j] = buffer[whitespacePos-1] == '1';
            whitespacePos+=2;
        }
    }

    return new PBM(width,height,map);
}
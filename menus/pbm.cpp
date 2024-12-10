#include "pbm.h"


PBM::PBM(int width, int height){
    this->width = width;
    this->height = height;
    this->map = new bool*[height];
    for(int i = 0; i < height; i++){
        this->map[i] = new bool[width];
    }
}
PBM::PBM(int width, int height, bool** map){
    this->width = width;
    this->height = height;
    this->map = map;
}

void PBM::save(QFile *file){
    QTextStream s{file};
    s<<this->header.c_str()<<'\n';
    s<<this->width<<' '<<this->height<<'\n';
    for(int i = 0;i < this->height; i++){
        for(int j = 0;j < this->width; j++){
            s<<this->map[i][j]<<' ';
        }
        s<<'\n';
    }
}

PBM PBM::fromFile(QFile *file){

    QTextStream s{file};

    QString buffer;
    int whitespacePos;

    QString header;
    int width, height;
    do{
        buffer = s.readLine();
    }while(buffer[0] == '#'); //comment lines begin with #
    s.readLine(); //skips the header
    do{
        buffer = s.readLine();
    }while(buffer[0] == '#'); //comment lines begin with #

    whitespacePos = buffer.indexOf(' ');
    height = buffer.left(whitespacePos).toInt();
    width = buffer.right(whitespacePos).toInt();

    bool** map = new bool*[height];

    for(int i = 0; i < height; i++){
        do{
            buffer = s.readLine();
        }while(buffer[0] == '#'); //comment lines begin with #
        map[i] = new bool[width];
        whitespacePos = 1;
        for(int j = 0; j < width; j++){ //because last position terminates in \n not space
            map[i][j] = buffer[whitespacePos-1] == '1';
            whitespacePos+=2;
        }
    }

    return PBM(width,height,map);
}

PBM::~PBM(){
    for(int i = 0;i < this->height; i++){
        delete [] this->map[i];
    }
    delete [] this->map;
}

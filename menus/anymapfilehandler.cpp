#include "anymapfilehandler.h"


inline void AnyMapFileHandler::appendFromSToWhiteOrCom(QTextStream &s, QString &pixmap, QString &buffer){
    buffer = s.read(1);
    if(s.atEnd()){
        return;
    }
    while(buffer[0].isPrint()){
        pixmap += buffer;
        buffer = s.read(1);
        if(s.atEnd()){
            return;
        }
        if(buffer[0] == '#'){
            s.readLine(1221);
            return;
        }
    }
}

QImage* AnyMapFileHandler::load(QFile *file){
    QTextStream s{file};
    QString pixmap = "";
    QString buffer;

    for(;;){
        appendFromSToWhiteOrCom(s,pixmap,buffer);
        if(s.atEnd()) break;
        pixmap += ' ';
    }

    QImage *img = new QImage();
    img->loadFromData((const uchar*)pixmap.toStdString().c_str());
    return img;
}

QImage* AnyMapFileHandler::newP1(int width, int height){
    QString pixmap = "P1";
    pixmap += std::to_string(width);
    pixmap += ' ';
    pixmap += std::to_string(height);
    pixmap += ' ';
    int ctr = 70 - pixmap.length();
    for(int i = 0; i < width * height; i++){
        pixmap += 0;
        if(--ctr > 0){
            pixmap += ' ';
            --ctr;
        }else{
            pixmap += '\n';
            ctr = 70;
        }
    }
    QImage *img = new QImage();
    img->loadFromData((const uchar*)pixmap.toStdString().c_str());
    return img;
}


QImage* AnyMapFileHandler::newP2(int width, int height){
    QString pixmap = "P2";
    pixmap += std::to_string(width);
    pixmap += ' ';
    pixmap += std::to_string(height);
    pixmap += " 255 ";
    int ctr = 70 - pixmap.length();
    for(int i = 0; i < width * height; i++){
        pixmap += 0;
        if(--ctr > 0){
            pixmap += ' ';
            --ctr;
        }else{
            pixmap += '\n';
            ctr = 70;
        }
    }
    QImage *img = new QImage();
    img->loadFromData((const uchar*)pixmap.toStdString().c_str());
    return img;
}


QImage* AnyMapFileHandler::newP3(int width, int height){
    QString pixmap = "P3";
    pixmap += std::to_string(width);
    pixmap += ' ';
    pixmap += std::to_string(height);
    pixmap += " 255 ";
    int ctr = 70 - pixmap.length();
    for(int i = 0; i < width * height; i++){
        pixmap += 0;
        if(--ctr > 0){
            pixmap += ' ';
            --ctr;
        }else{
            pixmap += '\n';
            ctr = 70;
        }
    }
    QImage *img = new QImage();
    img->loadFromData((const uchar*)pixmap.toStdString().c_str());
    return img;
}


QImage* AnyMapFileHandler::newP4(int width, int height){
    QImage *img = new QImage(width,height,QImage::Format_Mono);
    img->fill(0);
    return img;
}

QImage* AnyMapFileHandler::newP5(int width, int height){
    QString pixmap = "P5";
    pixmap += std::to_string(width);
    pixmap += ' ';
    pixmap += std::to_string(height);
    pixmap += " 255 ";
    int ctr = 70 - pixmap.length();
    int reqBytes = (int)(width / 8) * height;
    for(int i = 0; i < reqBytes; i++){
        pixmap += 0;
        if(--ctr > 0){
            pixmap += ' ';
            --ctr;
        }else{
            pixmap += '\n';
            ctr = 70;
        }
    }
    QImage *img = new QImage();
    img->loadFromData((const uchar*)pixmap.toStdString().c_str());
    return img;
}



QImage* AnyMapFileHandler::newP6(int width, int height){
    QImage *img = new QImage(width,height,QImage::Format_Indexed8);
    img->fill(0);
    return img;
}


#ifndef SIZE_H
#define SIZE_H

class Size {
    public:
    Size(unsigned width, unsigned height) : width(width), height(height){}
    unsigned width;
    unsigned height;
    int paddleSizeX = 20;
    int paddleSizeY = 80;
    int paddleStartY = (static_cast<int>(height) - paddleSizeY) / 2;
    int rightPadPosX = static_cast<int>(width) - paddleSizeX;
    int leftPadPosX = paddleSizeX;
    int midX = width / 2;
    int midY = height / 2;
};




#endif //SIZE_H

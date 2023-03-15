#ifndef BOARD_H
#define BOARD_H

#include <../RgbImage.h>
#include <GL/glut.h>
#include <fstream>

class Board{
    public:
        Board(int width, int heigth, const char* filename);
        ~Board();
        void loadTextureBoard();
        void drawBoard();

        int Heigth;
        int Width;
        const char *BOARD;
        GLuint TextureID;
};

#endif


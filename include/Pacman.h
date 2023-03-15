#ifndef PACMAN_H
#define PACMAN_H

#include "../RgbImage.h"
#include <GL/glut.h>
#include <iostream>
#include <fstream>

class Pacman {
    public:
        Pacman(int x, int y, int size, const char* filename);
        ~Pacman();
        void loadTexturePacman();
        void drawPacman();

        float pacmanX;
        float pacmanY;
        const char *PACMAN;
        GLuint TextureID;
};

#endif // PACMAN_H

#ifndef GHOST_H
#define GHOST_H

#include "../RgbImage.h"
#include <GL/glut.h>
#include <iostream>
#include <fstream>


class Ghost
{
    public:
        Ghost(int x, int y, int size, const char* filename);
        ~Ghost();
        void loadTextureGhost();
        void drawGhost();

        float GhostX;
        float GhostY;
        const char *GHOST;
        GLuint TextureID;
};

#endif // GHOST_H

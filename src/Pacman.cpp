#include "Pacman.h"
#include <GL/glut.h>
#include <iostream>
#include <fstream>
using namespace std;

Pacman::Pacman(int x, int y, int size, const char* filename){

    pacmanX = x;
    pacmanY = y;

    PACMAN = filename;
}

Pacman::~Pacman(){
    // Libera la memoria de la textura
    glDeleteTextures(1, &TextureID);
}

void Pacman::loadTexturePacman(){

    glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( PACMAN );

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &TextureID);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, TextureID);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

void Pacman::drawPacman(){

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, TextureID);
    glTranslatef(pacmanX,pacmanY,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(pacmanX - 40, pacmanY - 40, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(pacmanX - 40, pacmanY + 40, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(pacmanX + 40, pacmanY + 40, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(pacmanX + 40, pacmanY - 40, 0.0);
    glEnd();

    glPopMatrix();

    //cout << pacmanX << "," << pacmanY << endl;
}




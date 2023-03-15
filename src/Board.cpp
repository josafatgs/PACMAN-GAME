#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int width, int heigth, const char* filename) {

    BOARD = filename;

}

Board::~Board()
{
    glDeleteTextures(1, &TextureID);
}

void Board::loadTextureBoard(){

    glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( BOARD );

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

void Board::drawBoard(){

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, TextureID);
    glTranslatef(0,0,0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0, 0.0, 0.00);

    glTexCoord2f(0.0, 1.0);
    glVertex3f(1600.0, 0.00, 0.0);

    glTexCoord2f(1.0, 1.0);
    glVertex3f(1600.0, 1600.0, 0.0);

    glTexCoord2f(1.0, 0.0);
    glVertex3f( 0.0, 1600.00, 0.0);
    glEnd();
    glPopMatrix();

}



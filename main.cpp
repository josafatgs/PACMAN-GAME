#include <GL/glut.h>
#include <iostream>
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
using namespace std;

//Game Node
GLuint GameBoardMatrix[16][16] = {
                    2,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,
                    1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,
                    1,0,2,1,1,1,1,2,0,2,3,1,2,2,0,1,
                    1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,
                    1,0,3,1,1,1,0,1,0,1,3,2,0,3,1,2,
                    1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,
                    2,1,3,0,1,1,1,3,0,2,1,3,1,2,1,2,
                    0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,
                    2,1,3,1,1,1,1,4,1,3,1,3,1,2,0,1,
                    1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
                    3,1,2,0,2,1,0,2,1,2,0,3,1,2,0,1,
                    1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,
                    3,1,3,0,2,2,0,0,2,3,1,3,0,1,0,1,
                    1,0,3,1,4,3,1,1,2,0,0,1,0,3,1,2,
                    1,0,1,0,1,0,0,0,0,0,0,3,1,2,0,0,
                    2,1,2,0,2,1,1,1,1,1,1,2,0,0,0,0
};

// Ancho y alto de la ventana
const int WindowWidth = 800;
const int WindowHeight = 800;

//Archivos BMP
const char* GHOST = "Ghost.bmp";
const char* PACMAN = "Pacman.bmp";
const char* MAP = "PACMAP.bmp";

// Instancias del tablero y de Pacman
Board GameBoard(WindowWidth,WindowHeight,MAP);
Pacman PacmanChar(25, 25, 50, PACMAN);
Ghost GhostChar(100, 100, 50, GHOST);

void drawScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    //Draw Characteres
    PacmanChar.drawPacman();
    GhostChar.drawGhost();
    GameBoard.drawBoard();

    glFlush();
    glDisable(GL_TEXTURE_2D);
}


void keyboard(int key, int x, int y){
    switch (key) {
            case GLUT_KEY_UP:
                if (PacmanChar.pacmanY <= 25) {
                    PacmanChar.pacmanY = 25;
                } else{
                    PacmanChar.pacmanY -= 2.5;
                }
                break;
            case GLUT_KEY_DOWN:
                if (PacmanChar.pacmanY >=775) {
                    PacmanChar.pacmanY = 775;
                } else{
                    PacmanChar.pacmanY += 2.5;
                }
                break;
            case GLUT_KEY_LEFT:
                if (PacmanChar.pacmanX <= 25) {
                    PacmanChar.pacmanX = 25;
                } else {
                    PacmanChar.pacmanX -= 2.5;
                }
                break;
            case GLUT_KEY_RIGHT:
                if (PacmanChar.pacmanX >= 775) {
                    PacmanChar.pacmanX = 775;
                } else {
                    PacmanChar.pacmanX += 2.5;
                }

                break;
            case 27:
                exit(0);
                break;
            default:
                break;
    }
}

/*
void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WindowWidth, WindowHeight, 0, -1, 1);
  //gluOrtho2D(-800, 800,-800,800);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Inicializamos Texturas
    GameBoard.loadTextureBoard();
    PacmanChar.loadTexturePacman();
    GhostChar.loadTextureGhost();


}
*/

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1600, 1600, 0,-1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // Dibujar objetos aquí
    GameBoard.loadTextureBoard();
    PacmanChar.loadTexturePacman();
    GhostChar.loadTextureGhost();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // Inicializar la ventana de GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("PACMAN");

    // Inicializar OpenGL y el tablero de juego
    init();
    // Registrar las funciones de display y keyboard con GLUT
    glutDisplayFunc(drawScene); //Esta es una funcion que se llama cada vez que se debe actualizar la ventana
	glutIdleFunc(drawScene); //Es una funcion que espera las entradas de usurioa
	//glutReshapeFunc(resizeWindow); //
    glutSpecialFunc(keyboard);
    glutSpecialUpFunc(keyboard);

    // Iniciar el ciclo de eventos de GLUT
    glutMainLoop();

    return 0;
}

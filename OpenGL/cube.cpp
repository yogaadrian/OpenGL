#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>


void display();
void viewButtons();


double rotationY = 0;
double rotationX = 0;
double rotationZ = 0;
double rusuk = 0.2;
//static int scale = 1;

void drawCube(double scaleX,double scaleY, double scaleZ){
    glBegin(GL_POLYGON);
    //Vertices and colors Front orange
    glColor3f(1.0, 0.5, 0.0);     
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);     
    glVertex3f(rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);      
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);     
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);      

    glEnd();

    // Red side - BACK
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glEnd();

    // Green side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glEnd();

    // Blue side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);
    glEnd();

    // White side - TOP
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, rusuk + scaleY, rusuk + scaleZ);
    glEnd();

    // Yellow side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);
    glVertex3f(rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, rusuk + scaleZ);
    glVertex3f(-rusuk + scaleX, -rusuk + scaleY, -rusuk + scaleZ);
    glEnd();
}


void display()
{
 //Clear the screen and clear z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Reset transformations
    glLoadIdentity();

// Rotate when user changes rotate_x and rotate_y
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);
    for (int i = 1; i <3; i++ ){
        for (int j = 1; j <3; j++ ){
            for (int k = 1; k <3; k++ ){
                drawCube(i*rusuk,j*rusuk,k*rusuk);
            }
        }
    }

glFlush();
glutSwapBuffers();


}


void viewButtons(int button, int x, int y)
{
if (button == GLUT_KEY_RIGHT)
    rotationY += 5;

else if (button == GLUT_KEY_LEFT)
    rotationY -= 5;

else if (button == GLUT_KEY_UP)
    rotationX += 5;

else if (button == GLUT_KEY_DOWN)
    rotationX -= 5;


//update display
glutPostRedisplay();
}

void keyPress(unsigned char button, int x, int y)
{
    if (button == 'w')
        rotationZ += 5;

    else if (button == 'q')
        rotationZ -= 5;


    //update display
    glutPostRedisplay();
}

int main(int argc, char **argv) {

// init GLUT and create window
// init GLUT and create Window
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(100, 100);
glutInitWindowSize(720, 640);
glutCreateWindow("Cube");
glEnable(GL_DEPTH_TEST);

// register callbacks
glutDisplayFunc(display);
glutSpecialFunc(viewButtons);
glutKeyboardFunc(keyPress);
// enter GLUT event processing cycle
glutMainLoop();

return 1;
}
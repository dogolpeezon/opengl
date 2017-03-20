/*
 * model.c
 * Copyright 2017 dogol peezon <dogol@dogol-laptop>
 * 
 */
 
#include <GL/glut.h>
#include <cmath>
#include <map>

std::map< int, bool > keys;
void pressKey(int key, int xx, int yy)
{			
    keys[ key ] = true;
}
void relaseKey(int key, int x, int y)
{
    keys[ key ] = false;
}

float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
void update()
{
    const float angleStep = 0.5f;
    if( keys[ GLUT_KEY_LEFT  ] )    angle -= angleStep;
    if( keys[ GLUT_KEY_RIGHT ] )    angle += angleStep;

    const float moveStep = 0.5f;
    float move = 0.0f;
    if( keys[ GLUT_KEY_DOWN  ] )    move -= moveStep;
    if( keys[ GLUT_KEY_UP    ] )    move += moveStep;

    x += move * lx * 0.1f;
    z += move * lz * 0.1f;

    lx = sin(angle/75.0);
    lz = -cos(angle/75.0);
}

void drawSnowMan()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    glTranslatef(0.0f, 0.75f, 0.0f);
    glutSolidSphere(0.75f, 20, 20);

    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f, 20, 20);

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.5f, 0.10f, 0.18f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();

    glColor3f(1.0f, 0.5f, 0.5f);
    glutSolidCone(0.8f, 0.5f, 10, 2);
}

void renderScene(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    const double w = glutGet( GLUT_WINDOW_WIDTH );
    const double h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective(45.0f, w / h, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    glColor3f(0.9f, 0.9f, 0.9f);

    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f(100.0f, 0.0f, 100.0f);
    glVertex3f(100.0f, 0.0f, -100.0f);
    glEnd();

    for(int i = -3; i < 3; i++)
    {
        for(int j = -3; j < 3; j++)
        {
            glPushMatrix();
            glTranslatef(i*10.0,0, j*10.0);
            drawSnowMan();
            glPopMatrix();
        }
    }

    glutSwapBuffers();
}

void timer( int value )
{
    update();
    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(320,320);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Lighthouse 3D");

    glutDisplayFunc(renderScene);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(relaseKey);
    glutTimerFunc( 0, timer, 0 );

    glutMainLoop();

    return 1;
}


/*This is Ex 3-1 GL sample in the red book*/
#include <math.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>

static GLfloat red[3] = {1.0, 0.0, 0.0}, green[3] = {0.0, 1.0, 0.0}, blue[3] = {0.0, 0.0, 1.0};

struct rotate_cube{
	float cube_rotation;
}rot_x, rot_y;

void init(void)
{
	GLenum err = glewInit();
	if( GLEW_OK != err )
	{
		fprintf(stderr, "Error initializing GLEW: %s\n", glewGetErrorString(err));
	}
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(red);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(rot_x.cube_rotation, 0., 1., 0.);
	glRotatef(rot_y.cube_rotation, 1., 0., 0.);
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.5, 20.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0);
}

void  keyboard(unsigned char key, int x, int y)
{
	int i = 0;
	if(key == 27)
	{
		exit(0);
	}
	if(key == 'f')
	{
		glutFullScreen();
	}
    switch(key)
    {
		case 'w':
			break;
		case 's':
			break;
		case 'a':
			break;
		case 'd':
		break;
	}
	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	switch(key)	{
		case GLUT_KEY_UP:
			rot_y.cube_rotation++;
		break;
		case GLUT_KEY_DOWN:
			rot_y.cube_rotation--;
		break;
		case GLUT_KEY_LEFT:
			rot_x.cube_rotation--;
		break;
		case GLUT_KEY_RIGHT:
			rot_x.cube_rotation++;
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN){
			//select item
			glColor3fv(blue);              	
		}
		else{
			//try
		}
		break;
		case GLUT_RIGHT_BUTTON:
		if(state == GLUT_DOWN){
		}
		break;
	}
}

void motion(int x, int y)
{
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gl Red Book Ex 3-1");
	init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    //glutSetKeyRepeat(0);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

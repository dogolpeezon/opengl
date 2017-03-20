/*This is Ex 3-1 GL sample in the red book*/
#include <GL/freeglut.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	int r, g, b;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0);
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
}

void  keyboard(unsigned char key, int x, int y)
{
    switch(key){
		case 'r':
		break;
		case 'g':
		break;
		case 'b':
		break;
	}
	
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gl Red Book Ex 3-1");
	init();
    glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

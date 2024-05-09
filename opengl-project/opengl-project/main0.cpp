#include "GL\glut.h" 

#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 

#define M_PI 3.14 

GLuint theTorus;

/* afişare tor */
void torus(int numc, int numt)
{
	int i, j, k;
	double s, t, x, y, z, twopi;
	twopi = 2 * (double)M_PI;

	for (i = 0; i < numc; i++)
	{
		glBegin(GL_QUAD_STRIP);

		for (j = 0; j <= numt; j++)
		{
			for (k = 1; k >= 0; k--)
			{
				s = (i + k) % numc + 0.5;
				t = j % numt;
				x = (1 + .1*cos(s*twopi / numc))*cos(t*twopi / numt);
				y = (1 + .1*cos(s*twopi / numc))*sin(t*twopi / numt);
				z = .1 * sin(s * twopi / numc);
				glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
}

/* creează lista de afişare pentru tor */
void init(void)
{
	theTorus = glGenLists(1);
	glNewList(theTorus, GL_COMPILE);
	torus(8, 25);
	glEndList();
	glShadeModel(GL_FLAT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glCallList(theTorus);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

/* la apăsarea tastei 'x' - se roteşte în jurul axei x
   la apăsarea tastei 'y' - se roteşte în jurul axei y
   la apăsarea tastei 'i' - se poziŃioneaza torul în poziŃia originală
   */
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
	case 'X':
		glRotatef(30., 1.0, 0.0, 0.0);
		glutPostRedisplay();
		break;
	case 'y':
	case 'Y':
		glRotatef(30., 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 'i':
	case 'I':
		glLoadIdentity();
		gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInitWindowSize(200, 200);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("L12E0");
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
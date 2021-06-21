#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float ztran = 0.0f;
float ytran = 0.0f;
float xtran = 0.0f;
bool mouseDown = false;
int in_depth;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	in_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{

	if (in_depth) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glLoadIdentity();
	// mengatur sudut pandang mata ataukamera
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 0.0f, 1.0f, 0.0f);
	glRotatef(yrot, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, ztran);
	glTranslatef(0.0f, ytran, ztran);
	glTranslatef(xtran, 0.0f, 0.0f);
	glPushMatrix();

	// membuat object depan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(-10.f, 10.f, 10.f);
	glVertex3f(10.f, 10.f, 10.f);
	glVertex3f(10.f, -10.f, 10.f);
	glEnd();

	// membuat object belakang
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-10.f, -10.f, -10.f);
	glVertex3f(-10.f, 10.f, -10.f);
	glVertex3f(10.f, 10.f, -10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glEnd();

	// membuat object samping kanan
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(10.f, 10.f, 10.f);
	glVertex3f(10.f, -10.f, 10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glVertex3f(10.f, 10.f, -10.f);
	glEnd();

	// membuat object samping kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-10.f, 10.f, 10.f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(-10.f, -10.f, -10.f);
	glVertex3f(-10.f, 10.f, -10.f);
	glEnd();

	// membuat object diatas
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f(-10.f, 20.f, 10.f);
	glVertex3f(10.f, 10.f, 10.f);
	glVertex3f(10.f, 10.f, -10.f);
	glVertex3f(-10.f, 20.f, -10.f);
	glEnd();

	// membuat object bawah
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-10.f, -10.f, 10.f);
	glVertex3f(10.f, -10.f, 10.f);
	glVertex3f(10.f, -10.f, -10.f);
	glVertex3f(-10.f, -10.f, -10.f);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		cout << "W" << endl;
		ztran += 3.0f;
		break;
	case 'a':
	case 'A':
		if (xrot > -45 && xrot <= 45) {
			xtran += 3.0f;
			cout << "D +XTRAN" << endl;
		}
		if (xrot > 45 && xrot <= 135) {
			ztran += 3.0f;
			cout << "D +ZTRAN" << endl;
		}
		if (xrot > 135 && xrot <= 225) {
			xtran -= 3.0f;
			cout << "D -XTRAN" << endl;
		}
		if (xrot > 225 && xrot <= 315) {
			ztran -= 3.0f;
			cout << "D -ZTRAN" << endl;
		}
		break;
	case 'd':
	case 'D':
		if (xrot > -45 && xrot <= 45) {
			xtran -= 3.0f;
			cout << "D -XTRAN" << endl;
		}
		if (xrot > 45 && xrot <= 135) {
			ztran -= 3.0f;
			cout << "D -ZTRAN" << endl;
		}
		if (xrot > 135 && xrot <= 225) {
			xtran += 3.0f;
			cout << "D +XTRAN" << endl;
		}
		if (xrot > 225 && xrot <= 315) {
			ztran += 3.0f;
			cout << "D +ZTRAN" << endl;
		}
		break;
	case 's':
	case 'S':
		cout << "S" << endl;
		ztran -= 3.0f;
		break;



	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (in_depth)
		{
			in_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			in_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();

}

void mouse(int button, int state, int x, int y)

{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - xrot;
		ydiff = -y - yrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		xrot = x - xdiff;
		yrot = y + ydiff;
		if (xrot > 315) {
			xrot = xrot - 360;
		}
		cout << "X = "<< xrot << "  Y = " << yrot << endl;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0f, -5.0f, -150.0f);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Percobaan fungsi tikus");
	init();
	glutDisplayFunc(tampil);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

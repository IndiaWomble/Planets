//Planetary Motion

#include "Angel.h"

using namespace std;

vec2 newPosRed(0.5f, 0.5f);
vec2 newPosGreen(0.8f, 0.8f);
float angleRedSpeed = 0.5f;
float angleGreenSpeed = 0.1f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Sun
	float x, y;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 0.5f);
	glVertex2f(0.0f, 0.0f);
	for (double i = 0; i < 7.0f; i = i + 0.2f)
	{
		x = 0.0f + sin(i) * 0.3f;
		y = 0.0f + cos(i) * 0.3f;
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2fv(newPosRed);
	for (double i = 0; i < 7.0f; i = i + 0.2f)
	{
		x = newPosRed.x + sin(i) * 0.1f;
		y = newPosRed.y + cos(i) * 0.1f;
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2fv(newPosGreen);
	for (double i = 0; i < 7.0f; i = i + 0.2f)
	{
		x = newPosGreen.x + sin(i) * 0.1f;
		y = newPosGreen.y + cos(i) * 0.1f;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void timer(int state)
{
	vec2 posRed, posGreen;
	float angleRed = DegreesToRadians * angleRedSpeed;
	float angleGreen = DegreesToRadians * angleGreenSpeed;
	posRed.x = newPosRed.x * cos(angleRed) - newPosRed.y * sin(angleRed);
	posGreen.x = newPosGreen.x * cos(angleGreen) - newPosGreen.y * sin(angleGreen);
	posRed.y = newPosRed.x * sin(angleRed) + newPosRed.y * cos(angleRed);
	posGreen.y = newPosGreen.x * sin(angleGreen) + newPosGreen.y * cos(angleGreen);
	newPosRed = posRed;
	newPosGreen = posGreen;
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}

void myMouse(int key, int state, int x, int y)
{
	if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		angleRedSpeed = -angleRedSpeed;
		angleGreenSpeed = -angleGreenSpeed;
	}
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Planets");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(1, timer, 0);
	glutMouseFunc(myMouse);
	glutMainLoop();
	return 0;
}
#include <stdio.h>

#define NDEBUG  // 表示不使用debug的lib，使用release的lib，如果去除，将使用debug的lib  
#include <GL/glut.h>

void Initial(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Ztory's First OpenGL Program");
	glutDisplayFunc(&MyDisplay);
	//Initial();
	glutMainLoop();
	return 0;
}
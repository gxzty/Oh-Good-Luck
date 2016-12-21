/// 创建一个窗口,画一个正方形
#include <stdio.h>
#include <GL/glut.h>

void Initial(void);  // 初始化函数,这里初始化了glClearColor
void MyDisplay(void);  // 回调函数


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Ztory's First OpenGL Program");
	glutDisplayFunc(&MyDisplay);
	Initial();
	glutMainLoop();
	return 0;
}


void Initial(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

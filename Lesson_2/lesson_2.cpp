/// 画一个点
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "ogldev_math_3d.h"


GLuint VBO;

static void RenderScenceCB();  // 渲染回调函数
static void CreateVertexBuffer();  // 创建顶点缓冲器


int main(int argc, char ** argv) {
	// 初始化
	glutInit(&argc, argv);
	// 显示模式:双缓冲,RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// 窗口设置
	glutInitWindowSize(480, 320);      // 窗口尺寸
	glutInitWindowPosition(100, 100);  // 窗口位置
	glutCreateWindow("Lesson 02");

	// 开始渲染
	glutDisplayFunc(&RenderScenceCB);
	
	// 检查GLEW是否就绪,必须要在GLUT初始化之后!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	// 缓存清空后的颜色值
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// 创建顶点缓冲器
	CreateVertexBuffer();
	// 通知开始GLUT的内部循环
	glutMainLoop();
	return 0;

}


/*
* 渲染回调函数
*/

static void RenderScenceCB() {
	// 清空颜色缓存
	glClear(GL_COLOR_BUFFER_BIT);

	// 开启顶点属性
	glEnableVertexAttribArray(0);
	// 绑定GL_ARRAY_BUFFER缓冲器
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// 告诉管线怎样解析buffer中的数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// 开始绘制几何图形(绘制一个点)
	glDrawArrays(GL_POINTS, 0, 1);

	// 禁用定点数据
	glDisableVertexAttribArray(0);

	// 交换前后缓存
	glutSwapBuffers();
}
/*
* 创建顶点缓冲器
*/
static void CreateVertexBuffer() {
	// 创建含有一个顶点的顶点数组
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	// 创建缓冲器
	glGenBuffers(1, &VBO);
	// 绑定GLARRAY_BUFFER缓冲器
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// 绑定顶点数据
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

}

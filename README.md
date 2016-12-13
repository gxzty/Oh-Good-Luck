# Open-Good-Luck
OpenGL (Open Graphics Library)

1. 配置VS2013,使用cmake+VS编译freeglut3.0,使用vs编译glew2.0
2. OpenGL：
 * 是一个大状态机,注意上下文
 * 是C/S架构，GPU是服务器，CPU是客户端
3. lesson_1: 创建窗口,画正方形
 * Lens:
     * **glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);**
         * 设置初始化模式
         * 参数RGB,单/双缓冲,利用位运算,设计的真好
     * glutInitWindowPosition(100, 100) & glutInitWindowSize(400, 400)
         * 设置窗口初始位置以及大小
         * 参数(x,y)&(width,height)  // int
     * glutCreateWindow("Ztory's First OpenGL Program");
         * 创建窗口并设置标题
     * **glClearColor(1.0f, 1.0f, 1.0f, 1.0f);**
         * 设置颜色缓冲区默认颜色
         * 参数RGBA, 范围0.0f~1.0f
     * gluOrtho2D(0.0, 200.0, 0.0, 150.0);
         * 用来在投影矩阵中画矩形
         * 参数左,右,下,上,即左下为(0,0)
     * **glClear(GL_COLOR_BUFFER_BIT);**
         * 将XX缓冲设置为之前glClearColor的设置
         * 参数CL_(COLOR/DEPTH/ACCUM/STENCIL)_BUFFER_BIT  // 深度/累积/模版缓冲暂未涉及
     * glColor3f(1.0f, 0.0f, 0.0f);
         * 设置随后的颜色
         * 参数RGB,范围0.0f~1.0f
     * glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
         * 画一个正方形,中心点在窗口中心,左下角(-1,-1),右上角(1,1)
         * 参数(x1,y1,x2,y2)  // float
     * **glFlush();**
         * 强制刷新,把上边设置的东西强制刷新出来
         * 否则是存在缓冲区,等待各种指令将缓冲区填满才一次性发送到驱动程序里执行
 * 一五得五,二五一十,三五太难了:
     * glutInit(&argc, argv);  // 用于从command line传参
     * glutDisplayFunc(&MyDisplay);  // 设置渲染回调函数
     * glutMainLoop();  // 让上边的特定事件处于死循环中
4. lesson_2: 创建窗口,画点
 * Lens:
     * "math_3d.h"
         * 其中声明了一个Vector3f结构体，Vector3f(x, y, z)
     * **\#pragma comment(lib, "glew32d.lib")**
         * 将库glew32d.lib加入到本工程
     * GLenum res = glewInit();
         * 检查GLEW是否就绪，若就绪则glewInit会返回GLEW_OK
         * 若失败则输出错误信息
     * **glEnableVertexAttribArray(0);**
         * 开启顶点属性(Attribute),出于性能考虑,该属性默认都是关闭的
         * 个人理解为一个客户端连接到服务端的数据库的连接过程,只有这样才可以修改数据库
         * 所以结尾要跟上关闭数据库(顶点属性)的过程,即glDisableVertexAttribArray(0);
         * 参数是顶点的索引值(index)
         * 一定要在"glDraw*"系列函数之前
     * **glGenBuffers(1, &VBO);**
         * 生成1个缓冲区对象,并保存在VBO数组中
         * 参数是生成缓冲区对象数目以及用来存储缓冲区对象的数组
         * 生成的对象不保证是连续的整数,但是保证是之前没有用过的
         * 可以使用glDeleteBuffers(n,*buffer)来删除指定缓冲区的n个对象
     * glDrawArrays(GL_POINTS, 0, 1);
         * 从数组中渲染图元,此处使用的是GL_POINTS,还有别的很多可选参数
         * 参数图元类型,数组起始位置,顶点数量
         * 数组为之前glBindBuffer所绑定的缓冲区数组
     * glutSwapBuffers();
         * 对应之前设置的双缓存glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA),未使用双缓存则等于glFlush();
         * 交换前后缓存,即显示缓存区内容
         * 自带隐式glFlush(),即强制刷新
         * ***后续的OpenGL命令可以在调用glutSwapBuffers之后立即发出，但在缓冲区交换完成之前不会执行***
 * 一五得五,二五一十,三五太难了:
     * **glBindBuffer(GL_ARRAY_BUFFER, VBO);**  // 绑定一个缓冲区对象,GL_ARRAY_BUFFER指顶点属性(Vertex attributes)
     * **glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);**
     * **glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);**  // Vector3f Vertices[1];
5. lesson_3:创建窗口,画三角形
 * Lens:
     * glDrawArrays(GL_TRIANGLES, 0, 3);
         * 从数组中渲染图元,此处使用的是GL_TRIANGLES,还有别的很多可选参数
         * 参数图元类型,数组起始位置,顶点数量
         * 数组为之前glBindBuffer所绑定的缓冲区数组
# // TO BE CONTINUED

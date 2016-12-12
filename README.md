# Oh-Good-Luck
OpenGL (Open Graphics Library)

1. 配置VS2013,使用cmake+VS编译freeglut3.0,使用vs编译glew2.0
2. OpenGL是一个大状态机,注意上下文
3. lesson_1: 创建窗口,画正方形
 * Lens:
  * glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   * 设置初始化模式
   * 参数RGB,单/双缓冲,利用位运算,设计的真好
  * glutInitWindowPosition(100, 100) & glutInitWindowSize(400, 400)
   * 设置窗口初始位置以及大小
   * 参数(x,y)&(width,height)  // int
  * glutCreateWindow("Ztory's First OpenGL Program");
   * 创建窗口并设置标题
  * glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   * 设置颜色缓冲区
   * 参数RGBA, 范围0.0f~1.0f
  * gluOrtho2D(0.0, 200.0, 0.0, 150.0);
   * 用来在投影矩阵中画矩形
   * 参数左,右,下,上,即左下为(0,0)
  * glClear(GL_COLOR_BUFFER_BIT);
   * 将XX缓冲设置为之前glClearColor的设置
   * 参数CL_(COLOR/DEPTH/ACCUM/STENCIL)_BUFFER_BIT  // 深度/累积/模版缓冲暂未涉及
  * glColor3f(1.0f, 0.0f, 0.0f);
   * 设置随后的颜色
   * 参数RGB,范围0.0f~1.0f
  * glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
   * 画一个正方形,中心点在窗口中心,左下角(-1,-1),右上角(1,1)
   * 参数(x1,y1,x2,y2)  // float
  * glFlush();
   * 强制刷新,把上边设置的东西强制刷新出来
   * 否则是存在缓冲区,等待各种指令将缓冲区填满才一次性发送到驱动程序里执行
 * 一五得五,二五一十,三五太难了:
  * glutInit(&argc, argv);  // 用于从command line传参
  * glutDisplayFunc(&MyDisplay);  // 设置渲染回调函数
  * glutMainLoop();  // 让上边的特定事件处于死循环中
4. lesson_2: 创建窗口,画点
 * Lens:
  * #pragma comment(lib, "glew32d.lib")
   * 将库glew32d.lib加入到本工程
  * GLuint VBO;
   * 全局变量,顶点
   // TO BE CONTINUED
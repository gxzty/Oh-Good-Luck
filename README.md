# Oh-Good-Luck
OpenGL (Open Graphics Library)

1. ����VS2013,ʹ��cmake+VS����freeglut3.0,ʹ��vs����glew2.0
2. OpenGL��һ����״̬��,ע��������
3. lesson_1: ��������,��������
 * Lens:
  * glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   * ���ó�ʼ��ģʽ
   * ����RGB,��/˫����,����λ����,��Ƶ����
  * glutInitWindowPosition(100, 100) & glutInitWindowSize(400, 400)
   * ���ô��ڳ�ʼλ���Լ���С
   * ����(x,y)&(width,height)  // int
  * glutCreateWindow("Ztory's First OpenGL Program");
   * �������ڲ����ñ���
  * glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   * ������ɫ������
   * ����RGBA, ��Χ0.0f~1.0f
  * gluOrtho2D(0.0, 200.0, 0.0, 150.0);
   * ������ͶӰ�����л�����
   * ������,��,��,��,������Ϊ(0,0)
  * glClear(GL_COLOR_BUFFER_BIT);
   * ��XX��������Ϊ֮ǰglClearColor������
   * ����CL_(COLOR/DEPTH/ACCUM/STENCIL)_BUFFER_BIT  // ���/�ۻ�/ģ�滺����δ�漰
  * glColor3f(1.0f, 0.0f, 0.0f);
   * ����������ɫ
   * ����RGB,��Χ0.0f~1.0f
  * glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
   * ��һ��������,���ĵ��ڴ�������,���½�(-1,-1),���Ͻ�(1,1)
   * ����(x1,y1,x2,y2)  // float
  * glFlush();
   * ǿ��ˢ��,���ϱ����õĶ���ǿ��ˢ�³���
   * �����Ǵ��ڻ�����,�ȴ�����ָ�������������һ���Է��͵�����������ִ��
 * һ�����,����һʮ,����̫����:
  * glutInit(&argc, argv);  // ���ڴ�command line����
  * glutDisplayFunc(&MyDisplay);  // ������Ⱦ�ص�����
  * glutMainLoop();  // ���ϱߵ��ض��¼�������ѭ����
4. lesson_2: ��������,����
 * Lens:
  * #pragma comment(lib, "glew32d.lib")
   * ����glew32d.lib���뵽������
  * GLuint VBO;
   * ȫ�ֱ���,����
   // TO BE CONTINUED
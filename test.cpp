#include <windows.h>
#include "GL/glut.h"



  void display() 
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5,  0.5);
    glVertex2f(0.5,  0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
  }

inline int round (const float a) 
{ 
    return int (a + 0.5); 
}
void lineDDA (int x0, int y0, int xEnd, int yEnd) 
{ 
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
     float xIncrement, yIncrement, x = x0, y = y0;
    if (fabs (dx) > fabs (dy)) 
        steps = fabs (dx); 
    else 
        steps = fabs (dy); 
    xIncrement = float (dx) / float (steps); 
    yIncrement = float (dy) / float (steps);
    setPixel (round (x), round (y)); 
    for (k = 0; k < steps; k++) 
    { 
        x += xIncrement; 
        y += yIncrement; 
        setPixel (round (x), round (y)); 
    }
}

  void init() 
  {
    glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold

    glColor3f(0.314, 0.314, 0.000); // JMU Purple

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  }

  int main(int argc, char** argv) 
  {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
  }
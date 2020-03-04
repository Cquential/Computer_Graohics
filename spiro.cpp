#include<iostream>
#include <stdlib.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;

class Spirograph{
static GLfloat theta;
float Rg, rg, rhog , speed;
float r_C, g_C, b_C;

public:
   Spirograph()
   {
      theta = 0;
      Rg = 1;
      rg = 0.3;
      rhog = 0.3;
      speed = 0.0275;
      r_C = 1.0f;
      g_C = 1.0f;
      b_C = 1.0f;
   }
   void DrawSpiro()
   {
      float t = 0.0;
      float x = 0.0f, y = 0.0f , x1 = 0.0f, y1 = 0.0f;
      float R= Rg, r = rg, rho = rhog;

      r_C = (rand() % 100 + 10)*0.01;
      g_C = (rand() % 100 + 10)*0.01;
      b_C = (rand() % 100 + 10)*0.01;

      x1 = (R - r)*cos(r/R*t) + rho*cos(((R - r) / r)*t);
      y1 = (R - r)*sin(r/R*t) - rho*sin(((R - r) / r)*t);

      for (int i = 0; i < 10000; i++)
      {
         t = i * speed;
   
         x = (R - r)*cos(r/R*t) + rho*cos(((R - r) / r)*t);
         y = (R - r)*sin(r/R*t) - rho*sin(((R - r) / r)*t);

         glBegin(GL_LINE_LOOP);
            glColor3f(r_C, g_C, b_C);
            glVertex2f(x1, y1);
            glVertex2f(x , y);
         glEnd();
         glFlush();
   
         x1 = x;
         y1 = y;
      }
   }

   void display(void)
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      glRotatef(theta, 0.0, 0.0, 1.0);
      DrawSpiro();
      glutSwapBuffers();

      return ;
   }
};
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 800);
   glutCreateWindow("Spirograph");
   Spirograph obj;
   glutDisplayFunc(obj.display);
   glEnable(GL_DEPTH_TEST);  //Enable hidden surface removal
   glutMainLoop();
  
   exit(0);
}
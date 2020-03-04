#include <iostream>
#include <GL/glut.h>

using namespace std;

void ellipsePlotPoints (int xc, int yc, int x, int y);

int round (float a)
{
  return int (a + 0.5); 
}

void setPixel (GLint xCoord, GLint yCoord)
{
  glBegin (GL_POINTS);
  glVertex2i(xCoord, yCoord);
  glEnd ( );
}

void ellipseMidpoint (GLint xc, GLint yc, GLint a, GLint b)
{
   int p;
   int x = 0, y = b;
   int px = 0, py = (2 * (a * a)) * y;

   ellipsePlotPoints (xc, yc, x, y);
   p = round ((b * b) - ((a * a) * b) + (0.25 * (a * a)));
   while (px < py)
   {
      x++;
      px += (2 * (b * b));
      if (p < 0)
      {
         p += (b * b) + px;
      }
      else
      {
         y--;
         py -= (2 * (a * a));
         p += (b * b) + px - py;
      }
      ellipsePlotPoints (xc, yc, x, y);
   }

   p = round ((b * b) * (x+0.5) * (x+0.5) + (a * a) * (y-1) * (y-1) - (a * a) * (b * b));
   while (y > 0)
   {
      y--;
      py -= (2 * (a * a));
      if (p > 0)
      {
         p += (a * a) - py;
      }
      else
      {
         x++;
         px += (2 * (b * b));
         p += (a * a) - py + px;
      }
      ellipsePlotPoints (xc, yc, x, y);
   }
}

void display(void)
{
  glClearColor (1.0,1.0,1.0,0.0);
  gluOrtho2D (0.0,200.0,0.0,200.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  ellipseMidpoint(100, 100, 64, 36);
  glutSwapBuffers();
}

void ellipsePlotPoints (GLint xc, GLint yc, int x, int y)
{
   setPixel(xc + x, yc + y);
   setPixel(xc + x, yc - y);
   setPixel(xc - x, yc + y);
   setPixel(xc - x, yc - y);
}

int main(int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(100,60);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Ellipse");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
#include <GL/glut.h>
#include <cmath>
void init()
{
   glClearColor(0, 0, 0, 1);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0, 500, 0, 500);
}
void setPixel(int x, int y)
{
   glBegin(GL_POINTS);
   glVertex2i(x, y);
   glEnd();
   glFlush();
}
void dda(int x1, int y1, int x2, int y2)
{
   float dx = x2 - x1, dy = y2 - y1, steps;
   steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
   float xInc = dx / steps, yInc = dy / steps;
   float x = x1, y = y1;
   for (int i = 0; i <= steps; i++)
   {
      setPixel(round(x), round(y));
      x += xInc;
      y += yInc;
   }
}
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   dda(50, 50, 450, 400);
   glFlush();
}
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("DDA Line Drawing");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
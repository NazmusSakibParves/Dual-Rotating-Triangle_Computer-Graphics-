#include <stdio.h>

#include <GL/glut.h>

int GAngle=0;
void Display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glRotated(GAngle,0,1,0);

// Anti-Clockwise Winding

glBegin(GL_TRIANGLES);
glColor3f(1,0,0);
glVertex3f(-1,0,0);
glVertex3f(1,0,0);
glVertex3f(0,1,0);
glColor3f(0,1,0);
glVertex3f(-1,0,0.5);
glVertex3f(1,0,0.5);
glVertex3f(0,1,0.5);
glEnd();

GAngle = GAngle + 4;

glFlush();

glutSwapBuffers();

}

void Timer(int extra)
{
glutPostRedisplay();
glutTimerFunc(30,Timer,0);
}

int main(void)
{
// Init to double buffering

glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutCreateWindow("Dual Rotating Triangle");
glutDisplayFunc(Display);
glutTimerFunc(0,Timer,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1,1,-1,1,1,3);
glTranslated(0,0,-2);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}

#include <GL/glut.h>

float rt = 0.0f;

void init(int Width, int Height)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Values corrected to 1.0 (OpenGL expects values in range [0.0, 1.0])
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
}

float ballX = -0.5f;
float ballY = 0.0f;
float ballZ = 0.0f;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(rt, 0.0f, -8.0f); // Move scene along X-axis

    // Draw base polygon
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(0.2f, 1.0f, 0.0f);
        glVertex3f(1.0f, 0.4f, 0.0f);

        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, 0.0f, 0.0f);
    glEnd();

    // Draw first wheel
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(ballX, ballY, ballZ);
    glutSolidSphere(0.3, 20, 20);

    // Draw second wheel
    glTranslatef(1.5f, 0.0f, 0.0f);
    glutSolidSphere(0.3, 20, 20);

    rt += 0.001f;

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Changed to double buffering for animation
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Moving Vehicle");

    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);

    init(640, 480);
    glEnable(GL_DEPTH_TEST); // Enables depth testing for 3D rendering

    glutMainLoop();
    return 0;
}

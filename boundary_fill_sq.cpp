#include <iostream>
#include <GL/glut.h>

using namespace std;

// Initialize the OpenGL environment
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);   // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);        // 2D projection
}

// Recursive boundary fill algorithm (4-connected)
void boundaryFill(int x, int y, float* fillColor, float* boundaryColor) {
    float pixelColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixelColor);

    bool isBoundary = (pixelColor[0] == boundaryColor[0] &&
                       pixelColor[1] == boundaryColor[1] &&
                       pixelColor[2] == boundaryColor[2]);

    bool isFilled = (pixelColor[0] == fillColor[0] &&
                     pixelColor[1] == fillColor[1] &&
                     pixelColor[2] == fillColor[2]);

    if (!isBoundary && !isFilled) {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        // Recurse in 4 directions
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

// Mouse callback to trigger fill on click
void mouse(int button, int state, int x, int y) {
    y = 480 - y;  // Convert window to OpenGL coordinate
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float boundaryColor[] = {1.0, 0.0, 0.0};  // Red boundary
        float fillColor[] = {0.0, 0.0, 1.0};      // Blue fill
        boundaryFill(x, y, fillColor, boundaryColor);
    }
}

// Display callback to draw the shape
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  // Red boundary

    // Draw a rectangle as the boundary
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 400);
    glVertex2i(200, 400);
    glEnd();

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Boundary Fill Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

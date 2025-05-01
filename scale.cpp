#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> pntX, pntY;
int edges;
float scaleX, scaleY;

void drawOriginalPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0); // Red
    for (int i = 0; i < edges; i++) glVertex2i(pntX[i], pntY[i]);
    glEnd();
}

void drawScaledPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 1); // Blue
    for (int i = 0; i < edges; i++)
        glVertex2i(round(pntX[i] * scaleX), round(pntY[i] * scaleY));
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawOriginalPolygon();
    drawScaledPolygon();
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    cout << "Enter number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int x, y;
        cout << "Enter vertex " << i+1 << ": ";
        cin >> x >> y;
        pntX.push_back(x);
        pntY.push_back(y);
    }
    cout << "Enter scaling factors (sx sy): ";
    cin >> scaleX >> scaleY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Scaling");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> pntX, pntY;
int edges;
float angleDeg;

void drawOriginalPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0); // Red
    for (int i = 0; i < edges; i++) glVertex2i(pntX[i], pntY[i]);
    glEnd();
}

void drawRotatedPolygon() {
    float angleRad = angleDeg * 3.1416 / 180;
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 1); // Blue
    for (int i = 0; i < edges; i++) {
        int x = round(pntX[i] * cos(angleRad) - pntY[i] * sin(angleRad));
        int y = round(pntX[i] * sin(angleRad) + pntY[i] * cos(angleRad));
        glVertex2i(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawOriginalPolygon();
    drawRotatedPolygon();
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
    cout << "Enter rotation angle (in degrees): ";
    cin >> angleDeg;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rotation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

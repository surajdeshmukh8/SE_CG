#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> pntX, pntY;
int edges, transX, transY;

void drawOriginalPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0); // Red
    for (int i = 0; i < edges; i++) glVertex2i(pntX[i], pntY[i]);
    glEnd();
}

void drawTranslatedPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 1, 0); // Green
    for (int i = 0; i < edges; i++) glVertex2i(pntX[i] + transX, pntY[i] + transY);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawOriginalPolygon();
    drawTranslatedPolygon();
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
    cout << "Enter translation factors (tx ty): ";
    cin >> transX >> transY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

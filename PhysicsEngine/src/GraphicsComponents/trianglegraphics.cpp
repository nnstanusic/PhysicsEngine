#include "trianglegraphics.h"

TriangleGraphics::TriangleGraphics()
{

}

void TriangleGraphics::Draw()
{
    glBegin(GL_TRIANGLES);
           glColor3f(1, 0, 0);
           glVertex3f(0, 0, 0);
           glVertex3f(1, 0, 0);
           glVertex3f(0, 1, 0);
    glEnd();
}


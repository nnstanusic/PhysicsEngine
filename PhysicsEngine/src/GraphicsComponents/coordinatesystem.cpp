#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem()
{

}

void CoordinateSystem::Draw()
{

    //glLineWidth(3);
    glBegin(GL_LINES);
        glVertex3f(-12,0, -7);
        glVertex3f(-12,0,7);

        glVertex3f(-12,0, -7);
        glVertex3f(12,0,-7);

        glVertex3f(12,0, -7);
        glVertex3f(12,0,7);

        glVertex3f(12,0, 7);
        glVertex3f(-12,0,7);

        glVertex3f(-12,0, -7);
        glVertex3f(-12,40,-7);

        glVertex3f(12,0, 7);
        glVertex3f(12,40,7);

        glVertex3f(-12,0, 7);
        glVertex3f(-12,40,7);

        glVertex3f(12,0, -7);
        glVertex3f(12,40,-7);

    glEnd();
}

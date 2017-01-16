#include "particleeffect.h"

ParticleEffect::ParticleEffect()
{

}

void ParticleEffect::Draw()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0,1,0);
    glEnd();
}

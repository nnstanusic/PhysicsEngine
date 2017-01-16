
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "world.h"
#include "graphicsfactory.h"
#include "bsplajnline.h"
#include "followline.h"
#include "coordinatesystem.h"
#include <iostream>

#include <random>

World *world;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);


   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 60.0 };
   GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };
   GLfloat light_colour[] = {0.0, 1.0, 0.0};

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_colour);


   GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
   GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light1_position[] = { 0, 5.0, 0, 1.0 };

   GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

   glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
   glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

   glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0);
   glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
   glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 3.0);


   glEnable(GL_LIGHTING);

   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);

   glEnable(GL_DEPTH_TEST);
}


void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef (0.0, 0.0, -30.0);

    world->Update();

    glPopMatrix ();

    glFlush();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 55.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {

         }
         break;
      default:
         break;
   }
}
void keyboard(unsigned char key, int x, int y)
{

}

void timerfunc(int data)
{

    glutTimerFunc(16, timerfunc, 0);

    glutPostRedisplay();
}


void GameObjectInit(World* world)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-10,10);
    GameObject* x = new GameObject(std::make_unique<Transform>(),
                                   nullptr,
                                   std::make_unique<PhysicsComponent>(),
                                   std::make_unique<Sphere>() );


    x->GetPhysicsComponent()->AddRigidbody();
    x->GetPhysicsComponent()->AddCollider(new SphereCollider());
    x->GetTransformComponent()->Translate(glm::vec3(0,5,0));

    world->AddGameobject(x);

    for (int i = 0; i < 40; ++i)
    {
        x = new GameObject(std::make_unique<Transform>(),
                           nullptr,
                           std::make_unique<PhysicsComponent>(),
                           std::make_unique<Sphere>() );


        x->GetPhysicsComponent()->AddRigidbody();
        x->GetPhysicsComponent()->getRigidbody()->SetMass(50);
        x->GetPhysicsComponent()->AddCollider(new SphereCollider());
        x->GetTransformComponent()->Translate(
                    glm::vec3(distribution(generator),
                              5 * distribution(generator) + 100,
                              distribution(generator) / 2));

        world->AddGameobject(x);
    }

    x = new GameObject(std::make_unique<Transform>(),
                       nullptr,
                       nullptr,
                       std::make_unique<CoordinateSystem>() );


    x->GetTransformComponent()->Translate(glm::vec3(0,-6,0));
    world->AddGameobject(x);


}

void idle()
{



}

int main(int argc, char** argv)
{

    world = new World();
    GameObjectInit(world);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1200, 640);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, timerfunc, 0);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}

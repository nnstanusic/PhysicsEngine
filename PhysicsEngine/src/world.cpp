#include "world.h"

World::World()
{

}

void World::AddGameobject(GameObject *gameObject)
{

    objects_.push_back(gameObject);
    graphicsComponents_.push_back(gameObject->GetGraphicsComponent());
    inputComponents_.push_back(gameObject->GetInputComponent());
    physicsComponents_.push_back(gameObject->GetPhysicsComponent());

}

void World::Update()
{

    for(InputComponent* input : inputComponents_)
    {
        if(input)
            input->Update();
    }

    for(PhysicsComponent* physics : physicsComponents_)
    {
        if(physics)
        {
            //colision selection
            //TODO daj jarane uljepsaj ovo nemoj brute forceat
            for(PhysicsComponent* target : physicsComponents_)
            {
                if(target != physics)
                {
                    for(auto collider1 : physics->getColliders())
                    {
                        for(auto collider2 : target->getColliders())
                        {
                            auto collisionPoint = resolveCollision(collider1,
                                                                   collider2,
                                                     physics->getTransform(),
                                                     target->getTransform());
                            if(collisionPoint.first)
                            {
                                target->getRigidbody()
                                      ->Bounce(collisionPoint.second);
                            }
                        }
                    }

                }
            }
            //force manipulation

            //rotation


            physics->Update();
        }
    }

    for(GraphicsComponent* graphics : graphicsComponents_)
    {

        if(graphics)
        {
            glPushMatrix();
            graphics->Update();
            glPopMatrix();
        }
    }
}






std::pair<bool, glm::vec3>
    World::resolveCollision(Collider* coll1, Collider* coll2,
                            Transform* trans1, Transform* trans2 )
{



    if(typeid(*coll1) == typeid(SphereCollider))
    {
        if(typeid(*coll2) == typeid(SphereCollider))
        {

            return resolveCollision((SphereCollider*)coll1,
                                    (SphereCollider*)coll2,
                                    trans1, trans2);
        }
    }

    return {false, glm::vec3(0,0,0)} ;
}

std::pair<bool, glm::vec3>
    World::resolveCollision(SphereCollider *Coll, SphereCollider *Coll2,
                            Transform* trans1 , Transform* trans2)
{

    glm::vec3 coord1 = trans1->GetPosition() + Coll->getOffsetFromCentre();
    glm::vec3 coord2 = trans2->GetPosition() + Coll2->getOffsetFromCentre();

    float distance = glm::distance(coord1, coord2);

    bool isCollision = distance <= std::abs(Coll->radius + Coll2->radius);

    glm::vec3 collisionPoint = coord1 + 0.5f * distance *
                               (glm::normalize(coord2 - coord1));

    std:: cout<< std::endl;
    return {isCollision, collisionPoint};

}

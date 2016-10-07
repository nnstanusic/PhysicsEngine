#include "rigidbody.h"

Rigidbody::Rigidbody()
{

}

void Rigidbody::Init(Transform *transform)
{
    transform_ = transform;
}

void Rigidbody::Bounce(glm::vec3 pointOfCollision)
{


    float speed = glm::length(velocity);

    velocity = -speed * glm::normalize(pointOfCollision -
                                      transform_->GetPosition());

}


void Rigidbody::updateGravity()
{
    force.y = -mass * gravity;
}

void Rigidbody::airResistance()
{
    // fx += -1 * 0.5 * rho * C_d * A * vx * vx;
    force.x += -0.5 * airDensity * coeficientOfDrag * 0.003 *
                velocity.x * velocity.x;

    force.y += -0.5 * airDensity * coeficientOfDrag * 0.003 *
                velocity.y * velocity.y;

    force.z += -0.5 * airDensity * coeficientOfDrag * 0.003 *
                velocity.z * velocity.z;
}

void Rigidbody::updateAcceleration()
{
    acceleration.x = force.x / mass;
    acceleration.y = force.y/ mass;
    acceleration.z = force.z / mass;
}


void Rigidbody::updateVelocity()
{




    //verlet integration
    //dx = vx * dt + (0.5 * ax * dt * dt);


    transform_->Translate(velocity * deltaTime +
                          0.5f * acceleration * deltaTime * deltaTime);


    velocity += 0.5f * ((force / mass) + acceleration) * deltaTime;

}



void Rigidbody::Update()
{
    //forces
    updateGravity();
    airResistance();

    //acceleration
    updateAcceleration();

    //speed
    updateVelocity();

    //TODO
    //collision with fake world box
    if(transform_->GetPosition()[1] <= -4)
    {
        velocity.y *= bounciness;
        transform_->Translate(glm::vec3(0,-transform_->GetPosition()[1] -4,0));
        force.x /= 2;
        force.z /= 2;
    }

    if( transform_->GetPosition()[0] >= 3 )
    {
        velocity.x *= bounciness;
    }

    if( std::abs(transform_->GetPosition()[2]) > 0.5 )
    {
        //velocityX *= bounciness;
    }
}


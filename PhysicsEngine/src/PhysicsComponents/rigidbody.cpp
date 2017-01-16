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

    velocity = bounciness *speed * glm::normalize(pointOfCollision -
                                      transform_->GetPosition());



}

void Rigidbody::SetMass(float mass)
{
    this->mass = mass;
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


    if( std::abs(transform_->GetPosition()[0]) > 10)
    {
        float direction = transform_->GetPosition()[0];
        direction /= -10 * std::abs(direction);
        velocity.x *= bounciness;
        transform_->Translate(glm::vec3(direction,0,0));
        force.x *= bounciness;
    }

    if(transform_->GetPosition()[1] <= -4)
    {
        velocity *= -bounciness;
        velocity.y *= -1;
        transform_->Translate(glm::vec3(0,-transform_->GetPosition()[1] -4,0));

    }

    if( std::abs(transform_->GetPosition()[2]) > 5 )
    {
        velocity.z *= bounciness;
    }
}


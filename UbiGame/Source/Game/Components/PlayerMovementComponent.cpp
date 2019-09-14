#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <cmath>
#define PI 3.1415926535897

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
{

}

PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void PlayerMovementComponent::Update()
{
	__super::Update();

	//Grabs how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default the wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	
	//player Velocity is applied when we have some input (for the time being let's make it 10pixels a second)
	float playerVel = 100.f;

	acceleration.x = std::cos(angle * (PI / 180.0)) * speed;
	acceleration.y = std::sin(angle * (PI / 180.0)) * speed;
	velocity += acceleration;
	velocity /= drag;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		angle += turnSpeed;
		//wantedVel.x -= playerVel * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		angle -= turnSpeed;
		//wantedVel.x += playerVel * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed = forwardSpeed;
		//wantedVel.y -= playerVel * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed = -backwardSpeed;
		//wantedVel.y += playerVel * dt;
	}

	//Update the entity position with new velocity
	GetEntity()->SetPos(GetEntity()->GetPos() + (velocity * dt));
}

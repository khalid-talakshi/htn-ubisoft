#pragma once
#include "GameEngine\EntitySystem\Component.h"

#include <SFML/System/Vector2.hpp>

namespace Game
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:
		const float forwardSpeed = 2;
		const float backwardSpeed = 1.3;
		const float turnSpeed = 0.15;
		const float drag = .99;
		
		sf::Vector2f acceleration = sf::Vector2f(0.f, 0.f);;
		sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
		double speed = 0;
		double angle = 0;
	};
}

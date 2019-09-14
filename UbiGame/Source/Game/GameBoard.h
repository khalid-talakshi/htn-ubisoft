#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();


		void Update();
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();
		void CreateFlags();

		GameEngine::Entity team1_flag;
		GameEngine::Entity team2_flag;

		GameEngine::Entity player1_ship1;
		GameEngine::Entity player1_ship2;
		GameEngine::Entity player1_ship3;
		GameEngine::Entity player2_ship1;
		GameEngine::Entity player2_ship2;
		GameEngine::Entity player2_ship3;

		GameEngine::RenderComponent render_player1_ship1;
		GameEngine::RenderComponent render_player1_ship2;
		GameEngine::RenderComponent render_player1_ship3;

		GameEngine::RenderComponent render_player2_ship1;
		GameEngine::RenderComponent render_player2_ship2;
		GameEngine::RenderComponent render_player2_ship3;

		GameEngine::RenderComponent render_team1_flag;
		GameEngine::RenderComponent render_team2_flag;
	};
}
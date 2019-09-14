#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateFlags();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{

}

void GameBoard::CreatePlayer()
{
	//Initialize all the ships
	GameEngine::Entity* player1_ship1 = new GameEngine::Entity();
	GameEngine::Entity* player1_ship2 = new GameEngine::Entity();
	GameEngine::Entity* player1_ship3 = new GameEngine::Entity();
	GameEngine::Entity* player2_ship1 = new GameEngine::Entity();
	GameEngine::Entity* player2_ship2 = new GameEngine::Entity();
	GameEngine::Entity* player2_ship3 = new GameEngine::Entity();

	//Initalize all the entities in the gameboard
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player1_ship1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player1_ship2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player1_ship3);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player2_ship1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player2_ship2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player2_ship3);

	//Initialize array of ships
	GameEngine::Entity* player1_ships[3] = { player1_ship1, player1_ship2, player1_ship3 };
	GameEngine::Entity* player2_ships[3] = { player2_ship1, player2_ship2, player2_ship3 };

	//Add render components
	GameEngine::RenderComponent* render_player1_ship1 = static_cast<GameEngine::RenderComponent*>(player1_ship1->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_player1_ship2 = static_cast<GameEngine::RenderComponent*>(player1_ship2->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_player1_ship3 = static_cast<GameEngine::RenderComponent*>(player1_ship3->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_player2_ship1 = static_cast<GameEngine::RenderComponent*>(player2_ship1->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_player2_ship2 = static_cast<GameEngine::RenderComponent*>(player2_ship2->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_player2_ship3 = static_cast<GameEngine::RenderComponent*>(player2_ship3->AddComponent<GameEngine::RenderComponent>());

	// Set Ship Positions
	player1_ship1->SetPos(sf::Vector2f(120.f, 100.f));
	player1_ship2->SetPos(sf::Vector2f(240.f, 100.f));
	player1_ship3->SetPos(sf::Vector2f(360.f, 100.f));

	player2_ship1->SetPos(sf::Vector2f(120.f, 350.f));
	player2_ship2->SetPos(sf::Vector2f(240.f, 350.f));
	player2_ship3->SetPos(sf::Vector2f(360.f, 350.f));

	// Set Ship sizes
	for (int i = 0; i < 3; i++) {
		player1_ships[i]->SetSize(sf::Vector2f(20.f, 20.f));
		player2_ships[i]->SetSize(sf::Vector2f(20.f, 20.f));
	}
}

void GameBoard::CreateFlags() {
	// Initialize the flags
	GameEngine::Entity* team1_flag = new GameEngine::Entity();
	GameEngine::Entity* team2_flag = new GameEngine::Entity();

	// Initalize flags on the board

	GameEngine::GameEngineMain::GetInstance()->AddEntity(team1_flag);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(team2_flag);

	// Add Render Components
	GameEngine::RenderComponent* render_team1_flag = static_cast<GameEngine::RenderComponent*>(team1_flag->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_team2_flag = static_cast<GameEngine::RenderComponent*>(team2_flag->AddComponent<GameEngine::RenderComponent>());

	// Set flag positions
	team1_flag->SetPos(sf::Vector2f(240.f, 50.f));
	team2_flag->SetPos(sf::Vector2f(240.f, 400.f));

	// Set flag size
	team1_flag->SetSize(sf::Vector2f(10.f, 10.f));
	team2_flag->SetSize(sf::Vector2f(10.f, 10.f));
}
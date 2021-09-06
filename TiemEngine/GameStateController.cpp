#include "GameStateController.h"

GameStateController::GameStateController()
{
	// set the initial game state
	GameData::GetInstance()->gGameStateInit =
	GameData::GetInstance()->gGameStateCurr =
	GameData::GetInstance()->gGameStatePrev =
	GameData::GetInstance()->gGameStateNext = GameState::GS_NONE;
}

void GameStateController::Init(GameState gameStateInit)
{
	// set the initial game state
	GameData::GetInstance()->gGameStateInit = gameStateInit;

	// reset the current, previoud and next game
	GameData::GetInstance()->gGameStateCurr =
	GameData::GetInstance()->gGameStatePrev =
	GameData::GetInstance()->gGameStateNext = GameData::GetInstance()->gGameStateInit;

	// call the update to set up level class
	Update();
}

void GameStateController::Update()
{
	if ((GameData::GetInstance()->gGameStateCurr == GameState::GS_RESTART) || (GameData::GetInstance()->gGameStateCurr == GameState::GS_QUIT))
	{
		return;
	}

	switch (GameData::GetInstance()->gGameStateCurr)
	{
		case GameState::GS_LEVEL1:
			currentLevel = new Level();
			break;
		case GameState::GS_LEVEL2:
			currentLevel = new LevelTest();
			break;
		case GameState::GS_LEVEL3:
			currentLevel = new LevelTest2();
			break;
		default:
			cout << "gGameStateCurr : invalid state!!" << endl;
			exit(1);
	}
}
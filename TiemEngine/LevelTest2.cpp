#include "LevelTest2.h"

void LevelTest2::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void LevelTest2::LevelInit()
{
	GameObject * obj = new GameObject();
	obj->SetColor(0.0, 1.0, 0.0);
	objectsList.push_back(obj);

	player = obj;

	GameObject * obj2 = new GameObject();
	obj2->SetColor(1.0, 0.0, 0.0);
	obj2->SetPosition(glm::vec3(2.0f, 2.0f, 0.0f));
	objectsList.push_back(obj2);

	GameObject * obj3 = new GameObject();
	obj3->SetColor(0.0, 0.0, 1.0);
	obj3->SetPosition(glm::vec3(-2.0f, -2.0f, 0.0f));
	objectsList.push_back(obj3);

	//cout << "Init Level" << endl;
}

void LevelTest2::LevelUpdate()
{
	//cout << "Update Level" << endl;
	//cout << player->GetPosition().x << " " << player->GetPosition().y << endl;
		//for (int j = 0; j < objectsList.size(); j++)
		//{
		//	DrawableObject* obj1 = player;
		//	DrawableObject* obj2 = objectsList.at(j);

		//	if (obj1 == obj2)
		//		continue;

		//	float r = 1.0f;
		//	glm::vec3 c = obj1->GetPosition();
		//	glm::vec3 t = obj2->GetPosition();

		//	float dis = sqrt((t.x - c.x)*(t.x - c.x) - (t.y - c.y) * (t.y - c.y));
		//	cout << c.x << endl;
		//	cout << c.y << endl;
		//	float overlap = dis - r;
		//	if (dis < r)
		//	{
		//		//obj2->SetPosition(glm::vec3(cx - (dis * (cx - tx)), cy - (dis * (cy - ty)), 0));
		//		//obj2->SetPosition(glm::vec3(t.x - (overlap * (t.x - c.x))/dis, t.y - (overlap * (t.y - c.y))/dis, 0));
		//	}
		//}
		//
	
}

void LevelTest2::LevelDraw()
{
	GameEngine::GetInstance()->Render(objectsList);
	//cout << "Draw Level" << endl;
}

void LevelTest2::LevelFree()
{
	for (DrawableObject* obj : objectsList) {
		delete obj;
	}
	objectsList.clear();
	//cout << "Free Level" << endl;
}

void LevelTest2::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void LevelTest2::HandleKey(char key)
{

	switch (key)
	{
	case 'w': player->Translate(glm::vec3(0, 0.1, 0)); break;
	case 's': player->Translate(glm::vec3(0, -0.1, 0)); break;
	case 'a': player->Translate(glm::vec3(-0.1, 0, 0)); break;
	case 'd': player->Translate(glm::vec3(0.1, 0, 0)); break;
	case 'q': GameData::GetInstance()->gGameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameData::GetInstance()->gGameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameData::GetInstance()->gGameStateNext = GameState::GS_LEVEL1; ; break;
	}
}

void LevelTest2::HandleMouse(int type, int x, int y)
{
	float realX, realY;

	// Calculate Real X Y 
	realX = x;
	realY = y;


	player->SetPosition(glm::vec3(realX, realY, 0));
}
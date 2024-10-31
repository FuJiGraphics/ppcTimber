#include "stdafx.h"
#include "ChtSeletionScene.h"
#include "Player.h"
#include "Player2.h"
#include "GameMgr.h"

ChtSeletionScene::ChtSeletionScene() : Scene(SceneIds::ChtSeletion)
{
}

void ChtSeletionScene::Init()
{
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	Cht1 = AddGo(new SpriteGo("graphics/player.png"));
	Cht2 = AddGo(new SpriteGo("graphics/player2.png"));


	Cht1->sortingLayer = SortingLayers::Foreground;
	Cht1->SetOrigin(Origins::MR);
	Cht1->SetPosition({ 1920 / 2-300, 1080 / 2 });
	
	Cht2->sortingLayer = SortingLayers::Foreground;
	Cht2->SetOrigin(Origins::ML);
	Cht2->SetPosition({ 1920 / 2+300, 1080 / 2 });


	Scene::Init();
}

void ChtSeletionScene::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/player2.png");
	Scene::Enter();
}

void ChtSeletionScene::Exit()
{

	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/player.png");
	TEXTURE_MGR.Unload("graphics/player2.png");
}

void ChtSeletionScene::Update(float dt)
{
	Scene::Update(dt);

	
	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		GameMgr::SetUsers(play1,play2);
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			SCENE_MGR.ChangeScene(SceneIds::Dev2);
		}
		
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		GameMgr::SetUsers(play2,play1);
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			SCENE_MGR.ChangeScene(SceneIds::Dev2);
		}
	}
}



#include "stdafx.h"
#include "SoloSltScene.h"
#include "GameMgr.h"
#include "PlayerModel.h"

SoloSltScene::SoloSltScene() : Scene(SceneIds::SoloSeletion)
{
}

void SoloSltScene::Init()
{
	
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	Cht1 = AddGo(new SpriteGo("graphics/player.png"));
	Cht2 = AddGo(new PlayerModel());
	Cht2->SetPalyerTexturId("graphics/player2.png");

	Cht1->sortingLayer = SortingLayers::Foreground;
	Cht1->SetOrigin(Origins::MR);
	Cht1->SetPosition({ 1920 / 2 - 300, 1080 / 2 });
	Cht1->SetScale({ -1.0f, 1.0f });

	Cht2->sortingLayer = SortingLayers::Foreground;
	Cht2->SetOrigin(Origins::ML);
	Cht2->SetPosition({ 1920 / 2 + 450, 1080 / 2 - 230 }); 
	Scene::Init();

}

void SoloSltScene::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/player2.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void SoloSltScene::Exit()
{
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/player.png");
	TEXTURE_MGR.Unload("graphics/player2.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
}



void SoloSltScene::Update(float dt)
{
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		 GameMgr::playTexId = "graphics/player.png";
		 SCENE_MGR.ChangeScene(SceneIds::Dev1);
		
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		GameMgr::playTexId = "graphics/player2.png";
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}

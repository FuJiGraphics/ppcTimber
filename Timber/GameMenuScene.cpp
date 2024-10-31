#include "stdafx.h"
#include "GameMenuScene.h"

GameMenuScene::GameMenuScene() : Scene(SceneIds::GameMenu)
{
}

void GameMenuScene::Init()
{
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	titleText = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Title"));
	titleText->text.setCharacterSize(200);
	titleText->text.setFillColor(sf::Color::White);
	titleText->SetOrigin(Origins::BC);
	titleText->SetPosition({ 1920 / 2, 400 });
	titleText->text.setString("TIMBER!!");

	solomodeText = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "solomode"));
	solomodeText->text.setCharacterSize(80);
	solomodeText->text.setFillColor(sf::Color::White);
	solomodeText->SetOrigin(Origins::TC);
	solomodeText->SetPosition({ 1920 / 2,  500 });
	solomodeText->text.setString("1. SOLO MODE!!");

	friendmodeText = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "friendmode"));
	friendmodeText->text.setCharacterSize(80);
	friendmodeText->text.setFillColor(sf::Color::White);
	friendmodeText->SetOrigin(Origins::TC);
	friendmodeText->SetPosition({ 1920 / 2,  600 });
	friendmodeText->text.setString("2. FRIEND MODE!!");



	Scene::Init();


}

void GameMenuScene::Enter()
{
	
	TEXTURE_MGR.Load("graphics/background.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void GameMenuScene::Exit()
{
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
}

void GameMenuScene::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		SCENE_MGR.ChangeScene(SceneIds::SoloSeletion);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
}

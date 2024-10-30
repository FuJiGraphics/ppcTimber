#include "stdafx.h"
#include "TitleScene.h"

TitleScene::TitleScene() :Scene(SceneIds::Title)
{
}

void TitleScene::Init()
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

	titleMsgText = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Title Messege"));
	titleMsgText->text.setCharacterSize(80);
	titleMsgText->text.setFillColor(sf::Color::White);
	titleMsgText->SetOrigin(Origins::TC);
	titleMsgText->SetPosition({ 1920 / 2, 500 });
	titleMsgText->text.setString("Press Space to GameMenu");

	Scene::Init();

}

void TitleScene::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void TitleScene::Exit()
{

	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
}

void TitleScene::Update(float dt)
{
	Scene::Update(dt);


	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}

}

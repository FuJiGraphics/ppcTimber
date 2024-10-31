#include "stdafx.h"
#include "TitleScene.h"
#include "CloudGo.h"
TitleScene::TitleScene() :Scene(SceneIds::Title)
{
}

void TitleScene::Init()
{
	GameObject* obj = AddGo(new SpriteGo("graphics/file.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });


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
	TEXTURE_MGR.Load("graphics/file.png");
	TEXTURE_MGR.Load("graphics/cloud.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void TitleScene::Exit()
{

	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/file.png");
	TEXTURE_MGR.Unload("graphics/cloud.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
}

void TitleScene::Update(float dt)
{
	Scene::Update(dt);


	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::GameMenu);
	}

}

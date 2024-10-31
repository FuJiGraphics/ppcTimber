#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "TitleScene.h"
#include "GameMenuScene.h"
#include "ChtSeletionScene.h"
#include "SoloSltScene.h"
void SceneMgr::Init()
{
	scenes.push_back(new TitleScene());
	scenes.push_back(new GameMenuScene());
	scenes.push_back(new ChtSeletionScene());
	scenes.push_back(new SoloSltScene());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
	if (nextScene == SceneIds::Dev1)
	{
		SceneDev1* newDev1 = new SceneDev1();
		newDev1->Init();
		scenes.push_back(newDev1);
	}
	if (nextScene == SceneIds::Dev2)
	{
		SceneDev2* newDev2 = new SceneDev2();
		newDev2->Init();
		scenes.push_back(new SceneDev2());
	}
}

void SceneMgr::LateUpdate(float dt)
{
	scenes[(int)currentScene]->LateUpdate(dt);
}

void SceneMgr::OnPreDraw()
{
	scenes[(int)currentScene]->OnPreDraw();
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	OnPreDraw();
	scenes[(int)currentScene]->Draw(window);
	OnPostDraw();
}

void SceneMgr::OnPostDraw()
{
	scenes[(int)currentScene]->OnPostDraw();
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}
}

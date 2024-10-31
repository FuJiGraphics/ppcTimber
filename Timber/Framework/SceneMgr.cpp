#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"


void SceneMgr::Init()
{
	sceneFrameBuffer1.create(1920, 1080);
	sceneFrameBuffer2.create(1920, 1080);

	scenes.push_back(new SceneDev1());	
	scenes.push_back(new SceneDev2());

	camera1.setCenter(1920.f, 1080.f * 0.5f);
	camera2.setCenter(0.0f, 1080.f * 0.5f);
	camera1.setSize({ 1920.f * 2.0f, 1080.f });
	camera2.setSize({ 1920.f * 2.0f, 1080.f });
	camera1.setViewport({ 0.0f, 0.0f, 1.0f, 1.0f });
	camera2.setViewport({ 0.0f, 0.0f, 1.0f, 1.0f });

	for (auto scene : scenes)
	{
		scene->Init();
	}
	scenes[(int)SceneIds::Dev1]->Enter();
	scenes[(int)SceneIds::Dev2]->Enter();
	sceneFrameBuffer1.clear(sf::Color::Red);
	sceneFrameBuffer2.clear(sf::Color::Red);
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

void SceneMgr::Update(float dt)
{
	scenes[(int)SceneIds::Dev1]->Update(dt);
	scenes[(int)SceneIds::Dev2]->Update(dt);

	// 결과 처리
}

void SceneMgr::LateUpdate(float dt)
{
	scenes[(int)SceneIds::Dev1]->LateUpdate(dt);
	scenes[(int)SceneIds::Dev2]->LateUpdate(dt);
}

void SceneMgr::OnPreDraw()
{
	scenes[(int)SceneIds::Dev1]->OnPreDraw();
	scenes[(int)SceneIds::Dev2]->OnPreDraw();
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	sceneFrameBuffer1.clear(sf::Color::Red);
	sceneFrameBuffer2.clear(sf::Color::Red);
	OnPreDraw();
	scenes[(int)SceneIds::Dev1]->Draw(sceneFrameBuffer1);
	scenes[(int)SceneIds::Dev2]->Draw(sceneFrameBuffer2);
	OnPostDraw();
	sceneFrameBuffer1.display();
	sceneFrameBuffer2.display();
	
	window.clear();

	renderer.setTexture(sceneFrameBuffer1.getTexture());
	window.setView(camera1);
	window.draw(renderer);

	renderer.setTexture(sceneFrameBuffer2.getTexture());
	window.setView(camera2);
	window.draw(renderer);
}

void SceneMgr::OnPostDraw()
{
	scenes[(int)SceneIds::Dev1]->OnPostDraw();
	scenes[(int)SceneIds::Dev2]->OnPostDraw();
}

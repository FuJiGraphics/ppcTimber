#pragma once
#include "Framework/Scene.h"
class GameObject;
class Player;
class Player2;
class ChtSeletionScene : public Scene
{
protected:
	GameObject* Cht1;
	GameObject* Cht2;

	TextGo* selet1;
	TextGo* selet2;


public:
	ChtSeletionScene();
	virtual ~ChtSeletionScene() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;


	void Update(float dt) override;



};


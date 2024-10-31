#pragma once
#include "Framework/Scene.h"
class Player;
class Player2;
class ChtSeletionScene : public Scene
{
protected:
	Player* Cht1;
	Player* Cht2;

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


#pragma once
#include "Framework/Scene.h"
class GameObject;
class TextGo;
class Player;
class SoloSltScene : public Scene
{
protected:
	GameObject* Cht1;
	GameObject* Cht2;

	TextGo* selet1;
	std::string p1texId;
	

	Charetor charetor = Charetor::None; 
public:
	SoloSltScene();
	virtual ~SoloSltScene() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
};


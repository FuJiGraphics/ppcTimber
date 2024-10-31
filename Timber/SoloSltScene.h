#pragma once
#include "Framework/Scene.h"
class SpriteGo;
class TextGo;
class PlayerModel;
class SoloSltScene : public Scene
{
protected:
	SpriteGo* Cht1;
	PlayerModel* Cht2;

	TextGo* selet1;
	std::string p1texId;
	
public:
	SoloSltScene();
	virtual ~SoloSltScene() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
};


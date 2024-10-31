#pragma once
#include "Framework/Scene.h"
class TextGo;

class GameMenuScene : public Scene
{
protected:
	TextGo* titleText;
	TextGo* solomodeText;
	TextGo* friendmodeText;
	sf::RectangleShape menuShape;

public:
	GameMenuScene();
	virtual ~GameMenuScene() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};


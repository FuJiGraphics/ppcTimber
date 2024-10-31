#pragma once
#include "Framework/Scene.h"

class TextGo;


class TitleScene : public Scene
{
protected:
	TextGo* titleMsgText;
public:
	TitleScene();
	virtual ~TitleScene() = default;
	

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};


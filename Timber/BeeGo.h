#pragma once
#include "Framework/SpriteGo.h"

class BeeGo : public SpriteGo
{
protected:
	float speed = 100.f;
	Sides dir = Sides::Left;
	double elap = 0.0;

	fz::Anim animIdleR;
	fz::Anim animIdleL;

public:
	BeeGo(const std::string& texId, const std::string& name = "");
	~BeeGo() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& scale) override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetSpeed(float speed);
	void SetDirection(Sides side);
};


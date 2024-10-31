#pragma once
#include "Framework/GameObject.h"

class SceneDev1;

class BeeHive : public GameObject
{
protected:
	std::string		name;
	std::string		texIdBeeHive = "graphics/Stup.png";
	std::string		texIdBeeHiveDead = "graphics/StupDead.png";
	sf::Sprite		spriteIdle;
	sf::Sprite		spriteDead;
	Sides			side = Sides::Right;
	bool			isAlive = true;
	bool			isExploded = false;

	sf::Vector2f	gravity = { 0.f, 1000.f };
	sf::Vector2f	velocity;
	double			timer = 0.0;
	double			duration = 5.0;

public:
	BeeHive(const std::string& name = "");
	virtual ~BeeHive() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& scale) override;

	sf::Vector2f GetPosition() const;

	bool IsExploded();
	void Init() override;

	void Update(float dt) override;
	void Reset() override;
	void Draw(sf::RenderTexture& render)  override;
};


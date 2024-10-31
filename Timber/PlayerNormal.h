#pragma once
#include "Player.h"

class PlayerNormal : public Player
{
private:
	sf::Sprite sprite;

public:
	PlayerNormal(const std::string& texPath);
	virtual Sides GetSide() const { return side; }
	virtual void OnDie();

	void SetPalyerTexturId(const std::string& id);
	std::string GetPlayerTexturId() { return texIdPlayer; }

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& scale) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset()  override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window)  override;

	void SetSceneGame(SceneDev1* scene);
};


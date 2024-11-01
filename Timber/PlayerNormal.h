#pragma once
#include "Player.h"

class PlayerNormal : public Player
{
private:
	sf::Sprite spritePlayer;
	sf::Sprite spriteAxe;
	sf::Sprite spriteRip;

	sf::Sound sfxChop;
	std::string sbIdChop = "audio/chop.wav";

	std::string texIdAxe = "graphics/axe.png";
	std::string texIdRip = "graphics/rip.png";

	Sides side = Sides::Right;
	sf::Vector2f localPosPlayer[3] = { { -200.f, 0.f },  { 200.f, 0.f },  { 0.f, 0.f } };
	sf::Vector2f localPosAxe = { 0.f, 150.f };
	sf::Vector2f localPosRip = { 0.f, 0.f };


public:
	PlayerNormal(const std::string& texPath);
	virtual Sides GetSide() const { return side; }
	void SetSide(Sides s);
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


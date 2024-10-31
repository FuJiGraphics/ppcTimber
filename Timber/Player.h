#pragma once
#include "Framework/GameObject.h"

class SceneDev1;

enum class PlayerId
{
	Player1,
	Player2,
};

class Player : public GameObject
{


protected:
	sf::Sound sfxChop;

	fz::Anim animIdle;
	fz::Anim animAttack;
	fz::Anim animFinishMove;
	fz::Anim animTransform;
	fz::Anim animEnergyBeam;
	
	sf::Sprite spriteDie;
	std::string sbIdChop = "sound/chop.wav";
	std::string texIdPlayer = "graphics/player2.png";

	Sides side = Sides::Right;

	sf::Vector2f originAxe = { -65.f, 0.f };

	bool isAlive = true;
	bool isChppoing = false;
	bool isFinishMove = false;

	SceneDev1* sceneGame = nullptr;
	SceneDev2* sceneGame2 = nullptr;
	PlayerId playerId;
	Player* player1; // 첫 번째 플레이어
	Player* player2;

public:
	Player(const std::string& name = "", PlayerId id = PlayerId::Player1);
	virtual ~Player() = default;

	Sides GetSide() const { return side; }
	void OnDie();

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
	void SetSceneGame2(SceneDev2* scene);

};


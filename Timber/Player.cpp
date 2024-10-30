#include "stdafx.h"
#include "Player.h"
#include "Framework/SceneDev1.h"



Player::Player(const std::string& name, PlayerId id) : GameObject(name), playerId(id)
{
}

void Player::SetSide(Sides s)
{
	side = s;

	if (side == Sides::Left)
	{
		SetScale({ -1.f, 1.f });
	}
	else if (side == Sides::Right)
	{
		SetScale({ 1.f, 1.f });
	}

	sf::Vector2f newPos = position + localPosPlayer[(int)s];
	spritePlayer.setPosition(newPos);
	spriteAxe.setPosition(newPos + localPosAxe);
	spriteRip.setPosition(newPos + localRipAxe);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	SetSide(side);
}

void Player::OnDie()
{
	isAlive = false;
	isChppoing = false;


}

void Player::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	spritePlayer.setScale(this->scale);

	sf::Vector2f axeScale = this->scale;
	axeScale.x *= -1.f;
	spriteAxe.setScale(axeScale);

	sf::Vector2f axeRip = this->scale;
	axeRip.x = abs(axeScale.x);
	spriteRip.setScale(axeRip);
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		origin = Utils::SetOrigin(spritePlayer, preset);
	}
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spritePlayer.setOrigin(origin);
}

void Player::Init()
{
	spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	SetOrigin(Origins::BC);

	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteAxe.setOrigin(originAxe);

	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));
	Utils::SetOrigin(spriteRip, Origins::BC);
}

void Player::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));

	spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));

	isAlive = true;
	isChppoing = false;
	SetPosition(position);
	SetScale({ 1.f, 1.f });
	SetSide(Sides::Right);
}


void Player::Release()
{
}


void Player::Update(float dt)
{
	if (!isAlive)
		return;

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		isChppoing = true;
		SetSide(Sides::Left);
		sceneGame->OnChop(Sides::Left);
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Left))
	{
		isChppoing = false;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		isChppoing = true;
		SetSide(Sides::Right);
		sceneGame->OnChop(Sides::Right);
		sceneGame->OnChop(Sides::Left);
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		isChppoing = false;
	}
	if (!isAlive)
		return;

	if (this == player1) // 첫 번째 플레이어
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			isChppoing = true;
			SetSide(Sides::Left);
			sceneGame2->OnChop(Sides::Left, this, sceneGame2->tree1);
			sfxChop.play();
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			isChppoing = true;
			SetSide(Sides::Right);
			sceneGame2->OnChop(Sides::Right, this, sceneGame2->tree1);
			sfxChop.play();
		}
	}
	else if (this == player2) // 두 번째 플레이어
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::A))
		{
			isChppoing = true;
			SetSide(Sides::Left);
			sceneGame2->OnChop(Sides::Left, this, sceneGame2->tree2);
			sfxChop.play();
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::D))
		{
			isChppoing = true;
			SetSide(Sides::Right);
			sceneGame2->OnChop(Sides::Right, this, sceneGame2->tree2);
			sfxChop.play();
		}
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Left) || InputMgr::GetKeyUp(sf::Keyboard::Right) ||
		InputMgr::GetKeyUp(sf::Keyboard::A) || InputMgr::GetKeyUp(sf::Keyboard::D))
	{
		isChppoing = false;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	if (isAlive)
	{
		window.draw(spritePlayer);
		if (isChppoing)
		{
			window.draw(spriteAxe);
		}
	}
	else
	{
		window.draw(spriteRip);
	}
}

void Player::SetSceneGame(SceneDev1* scene)
{
	sceneGame = scene;
}

void Player::SetSceneGame2(SceneDev2* scene)
{
	sceneGame2 = scene;
}

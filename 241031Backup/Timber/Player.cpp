#include "stdafx.h"
#include "Player.h"
#include "Framework/SceneDev1.h"

Player::Player(const std::string& name, int playerId) : GameObject(name), playerId(playerId)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
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

	//Tree* targetTree = nullptr; 
	Tree* targetTree = (playerId == 1) ? sceneGame->GetTree1() : sceneGame->GetTree2();
	
		if (InputMgr::GetKeyDown(buttonL) && !isChopping)
		{
			isChppoing = true;
			SetSide(Sides::Left);
			sceneGame->OnChop(Sides::Left, this, targetTree);
			sfxChop.play();
		}

		else if (InputMgr::GetKeyUp(buttonL))
		{
			isChppoing = false;
		}

		if (InputMgr::GetKeyDown(buttonR) && !isChopping)
		{
			isChppoing = true;
			SetSide(Sides::Right);
			sceneGame->OnChop(Sides::Right, this, targetTree);
			sfxChop.play();
		}

		else if (InputMgr::GetKeyUp(buttonR))
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


int Player::GetPlayerId() const
{
	return playerId;
}

void Player::SetKeySetting(sf::Keyboard::Key buttonL, sf::Keyboard::Key buttonR)
{
	this->buttonL = buttonL;
	this->buttonR = buttonR;
}




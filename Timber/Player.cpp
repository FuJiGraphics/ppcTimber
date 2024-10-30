#include "stdafx.h"
#include "Player.h"
#include "Framework/SceneDev1.h"

Player::Player(const std::string& name) : GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
}


void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
}

void Player::OnDie()
{
	isAlive = false;
	isChppoing = false;
}

void Player::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		origin = Utils::SetOrigin(spriteIdle, preset);
	}
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spriteIdle.setOrigin(origin);
}

void Player::Init()
{
	isAlive = true;
	spriteIdle.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAttack.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteFinishMove.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteTransform.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteDie.setTexture(TEXTURE_MGR.Get("graphics/rip.png"));

	// Idle
	animIdle.SetSprite(spriteIdle);
	for (int i = 0; i < 6; ++i)
	{
		int x = (i * 116) + 11;
		animIdle.AddFrame({ sf::IntRect{x, 140, 112, 82}, 0.1f });
	}
	animIdle.AddFrame({ sf::IntRect{116 * 5 + 11, 140, 112, 82}, 0.5f });
	for (int i = 5; i >= 0; --i)
	{
		int x = (i * 116) + 11;
		animIdle.AddFrame({ sf::IntRect{x, 140, 112, 82}, 0.1f });
	}
	animIdle.AddFrame({ sf::IntRect{11, 140, 112, 82}, 0.5f });

	// Attack
	animAttack.SetSprite(spriteAttack);
	//for (int i = 0; i < 11; ++i)
	//{
	//	int x = (i * 116) + 11;
	//	animAttack.AddFrame({ sf::IntRect{x, 759, 112, 82}, 0.02f });
	//}
	for (int i = 0; i < 6; ++i)
	{
		int x = (i * 116) + 11;
		animAttack.AddFrame({ sf::IntRect{x, 1090, 112, 82}, 0.02f });
	}
	animAttack.Repeat = false;
	animAttack.SetEnd(true);

	// Finish Move
	animFinishMove.SetSprite(spriteFinishMove);
	for (int i = 0; i < 6; ++i)
	{
		int x = (i * 116) + 11;
		animFinishMove.AddFrame({ sf::IntRect{x, 1198, 112, 82}, 0.1f });
	}
	animFinishMove.Repeat = false;
	animFinishMove.SetEnd(true);

	// Transform
	animTransform.SetSprite(spriteTransform);
	for (int i = 0; i < 11; ++i)
	{
		int x = (i * 116) + 11;
		animFinishMove.AddFrame({ sf::IntRect{x, 758, 112, 82}, 0.1f });
	}

}

void Player::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));
	spriteIdle.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAttack.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteFinishMove.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteTransform.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteDie.setTexture(TEXTURE_MGR.Get("graphics/rip.png"));
	isAlive = true;
	isChppoing = false;
	SetPosition(position);
	SetScale(scale);
}


void Player::Release()
{
}


void Player::Update(float dt)
{
	if (!isAlive)
		return;

	animIdle.Update(dt);
	animAttack.Update(dt);
	animFinishMove.Update(dt);
	animTransform.Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		isChppoing = true;
		side = Sides::Left;
		sceneGame->OnChop(side);
		animAttack.Reset();
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Left))
	{
		isChppoing = false;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		isChppoing = true;
		side = Sides::Right;
		sceneGame->OnChop(side);
		animAttack.Reset();
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		isChppoing = false;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	sf::Vector2f newScale = scale;
	if (side == Sides::Right)
	{
		sf::Vector2f newPos = position;
		newPos.x += 500.0f;
		newScale.x *= -1.0f;
		if (!isAlive)
		{
			newScale.x = 1.0f;
			newScale.y = 1.0f;
			newPos.x -= 260.0f;
			newPos.y += 150.0f;
			spriteDie.setPosition(newPos);
			spriteDie.setScale(newScale);
			window.draw(spriteDie);
			return;
		}
		else if (animAttack.IsEnd())
		{
			animIdle.GetSprite()->setPosition(newPos);
			animIdle.GetSprite()->setScale(newScale);
			window.draw(*animIdle.GetSprite());
		}
		else
		{
			animAttack.GetSprite()->setPosition(newPos);
			animAttack.GetSprite()->setScale(newScale);
			window.draw(*animAttack.GetSprite());
		}
	}
	else if (side == Sides::Left)
	{
		sf::Vector2f newPosRev = position;
		newPosRev.x -= 500.0f;
		if (!isAlive)
		{
			newScale.x = -1.0f;
			newScale.y = 1.0f;
			newPosRev.x += 260.0f;
			newPosRev.y += 150.0f;
			spriteDie.setPosition(newPosRev);
			spriteDie.setScale(newScale);
			window.draw(spriteDie);
			return;
		}
		else if (animAttack.IsEnd())
		{
			animIdle.GetSprite()->setPosition(newPosRev);
			animIdle.GetSprite()->setScale(newScale);
			window.draw(*animIdle.GetSprite());
		}
		else
		{
			animAttack.GetSprite()->setPosition(newPosRev);
			animAttack.GetSprite()->setScale(newScale);
			window.draw(*animAttack.GetSprite());
		}
	}
}

void Player::SetSceneGame(SceneDev1* scene)
{
	sceneGame = scene;
}

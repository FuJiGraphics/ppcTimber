#include "stdafx.h"
#include "PlayerNormal.h"
#include "Framework/Scene.h"

PlayerNormal::PlayerNormal(const std::string& texPath)
	:Player(texPath)
{

}

void PlayerNormal::SetSide(Sides s)
{
	side = s;

	if (side == Sides::Left)
	{
		SetScale({ -1.f,1.f });
	}
	else if (side == Sides::Right)
	{
		SetScale({ 1.f,1.f });
	}
	sf::Vector2f newPos = position + localPosPlayer[(int)s];

	spritePlayer.setPosition(newPos);
	Utils::SetOrigin(spriteAxe, Origins::BC);
	spriteAxe.setPosition(newPos + localPosAxe);
	spriteRip.setPosition(newPos + localPosRip);
}

void PlayerNormal::OnDie()
{
	isAlive = false;
	isChppoing = false;
}

void PlayerNormal::SetPalyerTexturId(const std::string& id)
{
	this->texIdPlayer = id;
}

void PlayerNormal::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
}

void PlayerNormal::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	spritePlayer.setScale(this->scale);

	sf::Vector2f axeScale = this->scale;
	axeScale.x *= -1.f;
	spriteAxe.setScale(axeScale);

	sf::Vector2f ripScale = this->scale;
	ripScale.x = abs(ripScale.x);
	spriteRip.setScale(ripScale);
}

void PlayerNormal::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(spritePlayer, preset);
	}
}

void PlayerNormal::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spritePlayer.setOrigin(origin);
	spriteRip.setOrigin(origin);
}

void PlayerNormal::Init()
{
	GameObject::Init();

	/*spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	SetOrigin(Origins::BC);*/

	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteAxe.setOrigin(originAxe);
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));
}

void PlayerNormal::Release()
{
}

void PlayerNormal::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));


	spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));

	SetPosition(position);
	SetScale({ 1.f,1.f });
	SetSide(Sides::Right);

	isChppoing = false;
	isAlive = true;
}

void PlayerNormal::Update(float dt)
{
	if (!isAlive || dt <= 0.0f)
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
		SetSide(Sides::Left);
		isChppoing = false;

	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		isChppoing = true;
		SetSide(Sides::Right);
		sceneGame->OnChop(Sides::Right);
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		SetSide(Sides::Right);
		isChppoing = false;
	}
}

void PlayerNormal::Draw(sf::RenderWindow& window)
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

void PlayerNormal::SetSceneGame(SceneDev1* scene)
{
	sceneGame = scene;
}

#include "stdafx.h"
#include "BeeHive.h"

BeeHive::BeeHive(const std::string& name)
	: name(name)
{
	// Empty
}

void BeeHive::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	spriteIdle.setPosition(position);
	spriteDead.setPosition(position);
}

void BeeHive::SetScale(const sf::Vector2f& scale)
{
	GameObject::SetScale(scale);
	spriteIdle.setScale(scale);
	spriteDead.setScale(scale);
}

sf::Vector2f BeeHive::GetPosition() const
{
	return position;
}

bool BeeHive::IsExploded()
{
	return isExploded;
}

void BeeHive::Init()
{
	TEXTURE_MGR.Load(texIdBeeHive);
	spriteIdle.setTexture(TEXTURE_MGR.Get(texIdBeeHive));
	TEXTURE_MGR.Load(texIdBeeHiveDead);
	spriteDead.setTexture(TEXTURE_MGR.Get(texIdBeeHiveDead));
}

void BeeHive::Update(float dt)
{
	timer += dt;
	if (timer > duration)
	{
		SetActive(false);
		return;
	}
	if (position.y < 750.f)
	{
		velocity += gravity * dt;
		this->SetPosition(position + velocity * dt);
	}
	else
	{
		isExploded = true;
		isAlive = false;
	}
}

void BeeHive::Reset()
{
	timer = 0.0f;
	isExploded = false;
	isAlive = true;
	velocity = { 0.0f, 0.0f };
}

void BeeHive::Draw(sf::RenderWindow& window)
{
	if (isAlive)
		window.draw(spriteIdle);
	else
		window.draw(spriteDead);
}

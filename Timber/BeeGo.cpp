#include "stdafx.h"
#include "BeeGo.h"

BeeGo::BeeGo(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
	animIdleR.LoadFromFile(textureId);
	animIdleR.SetAnimSequence({ 0, 128, 64, 64 }, 0, 0.1, 4);
	animIdleR.SetPosition(position);
	animIdleR.SetScale(scale);
	animIdleL.LoadFromFile(textureId);
	animIdleL.SetAnimSequence({ 0, 64, 64, 64 }, 0, 0.1, 4);
	animIdleL.SetPosition(position);
	animIdleL.SetScale(scale);
}

void BeeGo::SetPosition(const sf::Vector2f& pos)
{
	this->position = pos;
}

void BeeGo::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
}

void BeeGo::Reset()
{
	animIdleR.SetPosition(position);
	animIdleR.SetScale(scale);
	animIdleL.SetPosition(position);
	animIdleL.SetScale(scale);
}

void BeeGo::Update(float dt)
{
	if (currSceneStatus && (*currSceneStatus != SceneDev1::Status::Game))
		return;

	animIdleR.Update(dt);
	animIdleL.Update(dt);
	elap += dt;

	if (dir == Sides::Left)
		position.x -= speed * dt;
	else if (dir == Sides::Right)
		position.x += speed * dt;
	position.y += 0.25f * sin((15.f) * elap);
	animIdleR.SetPosition(position);
	animIdleL.SetPosition(position);

	if (position.x < -100.0f || position.x > 1920.f + 100.f)
		dir = (dir == Sides::Left) ? Sides::Right : Sides::Left;
}

void BeeGo::Draw(sf::RenderWindow& window)
{
	if (dir == Sides::Right)
	{
		animIdleR.Draw(window);
	}
	else if (dir == Sides::Left)
	{
		animIdleL.Draw(window);
	}
}

void BeeGo::SetSpeed(float speed)
{
	this->speed = speed;
}

void BeeGo::SetDirection(Sides side)
{
	this->dir = side;
}

void BeeGo::SetSceneStatus(SceneDev1::Status* status)
{
	currSceneStatus = status;
}


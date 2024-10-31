#include "stdafx.h"
#include "PlayerModel.h"

void PlayerModel::Update(float dt)
{
	animIdle.Update(dt);
}

void PlayerModel::Draw(sf::RenderWindow& window)
{
	animIdle.SetPosition(position);
	animIdle.SetFlipX(true);
	animIdle.Draw(window);
}

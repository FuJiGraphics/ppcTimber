#pragma once
#include "Player.h"

class PlayerModel : public Player
{
public:
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;


};


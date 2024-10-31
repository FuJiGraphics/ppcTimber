#include "stdafx.h"
#include "Player.h"
#include "Framework/SceneDev1.h"



Player::Player(const std::string& name, PlayerId id) : GameObject(name), playerId(id)
{
<<<<<<< HEAD
=======
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
	isAlive = true;
	animIdle.LoadFromFile(texIdPlayer);
	animAttack.LoadFromFile(texIdPlayer);
	animFinishMove.LoadFromFile(texIdPlayer);
	animTransform.LoadFromFile(texIdPlayer);

	// Die
	spriteDie.setTexture(TEXTURE_MGR.Get("graphics/rip.png"));
	spriteDie.setPosition({ 1920.0f * 0.5f, 600.0f });

	// Idle
	animIdle.SetAnimSequence({ 11, 140, 112, 82 }, 4, { 0.1, 0.1, 0.1, 0.1, 0.1, 0.6 }, 6);
	animIdle.AddAnimSequenceRev({ 11, 140, 112, 82 }, 4, { 0.1, 0.1, 0.1, 0.1, 0.1, 0.6 }, 6);
	animIdle.SetScale(3.7f, 3.7f);
	animIdle.SetPosition({ 1920.0f * 0.5f + 80.0f, 560.0f });

	// Attack
	animAttack.SetAnimSequence({ 11, 1090, 112, 82 }, 4, 0.02, 7);
	animAttack.SetScale(3.7f, 3.7f);
	animAttack.SetPosition({ 1920.0f * 0.5f + 80.0f, 560.0f });
	animAttack.Repeat = false;
	animAttack.Activated = false;

	// Finish Move
	animFinishMove.SetAnimSequence({ 11, 762, 112, 82 }, 4, 0.2, 11);
	animFinishMove.AddAnimSequence({ 11, 1198, 112, 82 }, 4, { 0.1, 0.1, 0.6, 0.2, 0.2, 2.0, 0.2 }, 7);
	animFinishMove.SetScale(3.7f, 3.7f);
	animFinishMove.SetPosition({ 1920.0f * 0.5f + 80.0f, 560.0f });
	animFinishMove.Repeat = false;

	// EnergyBeam
	animEnergyBeam.AddFrame({ {4, 1347, 50, 80}, 0.2 });
	animEnergyBeam.AddFrame({ {4, 1347, 80, 100}, 0.2 });
	animEnergyBeam.AddAnimSequence({ 4, 1347, 112, 82 }, 4, 0.2, 11);
	animEnergyBeam.SetScale(3.7f, 3.7f);
	animEnergyBeam.SetPosition({ 1920.0f * 0.5f + 80.0f, 560.0f });
	animEnergyBeam.Repeat = false;

	// Transform
	animTransform.SetAnimSequence({ 11, 758, 112, 82 }, 4, 0.1, 11);
	animTransform.SetScale(3.7f, 3.7f);
	animTransform.SetPosition({ 1920.0f * 0.5f + 80.0f, 560.0f });
>>>>>>> master
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
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
}

void Player::Init()
{
}

void Player::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));
	animIdle.Reset();
	animAttack.Reset();
	animFinishMove.Reset();
	animTransform.Reset();
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

	if (sceneGame->GetStatus() != SceneDev1::Status::Game)
		return;

	if (InputMgr::GetKeyUp(sf::Keyboard::Space))
	{
  		isChppoing = true;
		isFinishMove = true;
	}
	if (InputMgr::GetKeyUp(sf::Keyboard::Space))
	{
		isChppoing = false;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		isChppoing = true;
		side = Sides::Left;
		sceneGame->OnChop(side);
		animAttack.Reset();
		animAttack.Activated = true;
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
		animAttack.Activated = true;
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		isChppoing = false;
	}
<<<<<<< HEAD
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
=======

>>>>>>> master
}

void Player::Draw(sf::RenderWindow& window)
{
	if (side == Sides::Right)
	{
		if (!isAlive)
		{
			spriteDie.setPosition({ 1920.0f * 0.5f + 200.0f, 700.0f });
			window.draw(spriteDie);
			return;
		}
		else if (isFinishMove)
		{
			if (animFinishMove.IsFrameEnd())
			{
				animFinishMove.Reset();
				isFinishMove = false;
			}
			else
			{
				animFinishMove.SetPosition({ 1920.0f * 0.5f + 480.0f, 560.0f });
				animFinishMove.SetFlipX(true);
				animFinishMove.Draw(window);
			}
		}
		else if (animAttack.IsFrameEnd())
		{
			animIdle.SetPosition({ 1920.0f * 0.5f + 480.0f, 560.0f });
			animIdle.SetFlipX(true);
			animIdle.Draw(window);
		}
		else
		{
			animAttack.SetPosition({ 1920.0f * 0.5f + 480.0f, 560.0f });
			animAttack.SetFlipX(true);
			animAttack.Draw(window);
		}
	}
	else if (side == Sides::Left)
	{
		if (!isAlive)
		{
			spriteDie.setPosition({ 1920.0f * 0.5f - 350.0f, 700.0f });
			window.draw(spriteDie);
			return;
		}
		else if (isFinishMove)
		{
			if (animFinishMove.IsFrameEnd())
			{
				animFinishMove.Reset();
				isFinishMove = false;
			}
			else
			{
				animFinishMove.SetPosition({ 1920.0f * 0.5f - 480.0f, 560.0f });
				animFinishMove.SetFlipX(false);
				animFinishMove.Draw(window);
			}
		}
		else if (animAttack.IsFrameEnd())
		{
			animIdle.SetPosition({ 1920.0f * 0.5f - 480.0f, 560.0f });
			animIdle.SetFlipX(false);
			animIdle.Draw(window);
		}
		else
		{
			animAttack.SetPosition({ 1920.0f * 0.5f - 480.0f, 560.0f });
			animAttack.SetFlipX(false);
			animAttack.Draw(window);
		}
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

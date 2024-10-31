#pragma once

class Player;
class Player2;
class GameMgr
{
public:
	static Player* play1user1;
	static Player* play1user2;
	static Player2* play2user1;
	static Player2* play2user2;

	static void SetUsers(Player* p1, Player2* p2)
	{
		play1user1 = p1;
		play2user2 = p2;
	}

	static void SetUsers( Player2* p1, Player* p2)
	{
		play2user1 = p1;
		play1user2 = p2;
	}
};


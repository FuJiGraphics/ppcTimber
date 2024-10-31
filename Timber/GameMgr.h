#pragma once

class Player;
class Player2;
class GameMgr
{
public:
	static std::string playTexId;
	static std::string playTexId1;
	static std::string playTexId2;

	static void SetUsers(std::string p1, std::string p2)
	{
		playTexId1 = p1;
		playTexId2 = p2;
	}
};


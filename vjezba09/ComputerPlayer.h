#pragma once
#include "z2.h"
#include "Player.h"
#include "Game.h"

class ComputerPlayer : public Player {
public:
	void compRandomGuess(Game game);
};
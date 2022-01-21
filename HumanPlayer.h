#pragma once
#include "z2.h"
#include "Player.h"
#include "Game.h"


class HumanPlayer : public Player {
public:
	void coins();
	void guess(Game game);
};
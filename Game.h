#pragma once
#include "z2.h"
#include "Player.h"


class Game {
public:
	int humanPlayers;
	int computerPlayers;
	int total = 0;
	int points = 1;
	bool gameOver(Player* player);

	void coinTotal(Player player) {
		total = total + player.coinsInHand;
	}

	void winner(Player& player) {
		if (player.guessSum == total)
			player.gameScore += 1;
	}
};
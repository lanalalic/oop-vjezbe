#include "allTheIncludes.h"

bool Game::gameOver(Player* player)
{
	for (int i = 0; i < (humanPlayers + computerPlayers); i++) {
		if (player[i].gameScore == points) {
			cout << "Player number " << i << " wins!!";
			return true;
		}
	}
	return false;
}
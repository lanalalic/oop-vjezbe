#include "allTheIncludes.h"

void ComputerPlayer::compRandomGuess(Game game)
{
	srand(time(NULL));
	int arr[] = { 0, 1, 2, 3, 5, 6, 7, 8 };
	int random = rand() % 8;
	coinsInHand = arr[random];
	guessSum = coinsInHand + rand() % ((game.humanPlayers + game.computerPlayers)*8 - coinsInHand);
	cout << "Computer" << endl;
	cout << "Coins in hand: " << coinsInHand << endl;
	cout << "Computers guess: " << guessSum << endl;
}
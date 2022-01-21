#include "allTheIncludes.h"

void HumanPlayer::coins()
{
	int coin;
	cout << "Input your sum of coins: ";
	cin >> coin;
	while ((coin != 0) && (coin != 1)
		&& (coin != 2) && (coin != 3) 
		&& (coin != 5) && (coin != 6) 
		&& (coin != 7) && (coin != 8)) {
		cout << "Invalid sum, pick again: ";
		cin >> coin;
	}
	coinsInHand = coin;
}

void HumanPlayer::guess(Game game)
{
	int total;
	cout << "Guess the total: " << endl;
	cin >> total;
	cout << endl;
	guessSum = total;

}
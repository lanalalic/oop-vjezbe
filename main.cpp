#include "allTheIncludes.h"



int main()
{

	Game Japanez;
	Japanez.humanPlayers = 0;
	Japanez.computerPlayers = 0;
	
	
	const int numOfComp = 1;
	const int numOfPpl = 1;

	HumanPlayer human_player[numOfPpl];
	ComputerPlayer computer[numOfComp];
	while ((Japanez.gameOver(human_player) == false) && (Japanez.gameOver(computer) == false)){
		for (int i = 0; i < numOfPpl; i++) {
			cout << "Player " << i << endl;
			human_player[i].coins();
			human_player[i].guess(Japanez);
			Japanez.coinTotal(human_player[i]);
		}

		for (int i = 0; i < numOfComp; i++) {
			computer[i].compRandomGuess(Japanez);
			Japanez.coinTotal(computer[i]);
		}

		cout << "Total sum was: " << Japanez.total << endl;
		for (int i = 0; i < numOfPpl; i++) {
			Japanez.winner(human_player[i]);
			cout << "Player " << i << " score: " << human_player[i].gameScore << endl;
		}
		Japanez.total = 0;
		cout << endl;

		for (int i = 0; i < numOfComp; i++ ) {
			Japanez.winner(computer[i]);
			cout << "Player " << i << " score: " << computer[i].gameScore << endl;
		}

	}


	//z2

	DaddyLongLegs daddyLonglegs;
	Cockroach cockroach;
	Butterfly butterfly;
	Seagull seagull;
	Counter counter;
	counter.getAnimal(daddyLonglegs);
	counter.getAnimal(cockroach);
	counter.getAnimal(seagull);
	counter.getAnimal(butterfly);
	counter.sumOfLegs(); 

}



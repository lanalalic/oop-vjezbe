#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

class HangmanModel
{
public:
	string movie;
	string guessMovie;
	vector <char> usedLetters;
	int lives = 6;
};

class HangmanView
{
public:
	void guessingProgress(HangmanModel model);
	void displayUsedLetters(HangmanModel model);
};

class HangmanController
{
public:
	void randomMovie(HangmanModel& model);
	void dashes(HangmanModel& model);
	void numOfLives(HangmanModel& model, bool mistake);
	void inputLetter(HangmanModel& model);
	bool checkLetter(HangmanModel& model, char s);
	void updateGuessedLetters(HangmanModel& model);
	void updateHangman(HangmanModel& model);
	bool isGameOver(HangmanModel& model);
};


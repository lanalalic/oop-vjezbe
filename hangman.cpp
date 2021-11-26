#include "Header.h"

void HangmanController::randomMovie(HangmanModel& model)
{
    srand(time(NULL));
    ifstream movieList;
    vector <string> movies;
    int i = 0;
    string newStr;
    movieList.open("movie.txt");
    while (getline(movieList, newStr)) 
    {            
        movies.push_back(newStr);
    }     
    int k = rand() % sizeof(movies);
    model.movie = movies[k];  
    movieList.close();
    for (int i = 0; i < model.movie.size(); i++) 
    {
        if (model.movie[i] == ' ')
        {
            model.guessMovie.push_back(' ');
        }
        if (model.movie[i] >= 'a' && model.movie[i] <= 'z' || model.movie[i] >= 'A' && model.movie[i] <= 'Z' || model.movie[i] >= '0' && model.movie[i] <= '9')
        {
            model.guessMovie.push_back('_');
        }
        else
        {
            model.guessMovie.push_back(model.movie[i]);           
        }
    }
}

void  HangmanController::dashes(HangmanModel& model)
{
    for (int i = 0; i < model.movie.size(); i++)
    {
        if (model.movie[i] == ' ');
        {
            cout<<"  ";
        }
        if (model.movie[i] >= 'a' && model.movie[i] <= 'z' || model.movie[i] >= 'A' && model.movie[i] <= 'Z' || model.movie[i] >= '0' && model.movie[i] <= '9')
        {
            cout << "_";
        }
        else
        {
            cout << model.movie[i];
        }
    }
}
bool HangmanController::checkLetter(HangmanModel& model, char c) 
{
    for (int i = 0; i < model.usedLetters.size(); i++) 
    {
        if (model.usedLetters[i] == c)
        {
            return true;
        }
    }
    return false;
}

void HangmanController::updateHangman(HangmanModel& model) {

    int lives = model.lives;

    if (lives == 6)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
    }
    else if (lives == 5)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
    }
    else if (lives == 4)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|     |     " << endl;
        cout << "|     |     " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
    }
    else if (lives == 3)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|    /|     " << endl;
        cout << "|     |     " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
    }
    else if (lives == 2)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|    /|\\   " << endl;
        cout << "|     |     " << endl;
        cout << "|           " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;

    }
    else if (lives == 1)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|    /|\\   " << endl;
        cout << "|     |     " << endl;
        cout << "|    /      " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
    }
    else if (lives == 0)
    {
        cout << " __________ " << endl;
        cout << "|     |     " << endl;
        cout << "|     O     " << endl;
        cout << "|    /|\\   " << endl;
        cout << "|     |     " << endl;
        cout << "|    / \\   " << endl;
        cout << "|           " << endl;
        cout << "|___        " << endl;
        cout << "  GAME OVER!" << endl;
    }

}

void HangmanController::inputLetter(HangmanModel& model)
{
    char c;
    cout << "Guess the letter: " << endl;
    cin >> c;
    while ((!isalpha(c)) || (checkLetter(model, c)));
    {
        cout << "Guess the letter: " << endl;
        cin >> c;
    }   
    model.usedLetters.push_back(c);
}

void HangmanView::displayUsedLetters(HangmanModel model)
{
    cout << "Used letters: ";
    for (int i = 0; i < model.usedLetters.size(); i++) 
    {
        cout << model.usedLetters[i] << " ";
    }
    cout << endl;
}


void HangmanView::guessingProgress(HangmanModel model) {
    cout << model.guessMovie << endl;
}

void HangmanController::numOfLives(HangmanModel& model, bool mistake) 
{
    if (mistake) model.lives--;
}

void HangmanController::updateGuessedLetters(HangmanModel& model) {

    char letter = model.usedLetters.back();
    bool mistake = true;

    for (int i = 0; i < model.movie.size(); i++) 
    {
        if (model.movie[i] == letter)
        {
            model.guessMovie[i] = letter;
            mistake = false;
        }
    }
    numOfLives(model, mistake);
}

bool HangmanController::isGameOver(HangmanModel& model) {

    if (model.lives == 0)
    {
        cout << "GAME OVER! :(" << endl;
        return false;
    }

    for (int i = 0; i < model.movie.size(); i++)
    {
        if (model.movie[i] != model.guessMovie[i])
        {
            return true;
        }
    }
    cout << "YOU WIN!! :)" << endl;
    return false;
}
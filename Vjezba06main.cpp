#include "Header.h"

int main() {
    HangmanModel model;
    HangmanView view;
    HangmanController control;
    control.randomMovie(model);

    cout << "Guess the movie:" << endl;
    control.dashes(model);
    cout << endl;
    
    while (control.isGameOver(model)) {

        control.updateHangman(model);                
        control.inputLetter(model);
        view.displayUsedLetters(model);       
        control.updateGuessedLetters(model);
        view.guessingProgress(model);
    }

    control.updateHangman(model);
    view.displayUsedLetters(model);
    view.guessingProgress(model);
}



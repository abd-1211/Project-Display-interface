#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Hang_out(int attemptsLeft) {
    switch (attemptsLeft) {
        case 6:
            cout << "\n Attempts left: 6" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 5:
            cout << "\n Attempts left: 5" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |     " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 4:
            cout << "\n Attempts left: 4" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            break;
        case 3:
            cout << "\n Attempts left: 3" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |    |" << endl;
            cout << " |" << endl;
            break;
        case 2:
            cout << "\n Attempts left: 2" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   -|-" << endl;
            cout << " |" << endl;
            break;
        case 1:
            cout << "\n Attempts left: 1" << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   -|-" << endl;
            cout << " |   .*" << endl;
            break;
        case 0:
            cout << "\n Attempts left: 0" << endl << endl;
            cout << "  __" << endl;
            cout << " |    |" << endl;
            cout << " |    |" << endl;
            cout << " |    O" << endl;
            cout << " |   -|-" << endl;
            cout << " |   .*." << endl;
            break;
    }
}

int main() {
    string countries[] = {"pakistan", "india", "russia", "afghanistan", "oman"};
    srand(time(0));
    string randword = countries[rand() % 5];
    string Word_out(randword.length(), '_');
    string guessedLetters = "";
    int attempts = 6;

    cout << "Hangman! \n Guess the Country. \n Guess a letter right and you're on the path to victory. Guess wrong and you lose a turn! \n You have 6 turns" << endl;

    while (attempts >= 0) {
        cout << "Current status: " << Word_out << endl;
        cout << "Guessed letters: " << guessedLetters << endl;

        Hang_out(attempts);

        char guess;
        cout << " . turns left: " << attempts << endl;
        cout << " . Guess a letter: ";
        cin >> guess;

        bool Guessed = false;
       for (int i = 0; i < guessedLetters.length(); ++i) {
    if (guessedLetters[i] == guess) {
        cout << "\n Failure... \n You cannot guess the same letters again. \n Try Again: " << endl;
        Guessed = true;
        break;
    }
}


        if (Guessed) {
            continue;
        }

        guessedLetters += guess;
        bool found = false;

        for (int i = 0; i < randword.length(); ++i) {
            if (randword[i] == guess) {
                Word_out[i] = guess;
                found = true;
            }
        }

        if (!found) {
            attempts--;
            cout << "\n Incorrect Letter. Try again \n" << endl;
        }

        if (Word_out == randword) {
            cout << "\n Congratulations! You guessed the word: \n" << "!!! " << randword << " !!!"<< endl;
            return 0;
        }
    }

    cout << "\n Failure, no more attempts left. The word was: \n " << randword << endl;
    return 0;
}

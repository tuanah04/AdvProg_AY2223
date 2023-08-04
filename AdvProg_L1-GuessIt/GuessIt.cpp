#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    return rand() % 100 + 1;
}


int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int number;
    cout << "Guess the number: ";
    cin >> number;
    return number;
}



string getAnswer(int number, int randomNumber) {
    
    string answer;
    if (number > randomNumber)
        answer = "Your number is higher.";
    else if (number < randomNumber)
        answer = "Your number is lower.";
    else
        answer = "Congratulation! You win.";
    return answer;
}


bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if (answer == "Congratulation! You win.")
        return true;
    else
        return false;
}



bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if (isContinued == 'y' || isContinued == 'Y')
        result = true;
    return result;
}



char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cout << "Do you want to continue playing? (y/n): ";
    if (cin >> isContinued)
        return isContinued;
    else
        return 'n';
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}

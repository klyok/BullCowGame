/* This is console executable that makes use of FBullCowGame class.
 * This acts as the view in MVC pattern, and is responsible for
 * all user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    return 0; // exit the application
}

// introduce the game
void PrintIntro()
{
    std::cout << "Welcome to Cows and Bulls, a fun word game.\n";
    std::cout << "Can you guess the ";
    std::cout << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

    // loop for the number of turns asking for guesses
    for (int32 count = 1; count <= MaxTries; count++) // TODO change for FOR to WHILE
    {
        FText Guess = GetGuess();

        // submit valid guess to the game, and recieve counts
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }

    // TODO summarize a game

}

// get a guess from the player and print it back
FText GetGuess() // TODO change to valid GetValidGuess
{
    // get a guess from the player
    FText Guess = "";
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
    getline(std::cin, Guess);
    return Guess;
}


bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) ";
    FText Response = "";
    getline (std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

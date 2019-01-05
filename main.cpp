#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
    std::cout << BCGame.GetCurrentTry();

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
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome to Cows and Bulls, a fun world game.\n";
    std::cout << "Can you guess the ";
    std::cout << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();

    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;

    // loop for the number of turns asking for guesses
    // TODO change for FOR to WHILE loop once we are validating tries
    constexpr int NUMBER_OF_TURNS = 5;
    for (int count = 1; count <= MaxTries; count++)
    {
        FText Guess = GetGuess(); // TODO make loop checking valid guesses

        // submit valid guess to the game
        // print number of bulls and cows

        std::cout << "Your guess is: " << Guess << std::endl;
        std::cout << std::endl;
    }

    // TODO summarize a game

}

// get a guess from the player and print it back
FText GetGuess()
{
    // get a guess from the player
    FText Guess = "";
    int CurrentTry = BCGame.GetCurrentTry();
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

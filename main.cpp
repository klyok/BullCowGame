#include <iostream>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
        // TODO add a game summary
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
    constexpr int NUMBER_OF_TURNS = 5;
    for (int count = 1; count <= MaxTries; count++)
    {
        std::string Guess = GetGuess();
        std::cout << "Your guess is: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

// get a guess from the player and print it back
std::string GetGuess()
{
    // get a guess from the player
    std::string Guess = "";
    int CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
    getline(std::cin, Guess);
    return Guess;
}


bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) ";
    std::string Response = "";
    getline (std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

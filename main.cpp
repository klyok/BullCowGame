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
FText GetValidGuess();
void PrintGameSummary();
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
    std::cout << "\n\nWelcome to Cows and Bulls, a fun word game.\n";
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

    // loop asking for guesses while the game is NOT won
    // and there are still tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();

        // submit valid guess to the game, and recieve counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }

    PrintGameSummary();
    return;
}

// loop continually until the player gives a valid guess
FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid;
    FText Guess = "";
    do
    {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter a word without repeating letters.\n";
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter all lowercase letters.\n";
            break;
        default:
            // assume the guess is valid
            break;
        }
    std::cout << std::endl;
    } while (Status != EGuessStatus::OK); // keep looping until we get no errors
    return Guess;
}

void PrintGameSummary(){
    if (BCGame.IsGameWon())
    {
        std::cout << "Well done - You win!\n\n";
    } else
    {
        std::cout << "You lost! Better luck next time.\n\n";
    }
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same word? (y/n) ";
    FText Response = "";
    getline (std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

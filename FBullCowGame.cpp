#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return 0;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
    return 0;
}


// receives VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // incriment try number
    MyCurrentTry++;

    // setup a return variable
    FBullCowCount BullCowCount;

    // loop through all letters in the guess
    int HiddenWordLength = MyHiddenWord.length();
    for (int32 i = 0; i < HiddenWordLength; i++)
    {
        // compare letters against the hidden words
        for (int32 j = 0; j < HiddenWordLength; j++)
        {
            if (Guess[i] == MyHiddenWord[i]) // if they match then
            {
                if (j == i) // if they are in the same place
                {
                    BullCowCount.Bulls++; // increment bulls
                } else
                {
                    BullCowCount.Cows++; // must be cows
                }
            }
        }
    }
    return BullCowCount;
}

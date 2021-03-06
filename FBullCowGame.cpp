#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "ant";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    bGameIsWon = false;

    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false) // if the guess isn't an isogram TODO write a function
    {
        return EGuessStatus::Not_Isogram;
    } else if (false) // if the guess isn't all lowercase TODO write a function
    {
        return EGuessStatus::Not_Lowercase;
    } else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    } else
    {
        return EGuessStatus::OK;
    }
}


// receives VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int WordLength = MyHiddenWord.length(); // assuming same length as guess

    // loop through all letters in the hidden word
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        // compare letters against the guess
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            if (Guess[GChar] == MyHiddenWord[MHWChar]) // if they match then
            {
                if (GChar == MHWChar) // if they are in the same place
                {
                    BullCowCount.Bulls++; // increment bulls
                } else
                {
                    BullCowCount.Cows++; // must be cows
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    } else
    {
        bGameIsWon = false;
    };
    return BullCowCount;
}

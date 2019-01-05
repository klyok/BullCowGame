#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); // TODO make a more rich return value
    bool CheckGuessValidity(FString); // TODO make a more rich return value

    // TODO provide methods for changing MyMaxTries

// ^^ please try and ignore this and focus on the interface above ^^
private:
    int32 MyCurrentTry; // see constructor for initialization
    int32 MyMaxTries;
    bool IsIsogram(FString);
    BullCowCount SubmitGuess(FString);

};



#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus
{
    OK,
    Not_Isogram
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;

    bool IsGameWon() const;
    bool CheckGuessValidity(FString) const; // TODO make a more rich return value

    void Reset(); // TODO make a more rich return value
    FBullCowCount SubmitGuess(FString Guess);

    // TODO provide methods for changing MyMaxTries

// ^^ please try and ignore this and focus on the interface above ^^
private:
    int32 MyCurrentTry; // see constructor for initialization
    int32 MyMaxTries;
    bool IsIsogram(FString);
    FString MyHiddenWord;
};



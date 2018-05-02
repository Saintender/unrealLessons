#pragma once
#include <string>

struct bullCowCount 
{
	int bulls = 0;
	int cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Incorrect_Length,
	Not_Lowercase
};

class bullCowGame {
public:
	bullCowGame();
	int getCurrentTry() const;
	int getMaxTries() const;
	void reset();
	bool isGameWon();
	EGuessStatus checkValidGuess(std::string);
	int getHiddenWordLength() const;
	bullCowCount submission(std::string);
	bool isLowercase(std::string);

private:
	int myCurrentTry;
	int myMaxTries;
	std::string hiddenWord;
	bool gameWon;

	bool isIsogram(std::string) const;
};
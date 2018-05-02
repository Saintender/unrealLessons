#include "bullCowGame.h"
#include <string>
#include <map>
#define TMap std::map

bullCowGame::bullCowGame() { reset(); }

void bullCowGame::reset()
{
	const std::string HIDDEN_WORD = "helio";
	constexpr int MAX_TRIES = 8;
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	hiddenWord = HIDDEN_WORD;
	gameWon = false;
	return;
}

int bullCowGame::getCurrentTry() const { return myCurrentTry; }

int bullCowGame::getMaxTries() const { return myMaxTries; }

bool bullCowGame::isGameWon() {	return gameWon; }

int bullCowGame::getHiddenWordLength() const
{
	return hiddenWord.length();
}

EGuessStatus bullCowGame::checkValidGuess(std::string guess) 
{
	//check isogram
	if (!isIsogram(guess))
		return EGuessStatus::Not_Isogram;

	//check length
	else if (guess.length() != getHiddenWordLength())
		return EGuessStatus::Incorrect_Length;

	//check lowercase
	else if (!isLowercase(guess))
		return EGuessStatus::Not_Lowercase;

	//if clear, return ok
	else return EGuessStatus::OK;
}

bullCowCount bullCowGame::submission(std::string guess)
{
	myCurrentTry++;
	bullCowCount bcCount;
	int wordLength = getHiddenWordLength();
	//loops through the word to find the bulls and cows
	for (int i = 0; i < wordLength; i++) {
		for (int j = 0; j < wordLength; j++) {
			if (hiddenWord[i] == guess[j]) {
				if (i == j)
					bcCount.bulls++;
				else
					bcCount.cows++;
			}
		}
	}
	if (bcCount.bulls == wordLength)
		gameWon = true;
	else gameWon = false;
	return bcCount;
}

bool bullCowGame::isLowercase(std::string guess)
{
	return true;
}

bool bullCowGame::isIsogram(std::string guess) const
{
	//construct the map

	//loop the placement of the string


	return true;
}
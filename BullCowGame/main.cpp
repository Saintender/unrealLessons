#include <iostream>
#include <string>
#include "bullCowGame.h"

void printIntro();
void playGame();
void printCount(bullCowCount bcCount);
void printGameSummary();
bool continueGame(bool cc);
std::string getValidGuess();

bullCowGame bcGame;

int main()
{
	bool continueController = false;
	
	printIntro();

	do {
		playGame();
		continueController = continueGame(continueController);
	} while (continueController);
}

void printIntro()
{
	std::cout << "Welcome to the Bull and Cow game. A word game to challenge your deductive reasoning." << std::endl;
	std::cout << "The goal of the game is to guess the " << bcGame.getHiddenWordLength() << " letter isogram that I am thinking of." << std::endl;
	std::cout << "Good luck!" << std::endl;
	std::cout << std::endl;
}

void playGame()
{
	bcGame.reset();
	while (!bcGame.isGameWon() && bcGame.getCurrentTry() <= bcGame.getMaxTries()) {
		std::string guess = getValidGuess();
		bullCowCount bcCount = bcGame.submission(guess);
		printCount(bcCount);
		std::cout << std::endl;
	}
	printGameSummary();
	return;
}

void printCount(bullCowCount bcCount)
{
	std::cout << "|| " << bcCount.bulls << " bulls || " << bcCount.cows << " cows ||" << std::endl;
	return;
}

bool continueGame(bool cc)
{
	std::cout << "Do you want to play again?" << std::endl;
	std::string check = "";
	std::getline(std::cin, check);
	return (check[0] == 'y') || (check[0] == 'Y');
}

std::string getValidGuess()
{
	int tryNumber = bcGame.getCurrentTry();
	EGuessStatus status = EGuessStatus::Invalid;
	std::string guess = "";
	do {
		std::cout << "Try " << tryNumber << ": Enter your guess ~ ";
		std::getline(std::cin, guess);
		status = bcGame.checkValidGuess(guess);
		switch (status) {
		case EGuessStatus::Incorrect_Length:
			std::cout << "Please enter a " << bcGame.getHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess in all lowercase characters." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please ensure that your guess is an isogram. (All characters are different)" << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (status != EGuessStatus::OK);
	return guess;
}

void printGameSummary() 
{
	if (bcGame.isGameWon())
		std::cout << "Congratulations! You won!" << std::endl;
	else
		std::cout << "Better luck next time." << std::endl;
}
#include <iostream>
#include <string>
#include "bullCowGame.h"

void printIntro();
std::string getGuess();
void printBack(std::string guess);
void playGame();
bool continueGame();

bullCowGame bCGame;

int main()
{
	bool continueController = false;
	do{
		printIntro();
		playGame();
		continueController = continueGame();
	}while(continueController);
	return 0;
}

//prints out the intro to the game
void printIntro()
{
	constexpr int wordLength = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << wordLength;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

//get a guess from the player
std::string getguess()
{
	int currentTry = bCGame.getCurrentTry();
	std::string guess = "";
	std::cout << "Try " << currentTry << "Enter your guess: ";
	std::getline(std::cin, guess);

	return guess;
}

//prints the guess
void printBack(std::string guess)
{
	std::cout << "Your guess: " << guess << std::endl;
	return;
}

//loop the turns of the guessing
void playGame()
{
	bCGame.reset();
	int numberOfTurns = bCGame.getMaxTries();
	
	for(int i = 0; i < numberOfTurns; i++){
		std::string guess = getGuess();
		printBack(guess);
		std::cout << std::endl;
	}

	return;
}

bool continueGame()
{
	std::cout << "Do you want to play again? ";
	std::string response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y') || (response[0] == 'Y');
}
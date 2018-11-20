// Gambler.cpp
// Author: Sian McClean (Shane's notes)
// Date: 13/11/2018

// Function prototype - The function is below the main so the compiler won't know what the function is unless 
// you declare it in advance. There isn't a function body however
// see: http://www.learncpp.com/cpp-tutorial/17-forward-declarations/
#include <iostream>
#include <random>

float GenerateRandomNumber(); //Prototypes for the functions
void askAboutMoney(int &cash, int &goal);
int& CalculatePlayerBonus1(int numGames);
int& CalculatePlayerBonus2(int numGames);


int main(int args, const char * argv[]) {

	//int stake{0};
	int goal{ 0 };
	int num_games{ 0 };
	int cash{ 0 };

	int bets{ 0 };
	int wins{ 0 };

	char playAgain{ 'y' };

	do {

		num_games++;

		askAboutMoney(cash, goal);
		int bonus = CalculatePlayerBonus1(6) + CalculatePlayerBonus2(6);
		cash += bonus;

		std::cout << "Game: " << num_games << std::endl;

		while (cash > 0 && cash < goal) {

			bets++;
			if (GenerateRandomNumber() < 0.5)
				cash++;
			else
				cash--;
			std::cout << "cash: " << cash << std::endl;

		}

		if (cash == goal)
			wins++;
		else if (cash == 0)
			cash = 10;

		std::cout << "Do you want to play again? Y/N: ";
		std::cin >> playAgain;

	} while (playAgain == 'y' || 'Y');

	std::cout << "\n" << "The total number of bets: " << bets / num_games;
	std::cout << "\nwins: " << wins;
	std::cout << "\n" << (100 * wins / num_games) << " % wins" << std::endl;

	return 0;

}

//int& CalculatePlayerBonus1(int numGames, const int &cash) { //Pass by constant reference
int& CalculatePlayerBonus1(int numGames) { //Pass by constant reference

	int returnBonus{ 0 };

	if (numGames > 5) {
	
		returnBonus = 8;
		
	}
	return returnBonus;

}


//Pass by reference with pointers
int& CalculatePlayerBonus2(int numGames) {
	//int& CalculatePlayerBonus2(int* numGames) {

	int returnBonus{0};

	if (numGames > 5) {

		returnBonus = 2;

	}
	return returnBonus;

}

void askAboutMoney(int &cash, int &goal) { //now passing in the addresses of the variables that were declared in the main directly instead with the & symbol

	// this is an easier way of passing by reference
	std::cout << "Please enter the players intial cash: ";
	std::cin >> cash;

	std::cout << "\nPlease enter the goal: ";
	std::cin >> goal;

}

float GenerateRandomNumber(){

	return 5.0f;

}






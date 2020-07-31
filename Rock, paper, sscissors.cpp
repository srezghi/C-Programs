//**
// * @file Part1.cpp
// * @author Siavash Rezghighomi
// * @Date   26/05/2018
// * @version 1
// * @section DESCRIPTION
// * Rock, paper and scissors game between user and computer.
//
//
//
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Game
{
public:

	//Member of Game class
	string compChoice;
	string userChoice;

	//Additional member functions
	int range(string &input);
	void randChoice();
	void begin();
};

//---------------------------------------------------------------------------
//**
//* @brief This main function is the "Test Function". In the following main(),
//*		   a variable type Game Class is being initialized as test. Then the 
//*		   test calls the Class member function begin(), which begins the game
//*		   and gives the output of the game. Since the user and computer choices
//*		   are assigned randomly, the test function output will vary each time.
//*
//*/
int main()
{
	Game test;
	test.begin();

system ("pause");
return 0;
}

//---------------------------------------------------------------------------
//**
//* @brief This function runs the whole game. It asks user to make choice,
//*		   randomly picks "compChoice" using "randChoice()". Then it evalutes
//*		   the given data based on the rules of the game. Lastly, it shows the
//*		   computer choice and tells who is the winner. If the game turned to be
//*		   even, the code begins a new game until there is a winner.
//*
//*/
void Game::begin()
{
	int redo (0);
	while (redo == 0)
	{
		int redo1(0);
		while (redo1 == 0)
		{
			randChoice();
			cout << "rock, paper or scissors?" << endl;
			cin >> this->userChoice;
			if (range(this->userChoice) == false)
			{
				cout << "Invalid input. Please try again." << endl;
				redo1 = 0;
			}
			else
			{
				redo1 = 1;
			}
		}
		
		if (((this->compChoice == "rock") && ( this->userChoice == "scissors")) || 
			((this->compChoice == "paper") && ( this->userChoice == "rock")) ||
			((this->compChoice == "scissors") && ( this->userChoice == "paper")))
		{
			cout << "Computer is " << this->compChoice << "." << endl;
			cout << "Sorry, Computer won!" << endl;
			redo = 1;
		}
		else if (this->compChoice == this->userChoice)
			{
			cout << "Computer is " << this->compChoice << "." << endl;
			cout << "The game is even! You must play again!" << endl;
			redo = 0;
		}
		else
		{
			cout << "Computer is " << this->compChoice << "." << endl;
			cout << "Congrats! You won!" << endl;
			redo = 1;
		}
	}
}

//---------------------------------------------------------------------------
//**
//* @brief This function generates random choice for "compChoice"
//*		   in the class function.
//*/
void Game::randChoice()
{
	srand (time(NULL));
	int random = rand() % 3 + 1;
	if (random == 1)
	{
		this->compChoice = "rock";
	}
	else if (random == 2)
	{
		this->compChoice = "paper";
	}
	else
	{
		this->compChoice = "scissors";
	}
}

//---------------------------------------------------------------------------
//**
//* @brief This function checks if the given input is valid.
//*
//* @param "input" is the "userChoice" of the class function.
//* @return int 1 or 0.
//*/
int Game::range(string &input)
{
	if ((input == "rock") || (input == "paper") || (input == "scissors"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
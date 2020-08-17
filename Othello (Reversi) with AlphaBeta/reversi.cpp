#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "board.hpp"

using namespace std;

// Gets the user response to y/n 
bool user_respond(char input)
{
	while (true) 
	{
		if(input != '\n')
		{
			while (input != '\n');
			cout << "Invalid input!" << endl;
			continue; 
		}
		if(input == 'y' || input == 'Y')
			return true;
		else if(input == 'n' || input == 'N')
			return false;
		else
			cout << "Invalid input!" << endl;
	}
}	

// Checks if the end of the game has reached
// and arranges accordingly. Then prints the
// WIN or TIE statement or redo the games if 
// user wants to play another game
bool if_end_game(Board &temp_board){	
	if(temp_board.get_legal_moves_nums() == 0)
	{
		temp_board.change_turn();
		temp_board.update();	
		if(temp_board.get_legal_moves_nums() == 0)
		{
			if(temp_board.black_score() > temp_board.white_score())
				cout << "Black WON!" << endl;
			else if(temp_board.white_score() > temp_board.black_score())
				cout << "White WON!" << endl;
			else
				cout << "It's a TIE!" << endl;

			cout << "Wanna do another game?(Y/N): " << endl;
			char temp;
			cin >> temp;
			bool regame = user_respond(temp);

			if(!regame)
			{
				cout << "We'll play later then, bye!" << endl;
				exit(0);
			}
			else
				cout << endl << endl;

			return true;	
		}
	}
	return false;	
}			


///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	bool player1_flag, player2_flag, load_flag = false;
	int black_num(2), white_num(2);
	char brd[8][8], x = BLACK;
	
	while(1)
	{				
		//Starting the game
		player1_flag = true;	// black is the computer
		player2_flag = false; 	//White is the user
		Player player1 = Player(BLACK, player1_flag);
		Player player2 = Player(WHITE, player2_flag);
		Board board = (load_flag) ? Board(brd, x, black_num, white_num) : Board();
		cout << endl << endl << endl;
		cout << "AI is black pawns" << endl;
		cout << "User is white pawns" << endl;

		//Main Loop
		board.display_board(true);
		if(if_end_game(board)) 
			continue;

		if(board.get_turn() == BLACK)
			goto AI;

		else
			goto USER;

		while(true)
		{
			AI:
			player1.make_move(board);
			board.display_board(true);
			if(if_end_game(board))
				break;

			USER:
			player2.make_move(board);
			board.display_board(true);
			if(if_end_game(board))
				break;
		}
	}		
	return 0;
}
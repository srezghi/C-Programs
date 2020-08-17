#include <climits>
#include <iostream>
#include <sys/time.h>
#include "board.hpp"

using namespace std;

Player::Player(char c, bool comp)
{
	color = c;
	computer = comp;
}

char Player::get_color()
{
	return color;
}

bool Player::get_user()
{
	return computer;
}

int Player::make_move(Board &temp_board)
{
	int pawns_flipped(0);

	if (get_color() == BLACK)
	{
		cout << "Black's turn (AI): Let me take a good move please wait!!" << endl;
	}
	else
	{
		cout << "White's turn (USER):" << endl;
	}

	if (color == temp_board.get_turn())
	{ 
		//User
		if (!get_user()) 
		{ 
			char row, cln;
			do
			{ 
				get_user_move(temp_board, row, cln);
			} 
			while(!(pawns_flipped = temp_board.move(row,cln)));	

		}
		//AI
		else if(get_user())
		{ 	
			int temp = 0, move = 0, depth = 1;
			int row, cln;
				
			
			if (temp_board.get_legal_moves_nums() == 1)
			{
				for(row = 0; row < 8; row++)
				{
					for(cln = 0; cln < 8; cln++)
					{
						if(temp_board.permitted(row,cln))
						{
							pawns_flipped = temp_board.move(row,cln);
							goto terminate_loop;
						}
					}
				}
				terminate_loop:;	
			}

			else
			{ 				
				for(depth = 1; depth < 15; depth++)
				{
					temp = best_move(temp_board, depth);
					if(temp == -1)
					{
						break;
					} 
					else
					{
						move = temp;
					}
				}					
				row = move / 8; 
				cln = move % 8;  
				pawns_flipped = temp_board.move(row, cln); 
			}
			
			cout << "AI's choice is (" << row << "," << cln << ")" << endl;
		}
	}
	//No moves left
	else
	{ 	
		if (get_color() == BLACK)
		{
			cout << "Black must pass" << endl;
		}
		else
		{
			cout << "White must pass" << endl;
		}
	}
	return pawns_flipped;
}

inline int Player::min(int a, int b)
{	
	return (a < b) ? a : b;
}

inline int Player::max(int a, int b)
{	
	return (a > b) ? a : b;
}

//Core AI: alpha_beta heuristic
int Player::alpha_beta(Board &temp_board, int depth, int alpha, int beta)
{
	Board child_board = temp_board;
	if (depth == 0 || temp_board.end_of_game())
	{
		return child_board.eval(color);
	}

	//Max case
	if (temp_board.get_turn() == BLACK)
	{ 
		if (temp_board.get_legal_moves_nums() == 0)
		{ 
			child_board.pass();
			alpha = max(alpha, alpha_beta(child_board, depth-1, alpha, beta));
		}	
		else
		{
			for(int i(0); i < 8; i++)
			{
				for(int j(0); j < 8; j++)
				{
					if(temp_board.permitted(i, j))
					{
						child_board = temp_board;
						child_board.move(i,j);
						alpha = max(alpha, alpha_beta(child_board, depth-1, alpha, beta));
						if(beta <= alpha)
						{
							goto max_return_statement;
						}		
					}		
				}
			}
		}	
		max_return_statement:
		return alpha;	
	}	

	//Min case			
	else
	{
		if (temp_board.get_legal_moves_nums() == 0)
		{ 
			child_board.pass();
			beta = min(beta, alpha_beta(child_board, depth-1, alpha, beta));
		}	
		else
		{
			for(int i(0); i < 8; i++)
			{
				for(int j(0); j < 8; j++)
				{
					if(temp_board.permitted(i, j))
					{
						child_board = temp_board;
						child_board.move(i, j);
						beta = min(beta, alpha_beta(child_board, depth-1, alpha, beta));
						if(beta <= alpha)
						{
							goto min_return_statement;
						}	 
					}	
				}
			}
		}	
		min_return_statement:
		return beta;	
	}		
}						

int Player::best_move(Board &temp_board, int depth)
{
	int best_moves[temp_board.get_legal_moves_nums()];
	int	alpha = -1000000, beta = 1000000, temp_alpha, temp_beta, num_of_moves(0), n(0);	 
	Board child = temp_board;
	
	if (temp_board.get_turn() == BLACK)
	{
		for(int i(0); i < 8; i++)
		{
			for(int j(0); j < 8; j++)
			{
				if(temp_board.permitted(i, j))
				{
					n++;
					child = temp_board;
					child.move(i, j);
					temp_alpha = alpha_beta(child, depth-1, alpha-1, beta);
					if(temp_alpha > alpha)
					{
						num_of_moves = 0;
						best_moves[num_of_moves++] = i * 8 + j;
						alpha = temp_alpha;
					}
					else if(temp_alpha == alpha)
					{
						best_moves[num_of_moves++] = i * 8 + j;
					}
				}					
			}
		}
		if(n < temp_board.get_legal_moves_nums())
		{
			return -1;
		}
	}				
	else 
	{
		for(int i(0); i < 8; i++)
		{
			for(int j(0); j < 8; j++)
			{
				if(temp_board.permitted(i, j))
				{
					n++;
					child = temp_board;
					child.move(i, j);
					temp_beta = alpha_beta(child, depth-1, alpha, beta+1);
					if(temp_beta < beta)
					{
						num_of_moves = 0;
						best_moves[num_of_moves++] = i * 8 + j;
						beta = temp_beta;
					}
					else if(temp_beta == beta)
					{
						best_moves[num_of_moves++] = i * 8 + j;
					}	
				}
			}
		}
		if(n < temp_board.get_legal_moves_nums())
		{
			return -1;
		}	
	}
	
	int result;
	if (num_of_moves > 1)
	{
		result = best_moves[rand() % num_of_moves];
	}
	else
	{
		result = best_moves[0];
	}
	
	return result;
}	

void Player::get_user_move(Board &temp_board, char &row, char &cln)
{	
	char user_row, user_cln;
	while(true)
	{
		cout << "Enter the desired row (0-7): ";
		cin >> user_row; 
		if(cin.get() != '\n')
		{
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
			continue; 
		}
		row = user_row - '0';
		if (row >= 0 && row < 8) 
			break;

		cout << "Invalid input!" << endl;
	}
	while(true)
	{
		cout << "Enter the desired column (0-7): ";
		cin >> user_cln; 
		if(cin.get() != '\n')
		{
			while (cin.get() != '\n');
			cout << "Invalid input!" << endl;
			continue; 
		}
		cln = user_cln - '0';
		if (cln >= 0 && cln < 8) 
			break;

		cout << "Invalid input!" << endl;
	}
	cout << "The chosen move is (" << user_row << "," << user_cln << ")" << endl;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "board.hpp"

#define set_colors(x, y) "\33[3" << (xx = x) << ";4" << (yy = y) << "m"
#define finalize "\33[0m"
#define EMPTY '0'
#define BLACK '1'
#define WHITE '2'
static int  xx = 9;
static int  yy = 9;

using namespace std;


Board::Board()
{
	for (int i(0); i < 8; i++)
    {                
	    for (int j(0); j < 8; j++)
        {
			board[i][j] = EMPTY;
		}
	}
	board[3][3] = WHITE;
    board[4][4] = WHITE;
	board[3][4] = BLACK;
    board[4][3] = BLACK;
	turn = BLACK;
	update();
	white_pawns = 2;
    black_pawns = 2;
    game_end = false;
}

Board::Board(char game_board[8][8], char temp_turn, int b_pawns, int w_pawns)
{
	memcpy(board , game_board, 64);
	turn = temp_turn;
	update();
	white_pawns = w_pawns; 
    black_pawns = b_pawns;
	game_end = false;
}

bool Board::end_of_game() 
{	
	return game_end;
}

bool Board::permitted(char x, char y)
{	
	return legal_board[x][y];
}

int Board::get_legal_moves_nums()
{
	return legal_moves_nums;
} 

char Board::get_turn()
{
	return turn;
}

int Board::black_score()
{
	return black_pawns;
}

int Board::white_score()
{
	return white_pawns;
}

void Board::print_row(int row, bool legal_flag)
{	
	for(int i(0); i < 8; i++)
	{
        (i) ? cout << "  " : cout << "\t" << row << " |  " ;
                
		switch(board[row][i])
        {
			case BLACK:
				cout << set_colors(0, 2) << ' ' << finalize;
				break;
			case WHITE:
				cout << set_colors(0, 7) << ' ' << finalize;
				break;
			case EMPTY:
				if (legal_flag && legal_board[row][i])
					cout << set_colors(3, 9) << '-' << finalize;
				else
					cout <<  ' ';
				break;	
			default:
				cerr << "Not permitted\n";
		}
        if (i == 7)
            cout << "  | " << row;
		else
            cout << "  |";
	}
}

void Board::display_board(bool legal_flag)
{
	cout << endl << endl;
	cout <<  "\t                       REVERSI\n";
	cout << "\n\t     0     1     2     3     4     5     6     7  ";
	cout << "\n\t  *************************************************";
	for(int i(0); i < 8; i++)
        {  
		cout << "\n\t  |     |     |     |     |     |     |     |     |\n";
		print_row(i, legal_flag);		
		cout << "\n\t  |     |     |     |     |     |     |     |     |";
		cout << "\n\t  *************************************************";
	}	
	cout << "\n\t     0     1     2     3     4     5     6     7  \n";
	cout << "\n\n\n\t\t\t   Black's Score: " << black_pawns << endl;
	cout <<	"\n\n\n\t\t\t   White's Score: " << white_pawns << endl << endl <<endl;
}

int Board::update()
{
	int row, cln, i, j;
	char color, opponent_color; 
	int temp(0);
	
	color = turn; 
        if (color == BLACK)
                opponent_color = WHITE;
        
        else 
                opponent_color = BLACK;
	
	for (row = 0; row < 8; row++)
        {
		for (cln = 0; cln < 8; cln++)
                { 
			legal_board[row][cln] = false;
			if (board[row][cln] != EMPTY) continue;
			if (cln - 2 >= 0 && board[row][cln - 1] == opponent_color)
                        {	
				for (j = cln - 2; j > 0 && board[row][j] == opponent_color; j--){;}
				if (board[row][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}	
			if (cln + 2 <= 7 && board[row][cln + 1] == opponent_color)
                        {	
				for(j = cln + 2; j < 7 && board[row][j] == opponent_color; j++){;}
				if (board[row][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++; 
                                        continue;
                                }
			}	
			if(row - 2 >= 0 && board[row-1][cln] == opponent_color)
                        {	
				for(i = row - 2; i > 0 && board[i][cln] == opponent_color; i--){;}
				if (board[i][cln] == color)
                                {
                                        legal_board[row][cln]=true;
                                        temp++;
                                        continue;
                                }
			}
			if(row + 2 <= 7 && board[row + 1][cln] == opponent_color)
                        {	
				for(i = row + 2; i < 7 && board[i][cln] == opponent_color; i++){;}	
				if (board[i][cln] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}
			if(row - 2 >= 0 && cln - 2 >= 0 && board[row - 1][cln - 1] == opponent_color)
                        {	
				for(i = row - 2, j = cln - 2; i > 0 && j > 0 && board[i][j] == opponent_color; i--, j--){;} 	
				if (board[i][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}
			if(row - 2 >= 0 && cln + 2 <= 7 && board[row - 1][cln + 1] == opponent_color)
                        {	
				for(i = row - 2, j = cln + 2; i > 0 && j < 7 && board[i][j] == opponent_color; i--, j++){;}
				if (board[i][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}
			if (row + 2 <= 7 && cln - 2 >= 0 && board[row + 1][cln - 1] == opponent_color)
                        {	
				for(i = row + 2, j = cln - 2; i < 7 && j > 0 && board[i][j] == opponent_color; i++, j--){;}	
				if (board[i][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}
			if(row + 2 <= 7 && cln + 2 <= 7 && board[row + 1][cln + 1] == opponent_color)
                        {	
				for(i = row + 2, j = cln + 2; i < 7 && j < 7 && board[i][j] == opponent_color; i++, j++){;}	
				if (board[i][j] == color)
                                {
                                        legal_board[row][cln] = true;
                                        temp++;
                                        continue;
                                }
			}			
		}
	}
	legal_moves_nums = temp;
	return temp;
}	

int Board::move(char row, char cln)
{
	char color, opponent_color; 
	int i(0);
    int j(0);
    int pawns_flipped(0);
	
    color = turn; 
    if (color == BLACK)
    {
		opponent_color = WHITE;
	}
        
    else
	{
        opponent_color = BLACK;
	}

	if(!legal_board[row][cln])
    {
        cout << "Not permitted move" << endl; 
        return 0;
    }

	board[row][cln] = color;
	if(cln - 2 >= 0 && board[row][cln - 1] == opponent_color)
        {	
		for (j = cln - 2; j > 0 && board[row][j] == opponent_color; j--){;} 
		if (board[row][j] == color)
                {
                        while (++j < cln)
                        {
                                board[row][j] = color;
                                pawns_flipped++;
                        }
                }
	}		
	if(cln + 2 <= 7 && board[row][cln + 1] == opponent_color)
        {	
		for (j = cln + 2; j < 7 && board[row][j] == opponent_color; j++){;} 
		if (board[row][j] == color)
                {
                        while (--j > cln)
                        {
                                board[row][j] = color; 
                                pawns_flipped++;
                        }
                }
	}	
	if (row - 2 >= 0 && board[row - 1][cln] == opponent_color)
        {	
		for (i = row - 2; i > 0 && board[i][cln] == opponent_color; i--){;}	
		if (board[i][cln] == color)
                {
                        while (++i < row)
                        {
                                board[i][cln] = color;
                                pawns_flipped++;
                        }
                }
	}
	if (row + 2 <= 7 && board[row + 1][cln] == opponent_color)
        {	
		for (i = row + 2; i < 7 && board[i][cln] == opponent_color; i++) {;}	
		if (board[i][cln] == color)
                {
                        while (--i > row)
                        {
                                board[i][cln] = color;
                                pawns_flipped++;
                        }
                }
	}
	if (row - 2 >= 0 && cln - 2 >= 0 && board[row - 1][cln - 1] == opponent_color)
        {	
		for(i = row - 2, j = cln - 2; i > 0 && j > 0 && board[i][j] == opponent_color; i--, j--){;}	
		if (board[i][j] == color)
                {
                        while (++i < row)
                        {
                                board[i][++j] = color;
                                pawns_flipped++;
                        }
                }
	}
	if(row - 2 >= 0 && cln + 2 <= 7 && board[row - 1][cln + 1] == opponent_color)
        {	
		for(i = row - 2, j = cln + 2; i > 0 && j < 7 && board[i][j] == opponent_color; i--, j++ ){;}	
		if (board[i][j] == color) 
                {
                        while (++i < row)
                        {
                                board[i][--j] = color;
                                pawns_flipped++;
                        }
                }
	}
	if (row + 2 <= 7 && cln - 2 >= 0 && board[row + 1][cln - 1] == opponent_color)
        {	
		for(i = row + 2, j = cln - 2; i < 7 && j > 0 && board[i][j] == opponent_color; i++, j--) {;}	
		if (board[i][j] == color)
                {
                        while (--i > row)
                        {
                                board[i][++j] = color;
                                pawns_flipped++;
                        }
                }
	}
	if (row + 2 <= 7 && cln + 2 <= 7 && board[row + 1][cln + 1] == opponent_color)
        {	
		for (i = row + 2, j = cln + 2; i < 7 && j < 7 && board[i][j] == opponent_color; i++, j++) {;}	
		if (board[i][j] == color)
                {
                        while (--i > row)
                        {
                                board[i][--j] = color;
                                pawns_flipped++;
                        }
                }
	}
	turn = opponent_color;
	update();	
	if (color == BLACK)
        {
                black_pawns += pawns_flipped + 1;
                white_pawns -= pawns_flipped;
        }
	else
        {
                black_pawns -= pawns_flipped;
                white_pawns += pawns_flipped + 1;
        }

	return pawns_flipped;
}

bool Board::pass()
{
	change_turn();
	update();	
	if (legal_moves_nums == 0)
        {
		game_end = true;
		return false;
	}
	return true;
}

int Board::eval(char color)
{       
    int pieces_num(0);
    int temp[5] = {0, 0, 0, 0, 0}; 
    int p,q;
	int X[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int Y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int Z[8][8]={ 50, -1,  5,  2,  2,  5, -1, 50, /**/  -1,-10,  1,  1,  1,  1,-10, -1,  /**/
	               5,  1,  1,  1,  1,  1,  1,  5, /**/   2,  1,  1,  0,  0,  1,  1,  2,  /**/
				   2,  1,  1,  0,  0,  1,  1,  2, /**/   5,  1,  1,  1,  1,  1,  1,  5,  /**/
		 		  -1,-10,  1,  1,  1,  1,-10, -1, /**/  50, -1,  5,  2,  2,  5, -1, 50}; /**/
        if (turn == BLACK)
                int v = 1;
        else
                int v = -1;
        
				  
	switch(color)
        {
		case WHITE:
		case BLACK:
		default:
			if(!game_end) 
                        {
				
				pieces_num = 100 * (float)(black_pawns - white_pawns) / (float)(black_pawns + white_pawns);
				
				//Corner Occupancy
				if(board[0][0] == BLACK) 
                                        temp[0] += 25; 
                                else if(board[0][0] == WHITE) 
                                        temp[0] -= 25; 
				else if(board[0][7] == BLACK) 
                                        temp[0] += 25;
                                else if(board[0][7] == WHITE) 
                                        temp[0] -= 25; 
				else if(board[7][0] == BLACK) 
                                        temp[0] += 25; 
                                else if(board[7][0] == WHITE) 
                                        temp[0] -= 25; 
				else if(board[7][7] == BLACK) 
                                        temp[0] += 25; 
                                else if(board[7][7] == WHITE) 
                                        temp[0] -= 25; 
				
				//Corner closeness
				if(board[0][0] == EMPTY)
                                {
					if(board[1][1] == BLACK) 
                                                temp[2] -= 13; 
                                        else if(board[1][1] == WHITE) 
                                                temp[2] += 13; 
					else if(board[1][0] == BLACK) 
                                                temp[2] -= 6; 
                                        else if(board[1][0] == WHITE) 
                                                temp[2] += 6; 
					else if(board[0][1] == BLACK)
                                                temp[2] -= 6;
                                        else if(board[0][1] == WHITE)
                                                temp[2] += 6;
				}
				if(board[0][7] == EMPTY)
                                {				
					if(board[1][6] == BLACK) 
                                                temp[2] -= 13; 
                                        else if(board[1][6] == WHITE) 
                                                temp[2] += 13; 
					else if(board[1][7] == BLACK) 
                                                temp[2] -= 6; 
                                        else if(board[1][7] == WHITE) 
                                                temp[2] += 6; 
					else if(board[0][6] == BLACK) 
                                                temp[2] -= 6; 
                                        else if(board[0][6] == WHITE) 
                                                temp[2] += 6;
				}
				if(board[7][0] == EMPTY)
                                {	
					if(board[6][1] == BLACK) 
                                                temp[2] -= 13;
                                        else if(board[6][1] == WHITE) 
                                                temp[2] += 13; 
					else if(board[7][1] == BLACK) 
                                                temp[2] -= 6; 
                                        else if(board[7][1] == WHITE)
                                                temp[2] += 6; 
					else if(board[6][0] == BLACK) 
                                                temp[2] -= 6;
                                        else if(board[6][0] == WHITE)  
                                                temp[2] += 6;
				}
				if(board[7][7] == EMPTY)
                {
					if(board[6][6] == BLACK) 
                        temp[2] -= 13;
                    else if(board[6][6] == WHITE) 
                        temp[2] += 13;
					else if(board[7][6] == BLACK) 
                        temp[2] -= 6; 
                    else if(board[7][6] == WHITE) 
                        temp[2] += 6; 
					else if(board[6][7] == BLACK) 
                        temp[2] -= 6; 
                    else if(board[6][7] == WHITE) 
                        temp[2] += 6;
				}	
				
				//Mobility
				int n1(legal_moves_nums);
				change_turn();
                update();
				int n2(legal_moves_nums);
				if(n1 != n2) 
                    temp[1] = 100*temp[4]*(float)(n1 - n2)/(float)(n1 + n2);
				
				int a(0), b(0), c(0), d(0);
				for(int i(0); i < 8; i++)
                {
					for(int j(0); j < 8; j++)
                    {
						if (board[i][j] == EMPTY) 
                            continue;
						if (board[i][j] == BLACK)
                            c += Z[i][j];
                        else
                            d += Z[i][j];
						for(int r(0); r < 8; r++)
                        {
							p = i + X[r]; 
                            q = j + Y[r];
							if(p >= 0 && p < 8 && q >= 0 && q < 7 && board[p][q] == EMPTY)
                            {
								(board[i][j] == BLACK) ? a += 1 : b += 1;
								break;
							}	
						}
					}			
				}
				if(a != b) 
                    temp[3] = 100*(float)(b - a)/(float)(a + b);
                        
				if(c != d)
                    temp[4] = 100*(float)(c - d)/(float)(c + d);
				
				return (2*pieces_num + 120*temp[0] + 60*temp[1] + 80*temp[2] + 45*temp[3] + 20*temp[4]);
			}
			else
                return (512*(black_pawns - white_pawns));
	}
}
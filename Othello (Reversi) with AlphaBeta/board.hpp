#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <fstream>
#include <cstdlib>

#define EMPTY '0'
#define BLACK '1'
#define WHITE '2'

class Board 
{
public:
        Board();
        Board(char game_board[8][8], char turn, int b_pawns, int w_pawns);
        void change_turn() {(turn == BLACK) ? turn = WHITE : turn = BLACK;}
        void display_board(bool legal_flag=true);
        bool permitted(char x, char y);	
        int move(char row, char cln);
        int get_legal_moves_nums();
        bool end_of_game(); 
        char get_turn();
        int black_score();
        int white_score();
        int update();
        bool pass();
        int eval(char color = 0);
                
private:
        char board [8][8];
        bool legal_board[8][8];
        char turn;
        bool game_end;
        int black_pawns;
        int white_pawns;
        int legal_moves_nums;
        void print_row(int row, bool legal_flag);
};




class Player 
{

public:
  Player(char c, bool comp);                          
  char get_color();
  bool get_user();
  int make_move(Board &temp_board);
 
private:
  char color;
  bool computer;
  void get_user_move(Board &temp_board, char &row, char &cln);
  int best_move(Board &temp_board, int depth);
  inline int min(int a, int b);
  inline int max(int a, int b);
  int alpha_beta(Board &temp_board, int depth, int alpha, int beta);
};

#endif
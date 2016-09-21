#ifndef TICGAME_H
#define TICGAME_H
#include "GamePieces.h"
enum LowConstants{
	piece_pos1 = 1,
	piece_pos2=2,
	piece_pos3 = 3,
	coord_length = 4,
	boardLength=5
};



class ticGameBoard
{
	friend ostream &operator << (ostream &out, const ticGameBoard &game);

private:
	game_piece create_board[boardLength][boardLength];

public:

	//ticGameBoard::
	ticGameBoard::ticGameBoard()      //constructor that initialize the member vairables of this game class
	{
		for (int row = 0; row < boardLength; ++row){
			for (int col = 0; col < boardLength; ++col){
				//if border square -> empty, else -> full
				if (row == 0 || row == coord_length || col == 0 || col == coord_length){
					create_board[row][col].display = " ";
				}
				else{
					create_board[row][col].display = " ";

				}
			}
		}
	}


	bool done();
	bool draw();
	int prompt(unsigned int &x_int, unsigned int & y_int);
	int turn();
	bool check_valid();
	void player_X_print();
	void player_O_print();
	void check_win();
	bool which_player(int & times);


	bool chek_move_valid( int & int1, int & int2 );
	int play();

	
};



ostream & operator<<(ostream &out, const ticGameBoard &tic_game_board);
#endif

#include "stdafx.h"
#include "GamePieces.h"
#include "Ticgame.h"
#include <iostream>
#include "Common.h"
#include <string>
#include <sstream>
#include <vector>

ostream & operator<<(ostream &out, const ticGameBoard &game)
{
	//go through each spot and fill in the display
	for (int row = coord_length; row >= 0; --row){
		out << row;
		for (int col = 0; col < boardLength; ++col){

			out << " " << game.create_board[row][col].display;
		}
		out << endl;
		out << endl;
	}
	// display column numbers
	out << " 0 1 2 3 4" << endl;
	return out;
}
bool ticGameBoard::done(){
	// check the diagonal case
	bool req1 = (((create_board[piece_pos1][piece_pos1].display != " ") &&
		(create_board[piece_pos2][piece_pos2].display != " ")) &&
		(create_board[piece_pos3][piece_pos3].display != " "));
	bool req2 = (create_board[piece_pos1][piece_pos1].display == create_board[piece_pos2][piece_pos2].display) && (create_board[piece_pos2][piece_pos2].display == create_board[piece_pos3][piece_pos3].display);
	bool dia_case1 = req1 && req2;
	bool req3 = (((create_board[piece_pos1][piece_pos3].display != " ") &&
		(create_board[piece_pos2][piece_pos2].display != " ")) &&
		(create_board[piece_pos3][piece_pos1].display != " "));
	bool req4 = (create_board[piece_pos1][piece_pos3].display == create_board[piece_pos2][piece_pos2].display) && (create_board[piece_pos2][piece_pos2].display == create_board[piece_pos3][piece_pos1].display);
	bool dia_case2 = req3&&req4;
	bool diagonal = dia_case1 || dia_case2;   //diagonal is true if both cases are true.


	// check horizontal case
	bool horizontal;
	int count1 = 0, count2 = 0;
	int check_case = 1; // check whether the display exits horizontal or vertical case;
	for (int row = piece_pos1; row <= piece_pos3; row++)
	{
		if ((create_board[row][piece_pos1].display == create_board[row][piece_pos2].display)
			&& (create_board[row][piece_pos1].display == create_board[row][piece_pos3].display) && create_board[row][piece_pos1].display != " ")
		{
			count1++;
		}
	}
	horizontal = (count1 >= check_case);

	bool vertical;
	for (int col = piece_pos1; col <= piece_pos3; col++)
	{
		if ((create_board[piece_pos1][col].display == create_board[piece_pos2][col].display) && (create_board[piece_pos2][col].display == create_board[piece_pos3][col].display) && create_board[piece_pos1][col].display != " ")
		{
			count2++;
		}
	}
	vertical = (count2 >= check_case);

	       // if either of the cases are true then the done method will return true
		
	bool result = ((diagonal || vertical) || (horizontal));
	return result;
	
}

bool ticGameBoard::draw(){
	int count = 0;
	int check = 1;
	bool moves = false;
	//find whether there exists empty spece inside the bound 
	for (int row = 1; row <= 3; row++)
	{
		for (int col = 1; col <= 3; col++)
		{
			if (create_board[row][col].display == " ")
			{
				count++;
			}

		}
	}
	if (count >= 1)
		moves = true;
		return !(moves || done()); //return true if both done and moves are false
	

}

int ticGameBoard::prompt(unsigned int &x_int, unsigned int &y_int){
	string user_input;
	bool status = true;
	int x_coor, y_coor;
	while (status)
	{
		cout << "Please enter a comma seperated pair of unsigned decimal integers '0,0' or 'quit'" << endl;
		cin >> user_input;
		if (user_input == "quit")
		{
			status = false;
			return game_quit;
		}
		if ((user_input.length() == 3) && (isdigit(user_input.at(0))) && ((user_input.at(1) == ',') && isdigit(user_input.at(2))))
		{
			size_t position = user_input.find(','); //find the postion of the comma
			user_input.replace(position, 1, " "); // replace the comma with white space
			istringstream iss(user_input);
			iss >> x_coor;
			iss >> y_coor;
			// now check whether the two integer inputs are valid
			if (x_coor <= piece_pos3 && x_coor >= piece_pos1 && y_coor <= piece_pos3 && y_coor >= piece_pos1)
			{
				if (chek_move_valid(x_coor, y_coor))
				{
					x_int = x_coor;
					y_int = y_coor;
					status = false;
				}
				else
				{
					cout << "place was already occupied, pick a difference place" << endl;
				}
			}
			else
			{
				cout << "Invaid, Input are out of bound" << endl;
			}
		}
		else
		{
			cout << "Not a valid command. Please type in again (in comma-separated pair of unsigned decimal integers)." << endl;
		}
	}
	return succeed_promt;

}



int ticGameBoard::turn()
{
	unsigned int x_c;
	unsigned int y_c;
	int prompt_result = 0;
	int count=0;
	bool status = true;
	vector <int> store_xy;


	while (status)
	{
		prompt_result = prompt(x_c, y_c);
		cout << "prompt result= " << prompt_result << endl;

		if (prompt_result == game_quit)
		{
			return game_quit;
			status = false;
		}
		else
		{
			if (count % 2 == 0)
			{
				create_board[x_c][y_c].display = "X";
				cout << *this << endl;
				cout << endl;
				player_X_print();
			}
			else
			{
				create_board[x_c][y_c].display = "O";

				cout << *this << endl;
				player_O_print();
				cout << endl;

			}
			status = false;
		}

	}
	return 0;
}

int ticGameBoard::play(){
	int count = 0;
	unsigned int x_c;
	unsigned int y_c;
	cout << (*this);
	while ((!done()) && (!draw()))
	{
		
		int result = prompt(x_c, y_c);
	
		if (result == game_quit)
		{
			cout << '\n' << "User quit!  The game was played for " << count << " turns." << endl;
			cerr << game_quit << endl;
			return game_quit;
		}
		else
		{	
			count++;
			if (count % 2 == 0)
			{
				create_board[x_c][y_c].display = "X";
				cout << *this << endl;
				cout << endl;
				player_X_print();
			}
			else
			{
				create_board[x_c][y_c].display = "O";

				cout << *this << endl;
				cout << endl;
				player_O_print();
			}
		}
	}
	if (done())
	{
		string player = create_board[x_c][y_c].display;
		cout << "Player " << player << " wins the game!" << endl;
		return succeed;
	}
	if (draw())
	{
		cout << "No valid moves remain!  The game ended after " << count << " turns." << endl;
		cerr << no_valid_space << endl;
		return no_valid_space;
	}


	return succeed;
}
// check whether the board has empty place
bool ticGameBoard::check_valid(){
	int count = 0;
	int check = 1;
	bool empty_moves = false;

	for (int row = 1; row <= 3; row++)
	{
		for (int col = 1; col <= 3; col++)
		{
			if (create_board[row][col].display == " ")
			{
				count++;
			}
			if (count >= 1)
				empty_moves = true;
			break;
		}
	}
	return empty_moves;
}

// print out all X pieces
void ticGameBoard::player_X_print(){
	string output;
	int row, col;
	for (row = 1; row <= 3; row++)
	{
		for (col = 1; col <= 3; col++)
		{
			if (create_board[row][col].display == "X")
			{
				output = output + "; " + to_string(row) + "," + to_string(col);
			}
		}
	}
	output = output.replace(0, 1, "");
	cout << "Player X:" << output << endl;
}
// print out all O pieces
void ticGameBoard::player_O_print(){
	string output;
	int row, col;
	for (row = 1; row <= 3; row++)
	{
		for (col = 1; col <= 3; col++)
		{
			if (create_board[row][col].display == "O")
			{
				output = output + "; " + to_string(row) + "," + to_string(col);
			}
		}
	}
	output = output.replace(0, 1, "");
	cout << "Player O:" << output << endl;
}

// check whether a moves is vaid (only when it moves to a empty space)
bool ticGameBoard::chek_move_valid(int &int1, int &int2){
	if (create_board[int1][int2].display == " ")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ticGameBoard::check_win()
{
	int count_X = 0, count_O = 0;
	for (int row = 1; row <= 3; row++){
		for (int col = 1; col <= 3; col++){
			if (create_board[row][col].display == "X"){
				count_X++;
			}
			if (create_board[row][col].display == "O"){
				count_O++;
			}
		}
	}

	if (count_X > count_O){
		cout << "Player X wins the game" << endl;
	}
	else
	{
		cout << "Player O wins the game" << endl;
	}
}


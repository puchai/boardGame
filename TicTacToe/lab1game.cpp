
#include "stdafx.h"
#include"Common.h"
#include"GameBoard.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<cstring>
using namespace std;

int main(int argc, char* argv[])
{
	//A few useful constants for argument positions
	// minimum_arg = 2;
	// starting_index = 1
	// program_name; = 0

	//check arguemnts
	if (argc != minimum_arg || strcmp(argv[starting_index], "--help") == 0) {

		return usage_message(argv[program_name], "input_file");
	}
	else{
		ifstream ifs;
		ifs.open(argv[starting_index]);
		if (!ifs.is_open()){
			cout << "cannot open input file" << endl;
			return file_cannot_open;
		}
		else
		{
			unsigned int horizontal_extent, vertical_extent;
			int error_code = reading_dimens(ifs, horizontal_extent, vertical_extent);			// check the returned int value of reading_dimens function
			while (error_code == fail_extrating)												// continuely check the value of reading_dimens until it find the dimens.
			{
					error_code = reading_dimens(ifs, horizontal_extent, vertical_extent);
				
			}
			
			if (error_code == fail_getline)												// cannot find dimension if getline function hits the last line and still does not find dimensions
			{
				cout << "Error: Failure Extracting Dimension!" << endl;
				return fail_extrating;
			}
			else
			{
				vector <game_piece> piece_vector;
				game_piece empty_piece;
				empty_piece.color_type = no_color;
				empty_piece.display = " ";
				empty_piece.piece_name = " ";
				for (unsigned int i = 0; i < horizontal_extent*vertical_extent; ++i)
				{
					piece_vector.push_back(empty_piece);								// creat a empty piece vector for later push.
				}
				int result_read = reading_pieces(ifs, piece_vector, horizontal_extent, vertical_extent);

				if (result_read == not_well_formed)
				{
					cout << "fail to extract game pieces' coordinates" << endl;
					return not_well_formed;
				}
				else
				{
					int result_print = print_pieces(piece_vector, horizontal_extent, vertical_extent);						// prin out the lay out of the pieces
					if (result_print == fail_print_NoMatchSize)
					{
						cout << "failure printing--dimensions and vector size donot match" << endl;
					}
					else
					{
						ifs.close();
						extra_credit_print(piece_vector, horizontal_extent, vertical_extent);
						return success_print;
					}
				}
			}
		}
	}
}


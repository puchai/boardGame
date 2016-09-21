#include "stdafx.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include"Common.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

//function that read the dimension of a game board
int reading_dimens(ifstream & in_file, unsigned &int1, unsigned &int2){
	string line;
	if (getline(in_file, line))
	{
		istringstream iss(line);
		if (iss >> int1 && iss >> int2)
		{
			return success_extrating;
		}
		else{
			return fail_extrating; //can getline but cannot extrating
		}
	}
	else
	{
		return fail_getline; //cannot get line
	}
}
int reading_pieces(ifstream& in_file, vector<game_piece>& piece_vector, unsigned int& width, unsigned int& height)
{
	string line;
	string color_str, name, display_str;
	unsigned int horizontal = 0, vertical = 0;
	int error_code = not_well_formed;

	while (getline(in_file, line))      //get all lines.
	{
		istringstream iss_extract(line);  // wrap the string
		if (iss_extract >> color_str && iss_extract >> name
			&& iss_extract >> display_str&&iss_extract >> horizontal &&iss_extract >> vertical)
		{
			piece_color pieceColor = retrun_color_enum(color_str);  // change the color_string to enum piece_color integer value

			if (horizontal < width && vertical < height && pieceColor != invalid_color)  
			{
				int index = width*vertical + horizontal;
				piece_vector[index].color_type = pieceColor;
				piece_vector[index].piece_name = name;
				piece_vector[index].display = display_str;
				error_code = well_formed;
			}
		}

	}
	return error_code;
}

// function that print out the layout of all pieces.
int print_pieces(const vector <game_piece> &vectorPiece, unsigned int width, unsigned int height)
{
	cout << vectorPiece.size() << endl;
	if (vectorPiece.size() != width*height){         //check whether the vector matches the dimens of the gameboard
		return fail_print_NoMatchSize;           
	}
	for (int y = height - 1; y >= 0; y--)
	{
		for (unsigned int x = 0; x <= width - 1; x++)
		{
			cout << vectorPiece[width*y + x].display;            // print out the layout of every single piece
		}
		cout << endl;
	}
	return success_print;
}

int extra_credit_print(const vector <game_piece> &vectorPiece, unsigned int width, unsigned int height)
{
	int neighbour = 0;
	for (unsigned int y = 0; y <=height-1; y++)
	{
		for (unsigned int x = 0; x <= width - 1; x++)
		{
			int left = (x - 1)+(width*y); int right = (x + 1)+width*y; int up = x+width*(y + 1); int down = x+width*(y - 1);
			int leftup = left+1; int rightup = right+1; int leftdown =left-1; int rightdown = right-1;
			if (vectorPiece[width*y + x].color_type != no_color){
				cout << x << "," << y << print_color_string(vectorPiece[width*y + x].color_type)
					<< vectorPiece[width*y + x].piece_name << ":";

				if (left >= 0 && vectorPiece[left].color_type != no_color )
				{
					cout << x-1 << "," << y << " " << print_color_string(vectorPiece[left].color_type) << " " << vectorPiece[left].piece_name << "; ";
				
				}
				
				if (right < width-1 &&  vectorPiece[right].color_type != no_color )
				{
					cout << x+1 << "," << y << " " << print_color_string(vectorPiece[right].color_type) << " " << vectorPiece[right].piece_name << "; ";
					neighbour = 1;
				}
				
				if (up < height-1 &&  vectorPiece[up].color_type != no_color)
				{
					cout << x << "," << y+1 << " " << print_color_string(vectorPiece[up].color_type) << " " << vectorPiece[up].piece_name << "; ";
					neighbour = 1;
				}
				
				if (down >= 0 && vectorPiece[down].color_type != no_color)
				{
					cout << x << "," << y-1 << " " << print_color_string(vectorPiece[down].color_type) << " " << vectorPiece[down].piece_name << "; ";
					neighbour = 1;
				}
				
				if (rightup < (width-1)*(height-1)  && vectorPiece[rightup].color_type != no_color)
				{
					cout << x+1 << "," << y+1 << " " << print_color_string(vectorPiece[rightup].color_type) << " " << vectorPiece[rightup].piece_name << "; ";
					neighbour = 1;
				}
			
				if (rightdown <width-1 && vectorPiece[rightdown].color_type != no_color)
				{
					cout << x+1 << "," << y-1 << " " << print_color_string(vectorPiece[rightdown].color_type) << " " << vectorPiece[rightdown].piece_name << "; ";
					neighbour = 1;
				}
				
				if (leftup <height-1 && leftup>=0  && vectorPiece[leftup].color_type != no_color)
				{
					cout << x-1 << "," << y+1 << " " << print_color_string(vectorPiece[leftup].color_type) << " " << vectorPiece[leftup].piece_name << "; ";
					neighbour = 1;
				}
			
				if (leftdown >= 0  && vectorPiece[leftdown].color_type != no_color)
				{
					cout << x-1 << "," << y-1 << " " << print_color_string(vectorPiece[leftdown].color_type) << " " << vectorPiece[leftdown].piece_name << "; ";
					neighbour = 1;
				}
				
				if (neighbour == 0)
				{
					cout << "no neighbours";
				}
				cout << endl;
				neighbour = 0;

			}         
		}
		
	}

	return succeed;
}

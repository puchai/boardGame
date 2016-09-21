#include "stdafx.h"
#include "GamePieces.h"

string print_color_string(piece_color colors){

	if (colors == red)
		return "red";
	if (colors == white)
		return "white";
	if (colors == black)
		return "black";

	if (colors == no_color)
		return "nocolor";
	else
	{
		return "invalidcolor";
	}
}

piece_color retrun_color_enum(string in_color){
	{
		if (in_color == "red")
		return red;
		if (in_color == "white")
			return white;
		if (in_color == "black")
			return black;
		if (in_color == "nocolor")
			return no_color;
		else
		{
			return invalid_color;
		}
	}


}
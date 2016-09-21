#ifndef GAMEPIECES_H
#define GAMEPIECES_H
#include <string>

using namespace std;
enum piece_color
{
	red,
	black,
	white,
	invalid_color,
	no_color
};



struct game_piece
{
	piece_color color_type;
	string piece_name;
	string display;
};
string print_color_string(piece_color colors);
piece_color retrun_color_enum(string in_color);
#endif
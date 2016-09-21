#ifndef GAMEPIECES_H
#define GAMEPIECES_H
#include <string>
#include <vector>

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

#endif
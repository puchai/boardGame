
#include <vector>
#include <string>
#include "GamePieces.h"
using namespace std;

int reading_dimens(ifstream & in_file, unsigned &int1, unsigned &int2);
int reading_pieces(ifstream& in_file, vector<game_piece>& piece_vector, unsigned int& x, unsigned int& y);
int print_pieces(const vector <game_piece> &vectorPiece, unsigned int x, unsigned int y);
int extra_credit_print(const vector <game_piece> &vectorPiece, unsigned int width, unsigned int height);
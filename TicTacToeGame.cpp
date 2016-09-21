//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This source file contains the methods in derived class TicTacToe

//0 TicTacToeGame constructor
//1 method print()
//2 method prompt(unsigned&, unsigned&)
//3 method done()
//4 method turn()
//5 method stalemate()
//6 reload operator<<: return the ostream reference that was passed in.



#include "stdafx.h"
#include "TicTacToeGame.h"
#include<string>
#include<iomanip>
using namespace std;

TicTacToeGame::TicTacToeGame() :GameBase()
{
	ifstream history;
	history.open("TicTacToe.txt");
	unsigned int x_axis, y_axis;
	string line;
	string piece;

	getline(history, line);
	if (line == "Game Saved")
	{
		for (size_t i = 0; i <= 4; ++i) {
			for (size_t j = 0; j <= 4; ++j) {
				TicTacToeGame::gameB[i][j] = " ";
			}
		}

		while (getline(history, line))
		{
			istringstream iss_extract(line); //wrap the string
			iss_extract >> piece;
			iss_extract >> x_axis;
			iss_extract >> y_axis;
			TicTacToeGame::gameB[x_axis][y_axis] = piece;
			turns++;
		}
		string ClassName = "TicTacToeGame";

	}
	else
	{

		//initialize gameB
		for (size_t i = 0; i <= 4; ++i) {
			for (size_t j = 0; j <= 4; ++j) {
				TicTacToeGame::gameB[i][j] = " ";
			}
		}
		string ClassName = "TicTacToeGame";
	}
}

void TicTacToeGame::print() {
	//insert *this into an ostream?
	cout << *this << endl;
}

int TicTacToeGame::prompt(unsigned &a, unsigned &b) {
	string userInput, currentPlayer;
	string ask;
	string coord1, coord2;

	if (turns % 2 == 0) {
		//1.move the piece to the square.
		currentPlayer = "X";
	}
	else {
		currentPlayer = "O";
	}
	cout << "========Round" << turns + 1 << "=========" << endl;
	cout << "Player " << currentPlayer << ", Please input the position you want to move. E.g., 3,2." << endl;

	cin >> userInput;
	if (userInput == "quit")
	{

		cout << "do you want to save the game?" << endl;
		cout << "please answer with: Y or y (yes), N or n (NO)" << endl;
		cin >> ask;
		while (ask != "y" && ask != "n" && ask != "N" && ask != "Y")
		{
			cout << "Please enter Y or y or N or n " << endl;
			cin >> ask;
		}

		ofstream game_file;
		game_file.open("TicTacToe.txt");
		if (ask == "y" || ask == "Y")
		{
			game_file << "Game Saved\n";
			for (int i = 3; i >= 1; i--)
			{
				for (int j = 1; j <= 3; j++)
				{
					if ((TicTacToeGame::gameB[i][j] == "X") || (TicTacToeGame::gameB[i][j] == "O"))
					{
						game_file << TicTacToeGame::gameB[i][j] << " " << i << " " << j << endl;
					}
				}
			}
			cout << "Game Saved!" << endl;
			game_file.close();
		}
		if (ask == "n" || ask == "N"){
			game_file << "NO DATA";
			game_file.close();
		}


		return QUIT_REQUIRE;
	}
	size_t comma_count = count(userInput.begin(), userInput.end(), ',');
	if (comma_count == 1)
	{
		auto posConmma = userInput.find_first_of(",");
		if (posConmma > 3 || posConmma < 0) {
			return ERROR_INVAILID_INPUT;
		}
		else {
			//position, lenght, replacement
			userInput.replace(posConmma, 1, " ");
			istringstream record(userInput);
			if (record >> coord1 && record >> coord2) {
				a = stoi(coord1);
				b = stoi(coord2);
				return SUCCESS;
			}
			else {
				return ERROR_INVAILID_INPUT;
			}
		}
	}
	else
	{
		return ERROR_INVAILID_INPUT;
	}
}

bool TicTacToeGame::done() {
	//horizontal
	for (int i = 1; i <= 3; ++i) {
		if (gameB[1][i] != " " && gameB[1][i] == gameB[2][i] && gameB[2][i] == gameB[3][i])
		{
			return true;
		}
	}

	//vertical
	for (int i = 1; i <= 3; ++i) {
		if (gameB[i][1] != " " && gameB[i][1] == gameB[i][2] && gameB[i][2] == gameB[i][3])
		{
			return true;
		}
	}

	//diagnoal
	if (gameB[1][1] != " " && gameB[1][1] == gameB[2][2] && gameB[2][2] == gameB[3][3]) {
		return true;
	}
	if (gameB[1][3] != " " && gameB[1][3] == gameB[2][2] && gameB[2][2] == gameB[3][1]) {
		return true;
	}

	return false;
}

int TicTacToeGame::turn() {

	int status;
	unsigned i, j;

here:
	status = prompt(j, i);

	switch (status) {
	case QUIT_REQUIRE:
		return QUIT_REQUIRE;

	case ERROR_INVAILID_INPUT:
		cout << "Please input a valid postion coordinates, eg: 3,2" << endl;
		goto here;

	case SUCCESS:
		if (j*i == 0 || j > 3 || i > 3 || gameB[i][j] != " ") {
			cout << "Your input is exceed the range, or the position you want to move is not avaliable, please double check and input again.\n";
			goto here;
		}
		else {
			//0.get the piece information.
			if (turns % 2 == 0) {
				//1.move the piece to the square.
				gameB[i][j] = "X";
			}
			else {
				gameB[i][j] = "O";
			}
			//2.print out the updated game board.
			cout << "===Game Board===" << endl;
			cout << *this << endl;

			//3.print out the valid move
			cout << "\n";
			cout << "Player " << gameB[i][j] << ":" << j << "," << i << endl;
		}
	}
	return SUCCESS;
}

bool TicTacToeGame::stalemate(){
	if (done() == true){
		return true;
	}

	for (int i = 1; i <= 3; ++i){
		for (int j = 1; j <= 3; ++j){
			if (gameB[i][j] == " "){
				return false;
			}
		}
	}

	return true;
}

ostream &operator<<(ostream &out, TicTacToeGame const &t) {
	//4
	//3
	//2
	//1
	//0
	//  0 1 2 3 4

	for (int j = 4; j >= 0; --j) {
		out << j;
		for (int i = 0; i <= 4; ++i) {
			if (t.gameB[j][i] == " "){
				out << setw(t.lengthOfLongestPiece);
			}
			out << setw(t.lengthOfLongestPiece+1) << t.gameB[j][i];
		}
		out << "\n";
	}
	out << " ";
	for (int c = 0; c <= 4; ++c){
			out << setw(t.lengthOfLongestPiece + 1) << c;
	}
	return out;
}


//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This source file contains the methods in derived class GomokuGame

//0 GomokuGame constructor
//1 method print()
//2 method prompt(unsigned int&, unsigned int&)
//3 method done()
//4 method stalemate()
//5 method turn()
//6 reload operator<<: return the ostream reference that was passed in.

#include "stdafx.h"
#include"GomokuGame.h"
#include<string>
#include<iomanip>
#include <iostream> 
using namespace std;

GomokuGame::GomokuGame() :GameBase()
{
	ifstream history;
	history.open("GoMoKu.txt");
	unsigned int x_axis, y_axis;
	string line;
	string piece;

	getline(history, line);
	if (line == "Game Saved")
	{
		for (size_t i = 0; i <= 18; ++i) {
			for (size_t j = 0; j <= 18; ++j) {
				GomokuGame::gameB[i][j] = " ";
			}
		}

		while (getline(history, line))
		{
			istringstream iss_extract(line); //wrap the string
			iss_extract >> piece;
			iss_extract >> x_axis;
			iss_extract >> y_axis;
			GomokuGame::gameB[x_axis][y_axis] = piece;
			turns++;
		}
		string ClassName = "GomokuGame";

	}
	else
	{
		//initialize gameB
		for (size_t i = 0; i <= 18; ++i) {
			for (size_t j = 0; j <= 18; ++j) {
				GomokuGame::gameB[i][j] = " ";
			}
		}
		string ClassName = "GomokuGame";
	}
}

void GomokuGame::print(){
	cout << *this << endl;
}

int GomokuGame::prompt(unsigned &a, unsigned &b) {
	string userInput, currentPlayer;
	string ask;
	string coord1, coord2;

	if (turns % 2 == 0) {
		//Move the piece to the square.
		currentPlayer = "B";
	}
	else {
		currentPlayer = "W";
	}
	cout << "========Round" << turns + 1 << "=========" << endl;
	cout << "Player " << currentPlayer << ", Please input the position you want to move. E.g., 3,2." << endl;

	//User input
	cin >> userInput;
	cout << userInput << endl;

	//Quit case
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
		game_file.open("Gomoku.txt");
		//Save Game
		if (ask == "y" || ask == "Y")
		{
			game_file << "Game Saved\n";
			for (int i = 18; i >= 0; i--)
			{
				for (int j = 0; j <= 18; j++)
				{
					if ((GomokuGame::gameB[i][j] == "B") || (GomokuGame::gameB[i][j] == "W"))
					{
						game_file << GomokuGame::gameB[i][j] << " " << i << " " << j << endl;
					}
				}
			}
			cout << "Game Saved!" << endl;
			game_file.close();
		}
		//Quit Directly
		if (ask == "n" || ask == "N"){
			game_file << "NO DATA";
			game_file.close();
		}
		return QUIT_REQUIRE;
	}

	//Normal Case
	size_t comma_count = count(userInput.begin(), userInput.end(), ',');
	if (comma_count == 1)
	{
		auto posConmma = userInput.find_first_of(",");
		if (posConmma > 3 || posConmma < 0)
		{
			return ERROR_INVAILID_INPUT;
		}
		else
		{
			//position, lenght, replacement
			userInput.replace(posConmma, 1, " ");
			istringstream record(userInput);
			if (record >> coord1 && record >> coord2) {
				a = stoi(coord1);
				b = stoi(coord2);
				return SUCCESS;
			}
			else
			{
				return ERROR_INVAILID_INPUT;
			}
		}

	}
	else
	{
		cout << "the input format is wrong" << endl;
			return ERROR_INVAILID_INPUT;
	}
}

bool GomokuGame::done(){
	int counts = 1;
	int i = 0;
	int j = 0;
	string current, next;

	//Verticval
	for (int q = 0; q <= 18; ++q){
		i = 0;
		counts = 1;
		while (counts != 5 && i < 19){
			current = gameB[q][i];
			if (current != " "){
				next = gameB[q][i + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			i = i + 1; 
		}
		if (counts == 5){
			return true;
		}
	}

	//Horizotal
	i = 0;
	j = 0;
	for (int p = 0; p <= 18; ++p){
		j = 0;
		counts = 1;
		while (counts != 5 && j < 18){
			current = gameB[j][p];
			if (current != " "){
				next = gameB[j+1][p];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
		}
		if (counts == 5){
			return true;
		}
	}

	//Left_down triangle
	i = 0;
	j = 0;
	for (int q = 4; q <= 18; ++q){
		i = q;
		j = 0;
		counts = 1;
		while (counts != 5 && i > 0){
			current = gameB[i][j];
			if (current != " "){
				next = gameB[i-1][j+1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i - 1;
		}
		if (counts == 5){
			return true;
		}
	}

	//Right_up triangle
	i = 0;
	j = 19;
	for (int p = 1; p <= 15; ++p){
		i = p;
		j = 0;
		counts = 1;
		while (counts != 5 && i < 18){
			current = gameB[i][j];
			if (current != " "){
				next = gameB[i + 1][j - 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j - 1;
			i = i + 1;
		}
		if (counts == 5){
			return true;
		}
	}

	//Right_down triangle
	i = 0;
	j = 0;
	for (int p = 0; p <= 15; ++p){
		i = p;
		j = 0;
		counts = 1;
		while (counts != 5 && i < 18){
			current = gameB[i][j];
			if (current != " "){
				next = gameB[i + 1][j + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i + 1;
		}
		if (counts == 5){
			return true;
		}
	}

	//Left_up triangle
	i = 0;
	j = 1;
	for (int q = 1; q <= 15; ++q){
		j = q;
		i = 0;
		counts = 1;
		while (counts != 5 && j < 18){
			current = gameB[i][j];
			if (current != " "){
				next = gameB[i + 1][j + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i + 1;
		}
		if (counts == 5){
			return true;
		}
	}

	return false;
}

bool GomokuGame::stalemate(){

	int counts = 1;
	int i = 0;
	int j = 0;
	string current, next;

	//verticval
	for (int q = 0; q <= 18; ++q){
		i = 0;
		counts = 1;
		while (counts != 5 && i < 19){
			current = gameB[q][i];
			if (current == " "){
				next = gameB[q][i + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			i = i + 1;
		}
		if (counts == 5){
			return false;
		}
	}

	//horizotal
	i = 0;
	j = 0;
	for (int p = 0; p <= 18; ++p){
		j = 0;
		counts = 1;
		while (counts != 5 && j < 19){
			current = gameB[j][p];
			if (current == " "){
				next = gameB[j + 1][p];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
		}
		if (counts == 5){
			return false;
		}
	}

	//Left_down triangle
	i = 0;
	j = 0;
	for (int q = 4; q <= 18; ++q){
		i = q;
		j = 0;
		counts = 1;
		while (counts != 5 && i > 0){
			current = gameB[i][j];
			if (current == " "){
				next = gameB[i - 1][j + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i - 1;
		}
		if (counts == 5){
			return false;
		}
	}

	//Right_up triangle
	i = 0;
	j = 19;
	for (int p = 1; p <= 15; ++p){
		i = p;
		j = 0;
		counts = 1;
		while (counts != 5 && i < 19){
			current = gameB[i][j];
			if (current == " "){
				next = gameB[i + 1][j - 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j - 1;
			i = i + 1;
		}
		if (counts == 5){
			return false;
		}
	}

	//Right_down triangle
	i = 0;
	j = 0;
	for (int p = 0; p <= 15; ++p){
		i = p;
		j = 0;
		counts = 1;
		while (counts != 5 && i < 19){
			current = gameB[i][j];
			if (current == " "){
				next = gameB[i + 1][j + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i + 1;
		}
		if (counts == 5){
			return false;
		}
	}

	//Left_up triangle
	i = 0;
	j = 1;
	for (int q = 1; q <= 15; ++q){
		j = q;
		i = 0;
		counts = 1;
		while (counts != 5 && j < 19){
			current = gameB[i][j];
			if (current == " "){
				next = gameB[i + 1][j + 1];
				if (next == current){
					counts = counts + 1;
				}
			}
			j = j + 1;
			i = i + 1;
		}
		if (counts == 5){
			return false;
		}
	}

	return true;
}

int GomokuGame::turn(){
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
		if (j*i == 0 || j > 19 || i > 19 || gameB[i-1][j-1] != " ") {
			cout << "Your input is exceed the range, or the position you want to move is not avaliable, please double check and input again.\n";
			goto here;
		}
		else {
			//0.get the piece information.
			if (turns % 2 == 0) {
				//1.move the piece to the square.
				gameB[i - 1][j - 1] = "B";
			}
			else {
				gameB[i - 1][j - 1] = "W";
				}
			cout << "===Game Board===" << endl;
			
			cout << *this << endl;
			//3.print out the valid move
			cout << "\n";
			cout << "Player " << gameB[i-1][j-1] << ":" << j << "," << i << endl;
		}
	}
	return SUCCESS;
}

ostream &operator<<(ostream &out, GomokuGame const &g) {

	for (int j = 18; j >= 0; --j) {
		if (j <= 8){
			out << " " << j + 1;
		}
		else{
			out << j + 1;
		}
		for (int i = 0; i < 19; ++i) {
			if (g.gameB[j][i]==" "){
				out << setw(g.lengthOfLongestPiece+1);
			}
			if (i >= 9){
				out << setw(g.lengthOfLongestPiece + 2) << g.gameB[j][i];
			}
			else{
				out << setw(g.lengthOfLongestPiece + 1) << g.gameB[j][i];
			}

		}
		out << "\n";
	}
	out << " X";

	for (int c = 1; c <= 19; ++c){
		if (c >= 10){
			out << setw(g.lengthOfLongestPiece+2) << c;
		}
		else{
			out << setw(g.lengthOfLongestPiece+1) << c;
		}
	}
	return out;
}


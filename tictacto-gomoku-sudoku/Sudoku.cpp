//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This source file contains the methods in derived class Sudoku

//0 Soduku constructor
//1 method print()
//2 method check()
//3 method done()
//4 method stalemate()
//5 method prompt(unsigned int&, unsigned int&, unsigned int&)
//6 method turn()
//7 reload operator<<: return the ostream reference that was passed in.

#include "stdafx.h"
#include"Sudoku.h"
#include<string>
#include<iomanip>
#include <iostream> 
#include <algorithm>
using namespace std;

void Sudoku::print(){
	cout << *this << endl;
}

Sudoku::Sudoku() :GameBase()
{
	string line;
	ifstream history;
	history.open("Sudoku.txt");
	if (history.is_open()){
		getline(history, line);
	}
	if (line == "NO DATA" || line == "")
	{

		ifstream initial;
		initial.open("sudoku0.txt");
		cout << "open sudoku0?" << initial.is_open() << endl;
		if (initial.is_open()){
			string row, word;
			int tile_counter = 0;
			int j = 0;
			while (getline(initial, row))
			{
				istringstream record(row);

				int i = 0;
				while (record >> word)
				{
					if (word == "0"){ word = " "; }
					gameB[j][i] = word;
					gameInitialB[j][i] = word;
					i++;
					tile_counter++;
					if (tile_counter % 9 == 0)
					{
						j++;
					}
				}

			}
		}
	}
	else
	{
		//Create the gameB from the file.
		string  row, word;
		int tile_counter = 0;
		int j = 0;
		while (getline(history, row))
		{
			istringstream record(row);
			int i = 0;
			while (record >> word)
			{
				if (word == "0"){ word = " "; }
				gameB[j][i] = word;
				gameInitialB[j][i] = word;
				i++;
				tile_counter++;
				if (tile_counter % 9 == 0)
				{
					j++;
				}
			}

		}
	}

	history.close();
}

bool Sudoku::check(){

	string valueS;
	stringstream conversion;
	int valueI;
	int flag = 0;
	bool loop2 = true;

	int validRow[9][9];
	int validCol[9][9];
	int validBox[9][9];

	for (int i = 0; i <= 8; ++i){
		for (int j = 0; j <= 8; ++j){
			validRow[i][j] = 0;
			validCol[i][j] = 0;
			validBox[i][j] = 0;
		}
	}

	for (int i = 0; i <= 8 && loop2; ++i){
		for (int j = 0; j <= 8; ++j){
			valueS = gameB[i][j];
			if (valueS != " "){
				valueI = stoi(valueS);
				validRow[i][valueI - 1]++;
				validCol[j][valueI - 1]++;
				int re = i / 3 * 3 + j / 3;
				validBox[i / 3 * 3 + j / 3][valueI - 1]++;
				if (validRow[i][valueI - 1] > 1 || validCol[j][valueI - 1] > 1 || validBox[i / 3 * 3 + j / 3][valueI - 1] > 1){
					flag = 1;
					cout << "!Attention!: You can not place that number in this position. Please try another number." << endl;
					loop2 = false;
					break;
				}
			}
		}
	}

	if (flag == 1){
		return false;
	}
	else{
		return true;
	}
}

bool Sudoku::done(){

	int counts = 0;
	string current, next;
	bool loop = true;

	for (int i = 0; i <= 8&&loop; ++i){
		for (int j = 0; j <= 8; ++j){
			current = gameB[j][i];
			if (current == " "){
				counts++;
				loop = false;
				break;
			}
		}
	}

	int validRow[9][9];
	int validCol[9][9];
	int validBox[9][9];

	for (int i = 0; i <= 8; ++i){
		for (int j = 0; j <= 8; ++j){
			validRow[i][j] = 0;
			validCol[i][j] = 0;
			validBox[i][j] = 0;
		}
	}

	string valueS;
	stringstream conversion;
	int valueI;
	int flag = 0;
	bool loop2 = true;
	for (int i = 0; i <= 8 && loop2; ++i){
		for (int j = 0; j <= 8; ++j){
			valueS = gameB[i][j];
			if (valueS != " "){
				valueI = stoi(valueS);
				validRow[i][valueI - 1]++;
				validCol[j][valueI - 1]++;
				int re = i / 3 * 3 + j / 3;
				validBox[i / 3 * 3 + j / 3][valueI - 1]++;
				if (validRow[i][valueI - 1] > 1 || validCol[j][valueI - 1] > 1 || validBox[i / 3 * 3 + j / 3][valueI - 1] > 1){
					flag = 1;
					loop2 = false;
					break;
				}
			}
		}
	}

	if (counts + flag == 0){
		return true;
	}
	else{
		return false;
	}
}

bool Sudoku::stalemate(){
	return false;
};

void Sudoku::prompt(unsigned int &a, unsigned int &b, unsigned int &c){

	string userInput, currentPlayer;
	string coord1, coord2, number, previous;
	stringstream conversion;
	int prea, preb, prec, n;

	cout << "========Round" << turns + 1 << "=========" << endl;
	cout << "Please input the position you want to place the tile and the number. E.g., 3,2,8. Means place number 8 in position 3,2" << endl;

	//User Input
	cin >> userInput;

	//Quit Case
	if (userInput == "quit") {
		a = -10;
		b = -10;
		c = -10;
	}

	//Normal Case
	else{
		size_t comma_count = count(userInput.begin(), userInput.end(), ',');
		if (comma_count==2)
		{
			auto posConmma = userInput.find_first_of(",");
			userInput.replace(posConmma, 1, " ");
			auto posConmma2 = userInput.find_first_of(",");
			userInput.replace(posConmma2, 1, " ");
			istringstream record(userInput);
			if (record >> coord1 && record >> coord2&&record >> number)
			{
				prea = stoi(coord1);
				preb = stoi(coord2);
				prec = stoi(number);
				
				if (prea < 0 || prea > 8 || preb < 0 || preb > 8) {
				cout << "Your input is exceed the range, please try again." << endl;
				}
				else if(prec<1||prec>9){
					cout << "You should enter a valid number within 1~9, please try agian." << endl;
				}
				else
				{

					//Check whether the position is avaliable to the number of user input

					//Hold the previous number of that position.
					previous = gameB[prea][preb];
					n = prec;
					conversion << n;

					//Put the number in that position and then run the check.
					gameB[preb][prea] = conversion.str();

					bool status;
					status = check();

					if (status)
					{
						//If check return ture, change a, b, c
						a = prea;
						b = preb;
						c = prec;
					}
					else{
						//If check return false, put the previous number to that position
						gameB[preb][prea] = previous;
					}
				}
			}
		}
		else
		{
			cout << "the input format is incorect, E.g., 3,2,8. Means place number 8 in position 3,2" << endl;
		}
	}
}

int Sudoku::turn(){
	unsigned i, j, n;
	string numb;
	stringstream conversion;

here:
	prompt(j, i, n);

	//Quit Case
	if (i == -10 && j == -10 && n == -10){
		string ask;
		cout << "do you want to save the game?" << endl;
		cout << "please answer with: Y or y (yes), N or n (NO)" << endl;
		cin >> ask;
		while (ask != "y" && ask != "n" && ask != "N" && ask != "Y")
		{
			cout << "Please enter Y or y or N or n " << endl;
			cin >> ask;
		}
		ofstream game_file;
		game_file.open("Sudoku.txt");

		//Save
		if (ask == "y" || ask == "Y")
		{
			game_file << "Game Saved\n";
			for (int i = 0; i <=8; i++)
			{
				for (int j = 0; j <= 8; j++)
				{
					if (Sudoku::gameB[i][j] == " ")
					{
						gameB[i][j] = "0";
					}
					game_file << gameB[i][j]<<" ";
				}
				game_file << "\n";
			}
			cout << "Game Saved!" << endl;
			game_file.close();
		}
		//Quit Directly
		else{
			game_file << "NO DATA";
			game_file.close();
		}
		return QUIT_REQUIRE;
	}

	//If the a,b doesn't exceed the range and input number is valid
	else if (i >= 0 && i <= 8 && j >= 0 && j <= 8){

		//If the position has a default number
		if (gameInitialB[i][j] != " "){
			cout << "You can not overwrite this position, please try another plcae." << endl;
			goto here;
		}

		//Put the number in that position
		else{
			conversion << n;
			gameB[i][j] = conversion.str();

			cout << "===Game Board===" << endl;
			cout << *this << endl;
		}
	}
	return SUCCESS;
}

ostream &operator<<(ostream &out, Sudoku const &g) {

	for (int j = 8; j >= 0; --j){
		out << j << "|";
		for (int i = 0; i <= 8; ++i){
			if (i % 3 == 0){
				out << "|";
			}
			out << g.gameB[j][i] << "|";
		}
		out << "|" << endl;
		if (j % 3 == 0){
			out << "=||=|=|=||=|=|=||=|=|=||" << endl;
		}
		else{
			out << "-||-|-|-||-|-|-||-|-|-||" << endl;
		}
	}
	out << "#||0|1|2||3|4|5||6|7|8||" << endl;
	return out;
}


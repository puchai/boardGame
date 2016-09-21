//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This source file contains the method in the derived class GameBase. And delcare two vairiable gbp and ClassName

//1 method instance()
//2 method play()
//3 method initial(int, char*)

#include "stdafx.h"
#include "GameClass.h"
#include"TicTacToeGame.h"
#include"GomokuGame.h"
#include"Sudoku.h"
#include<string>
using namespace std;

//GameBasePointer
shared_ptr<GameBase> GameBase::gbp=nullptr;
//Current Game Name
string GameBase::ClassName = " ";

shared_ptr<GameBase> GameBase::instance()
{
	if (gbp != nullptr){
		return gbp;
	}
	else{
		throw SHARE_PTR_INVALID;
	}
}

int GameBase::play() {

	int turnStatus;
	bool doneStatus, drawStatus;
	string winner;
	int maxTurn=19*19;

	//1.print out the empty gameboard.
	cout << "Game is beginning!" << endl;
	cout << "====Game Boad====" << endl;
	print();
	cout << "Have Fun!" << endl;
	cout << "============================" << endl;

	while (turns<=maxTurn) { // Call turn, done, draw repeatlly.
		//2.call turn.
		turnStatus = turn();

		if (turnStatus == QUIT_REQUIRE)
		{
			return QUIT_REQUIRE;
		}

		//3.call done.
		doneStatus = done();
		if (doneStatus == true) {
			//3.1.print out the winner.
			if (ClassName != "Sudoku"){
				if (turns % 2 == 0) {
					//1.move the piece to the square.
					winner = "B";
				}
				else {
					winner = "W";
				}
				cout << "Game End. The winner is " << winner << "! Congratulation! " << endl;
				return SUCCESS;
			}
			else{
				cout << "Congratulation! You find the unique solution!" << endl;
//				system("pause");
				return SUCCESS;
			}
		}

		//4.call draw
		drawStatus = stalemate();
		if (drawStatus == true) {
			//4.1.print how many turns were played.
			cout << "You have already played " << turns << " rounds." << endl;
			cout << "However there is no winner this time." << endl;
			cout << "Have a good day!" << endl;
			return GAME_END;
		}
		//5.update the turns.
		turns = turns + 1;
	}

	return SUCCESS;

}

void GameBase::initial(int argc, char * p[])
{

	if (gbp != nullptr){
		throw SHARE_PTR_INVALID;
	}
	else{


		if (argc != PROPERNUMBERINPUTS) 
		{
			throw Wrong_Num_argu;

		}
		else
		{
			string GameName = p[FIRSTINPUT];

			if (GameName == "TicTacToe")
			{
				gbp = make_shared<TicTacToeGame>();
				ClassName = "TicTacToe";
			}
			else if (GameName == "Gomoku")
			{
				gbp = make_shared<GomokuGame>();
				ClassName = "Gomoku";
			}
			else if (GameName == "Sudoku")
			{
				gbp = make_shared<Sudoku>();
				ClassName = "Sudoku";
			}
			else
			{
				throw ERROR_INVAILID_INPUT;
			}
			
		}
	}
}

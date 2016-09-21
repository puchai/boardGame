//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

#include "stdafx.h"
#include"GameClass.h"
#include"TicTacToeGame.h"
#include"GomokuGame.h"
#include<memory>

using namespace std;

int main(int argc, char* argv[])
{
	string instructionInformation;
	string userInput;
	instructionInformation = " Please enter the program name and the game name.\n Enter Example: Lab4.exe TicTacToe.\n Then you will begin a simple tic-tac-toe game.\n Or you can enter Lab.exe Gomoku.\n Then you will start a Gomoku Game.\n Also, you can try Lab4.exe Sudoku to start a Soduku Game.";

	try{
		GameBase::initial(argc, argv);
		return 	GameBase::instance()->play();
	}
	catch (ParseResult error){

		//Error: Invalid share pointer
		if (error == SHARE_PTR_INVALID){
			cout << "Share Pointer Invalid" << endl;
			return SHARE_PTR_INVALID;
		}
		//Error: Invalid input
		if (error == ERROR_INVAILID_INPUT){
			cout << "Your input is incorrect." << endl;
			return Usage_Message(argv[NAME_PROGRAM], instructionInformation);
		}
		//Error: No valid file can be load.
		if (error == NO_FILE_FOUND){
			cout << "No file is found" << endl;
			return NO_FILE_FOUND;
		}
		//Error: Incorrect input argument number.
		if (error == Wrong_Num_argu){
			cout << "You Should Have two arguments" << endl;
			return Usage_Message(argv[NAME_PROGRAM], instructionInformation);
		}
	}
	catch (bad_alloc){
		cout << "Bad Allocation" << endl;
		return OTHER_ERROR;
	}
}


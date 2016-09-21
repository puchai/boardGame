// Lab2game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ticgame.h"
#include <iostream>
#include "Common.h"
using namespace std;

int main(int argc, char* argv[])
{
	string input_name = "TicTacToe";
	if (argc== two_argu && argv[starting_index]==input_name)
	{
		ticGameBoard play_game;
		
		int status = play_game.play();
		return status;
	}
	else
	{
		return usage_message(argv[program_name], "<TicTacToe>");
	}
}

int usage_message(string program_name, string information){
	cout << "Usage: " << program_name << " "<<information << endl;
	return wrong_number_arguments;

}

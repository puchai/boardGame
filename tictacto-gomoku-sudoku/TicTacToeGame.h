#pragma once
//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This head file contains 
//1 derived class TicTacToeGame
//2 reload insertion operator

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "stdafx.h"
#include "GameClass.h"
#include"customize.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

class TicTacToeGame : public GameBase {
	virtual void print();

public:
	string gameB[5][5];

	TicTacToeGame();
	virtual bool done();
	virtual bool stalemate();
	virtual int turn();
	virtual int prompt(unsigned &a, unsigned &b);

	friend ostream &operator<<(ostream &out, TicTacToeGame const &t);

};

ostream &operator<<(ostream &out, TicTacToeGame const &g);
#endif



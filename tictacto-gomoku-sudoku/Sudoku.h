#pragma once
//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This head file contains 
//1 derived class Sudoku
//2 reload insertion operator

#ifndef SUDOKU_H
#define SUDOKU_H

#include"stdafx.h"
#include"GameClass.h"
#include"customize.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Sudoku :public GameBase {
	string gameInitialB[9][9];
	virtual void print();
	bool check();
	
public:
	string gameB[9][9];

	Sudoku();
	virtual bool done();
	virtual bool stalemate();
	virtual void prompt(unsigned int &a, unsigned int &b, unsigned int &c);
	virtual int turn();

	friend ostream &operator<<(ostream &out, Sudoku const &g);

};

ostream &operator<<(ostream &out, Sudoku const &g);
#endif


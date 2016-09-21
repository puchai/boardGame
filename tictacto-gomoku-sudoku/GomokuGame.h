#pragma once
//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This head file contains 
//1 derived class GomokuGame
//2 reload insertion operator

#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include"stdafx.h"
#include"GameClass.h"
#include"customize.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class GomokuGame :public GameBase {
	virtual void print();

public:
	string gameB[19][19];

	GomokuGame();
	virtual bool done();
	virtual bool stalemate();
	virtual int prompt(unsigned &a, unsigned &b);
	virtual int turn();

	friend ostream &operator<<(ostream &out, GomokuGame const &g);

};

ostream &operator<<(ostream &out, GomokuGame const &g);
#endif


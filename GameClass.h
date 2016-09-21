//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This head file contains 
//1 base class GameBase

#ifndef GAMECLASS_H
#define GAMECLASS_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<memory>
using namespace std;


class GameBase{
protected:
	//gameboard is a 5*5 game_piece vector.
	string gameB;
	//Game Board :
	//y=4  [0][4]   [1][4]   [2][4]   [3][4]   [4][4]
	//y=3  [0][3]   [1][3]   [2][3]   [3][3]   [4][3]
	//y=2  [0][2]   [1][2]   [2][2]   [3][2]   [4][2]
	//y=1  [0][1]   [1][1]   [2][1]   [3][1]   [4][1]    weight=5
	//y=0  [0][0]   [1][0]   [2][0]   [3][0]   [4][0]    height=5
	//      x=0      x=1      x=2      x=3      x=4
	int turns = 0; //even X, odd O, 0, ++1
	int lengthOfLongestPiece=1;

	ostream updatedBoard;
	ostream gameBoard;
	static string ClassName;
	static shared_ptr<GameBase> gbp;

public:

	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool stalemate() = 0;
	virtual int turn() = 0;

	int play();

	static void initial(int o, char *p[]);

	static shared_ptr<GameBase> instance();

	GameBase::GameBase()
		: gameB(), updatedBoard(NULL), gameBoard(NULL) {
	};

};

#endif


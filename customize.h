//(Lab4)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This head file contains 
//1 enum Name: the first and the second parameters of arg[].
//2 enum ParseResult: the name and type of errors. 
//3 function Usage_Message: pop up the instruction of program when the input parameters are invalid or not enough.
//4 function lowerCase: convert uppercase letters to lowercase letters.

#ifndef CUSTOMIZE_H
#define CUSTOMIZE_H

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

// Declare an enumeration for the different array indices that are relevant to your program.
enum Name
{
	//Lab(0,1)
	NAME_PROGRAM = 0,
	NAME_INPUT_FILE = 1,

	//Lab(2)
	PROPERNUMBERINPUTS = 2,

	//Lab(3)
	FIRSTINPUT = 1
};

// Declare an enumeration for different success and failure values your program can return.
enum ParseResult
{
	//Lab(0,1)
	SUCCESS = 0,
	ERROR_OPENING_FILE = -1,
	ERROR_NO_ENTER = -2,
	ERROR_NOT_ENOUGH_INPUT = -3,
	ERROR_EMPTY_FILE = -4,
	FAIL_TO_READ_FIRST_LINE = -5,
	FAIL_TO_OPEN_FILE = -6,
	FAIL_TO_EXTRACT_DATA = -7,
	EXCEED_RANGE = -8,
	SIZE_NOT_MATCH = -9,
	CURRENT_LINE_IS_EMPTY = -10,
	EMPTY_GAME_PIECE = -11,

	//Lab(2)
	ERROR_INVAILID_INPUT = -12,
	QUIT_REQUIRE = -13,
	GAMEBORAD_IS_FULL = -14,
	GAME_END = -15,

	SHARE_PTR_INVALID = -16,
	OTHER_ERROR=-17,
	NO_FILE_FOUND=-18,
	ERROR_BAD_NAME=-19,
	Wrong_Num_argu=-20
};

int Usage_Message(char * help, string info);

#endif
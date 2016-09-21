//(Lab3)
//Xuchao Jia
//xuchao.jia@wustl.edu
//Pu Chai
//puchai1994@gmail.com

//This source file contains 
//1 function Usage_Message: pop up the instruction of program when the input parameters are invalid or not enough.
#include "stdafx.h"
#include"customize.h"

using namespace std;

int Usage_Message(char * help, string info){

	//1.print out the program name.
	cout << "Program Name: " << help << endl;

	//2.print out the instruction information.
	cout << info << endl;


	return ERROR_NOT_ENOUGH_INPUT;

}

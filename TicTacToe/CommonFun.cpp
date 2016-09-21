#include "stdafx.h"
#include "Common.h"
#include <algorithm>
#include <iostream>
using namespace std;
// function that transforms an input string 
//to the same string with all chacters in lower case 
int lower_case(string &in_string){
	transform(in_string.begin(), in_string.end(), in_string.begin(), ::tolower);
	return succeed;
}

// usage message
int usage_message(string program_name, string information){
	cout << "Usage: " << program_name << " "<<information << endl;
	return wrong_number_arguments;

}
#include <string>
#include <vector>
using namespace std;


enum member_variable {
	program_name = 0,
	starting_index,
	minimum_arg

};

enum error_code {
	succeed = 0,
	file_cannot_open=1,
	wrong_number_arguments=2,
	success_extrating=3,
	fail_extrating=4,
	fail_getline=5,
	well_formed=6,
	not_well_formed=7,
	success_print=8,
	fail_print_NoMatchSize=9

};
int parse_file(vector<string> & store, char * file_name);
int lower_case(string &in_string);
int usage_message(string program_name, string information);

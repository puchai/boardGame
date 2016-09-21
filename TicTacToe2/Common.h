#include <string>
#include <vector>
using namespace std;


enum member_variable {
	program_name = 0,
	starting_index=1,
	two_argu
	

};

enum error_code {
	succeed = 0,
	wrong_number_arguments = 2,
	game_quit,
	succeed_promt,
	succeed_turn,
	no_valid_space,
	occupied,
	not_in_bound,
	invalid_string

};
int usage_message(string program_name, string information);

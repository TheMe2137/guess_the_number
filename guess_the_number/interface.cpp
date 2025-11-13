#include "lib_of_everything.h" // include header file for function declarations (starting_screen, gra, leaderboard)
using namespace std;
int option;
void print2(string text) {
	cout << "************************************\n" << text << "\n************************************\n";
}
int starting_screen() {// starting screen function (returns option selected by user) little graphic design included :D
	
	print2("Welcome to my number game!");
		print2("1.Start Game");
	if (usernames.size() > 0) { // only show leaderboard option if there are usernames stored
		print2("2.Show the Leaderboards!");
	}
	print2("3.Exit");
	print2("Please select an option (1-3)");

    
    cin >> option;

	switch (option) { // switch case to handle user input and call appropriate functions (game, leaderboard, exit) its so damn cool
	case 1: // start game
        game();
	case 2: // view leaderboard
        leaderboard();
        break;
	case 3: // exit
        cout << "Goodbye!\n";
        break;
	default: // invalid option, close the program
        cout << "Invalid option!\n";
    }

    return 0;
}

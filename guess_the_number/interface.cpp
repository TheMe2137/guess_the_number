#include <iostream> // standard input-output library (cout, cin)
#include <string> 	// string library for using string data structure (std::string)
#include "functions.h" // include header file for function declarations (starting_screen, gra, leaderboard)
#include <vector> // include user class header file to access usernames vector

using namespace std;
int starting_screen() {// starting screen function (returns option selected by user) little graphic design included :D
	cout << "************************************" << endl;
	cout << "*      WELCOME TO GUESS THE       *" << endl;
	cout << "*            NUMBER GAME          *" << endl;
	cout << "************************************" << endl;
	cout << "* 1. Start Game                   *" << endl;
	if (usernames.size() > 0) { // only show leaderboard option if there are usernames stored
		cout << "* 2. View Top 5 Leaderboard       *" << endl;
	}
	cout << "* 3. Exit                         *" << endl;
	cout << "************************************" << endl;
	cout << "Please select an option (1-3): \n************************************\n";

    int option;
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

#include <iostream> // standard input-output library (cout, cin)
#include <list>    // list library for using list data structure (size_t)
#include <algorithm> // algorithm library for sorting and other algorithms (std::sort)
#include <cstdlib> // C Standard Library for random number generation (rand, srand)
#include <vector> // vector library for using vector data structure (std::vector) to be able to store multiple usernames and attempts
#include <ctime> 
#include "functions.h" // include header file for function declarations (starting_screen, gra, leaderboard) to avoid implicit declaration warnings
using namespace std; // standard namespace to avoid prefixing std:: i forgor previeously 
vector<int> attempt; // vector to store number of attempts
vector<int> difficulty_levels; // vector to store difficulty levels
vector<string> usernames;
	int game() { // main game function, returns to starting screen after game ends
		int level;
		int level2;
		vector<string> texts = {"try again!", "aw man, maybe next time! ", "aw dangit!", "ah shit, here we go again ","cmon you can do better then that ","XD nah just give up at this point ","COME OOON ","PLEASE I BEG YOU, GET A LIFE "};
		cout << "************************************\n Select difficulty \n1. Easy(1-50)\n2. Medium(1-100)\n3. Hard(1-250),\n4.Return to starting screen\n************************************\n";
		cin >> level;
		if (level == 1) { // set range based on difficulty level
			level2 = 50;
		}
		else if (level == 2) {
			level2 = 100;
		}
		else if (level == 3) {
			level2 = 250;
		}
		else if (level == 4) { // return to starting screen
			return(starting_screen());
		}
		else {
			cout << "Invalid option! Setting to Easy difficulty by default.\n"; // handle invalid input to avoid crashes
			level2 = 50;
		}
		srand(time(nullptr)); // seed the random number generator
		int number = rand() % level2 + 1;  // generate random number between 1 and level2 (daje modulo  do ustawienia zakresu)
		int guess;
		int attempts = 1;
		string name; // variable to store username
		
		cout << "************************************\nGuess a number between 1 and " << level2 << ": \n************************************\n";
		cin >> guess;
		for (guess; guess != number; ) // main game loop here the magic happens :D
			
		{
			if (guess < number)
			{
				int g = rand() % texts.size(); // generate random index for texts vector
				attempts++;
				cout << "************************************\n" << guess << " is too low! " << texts[g]<< "\nAttempt: " << attempts << "\n * ***********************************\n";
				cin >> guess;
			}
			else if (guess > number)
			{
				int g = rand() % texts.size(); // generate random index for texts vector
				attempts++;
				cout << "************************************\n" << guess << " is too high! "<< texts[g]<<"\nAttempt: " << attempts << "\n * ***********************************\n";
				cin >> guess;
			}
			if (guess == number)
			{
				cout << "************************************\nCongratulations!\n************************************" << endl;
				cout << "************************************\nYou guessed the number " << number << " only with " << attempts << " Try(ies)!\n************************************" << endl;
				cout << "************************************\nPlease input your name to submit the score to Top5 Leaderboard!\n************************************\n" << endl;
				cin >> name;
				attempt.push_back(attempts); // store the number of attempts

				attempts == 0; // reset attempts for next game
				difficulty_levels.push_back(level); // store the difficulty level
				level2 == 0; // reset level2 for next game
				usernames.push_back(name); // store the username
				break;
			}
		}

		return(starting_screen());  // return to starting screen after game ends as intended	

	}
	



int leaderboard() { // function to display the leaderboard
	if (usernames.size() == 0) {	// check if there are any scores and return to starting screen if none
		cout << "************************************\nNo scores yet! Play the game to submit your score!\n************************************\n";
		return (starting_screen());
	}

	for (size_t i = 0; i < usernames.size() - 1; i++) { // sort system to sort usernames and attempts based on attempts (no idea how to use sort function with 3 vectors) read somewhere that its called bubble sort no clue how it works tho xD
		for(size_t j = 0; j < usernames.size() - i - 1; j++) { 
			if (attempt[j] > attempt[j + 1]) {	// compare attempts and swap accordingly
				swap(attempt[j], attempt[j + 1]); // swap attempts
				swap(usernames[j], usernames[j + 1]); // swap usernames
			}
		}
	}
	cout << "************************************\nTop 5 Leaderboard:\n************************************\n";
	for (size_t i = 0; i < usernames.size() && i < 5; i++) { // display top 5
		cout << i + 1 << ". " << usernames[i] << " - " << attempt[i] << " attempts  difficulty "<< difficulty_levels[i]<<"\n ";
	}
	cout << "************************************\nPress 5 to return to starting screen \n************************************";
	int back;
	cin >> back;
	for (back; back != 5; ) { // loop to return to starting screen
		cout << "Invalid option! Press 5 to return to starting screen \n************************************";
		cin >> back;
	}
	return (starting_screen());
}

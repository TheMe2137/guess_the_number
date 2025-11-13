#include "lib_of_everything.h"// include header file for function declarations (starting_screen, gra, leaderboard) to avoid implicit declaration warnings

using namespace std; // standard namespace to avoid prefixing std:: i forgor previeously 

vector<int> attempt; // vector to store number of attempts
vector<int> difficulty_levels; // vector to store difficulty levels
vector<string> usernames;
void print(string text) {
	cout << "************************************\n" << text << "\n************************************\n";
}
	int game() { // main game function, returns to starting screen after game ends
		srand(time(nullptr));
		int level;
		int guess;
		int attempts = 1;
		int level_set;
		string name;
		vector<string> texts = {"try again!", "aw man, maybe next time! ", "aw dangit!", "ah shit, here we go again ","cmon you can do better then that ","XD nah just give up at this point ","COME OOON ","PLEASE I BEG YOU, GET A LIFE "};
		
		print("Select difficulty \n1. Easy(1-50)\n2. Medium(1-100)\n3. Hard(1-250),\n4.Return to starting screen");
		cin >> level;
		
		if (level == 1) { // set range based on difficulty level
			level_set = 50;
		}
		else if (level == 2) {
			level_set = 100;
		}
		else if (level == 3) {
			level_set = 250;
		}
		else if (level == 4) { // return to starting screen
			return(starting_screen());
		}
		else {
			print("Invalid option! Setting to Easy difficulty by default");
			level_set = 50;
		}
		
		int number = rand() % level_set + 1;  // generate random number between 1 and level2 (daje modulo  do ustawienia zakresu)
		string string_level_set = to_string(level_set);
		print("Guess a number between 1 and "+string_level_set);
		cin >> guess;


		for (guess; guess != number; ) // main game loop here the magic happens :
		{
			int g = rand() % texts.size();
			if (guess < number)
			{
				attempts++;
				string string_guess = to_string(guess);
				string string_text = texts[g];
				string string_attempts = to_string(attempts);
				print(string_guess + " is too low! \n" + string_text + " attempt: " + string_attempts);
				cin >> guess;
			}
			else if (guess > number)
			{
				attempts++;
				string string_guess = to_string(guess);
				string string_text = texts[g];
				string string_attempts = to_string(attempts);
				print(string_guess + " is too high! \n" + string_text + " attempt: " + string_attempts);
				cin >> guess;
			}
			
			if (guess == number){
				print("Congratulations!");
				string stringnumber = to_string(number);
				string stringattempts = to_string(attempts);
				print("You guessed the number "+stringnumber+" only with "+stringattempts+" tries!");
				print("Please input your name to submit the score to Top5 Leaderboard!");
				cin >> name;

				attempt.push_back(attempts); // store the number of attempts
				attempts == 0; // reset attempts for next game
				difficulty_levels.push_back(level); // store the difficulty level
				level_set == 0; // reset level2 for next game
				usernames.push_back(name); // store the username
				break;
			}
		}
		return(starting_screen());  // return to starting screen after game ends as intended	
	}
	



int leaderboard() { // function to display the leaderboard
	int back;

	if (usernames.size() == 0) {	// check if there are any scores and return to starting screen if none
		print("No scores yet! Play the game to submit your score!");
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

	print("Top 5 Leaderboard!");
	for (size_t i = 0; i < usernames.size() && i < 5; i++) { // display top 5
		cout << i + 1 << ". " << usernames[i] << " - " << attempt[i] << " attempts  difficulty "<< difficulty_levels[i]<<"\n ";
	}

	print("Press5 to return to starting screen");
	cin >> back;


	for (back; back != 5; ) { // loop to return to starting screen
		print("Invalid option! Press 5 to return to starting screen!");
		cin >> back;
	}
	return (starting_screen());
}

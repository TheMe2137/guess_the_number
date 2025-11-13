#pragma once // make it a header file only included once (to avoid redefinition errors ts happened too many times xD)TOOK ME TOO MUCH TIME TO FIGURE TS OUT MFW
#include <vector>
#include <iostream>
#include <string>
#include <list>    // list library for using list data structure (size_t)
#include <algorithm> // algorithm library for sorting and other algorithms (std::sort)
#include <cstdlib> // C Standard Library for random number generation (rand, srand)
#include <ctime> 


using namespace std;
int starting_screen(); // declaration of starting_screen function
int game(); // declaration of game function (dont mind the name)
int leaderboard(); // declaration of leaderboard 
extern vector<string> usernames; // vector to store 
//void abcd() {
	//cout << "************************************\n" << text << "************************************\n";


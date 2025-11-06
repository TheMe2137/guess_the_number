#pragma once // make it a header file only included once (to avoid redefinition errors ts happened too many times xD)TOOK ME TOO MUCH TIME TO FIGURE TS OUT MFW
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int starting_screen(); // declaration of starting_screen function
int game(); // declaration of game function (dont mind the name)
int leaderboard(); // declaration of leaderboard function
extern vector<string> usernames; // vector to store usernames

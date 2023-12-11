#ifndef SECONDARYFUNCTIONS_H 
#define SECONDARYFUNCTIONS_H 

#include <string>
#include <vector>
#include "recipeClass.h"
#include <iostream>
#include <limits>

//This is so that the user info defaults can be saved globaly.
//It was going to work with usernames and saved info
//but it was scrapped.
using namespace std;
extern string userInfo[6];


int numCheck(int limit);
				/*
				* Purpose:
				* Streamline errorchecking and user input
				* 
				* Summary:
				* Is a looping function desighned to streamline the error
				* checking in my code. It will acsept an intager as a paramiter
				* that will determin what user inputs will be acsepted. Will continue
				* asking for user input untill valid input is entered.
				* 
				* Post Condition:
				* Returns an intager value in the required range.
				*/

void setup();
				/*
				* Purpose:
				* Get user information
				* 
				* Summary:
				* This function will be called early on to get some of the inital information required
				* for sorting and filtering the retrieved recipe list.
				* 
				* Post Condition:
				* User information for expirience and avalable equipment will be updated
				* to user's specifications.
				*/

string fillValue(string);
				/*
				* Purpose:
				* Get user information and better sepperate setup() code.
				* 
				* Summary:
				* Takes a default value as a string and asks user if it needs changed. If it
				* does need changed then it will ask for a number or string respective to 
				* wether or not the paramiter can be converted to an intager.
				* 
				* Post Condition:
				* Returns the new values as strings.
				*/

string listCheck(string);
				/*
				* Purpose:
				* To alow the user to modify a list.
				* 
				* Summary:
				* Takes a list in string form seperated by commas as paramiter. It then converts
				* that string into a vector containing values seperated by commas. Afterwards in
				* a loop it asks the user how they want to modify the list until they chose to exit.
				* It can display the list, deleate an item from the list, and add an item to the list
				* using addString().
				* 
				* Note:
				* I chose vectors, because they fuction a bit like arays but have an adaptive limit, making
				* them much easier to add and subtract values from. This is especaly importaint here, as 
				* it's entire purpos is to modify a list of items.
				* 
				* Post Condition:
				* Returns the list as a string seperated by commas.
				*/

string addString();
				/*
				* Purpose:
				* To take user input as a single word, and check to enshure it is a valid input.
				* 
				* Summary:
				* This function will request the user to enter a word in lowercase letters. It will then
				* check to enshure the word is made of valid characters, if it is not, it will throw an exeption
				* and request the user to try again untill a valid input is recieved.
				* 
				* Post Condition:
				* Returns a user entered lowercase word as a string.
				*/

//void usernamePassword();																								//REMOVE

//string spellCheck(string);																							//REMOVE

vector<recipe> recipeReader();
				/*
				* Purpose:
				* To read information from a text file holding all recipies and record valid recipies
				* in a class and vector.
				* 
				* Summary:
				* This function reads the recipies from a file into a class, and then tests to see if
				* the recipe meets minimum requirements. If it does meet those requirements it is stored
				* in a vector. recipeReader() is where binary either meets or does not meet qualifications
				* for potentail recipes are sorted out. It is in efect a filter. It filters based on skill
				* and if there is a maching ingredient.
				* 
				* Note:
				* Vectors are used here due to potentaly large amounts of modifications to a list, as well
				* as vector's ability to be a returning value.
				* 
				* Post Condition:
				* Returns a vector with recipies that meet minimum requirements.
				*/

vector<recipe> recipeScore(vector<recipe> recipeArray);
/*
				* Purpose:
				* To give each recipe stored in a vector a score it can be sorted by.
				* 
				* Summary:
				* This program goes through each recipie and records information. First is how many
				* ingredients match the user's main avalable ingredients. Then how much epuipment is
				* required, and finaly how much of that equipment maches the user's equipment.
				* The equipment is valued using a percentage, while ingredients are simply add a set
				* ammount to the score. 
				* 
				* Note: 
				* The program values these aspects diferaintly because the user only enters a few of the
				* ingredients they want to use.
				* 
				* Post Condition:
				* Sets each recipie's score, so that it can be sorted.
				*/

vector<recipe> insertionSort(vector<recipe>, int);
/*
				* Purpose:
				* Sorts a vector of recipies acording to their score from highest to lowwest.
				* 
				* Summary:
				* Sorts a vector of recipies acording to their score from highest to lowwest, using a modified
				* insertion sort program.
				* 
				* Post Condition:
				* Returns a sorted vector of recipies
				*/

bool checkMatch(string str, string substr);
				/*
				* Purpose:
				* To check if substring is in string
				* 
				* Summary:
				* This program checks if substring is in string. If it is then it will return true. 
				* 
				* Post Condition:
				* Returns true or false baced on if substring is in string.
				*/

vector<int> checkInfoI(string recipeHolder[]);
				/*
				* Purpose:
				* To split the code for recipe reader.
				* 
				* Summary:
				* This part of the code checks and finds the information on how many ingredients
				* match and how many ingredients there are total.
				* 
				* Note:
				* There are two of these programs and they are used simularly but not exactly the same.
				* 
				* Post Condition:
				* Returns values in a vector for how many ingredients match and how many ingredients there are total.
				*/

vector<int> checkInfoE(string stri);
				/*
				* Purpose:
				* Mesure how much equipment there is in a recipe and how many mach the user's equipment
				* 
				* Summary:
				* This part of the code checks and finds the information on how much  epuipment total there is 
				* and how many of them mach the user's.
				* 
				* Note:
				* There are two of these programs and they are used simularly but not exactly the same.
				* 
				* Post Condition:
				* Returns how much user equipment maches recipe equipment and how much epuipment total there is in the recipe.
				*/








//SCRAPED FUNCTIONS

/*
int readUserInfo(string Username, string Password);
	finds and reads user information from file based on username
	and pasword in format username, password, info, info
	into a global variable storing the curent users information
	and returns the line number of that user, is a negitive if it does not exist

writeUserInfo(insert all info here);
	initialises and records all changes to user info then uses
	the line number of the user to rewrite the entire line to mach
	all changes made.
	
*/

#endif

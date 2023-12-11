#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

#include <vector>
#include "recipeClass.h"


void newOrReturning();
				/*
				* Prompts a question and then links to setup()
				* After setup is compleated links to mainIngredients()
				* Was initaly planed to also ask for username and password
				* but the functionality was scrapped last muinute
				*/

void mainIngredients();
				/*
				* Prompts the user to modify the list of ingredients using listCheck()
				* Links to displayRecipieList()
				*/

void displayRecipieList();
				/*
				* links to varius functions to print out a list of recipies.
				* The most importaint of these functions are recipeReader(),
				* recipeScore(), and insertionSort(). These functions read a
				* file containing all recipies, give those recipies a score
				* and then sort them acordingly.
				* Then this program will format and print quick summaries of each recipie,
				* which the user can then select, load more recipies or exit.
				*/

void printFullRecipie(recipe);
				/*
				* When the user choses to select a recipe it links to this function.
				* This fuction formats the recipe and prints it out accordingly for
				* the user to examin and use.
				*/



#endif
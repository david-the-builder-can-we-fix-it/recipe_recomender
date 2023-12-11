#ifndef RECIPECLASS_H
#define RECIPECLASS_H

#include <iostream>
#include <cassert>

using namespace std; 


//Recipe class, overall self explanitory as it is a simple class that holds many values.
class recipe
{
public:
	recipe()
	{
		title = "Hi recipe default";
		expirience = 3;
		summary = "This is a summary";
		equipment = "stove,microwave";
		ingredients = "hotdog";
		instructions = "Place hotdog in microwave.,Then cook it.,Then eat it.";
	}

	recipe(string titl, int scor, int exp, string summ, string equi, string ingr, string instruc)
	{
		title = titl;
		expirience = exp;
		summary = summ;
		equipment = equi;
		ingredients = ingr;
		instructions = instruc;
		score = scor;
	}

	string getTitle()
	{
		return title;
	}

	int getExpirience()
	{
		return expirience;
	}

	string getSummary()
	{
		return summary;
	}

	string getEquipment()
	{
		return equipment;
	}

	string getIngredients()
	{
		return ingredients;
	}

	string getInstructions()
	{
		return instructions;
	}

	int getValue()
	{
		return value;
	}

	int getDivercity()
	{
		return divercity;
	}

	void setValue(int val)
	{
		value = val;
	}

	void setDivercity(int div)
	{
		divercity = div;
	}


private:
	string title;
	int expirience;
	string summary;
	string equipment;
	string ingredients;
	string instructions;
	int score;
	int value;
	int divercity;
};










#endif

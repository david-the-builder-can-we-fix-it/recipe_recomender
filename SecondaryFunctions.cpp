#include "SecondaryFunctions.h"
#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <limits>

#include <stdio.h>

using namespace std;


//custom exeption class
class invalidInput : public std::exception {
public:
    string what() {
    return "\nSorry that was not a valid responce, please try again.\n";
    }
};


int numCheck(int limit)
{
    int in = -999;

    //while the input is incorect, ask for input
    while (in == -999)
    {
        try {
            // Block of code to try
            if (!(cin >> in))
            {
                // report not a number
                throw invalidInput();
            }
            else if (in < 0 || in > limit)
                // report invalid range
                throw in;
        }
        catch (const int error) {
            cout << "\nSorry " << error << " is not an option, please try again.\n";
            in = -999;
            cin.clear();
        }
        catch (const invalidInput&)
        {
            //let program know input is incorect and clear / ignore cin so it can request next input in loop.
            in = -999;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << invalidInput().what();
            //pause is required to prevent infinite loop when entering non-number
            system("pause");
        }
    }
    

    return in;
}



void setup() // include variable that all user info is stored on
{

    //expirence
    cout << "\n\nPlease rate your expirience with cooking from one to five.";
    userInfo[2] = fillValue(userInfo[2]);

    //equipment
    cout << "\nPlease modify the list of your avalable equipment.";
    userInfo[3] = fillValue(userInfo[3]);


    //IGNORE - this is for me so I can modify it to be better some day.
    // 
    //ingredient divercity      NOT TAKEN INTO ACOUNT
    //cout << "\nPlease rate your ingredient divercity from one to five. As in rate how many extra ingredients you have.";
    //userInfo[4] = fillValue(userInfo[4]);

    /*
    //username and password
    if (userInfo[0] == "User" && userInfo[1] == "Pass")
    {
        //change username
        cout << "\nEnter new username.\n";
        userInfo[0] = addString();

        //change password
        cout << "\nEnter new password.\n";
        userInfo[1] = addString();
    }
*/
    
}









string fillValue(string str)
{
    int correct;

    //print default value and request answer
    cout << "\nThe default value is " << str << " is this correct? 0 if yes 1 if no:  ";
    correct = numCheck(1);

    if (correct == 0)
    {
        //do nothing and move on
    }
    else if (correct == 1)
    {
        //check if can be converted to int
        if (isdigit(str[0]))
        {
            //request input of type int and set value
            cout << "\nEnter a Number between 1 and 5.\n";
            int in = numCheck(5);
            str = to_string(in);
        }
        else
        {
            //Request input of type string and set value
            str = listCheck(str);
        }
    }
    else
    {
        cout << "error";
    }

    return str;
}










string listCheck(string str)
{
    string stri;
    int in = 2;

    //start of convert to string
    stringstream ss(str);
    vector<string> result;

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }

    for (int i = 0; i < result.size(); i++)
        cout << "\n" << result[i];
    //end of convert to string

    //start of ask input
    while (in != 0)
    {

        cout << "\nPress 1 to delete, 2 to add an item, 3 to view the list, or 0 to finish editing the list.    ";
        in = numCheck(3);

        if (in == 1)
        {
            //delete item with 1 being position 0.
            cout << "Wich item do you want to delete? enter it's number. ";
            in = numCheck(result.size()) - 1;
            //if it isnt an invalid value (0)
            if (in != -1)
            {
                result.erase(result.begin() + in);
            }
            else
            {
                cout << "\nSorry but 0 isnt an option.\n";
            }
            //needed for ocational reset
            in = 1;
        }
        else if (in == 2)
        {
            //add item
            string newItem;

            //try loop
            newItem = addString();

            //spellChecking                 SCRAPED
            //newItem = spellCheck(newItem);

            // set to lowercase
            //sorta copied the code for this line cause i couldnt get tolower() to work
            transform(newItem.begin(), newItem.end(), newItem.begin(), [](unsigned char c) { return std::tolower(c); });

            //item is now added
            result.push_back(newItem);
        }
        else if (in == 3)
        {
            //display list
            cout << "\n";
            for (int i = 0; i < result.size(); i++)
                cout << "    " << result[i];
            cout << "\n";
        }
        else
        {
            //finished editing list
            stri = result[0];
            for (int i = 1; i < result.size(); i++)
                stri += "," + result[i];
        }
    }
    return str;
}








string addString()
{
    string allChar = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string newItem = "";

    //try loop
    while (newItem == "")
    {
        try {
            cout << "\n Enter item.(single word) \n";
            cin >> newItem;

            //check every character is valid
            for (int i = 0; i < newItem.length(); i++)
            {
                if (allChar.find(newItem[i]) == string::npos)
                {
                    throw newItem[i];
                }
            }

        }
        catch (char error) {
            //exeptions
            newItem = "";
            cout << "\nSorry " << error << " is not a valid character, please try using only characters.\n";
            cout << "Enter here: ";
            //reset cin just in case
            cin.clear();
        }
    }
    return newItem;
}








//IGNORE            - for me after a few months
void usernamePassword()
{
    /*
    ifstream myfile("recipes.txt");
    string myline;

    if (myfile.is_open()) {
        while (myfile) {

            //get the line
            getline(myfile, myline);
        }
    }
*/


    setup();
    
    /*
    int line;
    //enter username
    cout << "\nEnter username.\n";
    userInfo[0] = addString();

    //enter password
    cout << "\nEnter password.\n";
    userInfo[1] = addString();
    */


    //check for username
    //line = readUserInfo(userInfo[0], userInfo[0])
    // if line is anything else, save information.
    // if line == -1, does not exist, ask again
}




// not implemented
string spellCheck(string str)
{
    //check spelling
    return str;
};














//reader is where binary meets or does not meet
//qualifications for potentail recipes are sorted out
//it is in efect a filter
vector<recipe> recipeReader()
{
    vector<recipe> list;
    bool pass = false;
    //read from file into class
    //check line if is title


    ifstream myfile("recipes.txt");
    //string mystring;

    string myline = "NotEmpty";


    int userExp;
    int recipeExp;
    float recipeSc;
    string recipeHolder[7] = { "", "", "", "", "", "", ""};

    
    if (myfile.is_open()) {
        while (myfile) {

            //get the line
            getline(myfile, myline);

            //if it is a new recipe
            if (myline == "")
            {
                //check and store information from last one
                
                //if not first item then store information
                if (recipeHolder[0] != "")
                {
                    vector<int> a = checkInfoI(recipeHolder);
                    if (a[0] == 1)
                    {
                        userExp = stoi(userInfo[4]);
                        recipeExp = stoi(recipeHolder[1]);
                        recipeSc = stof(recipeHolder[2]);
                        recipe redRec(recipeHolder[0], recipeSc, recipeExp, recipeHolder[3], recipeHolder[4], recipeHolder[5], recipeHolder[6]);
                        list.push_back(redRec);
                    }
                }
                //END OF CHECHING AND STORING INFORMATION FROM LAST ONE




                //store varius new information
                for (int i = 0; i < 6; i++)
                {
                    recipeHolder[6] = "";
                    getline(myfile, myline);
                    recipeHolder[i] = myline;
                }
            }
            else
            {
                //store information here.
                
                //store all instructions in single string
                recipeHolder[6] = recipeHolder[6] + "," + myline;
            }

        
        }
    }

    //store information if passes checks
    vector<int> a = checkInfoI(recipeHolder);
    if (a[0] == 1)
    {
        userExp = stoi(userInfo[4]);
        recipeExp = stoi(recipeHolder[1]);
        recipeSc = stof(recipeHolder[2]);
        recipe redRec(recipeHolder[0], recipeSc, recipeExp, recipeHolder[3], recipeHolder[4], recipeHolder[5], recipeHolder[6]);
        list.push_back(redRec);
    }

    return list;
}









//in sorter each will get scores calculated and 
//then sorted in an according order                             CURENTLY DOENST TAKE SCORE INTO ACCOUNT
vector<recipe> recipeScore(vector<recipe> recipeArray)
{
    vector<int> ammounts;
    string str[7];
    vector<int> ingr;
    vector<int> equi;

    float percent;
    int value;
    
    int equipCount = 0;
    int ingredCount = 0;
    int equipMatches = 0;
    int ingredMatches = 0;

    // set the score for each recipie baced on ingredients and equipment

    //iterate over every item
    for (int i = 0; i < recipeArray.size(); i++)
    {

        //how many ingredents match
        str[1] = "1";
        str[5] = recipeArray[i].getIngredients();
        ingr = checkInfoI(str);
        ingredMatches = ingr[1];
        //cout << "\n" << ammounts[1] << "\n";

        //Check equipment stats
        equi = checkInfoE(recipeArray[i].getEquipment());

        equipCount = equi[0];
        ingredCount = ingr[0];
        equipMatches = equi[1];
        


        //set value
        percent = ((float) equipMatches / (float) equipCount) * 10;
        value = (ingredMatches * 10) + percent;
        recipeArray[i].setValue(value);
        
        //set divercity value
        recipeArray[i].setDivercity(ingredCount);

        //reset variables
        equipMatches = 0;
        ingredCount = 0;
        ingredMatches = 0;
        equipCount = 0;
    }

    //return array with scores
    return recipeArray;
}






vector<recipe> insertionSort(vector<recipe> v, int length)
{
    //convert to array
    recipe* list = new recipe[length];
    copy(v.begin(), v.end(), list);

    //sort
    for (int firOutOfOrd = 1; firOutOfOrd < length; firOutOfOrd++)
    {
        if (list[firOutOfOrd].getValue() < list[firOutOfOrd - 1].getValue())
        {
            recipe temp = list[firOutOfOrd];
            int location = firOutOfOrd;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1].getValue() > temp.getValue());
            list[location] = temp;
        }
    }
    //convert to vector
    vector<recipe> result;
    for (int i = 0; i < length; i++)
    {
        result.push_back(list[i]);
    }

    //return array in form vector
    return result;
}






bool checkMatch(string str, string substr)
{
    // over each character and checking for maches to see if
    // substring is in string
    bool isPresent = false;
    for (int i = 0; str[i] != '\0'; i++) {
        isPresent = false;
        for (int j = 0; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j]) {
                isPresent = false;
                break;
            }
            isPresent = true;
        }
        if (isPresent) {
            break;
        }
    }
    if (isPresent) {
        return true;
    }
    else {
        return false;
    }
}






vector<int> checkInfoI(string recipeHolder[])
{
    bool pass = false;
    int userExp;
    int recipeExp;
    int count = 0;
    int itPass = 0;

    // CHECK INFO
    //
    //CHECK FOR MACHING INGREDIENT
    stringstream ss(userInfo[5]);
    vector<string> result;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }

    //check if word matches
    for (int i = 0; i < result.size(); i++)
    {
        bool exists = checkMatch(recipeHolder[5], result[i]);               //REMOVE FIVE
        if (exists == true)
        {
            pass = true;
            count += 1;
        }
    }


    //CHECK FOR EXPIRIENCE
    userExp = stoi(userInfo[2]);
    recipeExp = stoi(recipeHolder[1]);
    //cout << "\nUser information string num expirience " << userExp;
    if (userExp > recipeExp)
    {
        if ((userExp - recipeExp) > 1)
        {
            pass = false;
        }
    }
    else if (userExp < recipeExp)
    {
        if ((recipeExp - userExp) > 1)
        {
            pass = false;
        }  
    }

    if (pass)
    {
        itPass = 1;
    }


    vector<int> a;
    a.push_back(itPass);
    a.push_back(count);
    a.push_back(result.size());

    return a;
    //return pass;
}






vector<int> checkInfoE(string stri)                                     //same as before, but with equipment now.
{
    vector<int> ammounts;
    bool exists;

    int count = 0;
    int ingredCount = 0;
    int equipMatches = 0;

    stringstream ss(userInfo[3]);
    vector<string> result;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }
    count = result.size();


    for (int i = 0; i < result.size(); i++)
    {
        exists = false;
        exists = checkMatch(stri, result[i]);
        if (exists == true)
        {
            equipMatches += 1;
        }
    }

    ammounts.push_back(count);
    ammounts.push_back(equipMatches);

    return ammounts;
}

#include <iostream>
#include "functions.h"
#include "SecondaryFunctions.h"
#include "recipeClass.h"
#include <vector>
#include <sstream>

using namespace std;

//main functions
void newOrReturning()
{
    cout << "\nWelcome to The Recipe Recomender!";
    setup();
    //next function
    mainIngredients();
}









void mainIngredients()
{
    cout << "\nList of main ingredients here.\n";
    userInfo[5] = listCheck(userInfo[5]);
    
    displayRecipieList();
}





void printFullRecipie(recipe rec)
{
    int i = 60;
    int t = 59;

    cout << "\n\n\n\n\nThe Full Recipie\n\n";
    
    cout << "Title:";
    cout << "\n" << rec.getTitle();
    cout << "\n\nIngredients:";
    cout << "\n" << rec.getIngredients();
    cout << "\n\nExpirience:";
    cout << "\n" << rec.getExpirience();

    cout << "\n\nSummary:";

    //the summary needs unique formating
    for (int v = 0; v < rec.getSummary().length();)
    {

        //while last letter is character
        //reduce numn, OR if there are too few characters
        //just play the remaining.
        if (rec.getSummary().length() - v <= 60)
        {
            i = rec.getSummary().length() - v - 1;
            cout << "\n" << rec.getSummary().substr(v, i);
            break;
        }
        else
        {
            //check character until " "
            t = 59;
            while (rec.getSummary().substr(v, 60).at(t) != ' ')
            {
                t--;
                i = t + 1;
                
            }
        }

        cout << "\n" << rec.getSummary().substr(v, i);

        v += i;

    }

    //print out the equipment list
    cout << "\n\nEquipment:";
    cout << "\n" << "            " << rec.getEquipment();






    //print out all steps
    //start of convert to string
    stringstream ss(rec.getInstructions());
    vector<string> result;

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }

    for (int w = 0; w < result.size(); w++)
    {
        cout << "\n\nStep" << w << ".";

        for (int v = 0; v < result[w].length();)
        {

            //while last letter is character
            //reduce numn, OR if there are too few characters
            //just play the remaining.
            if (result[w].length() - v <= 60)
            {
                i = result[w].length() - v - 1;
                cout << "\n" << result[w].substr(v, i);
                break;
            }
            else
            {
                //check character until " "
                t = 59;
                while (result[w].substr(v, 60).at(t) != ' ')
                {
                    t--;
                    i = t + 1;
                }
            }

            cout << "\n" << result[w].substr(v, i);

            v += i;

        }
    }
    //end of convert to string

    cout << "\n";
}













//in display list the list will be displayed
//and the user will modify search paramiters.
//to avoid constaint reordering the search
//paramiters will act like filters rather than
//score modifyers.
void displayRecipieList()
{
    int in = 1;
    string summ;
    int leng = 30;
    vector<recipe> recipeVector;

    int i = 0;
    int total = 5;

    //recipe reader and filter baced on if it has one of the main ingredients in it.
    recipeVector = recipeReader();


    //assighn value/score baced on how many ingredients match and the percent of the equipment the user has claimed to have
    //the percent of the equipment the user has claimed to have. Equipment is in percent because I do not expect the user to enter all
    //their information, just the most importaint or noteworthy.
    recipeVector = recipeScore(recipeVector);

    //recipe sorter
    recipeVector = insertionSort(recipeVector, recipeVector.size());



    //constrain results to search paramiters until five results are found
    // display results
    // ask if want any or to load more results enstied.
    while (in != 0)
    {
        while (i < total + 1 && i < recipeVector.size())
        {
            cout << "\n" << "         " << i+1 << ". " << recipeVector[i].getTitle();
            cout << "\n" << "            " << recipeVector[i].getIngredients();
            cout << "\n" << "            Expirience:" << recipeVector[i].getExpirience();

            cout << "\n" << "            Summary:";
            //the summary needs unique formating
            for (int v = 0; v < 60 && v < recipeVector[i].getSummary().length(); v += 30)
            {
                cout << "\n" << "            " << recipeVector[i].getSummary().substr(v, 30);
                if (recipeVector[i].getSummary().substr(v, 30).back() != ' ')
                {
                    cout << "..";
                }
            }
            cout << "..";

            //print out the equipment list
            cout << "\n" << "            " << recipeVector[i].getEquipment();
            cout << "\n";

            //increment
            i++;

        }


        //If out of recipies print this
        if (i = recipeVector.size())
        {
            cout << "\n\nThere are no recipies left\n\n";
        }





        //what do you want to do
        cout << "To print more recipies press 1, To select a recipe press 2, To exit press 0.    ";
        in = numCheck(2);
        if (in == 1)
        {
            //generate more
            total += 5;
            continue;
        }
        else if (in == 2)
        {
            //select a recipie
            

            //ask for number representing corect recipie
            cout << "\nEnter the number of the recipie you want to print, or 0 to exit.     ";
            in = numCheck(recipeVector.size()+1);
            if (in != 0)
            {
                //print the full recipie at corect position
                printFullRecipie(recipeVector[in - 1]);
                in = 0;
            }
        }
    }

}

/** @file main.cpp * /
  * @author Valerie Williams
  * @date 3/4/2023
  * @version 1
  * Program to analyze candy data from a csv file and display the names of candies with the
  * highest calorie count in the data set.
  */

// necessary libraries/files
#include <iostream> // to output data to the console
#include <fstream> // to read from a file
#include <string> // to store the candy names and data from file
#include <sstream> // for more powerful string operations
#include "LinkedStack.h" // to use a linked stack ADT

using namespace std;

/**
 * Reads data from a csv file containing names of candies and their calorie count in order 
 * to store the candies with the highest calorie count in a stack and display them.
*/
int main()
{
    // declare necessary variables
    ifstream myFile; // file to open & read from
    string currentString; // holds the current line of data for parsing
    int currentCalories; // current calorie count
    string currentCandy; // current candy 
    int highestCalories; // highest calorie count
    LinkedStack<string> candies; // stack containing the highest calorie candies

    // open the file + handle error if file cannot be opened 
    try
    {
        myFile.open("halloweenCandy.csv");
    }
    catch (const ifstream::failure& e)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    // logic summary:
    // read the first line of the file
    // push candy onto stack
    // read the next line
    // if the next line is higher, clear the stack, push the next line
    // if the calorie count is the same, push the candy onto the stack

    while (!myFile.eof() && currentString == "")
    {
        // read the line
        getline(myFile, currentString);

        // parse the data from the string
        currentCandy = currentString.substr(0, currentString.find(','));
        currentCalories = stoi(currentString.substr(currentString.find(',') + 1, currentString.find('\r')));

        if (candies.isEmpty()) // if the stack is empty
        {
            candies.push(currentCandy);
            highestCalories = currentCalories;
        }
        else if (currentCalories > highestCalories) // if the current candy has a higher calorie count
        {
            // clear the stack
            while(!candies.isEmpty())
            {
                candies.pop();
            }

            // add the current candy to the stack
            candies.push(currentCandy);

            // set the new highest calorie count
            highestCalories = currentCalories;

        }
        else if (currentCalories == highestCalories) // if the current candy shares the high calorie count
        {
            // add the current candy to the stack
            candies.push(currentCandy);
        }

    }

    // output!
    // display highest calorie count
    cout << "Highest calorie count: " << highestCalories << endl;
    // display candies with that calorie count from top of the stack to bottom of the stack
    cout << "Candies with " << highestCalories << " calories per serving: ";
    while (!candies.isEmpty())
    {
        cout << candies.peek() << " "; // display each candy
        candies.pop(); // remove from stack when done
    }

    // exit code
    return 0;

}

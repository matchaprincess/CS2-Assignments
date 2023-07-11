/** @file main.cpp * /
* @author Valerie Williams
* @date 3/4/2023
* @version 1
* Program to analyze a user inputted string for vowels, digits, and arithmetic symbols
* and display each unique one. Also calculates the sum/difference/product/quotient/modulus
* of the last two numbers in the string depending on the last arithmetic symbol in the string. 
*/

// include necessary files and libraries 
#include <string> 
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <exception>
#include "ArrayStack.h"

using namespace std;

// method declarations
bool isVowel(char toCheck);
bool isSymbol(char toCheck);
int calculateResult(int first, int second, char symbol);
bool validInput(string toCheck);

// main method

/**
 * The purpose of this method is to analyze a string for vowels, digits, and arithmetic symbols
 * to display each unique one and calculate the sum/difference/product/quotient/modulus
 * of the last two numbers in the string.
*/
int main()
{

    // declare necessary variables 
    string toParse; // the string to store
    ArrayStack<char> vowels; // stack to store vowels in the string
    ArrayStack<int> digits; // stack to store the digitd in the string
    ArrayStack<char> symbols; // stack to store the symbols in the string 
    int dig1, dig2; // the digit to add
    char arithmetic; // the arithmetic symbol
    int usedIndex = 0;
    char used[10];
    


    // ask user to enter a string
    // if the string is not in proper format, display an error message
    // and exit the program.
    try 
    {
        cout << "Please enter a string: " << endl;
        getline(cin, toParse);
        validInput(toParse);
    }
    catch(invalid_argument& e)
    {   
        cout << e.what() << endl; 
        exit(EXIT_FAILURE);
    }
    
    // traverse through the string
    for (int i = 0; i < toParse.length(); i++)
    {

        // if the char is a vowel, add it to the vowel stack (if it's not already in the stack)
        if(isVowel(toParse[i]) == true)
        {

            if(find(begin(used), end(used), toParse[i]) == end(used))
            {
                vowels.push(tolower(toParse[i]));
                used[usedIndex] = tolower(toParse[i]);
                usedIndex++;
            }

        }
        
        // if the char is a digit, add it to the digit stack
        if(isdigit(toParse[i]))
        {

            digits.push(atoi(&toParse[i]));
                
        }

        // if the char is a symbol, add it to the symbol stack regardless of whether it's already there or not
        if(isSymbol(toParse[i]))
        {

            if(find(begin(used), end(used), toParse[i]) == end(used))
            {
                symbols.push(toParse[i]);
                used[usedIndex] = toParse[i];
                usedIndex++;
            }

        }

    }
        
    // display all of the stacks
    cout << "~Displaying stacks from top to bottom~" << endl;

    cout << "----------" << endl;

    // display vowel stack
    vowels.display();

    cout << "----------" << endl;

    // display digit stack
    digits.display();

    cout << "----------" << endl;

    // display symbol stack 
    symbols.display();

    cout << "----------" << endl;

    // calculate the result of the arithmetic symbol

    dig1 = digits.peek();
    digits.pop();
    dig2 = digits.peek();
    digits.pop();
    arithmetic = symbols.peek();
    symbols.pop();
    

    cout << "The result: " << dig1 << " " << arithmetic << " " << dig2 << " = " <<
    calculateResult(dig1, dig2, arithmetic) << endl;
    
    return 0;

}

/**
 * The purpose of this method is to check if a character is a vowel or not (not case sensitive).
 * @param toCheck the char to analyze
 * @return true if the char is a vowel, false if not
*/
bool isVowel(char toCheck)
{
    bool vowel = false;

    if(toCheck == 'a' || toCheck == 'A')
    {
        vowel = true;
    }
    else if(toCheck == 'e' || toCheck == 'E')
    {
        vowel = true;
    }
    else if(toCheck == 'i' || toCheck == 'I')
    {
        vowel = true;
    }
    else if(toCheck == 'o' || toCheck == 'O')
    {
        vowel = true;
    }
    else if(toCheck == 'u' || toCheck == 'U')
    {
        vowel = true;
    }

    return vowel;

}

/**
 * The purpose of this method is to check if a char is an arithmetic symbol or not.
 * @param toCheck the char to analyze
 * @return true if the char is an arithmetic symbol, false if not
*/
bool isSymbol(char toCheck)
{


    bool symbol = false;

    if(toCheck == '+' || toCheck == '-' || toCheck == '*' || toCheck == '/' || toCheck == '%')
    {
        symbol = true;
    }

    return symbol;

}

/**
 * The purpose of this method is to calculate the result of two digits using the 
 * operation specified via the arithmetic symbol.
 * @param first the first digit
 * @param second the second digit
 * @param symbol the arithmetic symbol
 * @return the result of the arithmetic
*/
int calculateResult(int first, int second, char symbol)
{

    int result = 0;

    if(symbol == '+')
    {
        result = first + second;
    }
    else if(symbol == '-')
    {
        result = first - second;
    }
    else if(symbol == '*')
    {
        result = first * second;
    }
    else if(symbol == '/')
    {
        result = first / second;
    }
    else if(symbol == '%')
    {
        result = first % second;
    }
    else
    {
        result = 0;
    }

    return result;

}

/**
 * Checks whether the string has at least 2 digits and at least 1 arithmetic symbol.
 * @param toCheck the string to analyze
 * @return true if the string is valid according to the criteria above, false if not
*/
bool validInput(string toCheck)
{

    int symbolCount = 0;
    int digitCount = 0;
    bool valid = true;

    for(int i = 0; i < toCheck.size(); i++)
    {
        if (isSymbol(toCheck[i]))
        {
            symbolCount++;
        }

        if(isdigit(toCheck[i]))
        {
            digitCount++;
        }

    }

    if(symbolCount == 0 || digitCount < 2)
    {
        valid = false;
        throw invalid_argument("Input must have 2 or more digits and 1 or more arithmetic symbols.");
    }

    return valid;

}









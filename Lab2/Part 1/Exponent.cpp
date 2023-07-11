/** @file Exponent.cpp * /
  * @author Valerie Williams
  * @date 2/2/023
  * Program to allow a user to enter in a base and exponent
  * in order to calculate the value of the exponent.
  */

#include <iostream>
using namespace std;

// function prototypes
int Exponent(int b, int e);

/**
 * Asks user for input and then calculates an exponent's value based on the
 * user's input for the base and exponent.
 */
int main()
{
    
    // declare necessary variables
    int base;
    int exponent;
    
    // ask use for input (base and exponent)
    cout << "Please enter the base: " << endl;
    cin >> base;
    cout << "Please enter the exponent: " << endl;
    cin >> exponent;
    
    while (exponent < 0) 
    {
        
        cout << "Exponent must be positive, please re-enter exponent. " << endl;
        cin >> exponent;
        
    }
    
    while (base < 0) 
    {

        cout << "Base must be positive, please re-enter base. " << endl;
        cin >> base;
        
    }
    
    // output + call the exponent function
    cout << base << " ^ " << exponent << " = " << Exponent(base, exponent) << endl;
    
    return 0;

}

/**
 * Recursively calculates the value of an exponent, given a base and the power
 * to raise the base to.
 * @param b the base of the exponent
 * @param e the power to raise the base to
 * @return the value of the base, b, raised to the power, e
 */
int Exponent(int b, int e) 
{
    
    if (e == 0) 
    {

        return 1;

    }
    else 
    {

        return b * Exponent(b, e-1);
        
    }

    return 0;
    
}

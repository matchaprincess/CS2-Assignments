/** @file company.cpp * /
  * @author Valerie Williams
  * @date 2/4/2023
  * @version 1
  * A class created to store information about a company. 
  */

#include <iostream> // for input and output functionality
#include <string> // to use strings
#include <sstream> // to use stringstream for data parsing
using namespace std;

#include "company.h" // including the header file

/**
 * Default constructor to construct a Company object with no parameters. 
*/
Company::Company() 
{

    // set default attributes
    name = "N/A";
    tradingSym = " ";
    mktCapValue = 0;
    mktCapValueTB = '\n';
    country = " ";
    type = " ";
    ranks = 0;

}

/**
 * Constructor to create an object from a line from a CSV file. Parses out the
 * data from the file using a stringstream object. 
 * @param params a line from a CSV file. 
*/
Company::Company(string params) 
{

    string n = "";
    string tSym = "";
    string mCap = "";
    string mCapTB = "";
    string c = "";
    string t = "";
    string r = "";
    std::stringstream ss(params);
    
    // if the parameter string is not empty...
    if(!params.empty())
    {

        // parse out the string
        getline(ss, n, ',');
        getline(ss, tSym, ',');
        getline(ss, mCap, ',');
        getline(ss, mCapTB, ',');
        getline(ss, c, ',');
        getline(ss, t, ',');
        getline(ss, r, '\r');

        // set attributes
        name = n;
        tradingSym = tSym;
        mktCapValue = stod(mCap);
        mktCapValueTB = mCapTB[0];
        country = c;
        type = t;
        ranks = stoi(r);

    }

    // if the parameter string is empty, this function does nothing
    // and just goes back to the main method 

}

/**
 * Returns the name field of a Company object.
 * @return the name of a company.
*/
string Company::GetName() const 
{

    return name;
    
}

/**
 * Returns the trading symbol of a Company object.
 * @return the trading symbol of a company. 
*/
string Company::GetTradingSymbol() const 
{

    return tradingSym;

}

/**
 * Returns the numeric market cap value of a Company object.
 * @return the numeric market cap of a company.
*/
double Company::GetMarketCapValue() const 
{

    return mktCapValue;

}

/**
 * Returns the magnitude of the market cap value of a Company object.
 * @return the magnitude (trilions or billions) of the market cap of a company.
*/
char Company::GetMarketCapTB() const 
{

    return mktCapValueTB;

}

/**
 * Returns the country of a Company object.
 * @return the country a company is based in.
*/
string Company::GetCountry() const 
{

    return country;

}

/**
 * Returns the type of a Company object. 
 * @return the type of company. 
*/
string Company::GetType() const 
{

    return type;

}

/**
 * Returns the rank of a Company object.
 * @return the rank of a company. 
*/
int Company::GetRank() const 
{

    return ranks;

}

/**
 * Allows a user to set the rank of a Company object. 
 * @param int r the new rank of the calling Company object.
*/
void Company::SetRank(int r) 
{

    ranks = r;

}

/**
 * Allows a user to set the market cap of a Company object.
 * @param value the new numeric value of the calling Company object.
 * @param magnitude the new magnitude (T/B; trillions or billions) of
 *                  the calling Company object. 
*/
void Company::SetMarketCap(double value, char magnitude) 
{

    mktCapValue = value;
    mktCapValueTB = magnitude;

}

/**
 * Prints out all fields of a Company object in a clean, readable format. 
*/
void Company::Print() 
{

    cout << "Name: " << GetName() << endl;
    cout << "Trading Symbol: " << GetTradingSymbol() << endl;
    cout << "Market Cap Value: " << GetMarketCapValue() << GetMarketCapTB() << endl;
    cout << "Country: " << GetCountry() << endl;
    cout << "Type: " << GetType() << endl;
    cout << "Rank: " << GetRank() << endl;

}





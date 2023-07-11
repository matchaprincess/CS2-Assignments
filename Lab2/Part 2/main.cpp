/** @file main.cpp * /
  * @author Valerie Williams
  * @date 2/4/2023
  * @version 1
  * Program to analyze company market cap data from a CSV file. Equipped with functions
  * to analyze the max and min market caps, the number of US based companies in the data set,
  * the range of all market caps in the file, and to display all of the company's
  * trading information to the screen. 
  */

#include <fstream> // to use files
#include <string> // to use strings
#include <vector> // to use vectors
#include <iostream> // for input and output
#include <sstream> // for more powerful string functions

using namespace std; // using the standard namespace

#include "company.cpp" // including the company class

// function prototypes
vector<Company> readFile(string fileName);
void displayAll(vector<Company> companyVector);
int getUS(vector<Company> companyVector);
Company getWealthiest(vector<Company> companyVector);
vector<Company> getRange(vector<Company> companyVector);
Company getLeast(vector<Company> companyVector);


/**
 * Reads a .csv file, displays all of the information from the file in a readable
 * format, shows the wealthiest company, the least wealthy company, the range 
 * of the market caps present in the file, and the number of companies in the file
 * that are based in the US. 
*/
int main() 
{
    // declare necessary variables/objects (filename, vector, etc)
    string fName;
    vector<Company> companies;
    vector<Company> myRanges;

    // read the file
    companies = readFile("companiesMarketCap.csv");

    // calculate ranges
    myRanges = getRange(companies);

    // display all of the companies 
    displayAll(companies);

    // display the wealthiest company
    cout << "The wealthiest company is " << getWealthiest(companies).GetName() << endl;

    // display the least wealthy company
    cout << "The least wealthy company is " << getLeast(companies).GetName() << endl;

    // display the range of market cap value
    cout << "The range of the market cap values is " << myRanges[0].GetMarketCapValue() << 
    myRanges[0].GetMarketCapTB() << " to " << myRanges[1].GetMarketCapValue()
    << myRanges[1].GetMarketCapTB() << endl;

    // display how many US companies are on the list
    cout << "There are " << getUS(companies) << " US-based companies on the list." << endl;

    // exit code 
    return 0;
    
}

/**
 * Returns a vector containing objects created from data from the .csv file.
 * @param fileName the name of the csv file to be read.
 * @return a vector containing the objects created from data from the file.
*/
vector<Company> readFile(string fileName) 
{

    // create necessary variables/objects 
    vector<Company> cList;
    istringstream ss;
    string toRead;
        
    // open the file
        ifstream myFile(fileName.c_str());
        
    // return an error message if there's an error opening the file or reading data
        if (!myFile) 
        {

            cout << "Error opening " << fileName << " for input" << endl;
            
        }
        else 
        {

            // skip the first line (contains header information)
            getline(myFile, toRead);

            // while loop to continue until end of file
            while(!myFile.eof())
            {

                // reading a line
                getline(myFile, toRead);
                
                // if the line isn't empty, 
                if (!toRead.empty()) 
                {

                    // create a Company object from the temp variable
                    Company currentCompany(toRead);

                    // add the new object to the end of the vector
                    cList.push_back(currentCompany);

                }
            
            }

        }
        
    // close the file
    myFile.close();
        
    // return the vector of company objects generated from the file
    return cList;

}

/**
 * Iterates through a vector of Company objects and displays the information
 * in a clean, readable format.
 * @param companyVector a vector of Company objects. 
*/
void displayAll(vector<Company> companyVector){

    // iterate through all the elements of the vector and print each object w/ a new line
    for(int i = 0; i < companyVector.size(); i++) 
    {

        companyVector[i].Print();
        cout << endl; 

    }

}

/**
 * Returns the lowest and highest values, aka the range, of
 * a vector containing Company objects.
 * @param companyVector a vector of Company objects. 
 * @return a vector of length 2 which contains the company with the lowest market cap and
 *         the highest market cap. Index 0 of the vector is the lowest, 
 *         index 1 of the vector is the highest. 
 */
vector<Company> getRange(vector<Company> companyVector) 
{

    // declare necessary variables 
    Company greatest;
    Company least; 
    vector<Company> ranges;

    // get the greatest and lowest market cap values from the vector
    greatest = getWealthiest(companyVector);
    least = getLeast(companyVector);

    // add the objects to the vector
    ranges.push_back(least);
    ranges.push_back(greatest);

    // return the vector of ranges
    return ranges;
    
}

/**
 * Returns the wealthiest company in the vector. 
 * @param companyVector a vector of Company objects.
 * @return the Company object with the greatest market cap in companyVector. 
*/
Company getWealthiest(vector<Company> companyVector) 
{
    // declare necessary variables
    Company greatest;
    greatest = companyVector[0];

    // using a linear search algorithm

    // iterate through the vector to find the greatest market cap
    for (int i = 0; i < companyVector.size(); i++)
    {

        // get all the market caps in the trillions, they are the largest
        if (companyVector[i].GetMarketCapTB() == 'T')
        {

            // compare the current element's numeric market cap value to the current greatest
            if (companyVector[i].GetMarketCapValue() > greatest.GetMarketCapValue())
            {

                greatest = companyVector[i];

            }

        }

    }

    //return the greatest variable 
    return greatest;

}

/**
 * Returns the least wealthy company in the vector.
 * @param companyVector a vector of Company objects.
 * @return the Company object with the smallest market cap in companyVector. 
*/
Company getLeast(vector<Company> companyVector)
{
    // declare the necessary variables
    Company least;
    least = companyVector[0];

    // using a linear search algorithm 

    // iterate through the vector to find the company with the lowest market cap
    for (int i = 0; i < companyVector.size(); i++)
    {

        // analyze the market caps in the billions, they are the lowest
        if (companyVector[i].GetMarketCapTB() == 'B')
        {

            least = companyVector[i];

            // compare the current element's numeric market cap value to the current lowest
            if (companyVector[i].GetMarketCapValue() < least.GetMarketCapValue())
            {

                least = companyVector[i];

            }

        }

    }

    // return the least variable
    return least;

}

/**
 * Returns the number of companies in the vector that are US based.
 * @param companyVector a vector of Company objects.
 * @return the number of companies in companyVector that are US based. 
*/
int getUS(vector<Company> companyVector) 
{
    //declare a counter variable
    int usCompanies = 0;

    //iterate through the vector, each time an element's country is USA, +1 to counter
    for(int i = 0; i < companyVector.size(); i++) 
    {

        if(companyVector[i].GetCountry() == "US")
        {

            usCompanies++;

        }

    }

    //return the counter variable
    return usCompanies;

}
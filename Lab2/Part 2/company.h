/** @file company.h * /
  * @author Valerie Williams
  * @date 2/4/2023
  * @version 1
  * The header file for a class created to store information about a company. 
  */

#ifndef company_h
#define company_h

/**
 * The purpose of this class is to store information about a company.
*/
class Company{

    public:
    /**
     * Default constructor to construct a Company object with no parameters. 
    */
    Company();

    /**
     * Constructor to create an object from a line from a CSV file. Parses out the
     * data from the file using a stringstream object. 
    */
    Company(string params);

    /**
     * Returns the name field of a Company object.
    */
    string GetName() const;

    /**
     * Returns the trading symbol of a Company object.
    */
    string GetTradingSymbol() const;

    /**
     * Returns the numeric market cap value of a Company object.
    */
    double GetMarketCapValue() const;

    /**
     * Returns the magnitude of the market cap value of a Company object.
    */
    char GetMarketCapTB() const;

    /**
     * Returns the country of a Company object.
    */
    string GetCountry() const;

    /**
     * Returns the type of a Company object. 
    */
    string GetType() const;

    /**
     * Returns the rank of a Company object.
    */
    int GetRank() const;

    /**
     * Allows a user to set the rank of a Company object.
    */
    void SetRank(int r);

    /** 
     * Allows a user to set the market cap of a Company object.
    */
    void SetMarketCap(double value, char magnitude);

    /**
     * Prints out all fields of a Company object in a clean, readable format. 
    */
    void Print();

    private:
    string name;
    string tradingSym;
    double mktCapValue;
    char mktCapValueTB;
    string country;
    string type;
    int ranks;

};

#endif

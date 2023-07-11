/** @file LineReader_v2.cpp * /
  * @author Valerie Williams
  * @date 1/26/2023
  * Program to read lines of text and determine vowels, consonants,
  * and special characters from a file.
  */

 // importing necessary libraries
 #include <iostream> // for input and output
 #include <cstdlib> // for standard constants
 #include <string> // for using strings
 #include <fstream> // for using files
 using namespace std; // using the standard namespace b/c it has useful functions

/**
 * Displays how many sentences started with vowels, consonants, and other characters given a text file + how
 * many lines were read in total.
 */
int main (void){

    // creating necessary variables and objects
    int vowels = 0; // number of vowels
    int consonants = 0; // number of consonants
    int other = 0; // number of other characters
    int lines = 0; // number of lines read
    string toRead; // empty string to hold user input
    const string INPUT_FILE = "lab1Data.txt"; // the name of the file to read

    // open the file
    ifstream inFile(INPUT_FILE.c_str());
    
    // catch any errors opening the file
    if (!inFile){
        cout << "Error opening " << INPUT_FILE << " for input" << endl;
    }
    else {
        
        getline(inFile, toRead); // reading a line
        
        while (inFile) {
            
            // update the lines variable
            lines++;
            
            // analyze vowels, consonants, and other characters
            if (isalpha(toRead[0])){
                
                if (tolower(toRead[0]) == 'a' || tolower(toRead[0]) == 'e' || tolower(toRead[0]) == 'i' || tolower(toRead[0]) == 'o' || tolower(toRead[0]) == 'u'){
                    vowels++;
                }
                else{
                    consonants++;
                }
                
            }
                
            else{
                
                other++;
                
            }
                
        
            getline(inFile, toRead); // reading the next line
            
        }

    }
                
    // close the file because it's not needed anymore
    inFile.close();

    // display results
    cout << "First words start with vowel: " << vowels << endl;
    cout << "First words start with consonant: " << consonants << endl;
    cout << "First words start with something else: " << other << endl;
    cout << lines << " lines of text read" << endl;

    // status code
    return 0;

}

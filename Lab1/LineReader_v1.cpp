/** @file LineReader_v1.cpp * /
  * @author Valerie Williams
  * @date 1/26/023
  * Program to read lines of text and determine vowels, consonants,
  * and special characters from the first word of every line.
  */

 // importing necessary libraries
 #include <iostream> // for input and output
 #include <cstdlib> // for standard constants
 #include <string> // for using strings
 using namespace std; // using the standard namespace b/c it has useful functions

/**
 * Displays how many sentences started with vowels, consonants, and other characters given user input + how
 * many lines were read in total.
 */
int main (void){

    // creating necessary variables and objects
    int vowels = 0; // number of vowels
    int consonants = 0; // number of consonants
    int other = 0; // number of other characters
    int lines = 0; // number of lines read
    string toRead; // empty string to hold user input

    // give user directions
    cout << "Enter lines of text to read, enter 'quit' when finished" << endl;

    // while statement to control when to stop reading text
    while (toRead != "quit") {

        // get the user input and store it in toRead string variable
        getline(cin, toRead);
        
        // analyze vowels, consonants, etc
        if (toRead != "quit"){

            // update the lines variable
            lines++;

            if (isalpha(toRead[0])){

                if (tolower(toRead[0]) == 'a' || tolower(toRead[0]) == 'e' ||
                tolower(toRead[0]) == 'i' || tolower(toRead[0]) == 'o' || tolower(toRead[0]) == 'u' ){
                    vowels++;
                }
                else {
                    consonants++;
                }

            }
            // character is not an alpha character, so it's 'other'
            else {

                other++;

            }

        }
        
    }

    // display results
    cout << "First words start with vowel: " << vowels << endl;
    cout << "First words start with consonant: " << consonants << endl;
    cout << "First words start with something else: " << other << endl;
    cout << lines << " lines of text read" << endl;

    // status code
    return 0;

}

/** @file main.cpp * /
  * @author Valerie Williams
  * @date 2/10/2023
  * Program to test and display various MyArray operations.
  */

#include <iostream>
#include "MyArray.h"

using namespace std;

/**
 * The purpose of this main method is to test out the various methods implemented in MyArray.
*/
int main()
{

    // creating the arrays that will be used for testing
    int anArray[10] = {1,2,3,4,5,6,7,8,9,10};
    double anArray2[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8,9.9, 10.10};
    char anArray3[10] = {'a', 'b' ,'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};


    // creating the integer array
    MyArray<int> myArr(anArray);

    // displaying the integer array
    myArr.displayArray();

    // creating the double array
    MyArray<double> myArr2 (anArray2);

    // displaying the double array
    myArr2.displayArray();

    // creating the char array
    MyArray<char> myArr3(anArray3);

    // displaying the char array
    myArr3.displayArray();


    // testing the maximumElement method
    cout <<"Maximum integer: " << myArr.maximumElement() << endl;

    cout <<"Maximum double: " << myArr2.maximumElement() << endl;

    cout <<"Maximum character: " << myArr3.maximumElement() << endl;


    // testing the countElements method
    cout << "Counting occurrences of 5: " << myArr.countElements(5) << endl;

    cout << "Counting occurrences of 10.1: " << myArr2.countElements(10.1) << endl;

    cout << "Counting occurrences of 'a': " << myArr3.countElements('a') << endl;

    // testing the printReverse method
    myArr.printReverse();
    myArr2.printReverse();
    myArr3.printReverse();

    // testing find method
    cout << "T/F Does the number 6 exist in the first array?: " << boolalpha << myArr.find(6) << endl;
    cout << "T/F Does the number 10.2 exist in the second array?: " << boolalpha << myArr2.find(10.2) << endl;
    cout << "T/F Does 'b' exist in the third array?: " << boolalpha << myArr3.find('b') << endl;

    // testing isFull method
    cout << "T/F Is the first array full?: " << boolalpha << myArr.isFull() << endl;
    cout << "T/F Is the second array full?: " << boolalpha << myArr2.isFull() << endl;
    cout << "T/F Is the third array full?: " << boolalpha << myArr3.isFull() << endl;

    // testing the removeLast method 
    cout << "Removing last element from the first array..." << endl;
    myArr.removeLast();
    myArr.displayArray();

    // testing the add method
    cout << "Adding an element to the first array..." << endl;
    myArr.add(13);
    myArr.displayArray();

    // testing remove(t) method
    cout << "Removing 9 from array 1..." << endl;
    myArr.remove(1);
    myArr.displayArray();

    // testing increaseElementsBy method
    myArr.increaseElementsBy(1);
    cout << "Increasing integer array's elements by 1..." << endl;
    myArr.displayArray();

    myArr2.increaseElementsBy(2.0);
    cout << "Increase double array's elements by 2..." << endl;
    myArr2.displayArray();

    myArr3.increaseElementsBy('a');
    cout << "Adding value of 'a' to every element in char array..." << endl;
    myArr3.displayArray();


    // exit code
    return 0;

}

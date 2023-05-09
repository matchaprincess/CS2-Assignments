// airportMenu header file

#ifndef AIRPORTMENU_H
#define AIRPORTMENU_H

#include <string>
#include <vector>
#include "BinarySearchTree.h"
#include "Airport.h"
#include "Node.h"

using namespace std;

    // main menus
    void menu_Main(BinarySearchTree<Airport>* tree);
    void menu_Search(BinarySearchTree<Airport>* tree);
    void menu_Report(BinarySearchTree<Airport>* tree);
    void menu_MaxMin(BinarySearchTree<Airport>* tree);
    void menu_Edit(BinarySearchTree<Airport>* tree);

#endif
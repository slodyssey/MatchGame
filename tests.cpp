// Tests definitions
// Created by Stephen Laux on 20/01/28.
//
#include "functions.h"
#include "tests.h"

void ClearScreenDiver()
{
    std::cout << "BEGIN ClearScreenDiver" << std::endl;
    ClearScreen();
    std::cout << "END ClearScreenDiver" << std::endl;
}
void createUiArrayDriver()
{
    std::cout << "BEGIN createUiArrayDriver" << std::endl;
    std::string myStringArr[4][4];
    const int size = 4;
    createUiArray(myStringArr, size);
    printStringArray(myStringArr, size);
    std::cout << "END createUiArrayDriver" << std::endl;
}
void printStringArray()
{
    std::cout << "BEGIN printStringArray" << std::endl;
    std::string myStringArr[4][4];
    const int size = 4;
    printStringArray(myStringArr, size);
    std::cout << "END printStringArray" << std::endl;
}
void returnRowColumnDriver()
{
    std::cout << "BEGIN returnRowColumnDriver" << std::endl;
    int val = 5;
    int row = 4;
    int column = 4;
    returnRowColumn(val, row, column);
    std::cout << "Row: " << row << endl;
    std::cout << "Column: " << column << endl;
    std::cout << "END returnRowColumnDriver" << std::endl;
}
void returnRowDriver()
{
    std::cout << "BEGIN returnRowDriver" << std::endl;
    int input = 5;
    int row = returnRow(input);
    std::cout << "Row: " << row << endl;
    std::cout << "END returnRowDriver" << std::endl;
}
void returnColumnDriver()
{
    std::cout << "BEGIN returnColumnDriver" << std::endl;
    int input = 5;
    int column = returnColumn(5);
    std::cout << "Column: " << column << endl;
    std::cout << "END returnColumnDriver" << std::endl;
}
void getTwoInputsDriver()
{
    std::cout << "BEGIN getTwoInputsDriver" << std::endl;
    int input1 = 1;
    int input2 = 2;
    getTwoInput(input1, input2);
    std::cout << "Selection 1: " << input1 << endl;
    std::cout << "Selection 2: " << input2 << endl;
    std::cout << "END getTwoInputsDriver" << std::endl;
}
void updateUiDriver()
{
    std::cout << "BEGIN updateUiDriver" << std::endl;
    std::string ui[4][4];
    std::string squareValues[4][4];
    int row1 = 4;
    int column1 = 4;
    int row2 = 4;
    int column2 = 4;
    int count = 0;
    int selection1 = 5;
    int selection2 = 6;
    updateUi(ui, squareValues, row1, column1, row2, column2, count, selection1, selection2);
    std::cout << "END updateUiDriver" << std::endl;
}
void ifMatchDriver()
{
    std::cout << "BEGIN ifMatchDriver" << std::endl;
    std::string arr1[4][4];
    int row1 = 4;
    int column1 = 4;
    int row2 = 4;
    int column2 = 4;
    ifMatch (arr1, row1, column1, row2, column2);
    std::cout << "END ifMatchDriver" << std::endl;
}
void fillStringDriver()
{
    std::cout << "BEGIN fillStringDriver" << std::endl;
    string arr[4][4];
    fillString(arr);
    printStringArray(arr, 4);
    std::cout << "END fillStringDriver" << std::endl;
}
void printInputDriver()
{
    std::cout << "BEGIN printInputDriver" << std::endl;
    string arr1[4][4];
    string arr2[4][4];
    int input1 = 5;
    int input2 = 5;
    printInput(arr1, arr2, input1, input2);
    cout << input1 << endl;
    std::cout << "END printInputDriver" << std::endl;
}

// UI to either test different functions of the game or to start the entire game
void driverStartUI() {
    char ans = 'y';
    do {
        int input1;
        cout << "What function would you like to test? " << endl;
        cout << "1. Clear Screen Driver. " << endl;
        cout << "2. Create UI Array Driver. " << endl;
        cout << "3. Print Input Driver. " << endl;
        cout << "4. Print String Array Driver. " << endl;
        cout << "5. Return Row Column Driver. " << endl;
        cout << "6. Return Row Driver. " << endl;
        cout << "7. Return Column Driver. " << endl;
        cout << "8. Get Two Inputs Driver. " << endl;
        cout << "9. Update UI Driver. " << endl;
        cout << "10. If Match Driver. " << endl;
        cout << "11. Fill String Driver. " << endl;
        cout << "12. Start game " << endl;
        cin >> input1;
        if (input1 == 1) {
            ClearScreenDiver();
        } else if (input1 == 2) {
            createUiArrayDriver();
        } else if (input1 == 3) {
            printInputDriver();
        } else if (input1 == 4) {
            printStringArray();
        } else if (input1 == 5) {
            returnRowColumnDriver();
        } else if (input1 == 6) {
            returnRowDriver();
        } else if (input1 == 7) {
            returnColumnDriver();
        } else if (input1 == 8) {
            getTwoInputsDriver();
        } else if (input1 == 9) {
            updateUiDriver();
        } else if (input1 == 10) {
            ifMatchDriver();
        } else if (input1 == 11) {
            fillStringDriver();
        } else if (input1 == 12) {
            startGame();
        }
        cout <<"Do you want to run another function?\n";
        cin >> ans;
    }
    while(ans == 'y' || ans == 'Y');

}
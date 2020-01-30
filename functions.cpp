// Functions
// Created by Stephen on 20/01/27.
//
#include <iostream>
#include "functions.h"

//Prints 100 lines to the command line simulate resetting the screen
void ClearScreen()
{
    cout << string( 100, '\n' );
}

//Initializes a string array a[4][4], with the values 1 - 16
void createUiArray(string a[4][4], int rowSize)
{
    int counter = 1;
    for(int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = to_string(counter);
            ++counter;
        }
    }
}

//Prints out values of 4x4 array for an entire row, then moves to next row, until 4 rows printed
void printStringArray(string a[4][4], int rowSize)
{
    //Row iterator
    for(int i = 0; i < rowSize; i++)
    {
        //Column iterator
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

//Takes in a value from the UI, and calculates where the expected row and column indices for that value would be
//on the UI array
void returnRowColumn(int valueVar, int& rowVar, int& columnVar)
{
    rowVar = returnRow(valueVar);
//    cout << rowVar << endl;
    columnVar = returnColumn(valueVar);
}

//Takes a value and calculates the row index of that value is on the 4x4 UI array. Special handling for multiples of 4
int returnRow(int input)
{
    int row = -1;
    if ((input % 4) != 0)
    {
        row = input / 4;
    }
    else
        row = (input / 4) - 1;
    return row;
}

//Takes a value and calculates the column index of that value is on the 4x4 UI array. Special handling for multiples
// of 4
int returnColumn(int input)
{
    int column = -1;
    int row = returnRow(input);
    if ((input % 4) != 0)
    {
        column = ((input - (4 * row)) % 4) - 1;
    }
    else
        column = ((input - (4 * row)) % 4) + 3;
    return column;
}

//Gets two user inputs and assigns them by reference to the variables entered as arguments
void getTwoInput(int& selection1, int& selection2)
{
    cout << "Please select two numbers you would like to flip, 1-16, separated by a space\n";
    cin >> selection1 >> selection2;
}

//checks if values in two locations in array match, returns true if they do
bool ifMatch (string arr1[4][4], int row1, int column1, int row2, int column2)
{
    return (arr1[row1][column1] == arr1[row2][column2]);
}

//If the Letter matrix values match, updates UI matrix to show those letters going forward
void updateUi(string ui[4][4], string squareValues[4][4], int row1, int column1, int row2, int column2, int & count,
        int selection1, int selection2)
{
    if (ifMatch (squareValues, row1, column1, row2, column2))
    {
        ui[row1][column1] = squareValues[row1][column1];
        ui[row2][column2] = squareValues[row2][column2];
        count++;
    }
    else
    {
        printInput(ui, squareValues, selection1, selection2);
        cout << "Sorry, not a match!\n";
    }
}

//takes a multi-dimensional array someArr[4][4] and fills it up with some strings
void fillString(string arr[4][4])
{
    //Fisherâ€“Yates shuffle
    const int size = 16;
    string myArr[size] = {"A","A","B","B","C","C","D","D","E","E","F","F","G","G","H","H"};
    for (int i = size-1; i != 0; i--)
    {
        int j = rand() % i;
        //char tmpArr[size];
        string temp =  myArr[i];
        myArr[i] = myArr[j];
        myArr[j] = temp;
    }
    //Assigns myArr[] to multi-dimensional array defined in function parameter
    int counter = 0;
    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++){
            int num = rand() % 16;
            arr[i][j] = myArr[counter];
            counter++;
        }
}


//takes 2 user inputs and prints 4x4 game board adjusted to user input.
//for example input of some number replaced with letter value, num 5 & 6 might now print "A" "B"
//all other numbers displayed will remain unaffected
void printInput(string arr1[4][4], string arr2[4][4], int input1, int input2)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            if (to_string(input1) != arr1[i][j] && to_string(input2) != arr1[i][j])
                std::cout << arr1[i][j] << "\t";
            else
                std::cout << arr2[i][j] << "\t";
        std::cout << std::endl;
    }
}

// Starts the entire game using all the functions built open the program
void startGame()
{

    char replay;
    do {                    // Creates two arrays. One for the UI and one that takes in the numbers for matching
        int count = 0;;
        string ui[4][4];
        string squareValues[4][4];
        fillString(squareValues);
        createUiArray(ui, 4);
        do {                                    // Takes two inputs and determines of they're a match. Clears the screen if its not
            printStringArray(ui, 4);
            int selection1 = 0, selection2 = 0, row1 = -1, column1 = -1, row2 = -1, column2 = -1;
            getTwoInput(selection1, selection2);
            returnRowColumn(selection1, row1, column1);
            returnRowColumn(selection2, row2, column2);
            ClearScreen();
            updateUi(ui, squareValues, row1, column1, row2, column2, count, selection1, selection2);
        }
        while(count < 8);                           // Asks the user if they want to play again
        cout << "Congrats! You finished the Matching Game!\n"
             << "Press Y if you'd like to play again.\n";
        cin >> replay;
    }        while(replay == 'Y' || replay == 'y');
    cout << "Thank you for playing our game!\n";
}
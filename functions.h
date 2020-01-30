// Functions header
// Created by Stephen on 20/01/27.
//

#ifndef INC_2020_01_27_MATCHGAME_FUNCTIONS_H
#define INC_2020_01_27_MATCHGAME_FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

void ClearScreen();
void createUiArray(string a[][4], int rowSize);
void printStringArray(string a[][4], int rowSize);
void returnRowColumn(int valueVar, int& rowVar, int& columnVar);
int returnRow(int input);
int returnColumn(int input);
void getTwoInput(int& selection1, int& selection2);
void updateUi(string ui[4][4], string squareValues[4][4], int row1, int column1, int row2, int column2, int & count,
              int selection1, int selection2);
bool ifMatch (string arr1[4][4], int row1, int column1, int row2, int column2);
void fillString(string arr[4][4]);
void startGame();
void printInput(string arr1[4][4], string arr2[4][4], int input1, int input2);
void printInputDriver();
#endif //INC_2020_01_27_MATCHGAME_FUNCTIONS_H

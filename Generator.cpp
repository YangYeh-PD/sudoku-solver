#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include "Sudoku.h"
using namespace std;

int main(int argc, char *argv[]) {
    int iRand, num;
    Sudoku board;
    ifstream inFile("Question_Database", ios::in);
    ofstream outFile("Problem", ios::out);

    inFile >> num;
    srand(time(NULL));
    iRand = rand() % num;

    for (int i = 0; i < iRand * 81; i++) {
        inFile >> num;
    }

    // Input the question
    for (int i = 0; i < Sudoku::Sudokusize; i++) {
        inFile >> num;
        board.setElement(i, num);
    }

    // Transformation
    int value1, value2;

    // Change numbers
    value1 = (rand() % 9 + 1);
    while ((value2 = rand() % 9 + 1) == value1) {
        continue;
    }
    board.changeNum(value1, value2);

    // Change rows
    value1 = (rand() % 3);
    while ((value2 = rand() % 3) == value1) {
        continue;
    }
    board.changeRow(value1, value2);

    // Change columns
    value1 = (rand() % 3);
    while ((value2 = rand() % 3) == value1) {
        continue;
    }
    board.changeCol(value1, value2);

    // Clockwise Rotation x times
    board.clockwiseRot(rand() % 4);

    // Up-down flip or Left-right flip
    board.filp(rand() % 2);

    // Print out the problem
    for (int i = 0; i < Sudoku::Sudokusize; i++) {
        cout << board.getElement(i) << " ";
        outFile << board.getElement(i) << " ";
        if (i % 9 == 8) {
            cout << endl;
            outFile << "\n";
        }
    }
    return 0;
}
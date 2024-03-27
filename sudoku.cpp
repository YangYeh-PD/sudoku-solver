#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {
    for (int i = 0; i < Sudokusize; i++) {
        map[i] = 0;
    }
}
Sudoku::Sudoku(const int init_map[]) {
    for (int i = 0; i < Sudokusize; i++) {
        map[i] = init_map[i];
    }
}
void Sudoku::setMap(const int set_map[]) {
    for (int i = 0; i < Sudokusize; i++) {
        map[i] = set_map[i];
    }
}
void Sudoku::setElement(int index, int value) {
    map[index] = value;
}
int Sudoku::getFirstZeroIndex() {
    for (int i = 0; i < Sudokusize; i++) {
        if (map[i] == 0) {
            return i;
        }
    }
    return -1;
}
int Sudoku::getElement(int index) {
    return map[index];
}
bool Sudoku::checkUnity(int arr[]) {
    int arr_unity[9]; // counters

    for (int i = 0; i < 9; i++) {
        arr_unity[i] = 0;   // initialize
    }
    for (int i = 0; i < 9; i++) {
        ++arr_unity[arr[i] - 1];    // count
    }
    for (int i = 0; i < 9; i++) {
        if (arr_unity[i] != 1) {    // all element
            return false;   // must be 1
        }
    }
    return true;
}
bool Sudoku::isLegal(int index) {
    // check the row
    for (int column = (index / 9) * 9; column < ((index / 9) + 1) * 9; column++) {
        if (column != index && map[column] == map[index]) {
            return false;
        }
    }
    // check the column
    for (int row = (index % 9); row < (index % 9) + Sudokusize; row += 9) {
        if (row != index && map[row] == map[index]) {
            return false;
        }
    }
    // check the cells
    int row = index / 9;
    int column = index % 9;
    int start_loc = (row / 3) * 27 + (column / 3) * 3;
    int counts = -1;
    for (int i = start_loc; i <= start_loc + 20; i += 1 + ((counts % 3) / 2) * 6) {
        if (i != index && map[i] == map[index]) {
            return false;
        }
        counts++;
    }
    return true;
}
bool Sudoku::isCorrect() {
    bool check_result;
    int check_arr[9];
    int location;
    // check rows
    for (int i = 0; i < Sudokusize; i += 9) {
        for (int j = 0; j < 9; j++) {
            check_arr[j] = map[i + j];
        }
        check_result = checkUnity(check_arr);
        if (!check_result) {
            return false;
        }
    }
    // check columns
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j += 1) {
            check_arr[j] = map[i + j * 9];
        }
        check_result = checkUnity(check_arr);
        if (!check_result) {
            return false;
        }
    }
    // check cells
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            location = 27 *  (i / 3) + 3 * (i % 3) + 9 * (j / 3) + (j % 3);
            check_arr[j] = map[location];
        }
        check_result = checkUnity(check_arr);
        if (!check_result) {
            return false;
        }
    }
    return true;
}
void Sudoku::changeNum(int num1, int num2) {
    for (int i = 0; i < Sudokusize; i++) {
        if (map[i] == num1) {
            map[i] = num2;
        } else if (map[i] == num2) {
            map[i] = num1;
        } else {
            continue;
        }
    }
}
void Sudoku::changeRow(int row1, int row2) {
    int buffer;
    for (int i = row1 * 27; i < (row1 * 27 + 27); i++) {
        buffer = map[i];
        map[i] = map[row2 * 27 + (i % 27)];
        map[row2 * 27 + (i % 27)] = buffer;
    }
}
void Sudoku::changeCol(int col1, int col2) {
    int buffer;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < Sudokusize; j += 9) {
            buffer = map[col1 * 3 + i + j];
            map[col1 * 3 + i + j] = map[col2 * 3 + i + j];
            map[col2 * 3 + i + j] = buffer;
        }
    }
}
void Sudoku::clockwiseRot(int times) {
    while (times != 0) {
        int ques[9][9], result[9][9];
        for (int i = 0; i < Sudokusize; i++) {
            ques[i / 9][i % 9] = map[i];
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                result[i][j] = ques[8 - j][i];
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                map[i * 9 + j] = result[i][j];
            }
        }
        times--;
    }  
}
void Sudoku::filp(int direction) {
    int result[9][9];
    if(direction) {
        // Left-right flip
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                result[i][j] = map[(9 * i) + (8 - j)];
            }
        }
    } else {
        // Up-Down flip
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                result[i][j] = map[9 * (8 - i) + j];
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            map[i * 9 + j] = result[i][j];
        }
    }
}


#include <iostream>
#include <iomanip>

using namespace std;
/**
practice:
1. looping over 2d arrays
2. output all row values
3. output all column values
4. output all left diagonal values
5. output all right diagonal values

notes on 2d arrays:
* - 2d arrays are tables with the first index being the row
    and the second index being the column e.g. int table[row][col]
  - a 3d array is a matrix with a third index e.g. int matrix[x][y][z]
  - declaration syntax -> Type Array_Name[Size_Dim_1][Size_Dim_2]...[Size_Dim_N]
  - REMEMBER: the first index is the size of the array, the second index is
    one dimensional array of the base type
**/

// print2DArray outputs a two-dimensional array of type integer...
void print2DArray(const int table[][3], int sizeDimension1);

// fill2DArray populates the elements of a two-dimensional array of type integer
// with the element parameter, if no parameter is supplied then the array is populated
// with 0 values
void fill2DArray(int table[][3], int sizeDimension1, int element);

int checkRowWin(int table[][3], int sizeDimension);
int checkColWin(int table[][3], int sizeDimension);
int checkDiagonalWin(int table[][3], int sizeDimension);

int main() {
    // row samples
    int boardEmpty[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };

    int boardRowWin1[3][3] = {
        {1,1,1},
        {0,0,0},
        {0,0,0},
    };

    int boardRowWin2[3][3] = {
        {0,0,0},
        {1,1,1},
        {0,0,0},
    };

    int boardRowWin3[3][3] = {
        {0,0,0},
        {0,0,0},
        {1,1,1},
    };

    int boardColWin1[3][3] = {
        {1,0,0},
        {1,0,0},
        {1,0,0},   
    };

    int boardColWin2[3][3] = {
        {0,1,0},
        {0,1,0},
        {0,1,0},   
    };

    int boardColWin3[3][3] = {
        {0,0,1},
        {0,0,1},
        {0,0,1},   
    };

    int boardDiagWin1[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}, 
    };

    int boardDiagWin2[3][3] = {
        {0,0,1},
        {0,1,0},
        {1,0,0}, 
    };

    //  check rows
    int rowWinFound = checkRowWin(boardDiagWin2, 3);
    if (rowWinFound == 1) {
        cout << "row win detected" << endl;
    } else {
        cout << "no row win detected" << endl;
    }

    // check column
    int colWinFound = checkColWin(boardDiagWin2, 3);
    if (colWinFound == 1) {
        cout << "col win detected" << endl;
    } else {
        cout << "no col win detected" << endl;
    }

    // check diagonals
    int diagonalWinFound = checkDiagonalWin(boardDiagWin2, 3);
    if (diagonalWinFound == 1) {
        cout << "diagonal win detected" << endl;
    } else {
        cout << "no diagonal win detected" << endl;
    }
    
    return 0;
}

int checkRowWin(int table[][3], int sizeDimension) {
    print2DArray(table, sizeDimension);
    
    const int win = 3;

    for (int row = 0; row < sizeDimension; row++) {
        int symbolCount = 0;

        for (int col = 0; col < sizeDimension; col++) {
            // access and process elements here
            if (table[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == win) {
                    cout << "win found at position " << row << ", " << col << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }

    return 0;
}

int checkColWin(int table[][3], int sizeDimension) {
    print2DArray(table, sizeDimension);

    const int win = 3;

    for (int col = 0; col < sizeDimension; col++) {
        int symbolCount = 0;

        for (int row = 0; row < sizeDimension; row++) {
            if (table[row][col] == 1) {
                ++symbolCount;
                
                if (symbolCount == win) {
                    cout << "win found at position " << col << ", " << row << endl;
                    return 1;
                }
            } else {
                symbolCount = 0;
            }
        }
    }
    
    return 0;
}

int checkDiagonalWin(int table[][3], int sizeDimension) {
    print2DArray(table, sizeDimension);

    const int win = 3;

    // top-left to bottom-right
    for (int row = 0; row <= sizeDimension - win; ++row) {
        for (int col = 0; col <= sizeDimension - win; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < win; ++i) {
                if (table[row + i][col + i] == 1) { // Assuming you're looking for the value 1
                    ++symbolCount;
                    if (symbolCount == win) {
                        cout << "win found at position " << row << ", " << col << endl;
                        return 1;
                    }
                } else {
                    symbolCount = 0; // reset the count if the sequence is broken
                }
            }
        }
    }

    // top-right to bottom-left
    for (int row = 0; row <= sizeDimension - win; ++row) {
        for (int col = win - 1; col < sizeDimension; ++col) {
            int symbolCount = 0;
            
            for (int i = 0; i < win; ++i) {
                if (table[row + i][col - i] == 1) {
                    ++symbolCount;

                    if (symbolCount == win) {
                        cout << "win found at position " << col << ", " << row << endl;
                        return 1;
                    }
                } else {
                    symbolCount = 0; // reset the count if the sequence is broken
                }
            }
        }
    }

    return 0;
}

void print2DArray(const int table[][3], int sizeDimension1) {
    for (int index1 = 0; index1 < sizeDimension1; index1++) {
        for (int index2 = 0; index2 < 3; index2++) {
            cout << setw(4) << table[index1][index2];
        }
        cout << endl;
        cout << endl;
    }
}

void fill2DArray(int table[][3], int sizeDimension1, int element) {
    for (int index1 = 0; index1 < sizeDimension1; index1++) {
        for (int index2 = 0; index2 < sizeDimension1; index2++) {
            table[index1][index2] = element;
        }
    }
}
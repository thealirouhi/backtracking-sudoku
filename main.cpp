#include <iostream>
using namespace std;

// Reads the Sudoku grid from standard input
void readBoard(int board[9][9]);

// Prints the Sudoku grid to standard output
void printBoard(int board[9][9]);

// Checks if placing num at (row, col) is valid
bool isValid(int board[9][9], int row, int col, int num);

// Backtracking solver
bool solve(int board[9][9]);

void readBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
            if (j < 8) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

bool isValid(int board[9][9], int row, int col, int num) {
    // check row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num) return false;
    }

    // check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) return false;
    }

    // check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(int board[9][9]) {

    int row = -1, col = -1;
    bool emptyFound = false;

    // 1. find empty cell
    for (int i = 0; i < 9 && !emptyFound; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                emptyFound = true;
                break;
            }
        }
    }

    // 2. base case: no empty cells
    if (!emptyFound) {
        return true;
    }

    // 3. try digits
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {

            board[row][col] = num;

            if (solve(board)) {
                return true;
            }

            // backtrack
            board[row][col] = 0;
        }
    }

    // 4. no valid number works
    return false;
}

int main() {
    int board[9][9];

    readBoard(board);

    if (solve(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists";
    }

    return 0;
}
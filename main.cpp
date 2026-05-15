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
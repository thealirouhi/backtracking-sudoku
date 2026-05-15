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
#include <iostream>
using namespace std;

// Reads the Sudoku grid from standard input
void readBoard(int board[9][9]);

// Prints the Sudoku grid to standard output
void printBoard(int board[9][9]);

bool isBoardValid(int board[9][9]);

// Checks if placing num at (row, col) is valid
bool isValid(int board[9][9], int row, int col, int num);

bool findEmpty(int board[9][9], int &row, int &col);

// Backtracking solver
bool solve(int board[9][9]);

void readBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
}

void printBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
            if (j < 8)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

bool isBoardValid(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
            {
                int temp = board[i][j];
                board[i][j] = 0;
                if (!isValid(board, i, j, temp))
                {
                    board[i][j] = temp;
                    return false;
                }
                board[i][j] = temp;
            }
        }
    }
    return true;
}

bool isValid(int board[9][9], int row, int col, int num)
{
    // check row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
            return false;
    }

    // check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool findEmpty(int board[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solve(int board[9][9])
{
    // 1. find empty
    int row, col;

    if (!findEmpty(board, row, col))
        return true;

    // 2. try digits
    for (int num = 1; num <= 9; num++)
    {
        if (isValid(board, row, col, num))
        {

            board[row][col] = num;

            if (solve(board))
            {
                return true;
            }

            // backtrack
            board[row][col] = 0;
        }
    }

    // 4. no valid number works
    return false;
}

int main()
{
    int board[9][9];

    readBoard(board);

    if (!isBoardValid(board))
    {
        cout << "No solution exists";
    }
    else if (solve(board))
    {
        printBoard(board);
    }
    else
    {
        cout << "No solution exists";
    }

    return 0;
}
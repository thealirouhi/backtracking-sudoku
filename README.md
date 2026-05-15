# Sudoku Backtracking Solver

## Overview

This project implements a **Sudoku solver** using the **Backtracking algorithm** in C++.  
The program reads an incomplete 9×9 Sudoku grid, solves it using recursive search, and prints the completed grid. If no valid solution exists, it reports it accordingly.

---

## Problem Description

A Sudoku puzzle consists of a 9×9 grid divided into nine 3×3 subgrids.  
The goal is to fill empty cells (represented by `0`) with digits from `1` to `9` such that:

- Each row contains all digits from 1 to 9 exactly once  
- Each column contains all digits from 1 to 9 exactly once  
- Each 3×3 subgrid contains all digits from 1 to 9 exactly once  

---

## Input Format

- The input consists of **9 lines**
- Each line contains **9 integers separated by spaces**
- `0` represents an empty cell

Example:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

---

## Output Format

### Case 1: Solution exists

Print the solved Sudoku grid:

```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

### Case 2: No solution exists

```
No solution exists
```

⚠️ No extra output is allowed (no prompts, debug text, or formatting).

---

## Algorithm

The solution uses **Backtracking (Depth-First Search)**:

### Core Idea

1. Find an empty cell
2. Try placing numbers 1–9
3. Check if placement is valid
4. Recursively attempt to solve the rest of the board
5. If failure occurs, undo the choice (backtrack)

---

## Functions

### `readBoard(int board[9][9])`
Reads the Sudoku grid from standard input.

---

### `printBoard(int board[9][9])`
Prints the grid in required format.

---

### `isValid(int board[9][9], int row, int col, int num)`
Checks whether placing `num` at `(row, col)` violates:

- Row constraint
- Column constraint
- 3×3 subgrid constraint

---

### `solve(int board[9][9])`
Recursive backtracking solver:

- Finds empty cell
- Tries all valid numbers
- Recurses
- Backtracks on failure
- Returns `true` if solved, otherwise `false`

---

## Complexity

Worst-case time complexity:
```
O(9^(empty cells))
````

However, pruning via constraints makes it significantly faster in practice.

---

## Constraints

- Must use recursion (Backtracking required)
- Must use `int board[9][9]`
- No external solving libraries allowed
- Only modify empty cells (`0`)
- No extra output beyond required format

---

## Build & Run

### Compile
```bash
g++ main.cpp -o sudoku
````

### Run

```bash
./sudoku
```

Then input the grid.

---

## Project Structure

```
backtracking-sudoku/
│
├── main.cpp
├── README.md
└── .gitignore
```

---

## Key Learning Outcome

This project demonstrates:

* Recursive problem solving
* Constraint satisfaction problems (CSP)
* Backtracking technique
* State exploration and undo mechanisms
* Clean modular C++ design

---

## Author Notes

This solver prioritizes correctness and clarity over optimization.
It is designed for educational understanding of backtracking rather than performance tuning.

## How to Compile and Run

### Compile
Use a C++ compiler (g++ recommended):

```bash
g++ main.cpp -o sudoku
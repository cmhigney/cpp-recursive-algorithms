#ifndef _SUDOKU_H_
#define _SUDOKU_H_

class Sudoku {
private:
    // Store the 9x9 puzzle as a 1D array of 81 integers
    int puzzle[81];
    
    // Load puzzle from CSV file
    void loadPuzzle(const char *filename);
    
    // Check if placing num at (row, col) is valid
    bool isValidMove(int row, int col, int num);
    
    // Check if num already exists in the given row
    bool isInRow(int row, int num);
    
    // Check if num already exists in the given column
    bool isInCol(int col, int num);
    
    // Check if num already exists in the 3x3 box
    bool isInBox(int row, int col, int num);
    
    // Recursive backtracking algorithm
    bool backtrackSolve(int row, int col);

public:
    Sudoku(const char *filename);
    ~Sudoku();
    void solve();
    void print();
};

#endif

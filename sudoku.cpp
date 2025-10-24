#include "sudoku.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Sudoku::Sudoku(const char *fname) {
    loadPuzzle(fname);
}

Sudoku::~Sudoku() {}

// Read CSV file and populate the puzzle array
void Sudoku::loadPuzzle(const char *fname) {
    std::ifstream infile(fname);
    std::string line, number;
    int i = 0;

    // Read each line from the file
    while (std::getline(infile, line)) {
        std::stringstream parser(line);
        
        // Parse comma-separated values
        while (std::getline(parser, number, ',')) {
            puzzle[i++] = std::stoi(number);
        }
    }
    infile.close();
}

// Check if placing num at (row, col) violates Sudoku rules
bool Sudoku::isValidMove(int row, int col, int num) {
    if (isInRow(row, num) || isInCol(col, num) || isInBox(row, col, num)) {
        return false;
    }
    return true;
}

bool Sudoku::isInRow(int row, int num) {
    for (int x = 0; x < 9; ++x) {
        if (puzzle[row * 9 + x] == num) {
            return true;
        }
    }
    return false;
}

bool Sudoku::isInCol(int col, int num) {
    for (int x = 0; x < 9; ++x) {
        if (puzzle[x * 9 + col] == num) {
            return true;
        }
    }
    return false;
}

bool Sudoku::isInBox(int row, int col, int num) {
    // Find the top-left corner of the 3x3 box
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    
    // Check all 9 cells in the box
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (puzzle[(startRow + i) * 9 + (startCol + j)] == num) {
                return true;
            }
        }
    }
    return false;
}

// Recursive backtracking solver
bool Sudoku::backtrackSolve(int row, int col) {
    // Base case: Reached end of puzzle
    if (row == 9) return true;
    
    // Move to next row
    if (col == 9) return backtrackSolve(row + 1, 0);
    
    // Skip cells that already have numbers
    if (puzzle[row * 9 + col] != 0) return backtrackSolve(row, col + 1);

    // Try placing numbers 1-9
    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            puzzle[row * 9 + col] = num;
            
            // Recursively solve the rest
            if (backtrackSolve(row, col + 1)) {
                return true;
            }
            
            // Backtrack if no solution found
            puzzle[row * 9 + col] = 0;
        }
    }
    return false;
}

void Sudoku::solve() {
    backtrackSolve(0, 0);
}

// Print the solved puzzle in CSV format
void Sudoku::print() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << puzzle[row * 9 + col];
            if (col < 8) {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
}

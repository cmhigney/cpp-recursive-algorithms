
#include "sudoku.h"
#include <iostream>

int main() {
    // Create and solve the puzzle
    Sudoku puzzle("test_puzzle.csv");
    
    std::cout << "Solving puzzle..." << std::endl;
    puzzle.solve();
    
    std::cout << "Solution:" << std::endl;
    puzzle.print();
    
    return 0;
}



#include "cellgrid.h"
#include <iostream>
#include <fstream>
using namespace std;

// Read grid from file and store in 1D array using row-major order
Cellgrid::Cellgrid(const char *fname, int m, int n) {
    rows = m;
    cols = n;
    
    // Allocate memory on the heap
    grid = new bool[rows*cols];

    ifstream infile;
    infile.open(fname);

    for(int i = 0; i < rows; i++) {
        // Calculate base index for current row
        int base = i * cols;
        for(int offset = 0; offset < cols; offset++) {
            infile >> grid[base + offset];
        }
    }
    infile.close();
}

// Deallocate memory
Cellgrid::~Cellgrid() {
    delete[] grid;
}

// Recursively count connected cells using depth-first search
int Cellgrid::countCells(int row, int col, int conn) {
    // Check if position is out of bounds
    if(row < 1 || row > rows) {
        return 0;
    }
    
    if(col < 1 || col > cols) {
        return 0;
    }
    
    // Check if cell is empty
    if(grid[(row - 1) * cols + (col - 1)] == 0) {
        return 0;
    }
    
    // Count current cell
    int count = 1;
    
    // Mark cell as visited
    grid[(row - 1) * cols + (col - 1)] = 0;
    
    if(conn == 4) {
        // Check orthogonal neighbors
        count += countCells(row + 1, col, conn);
        count += countCells(row - 1, col, conn);
        count += countCells(row, col + 1, conn);
        count += countCells(row, col - 1, conn);
    } else if(conn == 8) {
        // Check orthogonal neighbors
        count += countCells(row + 1, col, conn);
        count += countCells(row - 1, col, conn);
        count += countCells(row, col + 1, conn);
        count += countCells(row, col - 1, conn);
        
        // Check diagonal neighbors
        count += countCells(row + 1, col + 1, conn);
        count += countCells(row + 1, col - 1, conn);
        count += countCells(row - 1, col - 1, conn);
        count += countCells(row - 1, col + 1, conn);
    }
    
    return count;
}

// Count total number of separate blobs in grid
int Cellgrid::countBlobs(int conn) {
    int blobs = 0;
    
    // Scan through entire grid
    for(int row = 1; row <= rows; row++) {
        for(int col = 1; col <= cols; col++) {
            // When we find an unvisited cell, count its entire blob
            if(countCells(row, col, conn) > 0) {
                blobs++;
            }
        }    
    }
    return blobs;
}

// Print grid in 2D format
void Cellgrid::print() {
    for(int i = 0; i < rows; i++) {
        int base = i * cols;
        std::cout << grid[base];
        for(int offset = 1; offset < cols; offset++) {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}

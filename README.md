# C++ Algorithms & Image Processing

A collection of recursive algorithm implementations developed for my **CSC 211: Computer Programming** course at the University of Rhode Island. Built to explore backtracking techniques, depth-first search, and image processing through practical applications.

## Overview

This project implements three classic computational problems using recursive algorithms: a Sudoku solver with constraint propagation, a connected component analyzer for binary grids, and an image binarization tool. The programs efficiently explore solution spaces and process data structures through recursive techniques.

**Key Features:**
- Recursive backtracking Sudoku solver with constraint validation
- Connected component analysis with 4-connectivity and 8-connectivity
- Automatic threshold-based image binarization
- Efficient memory management with dynamic allocation
- Row-major array indexing for grid-based problems

## Quick Start

```bash
# Install compiler (if needed)
sudo apt update
sudo apt install g++ build-essential

# Clone repository
git clone https://github.com/yourusername/sudoku-solver-algorithms.git
cd sudoku-solver-algorithms

# Compile all programs
g++ -o sudoku test_sudoku.cpp sudoku.cpp
g++ -o test_cellgrid test_cellgrid.cpp cellgrid.cpp
g++ -o imagebin imageBin.cpp

# Run programs
./sudoku
./test_cellgrid
./imagebin test_image.bmp output_image.bmp
```

## Development & Code Documentation

This project was originally developed as a course assignment. When revisiting the code months later, I realized my initial submission lacked sufficient comments, making it difficult to understand my own implementation. This was a valuable lesson in maintainability - even when code works perfectly and passes all tests, clear documentation is essential.

I've since added comprehensive comments throughout the codebase to explain the recursive logic, memory management decisions, and algorithmic choices. This experience reinforced that good code isn't just about functionality - it's about writing code that you (and others) can understand when you return to it later.

## How the Algorithms Work

### Sudoku Backtracking

The solver uses recursive backtracking to explore the solution space efficiently. It exploits constraint propagation by checking validity before each placement rather than after completion.

**Algorithm:**
1. Find the next empty cell (represented as 0)
2. Try placing numbers 1-9
3. Validate against Sudoku constraints (row/column/3x3 box)
4. Recursively solve remaining cells
5. Backtrack and try next number if no solution found

**Example Execution:**
```
Input puzzle (0 = empty):
5,3,0,0,7,0,0,0,0
...

Solving puzzle...
Solution:
5,3,4,6,7,8,9,1,2
6,7,2,1,9,5,3,4,8
...
```

### Connected Component Analysis

Uses depth-first search to identify separate "blobs" of connected cells in a binary grid. The algorithm marks visited cells to avoid recounting and supports two connectivity modes.

**Connectivity Types:**
- **4-connectivity:** Only orthogonal neighbors (up/down/left/right)
- **8-connectivity:** Orthogonal + diagonal neighbors

**Expected Results:**
```
Number of blobs (4-connectivity): 5
Number of blobs (8-connectivity): 3
```

The 8-connectivity mode finds fewer blobs because diagonal connections merge some clusters together.

### Image Binarization

Converts grayscale images to pure black and white using automatic threshold calculation. The threshold is determined by averaging all pixel intensities in the image.

**Process:**
1. Convert color image to grayscale
2. Calculate average pixel intensity across entire image
3. Use average as threshold value
4. Convert each pixel: intensity < threshold → black (0), otherwise → white (255)

**Visual Result:** Output images contain only pure black and white pixels with no intermediate gray values.

## Technical Implementation

### Language & Tools
- **Language:** C++ 11
- **Compiler:** g++
- **Architecture:** Object-oriented design with class encapsulation
- **Key Classes:** `Sudoku`, `Cellgrid`

### Key Concepts
- Recursive backtracking algorithms
- Depth-first search (DFS)
- Dynamic memory allocation/deallocation
- File I/O for CSV and BMP formats
- Grid-based data structures with row-major ordering
- Constraint satisfaction problems

### Performance Characteristics
- **Sudoku Solver:** O(9^m) where m is the number of empty cells, optimized with constraint checking
- **Cell Counting:** O(n) time complexity where n is total grid cells
- **Image Processing:** O(width × height) with two passes over the image

## Project Structure

```
sudoku-solver-algorithms/
├── sudoku.h                  # Sudoku class definition
├── sudoku.cpp                # Solver implementation with backtracking
├── test_sudoku.cpp           # Sudoku test program
├── cellgrid.h                # Grid class definition
├── cellgrid.cpp              # DFS and blob counting implementation
├── test_cellgrid.cpp         # Cellgrid test program
├── imageBin.cpp              # Image processing with threshold calculation
├── bitmap_image.hpp          # BMP library (external)
├── test_puzzle.csv           # Sample Sudoku puzzle
├── test_grid.txt             # Sample binary grid
├── README.md                 # Documentation
└── .gitignore                # Excluded files
```

**Note:** Compiled executables and output files are generated locally and not included in the repository.

## Running the Programs

### 1. Sudoku Solver

```bash
./sudoku
```

**Input:** Reads `test_puzzle.csv` - a 9x9 grid where 0 represents empty cells

**Output:**
```
Solving puzzle...
Solution:
5,3,4,6,7,8,9,1,2
6,7,2,1,9,5,3,4,8
1,9,8,3,4,2,5,6,7
8,5,9,7,6,1,4,2,3
4,2,6,8,5,3,7,9,1
7,1,3,9,2,4,8,5,6
9,6,1,5,3,7,2,8,4
2,8,7,4,1,9,6,3,5
3,4,5,2,8,6,1,7,9
```

### 2. Connected Component Analysis

```bash
./test_cellgrid
```

**Input:** Reads `test_grid.txt` - a binary grid of 1s and 0s

**Sample Input:**
```
1 1 0 0 1
1 0 0 1 1
0 0 1 0 0
1 1 0 0 0
0 0 0 1 1
```

**Output:**
```
Number of blobs (4-connectivity): 5
Number of blobs (8-connectivity): 3
```

### 3. Image Binarization

```bash
# Download test image
wget https://people.math.sc.edu/Burkardt/data/bmp/blackbuck.bmp -O test_image.bmp

# Run binarization
./imagebin test_image.bmp output_image.bmp
```

**Result:** Creates `output_image.bmp` with only black and white pixels.

## Learning Outcomes

**Algorithms:**
- Recursive problem-solving techniques
- Backtracking and search space exploration
- Depth-first search implementation
- Constraint satisfaction strategies

**Software Engineering:**
- Object-oriented design in C++
- Memory management with heap allocation
- File I/O for different formats
- Code documentation and maintainability
- Testing and validation

**Problem Solving:**
- Breaking complex problems into smaller subproblems
- Choosing appropriate data structures
- Optimizing recursive algorithms
- Understanding time/space complexity tradeoffs

## Development Context

This project was developed as part of **CSC 211: Data Structures and Algorithms** at the University of Rhode Island. The assignment focused on applying recursive techniques to solve real-world computational problems efficiently. All three programs scored full marks (120/120) on the automated test suite.

## Limitations & Future Improvements

**Current Implementation:**
- Sudoku solver uses basic backtracking (could add forward checking)
- Image binarization uses simple averaging (could implement Otsu's method)
- Single-threaded execution only

**Potential Enhancements:**
- Add Sudoku difficulty rating algorithm
- Implement advanced image thresholding techniques
- Add visualization of algorithm execution
- Build comprehensive test suite with edge cases
- Add command-line argument parsing for flexibility

## Legal & Educational Context

**Educational Purpose:** This project was created for learning data structures and algorithm design in an academic setting.

**Academic Integrity:** All code represents original work completed for CSC 211 with appropriate comments and documentation added for clarity and maintainability.

## License

MIT License - Free to use, modify, and distribute

## Contact

Cameron Higney  
Email: cmhigney@uri.edu, cmhigney@gmail.com  
University of Rhode Island - Computer Science

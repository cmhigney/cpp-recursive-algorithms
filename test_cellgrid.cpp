#include "cellgrid.h"
#include <iostream>

int main() {
    // Test blob counting with 4-connectivity
    Cellgrid grid1("test_grid.txt", 5, 5);
    int blobs4 = grid1.countBlobs(4);
    std::cout << "Number of blobs (4-connectivity): " << blobs4 << std::endl;
    
    // Test blob counting with 8-connectivity
    Cellgrid grid2("test_grid.txt", 5, 5);
    int blobs8 = grid2.countBlobs(8);
    std::cout << "Number of blobs (8-connectivity): " << blobs8 << std::endl;
    
    return 0;
}

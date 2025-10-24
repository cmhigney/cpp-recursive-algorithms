#ifndef _CELLGRID_H_
#define _CELLGRID_H_

class Cellgrid {
    private:
        // Grid dimensions
        int rows, cols;
        
        // 1D array storing grid in row-major order
        bool *grid;
        
    public:
        Cellgrid(const char *fname, int m, int n);
        ~Cellgrid();
        
        // Count connected cells starting from (row, col)
        int countCells(int row, int col, int conn);
        
        // Count total number of separate blobs
        int countBlobs(int conn);
        
        void print();
};
#endif

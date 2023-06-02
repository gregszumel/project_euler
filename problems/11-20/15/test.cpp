#include <iostream>
#include <algorithm>
#include <string>
#include<map>
#include <list>
using namespace std;


/*
Starting in the top left corner of a 2 × 2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20 × 20 grid?
*/

// Creates a pointer to pointers; which point to vectors. 
long** createGrid(unsigned dim) {
    long** grid = new long*[dim];
    for (int d = 0; d < dim; d++){
        grid[d] = new long[dim];
        for (int i = 0; i < dim; i++) grid[d][i] = 0;
    }
    return grid;
}

int main() {
    int DIM = 21;
    long **grid = createGrid(DIM);

    // dynamic programming - new routes are routes to right plus routes below
    for (int i = DIM - 1; i >= 0; i--){
        for (int j = DIM - 1; j >= 0; j--) {
            if ((i + 1) >= DIM && (j+1) >= DIM) grid[i][j] = 1; // bot-right corner
            else if ((i + 1) >= DIM) grid[i][j] = grid[i][j+1]; // right col
            else if ((j + 1) >= DIM) grid[i][j] = grid[i+1][j]; // bottom row
            else grid[i][j] = grid[i][j+1] + grid[i+1][j]; // everything else
        }
    }

    // printing to debug;
    // for (int i = 0; i < DIM; i++){
    //     for (int j = 0; j < DIM; j++) cout << grid[i][j] << " ";
    //     cout << endl;
    // }

    cout << grid[0][0] << endl;
}
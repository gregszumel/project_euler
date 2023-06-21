#include <iostream>
using namespace std;

/*
Starting with the number 1 and moving to the right in a clockwise direction a 
5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101 .

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed 
in the same way?


43 44 45 46 47 48 49
42 21 22 23 24 25 26
41 20  7  8  9 10 27
40 19  6  1  2 11 28
39 18  5  4  3 12 29
38 17 16 15 14 13 30
37 36 35 34 33 32 31

*/

int main() {
    // We do not need to construct the spiral. Note that the top-left of the 
    // square is a square number, n^2. Then the other three corners of the 
    // square are n^2 - k(n-1), where k is the corner number.
    int radius, spiralsize;
    unsigned long sum, corner; 
    sum = 1; radius = 2; spiralsize = 3;
    while (spiralsize <= 1001) {
        // cout << radius << ", " << spiralsize << "---";
        // could make this a little nicer with a for loop
        long tr_corner = pow(spiralsize, 2);
        long tl_corner = tr_corner - (spiralsize - 1);
        long bl_corner = tl_corner - (spiralsize - 1);
        long br_corner = bl_corner - (spiralsize - 1);
        sum += tr_corner + tl_corner + bl_corner + br_corner;

        // cout << tr_corner << ", " << tl_corner << ", " << bl_corner << ", " << br_corner << endl;
        radius += 1;
        spiralsize = 2*(radius - 1) + 1;
    }
    cout << sum << endl; // 669171001
}
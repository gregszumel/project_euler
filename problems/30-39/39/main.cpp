#include <iostream>
using namespace std;

/*
If p is the perimeter of a right angle triangle with integral length sides, 
{ a , b , c } , there are exactly three solutions for p = 120 .

{ 20 , 48 , 52 } , { 24 , 45 , 51 } , { 30 , 40 , 50 }

For which value of p ≤ 1000 , is the number of solutions maximised?
*/

int nsolutions (int perimeter) {
    int solns = 0;
    // for loop A
    for (int A = 1; A <= perimeter - 2; A++) {
        // for loop B >= A
        for (int B = A; B <= perimeter - 1; B++) {
            int C = perimeter - B - A;
            if (pow(C, 2) == pow(B, 2) + pow(A, 2)) {
                // cout << A << ", " << B << ", "<< C << endl;
                solns += 1;
            } 
        }
    }
    return solns;
}


int main() {
    int maxval = 0;
    int maxnum = -1;
    for (int p = 10; p <= 1000; p++) {
        int solns = nsolutions(p);
        cout << p << ": " <<  solns << endl;
        if (solns > maxval) {
            maxval = solns; 
            maxnum = p;
        }
    }
    cout << maxnum << ": " << maxval << endl;
}
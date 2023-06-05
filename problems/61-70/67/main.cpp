#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 100;
const string FILENAME = "0067_triangle.txt";

void printTriangle(int triangle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

// max of two numbers
int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

// max over an array of length SIZE
int max(int x[], int size){
    int maxval = -2147483647 - 1;
    for (int i = 0; i < size; i++) if (x[i] > maxval) maxval = x[i]; 
    return maxval;
}

int main() {
    int x;
    int input_triangle[SIZE][SIZE];

    ifstream inFile;
    
    inFile.open(FILENAME);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    int xcounter = 0; 
    int ycounter = 0; 
    while (inFile >> x) {
        input_triangle[xcounter][ycounter] = x;
        if (ycounter == xcounter) {
            ycounter = 0;
            xcounter++;
        } else {
            ycounter++; 
        }
    }
    inFile.close();

    // printTriangle(input_triangle);


    int sum[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j <= i; j++){
            // top
            if (i == 0) sum[i][j] = input_triangle[i][j]; 
            // left edge -- only take num above
            else if (j == 0) sum[i][j] = input_triangle[i][j] + sum[i-1][j];
            // left edge -- only take num from top left
            else if (j == i) sum[i][j] = input_triangle[i][j] + sum[i-1][j-1];
            // typical case -- take max of numbers above
            else sum[i][j] = input_triangle[i][j] + max(sum[i-1][j-1], sum[i-1][j]);
        }
    }

    cout << max(sum[SIZE-1], SIZE) << endl;

    return 0;
}


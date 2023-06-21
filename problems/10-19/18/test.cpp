#include <iostream>
using namespace std;


// const int SIZE = 4;
// int A[SIZE][SIZE] = {
// {3},
// {7,4},
// {2,4,6},
// {8,5,9,3}
// };

const int SIZE = 15;
int A[SIZE][SIZE] = {
    {75},
    {95,64},
    {17,47,82},
    {18,35,87,10},
    {20,4,82,47,65},
    {19,1,23,75,3,34},
    {88,2,77,73,7,63,67},
    {99,65,4,28,6,16,70,92},
    {41,41,26,56,83,40,80,70,33},
    {41,48,72,33,47,32,37,16,94,29},
    {53,71,44,65,25,43,91,52,97,51,14},
    {70,11,33,28,77,73,17,78,39,68,17,57},
    {91,71,52,38,17,14,91,43,58,50,27,29,48},
    {63,66,4,68,89,53,67,30,73,16,69,87,40,31},
    {4,62,98,27,23,9,70,98,73,93,38,53,60,4,23}
};

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
int max(int x[SIZE]){
    int maxval = -2147483647 - 1;
    for (int i = 0; i < SIZE; i++) if (x[i] > maxval) maxval = x[i]; 
    return maxval;
}

int main() {
    int sum[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j <= i; j++){
            // top
            if (i == 0) sum[i][j] = A[i][j]; 
            // left edge -- only take num above
            else if (j == 0) sum[i][j] = A[i][j] + sum[i-1][j];
            // left edge -- only take num from top left
            else if (j == i) sum[i][j] = A[i][j] + sum[i-1][j-1];
            // typical case -- take max of numbers above
            else sum[i][j] = A[i][j] + max(sum[i-1][j-1], sum[i-1][j]);
        }
    }

    // printing for debugging
    // printTriangle(sum);


    cout << max(sum[SIZE-1]) << endl;
}
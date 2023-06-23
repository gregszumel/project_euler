#include <iostream>
using namespace std;

/*
The series, 1^1 + 2^2 + 3^3 + ⋯ + 10^10 = 10405071317.

Find the last ten digits of the series, 
1^1 + 2^2 + 3^3 + ⋯ + 1000 1000 */

int main () {
    // tracking the sum, next 10 digits, constant to mod out
    unsigned long long sum, next10digits;
    const unsigned long long maxval = pow(10, 10);
    
    sum = 0;
    // iterate through all the number
    for (int i = 1; i <= 1000; i++) {
        next10digits = 1;
        // do our own custom power calculation
        for (int powcounter = 1; powcounter <= i; powcounter++) {
            // we don't need to track the whole number, just the last 10 digits
            next10digits = (next10digits * i) % maxval;
        }
        // sum the digits and mod out
        sum += next10digits;
        sum = sum % maxval;
        // print for checking
        // cout << i << ": " << next10digits << ". new sum: " << sum << endl;
    }
    // answer
    cout << sum << endl;
}
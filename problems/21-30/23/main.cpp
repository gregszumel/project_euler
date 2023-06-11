#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

/*
A perfect number is a number for which the sum of its proper divisors is exactly
equal to the number. For example, the sum of the proper divisors of 28 would be 
1 + 2 + 4 + 7 + 14 = 28 , which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than 
n and it is called abundant if this sum exceeds n .  As 12 is the smallest 
abundant number, 1 + 2 + 3 + 4 + 6 = 16 , the smallest number that can be 
written as the sum of two abundant numbers is 24 . By mathematical analysis, 
it can be shown that all integers greater than 28123 can be written as the sum 
of two abundant numbers. However, this upper limit cannot be reduced any further 
by analysis even though it is known that the greatest number that cannot be 
expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of 
two abundant numbers.
*/



// gets the sum of the proper divisors; could probably be more efficient
// by not checking every potential number; only look until the sqrt and 
// if one is found, calculate the reciprocal
int sumOfProperDivisors(int n) {
    int divisorsum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0) divisorsum = divisorsum + i;
    }
    return divisorsum;
}

// bool using sum of proper divisors
bool isabundant(int i) {
    return sumOfProperDivisors(i) > i;
}

// checks whether or not x is the sum of abundant numbers
bool isSumOfAbundants(int x, int abundants[], int size){
    // starting with the first (lowest) element, assume it is part of the sum.
    // our target will be -> abundants[i] + abundants[j] = x
    for (int i = 0; i < size; i++) {
        int target = x - abundants[i];
        // if the target is less than zero, its not possible, so return false
        if (target <= 0) return false;

        // assuming target is greater than zero, check other potential numbers. 
        for (int j = i; j < size; j++){
            // if the target is found, then return true
            if (abundants[j] == target) return true;
            // if the abundants are greater than the target, break
            else if (abundants[j] > target) break;
        }
    }
    return false;
}


int main() {
    // build list
    list<int> abundantNumbersList;
    for (int i = 1; i < 28123; i++) {
        if (isabundant(i)) abundantNumbersList.push_back(i);
    }
    cout << "built list" << endl;

    // build vector
    int numAbundants = abundantNumbersList.size();
    int abundantNumbers[numAbundants];
    int counter = 0;
    for (int abundant: abundantNumbersList) {
        abundantNumbers[counter] = abundant;
        counter++;
    }
    cout << "built vector" << endl;


    // iterate through every number and calculate if it is an abundant number
    int sum = 0;
    counter = 0;
    for (int x = 1; x < 28123; x++) {
        if (!isSumOfAbundants(x, abundantNumbers, numAbundants)) {
            sum = sum + x;
            // cout << x << ", new sum:" << sum << endl;
        }
        if (x % 1406 == 0) {
            cout << counter << "%" << endl; 
            counter = counter + 5;
        }
    }
    cout << sum << endl; // 4179871
}
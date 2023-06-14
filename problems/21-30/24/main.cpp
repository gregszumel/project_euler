#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

/*
A permutation is an ordered arrangement of objects. For example, 3124 is one 
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are 
listed numerically or alphabetically, we call it lexicographic order. The 
lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 
6, 7, 8 and 9?
*/


// 0
// 10 01
// 210 120 102 201 021 012

class bigNumber {
    public:
        list<int> digits;

        // returns a copy of the digits
        list<int> copy() {
            list<int> copy;
            for (int digit: digits) copy.push_back(digit);
            return copy;
        }

        // returns a list of new bigNumbers
        list<bigNumber> insertNumber(int num_to_insert) {

            // return list
            list<bigNumber> new_numbers;

            // iterate through the list, inserting the new number in new copies
            for (int i = 0; i < digits.size(); i++) {
                list<int> digit_copy;
                int counter = 0;

                for (int digit: digits) {
                    if (counter == i) digit_copy.push_back(num_to_insert);
                    digit_copy.push_back(digit);
                    counter++;
                }
                bigNumber newNum; newNum.digits = digit_copy;
                new_numbers.push_back(newNum);
            }

            // also add one for the last element
            bigNumber finalNum; 
            list<int> finalDigits = copy(); 
            finalDigits.push_back(num_to_insert);
            finalNum.digits = finalDigits;
            new_numbers.push_back(finalNum);

            return new_numbers;
        }

        void print() {
            for (int digit: digits) cout << digit; 
        }

        long long toInt() {
            int counter, size; 
            long long number = 0;
            size = digits.size() - 1;

            for (int digit: digits) {
                number = number + (digit * pow(10, size));
                size--;
            }
            return number;
        }
};


int main() {
    list<int> digits = {0}; bigNumber N; N.digits = digits;
    list<bigNumber> currNumberSet = {N};

    // get all possibilities
    for (int i = 1; i < 10; i++) {
        cout << i << endl;
        list<bigNumber> nextNumberSet; 
        for (bigNumber n: currNumberSet) {
            list<bigNumber> nextNumberSubset = n.insertNumber(i);
            nextNumberSet.splice(nextNumberSet.end(), nextNumberSubset);
        }
        currNumberSet = nextNumberSet;
    }

    // make list fast for sorting
    list<long long> currNumberSetInts;
    cout << "making long-long list..." << endl;
    for (bigNumber x: currNumberSet) {
        long long n = x.toInt();
        currNumberSetInts.push_back(n);
    }
    cout << "made list of size " << currNumberSetInts.size() << endl;

    // sort once
    cout << "sorting..." << endl;
    currNumberSetInts.sort();
    cout << "done sorting!" << endl;

    int counter = 1;
    for (long long n: currNumberSetInts) {
        if (counter == 1000000) cout << "one millionth: " << n << endl;
        counter++;
    }
    // 2783915460

}
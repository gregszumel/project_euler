#include <iostream>
#include <list>
using namespace std;

/*
The prime 41 , can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13.  

This is the longest sum of consecutive primes that adds to a prime below 
one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, 
contains 21 terms, and is equal to 953 .

Which prime, below one-million, can be written as the sum of the most 
consecutive primes?
*/

// find all primes less than a million
// starting at primes greater than 1000
// make a new list of current primes in our consecutive sum
// add elements, keeping track of total sum. 
//  if next element makes our sum exceed the target, remove from the front until
//  we can add it

//  if the sum ever equals are target, return the length of the list


void build_primes(bool *primes,  int size) {
    for (int i = 0; i < size; i++) primes[i] = true;
    primes[0] = false; primes[1] = false;

    for (int i = 2; i < size; i++) {
        if (primes[i] == true){
            for (int k = 2; k*i < size; k++) {
                primes[i*k] = false;
            }
        }
    }
}

int get_next_prime_idx(bool *primes, int size, int idx) {
    for (int i = idx + 1; idx < size; i++) {
        // cout << "i: " << i << endl;
        if (primes[i] == true) return i;
    }
    return 0;
}


int get_consecutive_len(bool *primes, int size, int target) {
    int start = get_next_prime_idx(primes, size, 0);
    int end = start;
    int sumlength = 1;
    int sum = 2;

    // while the back of our list is less than the target value
    while (end < target) {
        // if we've found the sum, return it; 
        if (sum == target) {return sumlength;}

        end = get_next_prime_idx(primes, size, end);
        sum += end;
        sumlength++;

        while (sum > target) {
            sum -= start;
            start = get_next_prime_idx(primes, size, start);
            sumlength -= 1;
        }
        // cout << "sum: " << sum << "-- start: " << start << "-- end" << end << endl;
    }
    return 0;
}



int main () {
    int longest_len = 0;
    int longest_len_num = 0;
    int size = 1000000;
    bool primes[size];
    build_primes(primes, size);
    cout << "built primes" << endl;
    // cout << get_next_prime_idx(primes, size, 13) << endl;

    // int len = get_consecutive_len(primes, size, 953);
    // cout << "953 len: " << len;
    // cout << "got length" << endl;

    for (int target = 0; target < size; target++) {
        if (target < 1000) continue;
        else if (primes[target] == false) continue;

        int consecutive_len = get_consecutive_len(primes, size, target);
        cout << target << ": " << consecutive_len << endl;

        if (consecutive_len > longest_len) {
            longest_len = consecutive_len;
            longest_len_num = target;
        }
    }
    cout << longest_len << ", " << longest_len_num;
}
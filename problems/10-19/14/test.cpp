#include <iostream>
#include <algorithm>
#include <string>
#include<map>
#include <list>
using namespace std;

/* 
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 
10 terms. Although it has not been proved yet (Collatz Problem), it is thought 
that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

// Could be optimized to take a map of num->lengths, so that if we hit a num 
// we can just return current_length + stored_length
int collatzlength(long collatz_num){
    int length = 1;
    while (collatz_num != 1){
        if (collatz_num % 2 == 0) collatz_num = collatz_num / 2;
        else collatz_num = 3 * collatz_num + 1;
        length++;
    }
    return length;
}

int main() {
    int longest = 0;
    int longest_collatz = 0;
    for (long i = 1; i < 1000000; i++){
        int curr_length = collatzlength(i);
        if (curr_length > longest) {
            longest = curr_length;
            longest_collatz = i;
        }
    }
    cout << longest_collatz << ": " << longest << endl; // 837799: 525
}
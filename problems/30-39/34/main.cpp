#include <iostream> 
using namespace std;



/*
145 is a curious number, as 1 !  + 4 !  + 5 !  = 1 + 24 + 120 = 145 .

Find the sum of all numbers which are equal to the sum of the factorial of their
digits.  Note: As 1 !  = 1 and 2 !  = 2 are not sums they are not included.
*/

// we use a switch statement here for faster lookup than calculating it every 
// time... saves worst case 9x time complexity multiplier
int factorial(int n) {
    assert(n < 10);
    switch (n) {
        case 0: return 1;
        case 1: return 1;
        case 2: return 2;
        case 3: return 6;
        case 4: return 24;
        case 5: return 120;
        case 6: return 720;
        case 7: return 5040;
        case 8: return 40320;
        case 9: return 362880;
    }
}


int main () {
    // todo; could speed up by making factorial a switch statement (since 
    // there's only 10 possible outcomes), and by reducing the pow
    int nextdigit;
    long sumcheck, totalsum;
    totalsum = 0;

    // max value has 8 digits, since 9! * 7 = <a seven digit number>
    for (long i = 10; i < pow(10, 7); i++) {
        long j = i;
        sumcheck = 0;
        while (j > 0) {
            nextdigit = j % 10;
            sumcheck += factorial(nextdigit);
            j = j / 10;
        }
        if (sumcheck == i) {
            totalsum += i;
        }
    }
    cout << totalsum << endl;
}
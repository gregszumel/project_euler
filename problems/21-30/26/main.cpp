#include <iostream>
#include <list> 
using namespace std;


/*
A unit fraction contains 1 in the numerator. The decimal representation of the 
unit fractions with denominators 2 to 10 are given:
 
1 / 2	=0.5	
1 / 3	=0.(3)	
1 / 4	=0.25	
1 / 5	=0.2	
1 / 6	=0.1(6)	
1 / 7	=0.(142857)	
1 / 8	=0.125	
1 / 9	=0.(1)	
1 / 10	=0.1 

Where 0.1 ( 6) means 0.166666 ⋯ , and has a 1 -digit recurring cycle. It can be 
seen that 1 / 7 has a 6 -digit recurring cycle.  

Find the value of d < 1000 for which 1 / d contains the longest recurring cycle 
in its decimal fraction part.
*/

// gets the length of the cycle of 1 / x, where x in the input
int getPeriodicity(int x) {
    // setup remainder, digitcounter, and the remainder vector
    int remainder, digitcounter;
    digitcounter = 1; remainder = 1;
    // we'll use this to keep track of whether or not we've seen this remainder 
    // before, and when we saw it
    int remainders[x];
    for (int i = 0; i < x; i++) remainders[i] = 0;

    while (true) {
        remainder = (remainder % x);

        // if the remainder is ever zero, then 1/x has no repeats, and we can return 0;
        if (remainder == 0) {
            return 0;
        } 
        // if we've seen the reaminder before, then we've hit a repeat
        else if (remainders[remainder] != 0) {
            // now we can calculate the length of the repeat by taking the 
            // current digit number and subtract the digit number we were on 
            // when we hit the remainder the first time
            return digitcounter - remainders[remainder];
        } 
        // otherwise, we'll record the digit we saw this remainder;
        else {
            remainders[remainder] = digitcounter;
        }
        // increment the digit counter, and shift the remainder by a digit
        digitcounter++;
        remainder = remainder * 10;
    }
}


int main() {
    int maxPeriodicity = 0; 
    int maxPeriodicityVal = 0;

    for (int i = 10; i < 1000; i++) {
        int periodicity = getPeriodicity(i);
        if (periodicity > maxPeriodicity) {
            maxPeriodicity = periodicity;
            maxPeriodicityVal = i;
        }
    }
    cout << maxPeriodicityVal << ": " << maxPeriodicity << endl;
}
#include <iostream>
using namespace std;

/*
Take the number 192 and multiply it by each of 1 , 2 , and 3 :
192×1	=192	
192×2	=384	
192×3	=576 

By concatenating each product we get the 1 to 9 pandigital, 192384576 . 
We will call 192384576 the concatenated product of 192 and ( 1 , 2 , 3) .

The same can be achieved by starting with 9 and multiplying by 1 , 2 , 3 , 4 , 
and 5 , giving the pandigital, 918273645, which is the concatenated product of 9
and ( 1 , 2 , 3 , 4 , 5) .

What is the largest 1 to 9 pandigital 9 -digit number that can be formed as the 
concatenated product of an integer with ( 1 , 2 , … , n) where n > 1 ?
*/

int ndigits (unsigned long x ) {
    return floor(log10(x)) + 1;
}

bool ispandigital(unsigned long x) {
    unsigned long digit_tracker[10];
    for (int i = 0; i < 10; i++) digit_tracker[i] = 0;
    digit_tracker[0] = 1;
    while (ndigits(x) >= 1) {
        int digit = x % 10;
        // cout << x << ", " << digit << ", " << digit_tracker[digit] << endl;
        if (digit_tracker[digit] == 1) return false;
        digit_tracker[digit] = 1;
        x = x / 10;
    }
    return true;
}

int main () {

    // cout << ispandigital(982719654);

    // loop through all numbers less than 999999999
    for (unsigned long i = 1; i < 99999999; i++) {
        // iterate through all potential multiples
    unsigned long multiplier = 2;
    unsigned long pandigital = i;
        while (true) {
            // construct 9 digit number
            unsigned long digits_to_add = i * multiplier;
            // cout << digits_to_add << endl;
            pandigital = pandigital * pow(10, ndigits(digits_to_add));
            // cout << pandigital << endl;
            pandigital = pandigital + digits_to_add;
            // cout << pandigital << endl;
            if (ndigits(pandigital) == 9) {
                if (ispandigital(pandigital)) {
                    cout << i << ", " << multiplier << " => " << pandigital << endl;
                }
            }

            else if (ndigits(pandigital) > 9) break;
            multiplier++;
        }
    }
}
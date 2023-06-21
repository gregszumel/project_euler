#include <iostream>
using namespace std;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 
1634	= 1^4 + 6^4 + 3^4 + 4^4 
8208	= 8^4 + 2^4 + 0^4 + 8^4
9474	= 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1 4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth 
powers of their digits.
*/

int digits2int(int x1, int x2, int x3, int x4, int x5, int x6) {
    return pow(10, 0) * x6 + pow(10, 1) * x5 + pow(10, 2) * x4 + 
            pow(10, 3) * x3 + pow(10, 4) * x2 + pow(10, 5) * x1;
}

int digits2power(int x1, int x2, int x3, int x4, int x5, int x6, int exp) {
    return pow(x6, exp) + pow(x5, exp) + pow(x4, exp) + pow(x3, exp) 
            + pow(x2, exp) + pow(x1, exp);
}

int main() {
    // 1 digit: 9^5 = 59049        --> greater than 9
    // 5 digits: 9%6 * 5 = 295,245 --> greater than 99,999
    // 6 digits: 9^5 * 6 = 354,294 --> less than    999,999 
    // therefore, we can't go above six digits without it never being possible.
    int runningsum = 0;
    

    // lazy way.
    for (int x1 = 0; x1 < 10; x1++) {
        for (int x2 = 0; x2 < 10; x2++) {
            for (int x3 = 0; x3 < 10; x3++) {
                for (int x4 = 0; x4 < 10; x4++) {
                    for (int x5 = 0; x5 < 10; x5++) {
                        for (int x6 = 0; x6 < 10; x6++) {
                            // cout << x1 << x2 << x3 << x4 << x5 << x6 << "||";
                            // cout << actual_num(x1, x2, x3, x4, x5, x6) << endl;
                            int actualnum = digits2int(x1, x2, x3, x4, x5, x6);
                            int powersum = digits2power(x1, x2, x3, x4, x5, x6, 5);
                            if (actualnum == powersum && actualnum > 9)  {
                                cout << actualnum << "||" << powersum << endl;
                                runningsum += actualnum;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << runningsum << endl;
}



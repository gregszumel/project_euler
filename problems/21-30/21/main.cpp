#include <iostream>
#include <algorithm>
using namespace std;

/* Let d(n) be defined as the sum of proper divisors of n (numbers less than 
n which divide evenly into n).  If d ( a) = b and d ( b) = a , where a ≠ b, then
a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1 , 2 , 4 , 5 , 10 , 11 , 20 , 22, 
44 , 55 and 110 ; therefore d ( 220) = 284 . The proper divisors of 284 are 1,
2 , 4 , 71 and 142 ; so d ( 284) = 220 . 

Evaluate the sum of all the amicable numbers under 10000.
*/ 

int sumOfProperDivisors(int x) {
    int divisorsum = 1;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) divisorsum = divisorsum + i;
    }

    return divisorsum;
}

int main() {
    int potential_amicable, checking_amicable, amicable_sum;
    amicable_sum = 0;

    for (int n = 2; n < 10000; n++) {
        potential_amicable = sumOfProperDivisors(n);
        if (potential_amicable <= n) continue;
        checking_amicable = sumOfProperDivisors(potential_amicable);
        if (checking_amicable == n)  {
            amicable_sum = amicable_sum + n + potential_amicable;
            cout << "Amicable pair found! d(" << n << ") = " ;
            cout << potential_amicable << ", d("<< potential_amicable << ") = ";
            cout << checking_amicable << endl; 
        }
    }
    cout << amicable_sum << endl; // 31626
}
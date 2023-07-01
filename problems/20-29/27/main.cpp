#include <iostream>
using namespace std;

/*
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive integer 
values 0 ≤ n ≤ 39 . However, when n = 40 , 40^2 + 40 + 41 = 40 ( 40 + 1) + 41
is divisible by 41 , and certainly when n = 41 , 41^2 + 41 + 41 is clearly 
divisible by 41 .

The incredible formula 

n^2 − 79 n + 1601

was discovered, which produces 80 primes for the consecutive values 0 ≤ n ≤ 79 . 
The product of the coefficients, − 79 and 1601 , is − 126479 .

Considering quadratics of the form:

n^2 + a n + b , 

where | a | < 1000 and | b | ≤ 1000 where | n | is the modulus/absolute value 
of n (e.g.  | 11 | = 11 and | − 4 | = 4). Find the product of the coefficients, 
a and b , for the quadratic expression that produces the maximum number of 
primes for consecutive values of n, starting with n = 0 .
*/

bool isprime(int x) {
    if (x < 0) return false;
    for (int p = 2; p <= sqrt(x); p++) {
        if (x % p == 0) return false;
    }
    return true;
}


int main() {
    int counter;
    int longest_a = -9999;
    int longest_b = -9999;
    int longest_streak = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            counter = -1;
            bool streak_broken = false;
            while (!streak_broken) {
                counter++;
                int potential_prime = counter*counter + a * counter + b;
                if (!isprime(potential_prime)) streak_broken = true;
            }
            // cout << " a: " << a << " b: " << b << " nprimes: " << counter << endl;
            if (longest_streak < counter) {
                longest_a = a;
                longest_b = b;
                longest_streak = counter;
                // cout << "new longest streak " << counter << " a: " << a << " b: " << b << endl;
            }
        }
    }
    cout << "a: " << longest_a << " b: " << longest_b << " streak: "<< longest_streak << endl;
    cout << "a*b: " << longest_a*longest_b << endl;
}
#include <iostream> 
using namespace std;


/*
The number, 197 , is called a circular prime because all rotations of the 
digits: 197 , 971 , and 719 , are themselves prime.

There are thirteen such primes below 100 : 2 , 3 , 5 , 7 , 11 , 13 , 17 , 31 ,
37 , 71 , 73 , 79 , and 97 .

How many circular primes are there below one million?
*/

bool isprime(int p) {
    if (p < 2) return false;

    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) return false;
    } 
    return true;
}

int getnextcircular(int circular_num, int ndigits) {
    int circular_num_ones_digit = circular_num % 10;
    circular_num = circular_num / 10;
    circular_num = circular_num + circular_num_ones_digit * pow(10, ndigits);
    return circular_num;
}



int main() {
    int n_circ_primes = 13; // start off with what they gave us

    int MAXNUM = 1000000;
    int checked[MAXNUM];
    for (int i = 0; i < MAXNUM; i++) checked[i] = 0;

    for (int i = 100; i < MAXNUM; i++) {
        if (checked[i] == 1) {
            continue;
        } 

        bool all_prime = true;
        int circular_num = i;
        int ndigits = floor(log10(circular_num));

        for (int digit = 0; digit < ndigits + 1; digit++) {
            circular_num = getnextcircular(circular_num, ndigits);
            checked[circular_num] = 1;

            if (all_prime) {
                if (!isprime(circular_num)) {
                    all_prime = false;
                }
             }
        }

        if (all_prime) {
            // cout << i << ", adding " << ndigits + 1 << endl;
            n_circ_primes += ndigits+1;
        }
    }
    // cout << "Max reached: " << pow(10, 6) << endl;
    cout << n_circ_primes << endl;
}
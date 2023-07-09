#include <iostream>
#include <list>
using namespace std;

/*
It was proposed by Christian Goldbach that every odd composite number can be 
written as the sum of a prime and twice a square.

 
9=7+2× 1 2
15=7+2× 2 2
21=3+2× 3 2
25=7+2× 3 2
27=19+2× 2 2
33=31+2× 1 2
 
It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/


bool isprime(list<int> primes, int n) {
    for (int p: primes) {
        if (n % p == 0) return false;
        else if (sqrt(n) < p) break;
    }
    return true;
}

int golbach_val(int prime, int square) {
    return prime + 2 * square * square;
}

pair<int, int> find_goldbach_val (list<int> primes, int i) {
    for (int prime: primes) {
        int square = 1;
        int val;
        while ((val = golbach_val(prime, square)) < i) {
            square++;
        }
        if (val == i) {
            return make_pair(prime, square);
        }
    }
    return make_pair(-1, -1);
}


int main() {
    list<int> primes = {2, 3, 5, 7};
    int i = 9;
    while (true) {
        if (isprime(primes, i)) {
            primes.push_back(i);
        } 
        else {
            pair<int, int> gpair = find_goldbach_val(primes, i);
            if (gpair.first == -1 && gpair.second == -1) { 
                std::cout << i << endl;
                return 0;
                }
            // cout << i << ": " << gpair.first << ", " << gpair.second << endl;
        }
        i += 2;
    }
}
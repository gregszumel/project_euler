#include <iostream>
#include <list>
using namespace std;

/*
We shall say that an n -digit number is pandigital if it makes use of all the 
digits 1 to n exactly once. For example, 2143 is a 4 -digit pandigital and is 
also prime.

What is the largest n -digit pandigital prime that exists?
*/

bool ispandigital(unsigned long x) {
    string x_str = to_string(x);
    string digits = "123456789";
    unsigned long counter = 0;

    for (char digit: digits) {
        if ((int) x_str.find(digit) < 0) return false;
        counter++;
        if (counter == x_str.size()) break;
    }
    return true;
}

bool isprime(unsigned long p, list<unsigned long> primes){
    for (unsigned long prime: primes) {
        if (p % prime == 0) return false;
        else if (prime > sqrt(p)) return true;
    }
    return true;
}

bool isprime(unsigned long p) {
    for (unsigned long x = 2; x <= sqrt(p); x++) {
        if (p%x == 0) return false;
    }
    return true;
}

list<unsigned long> build_primes(int max_prime) {
    list<unsigned long> prime_list; prime_list.push_back(2);
    for (unsigned long n = 3; n <= max_prime; n++){
        if (isprime(n, prime_list)){
            prime_list.push_back(n);
        }
    }
    return prime_list;
}


int main() {
    int max_prime = sqrt(987654321);
    // list<unsigned long> primes; primes.push_back(2);
    list<unsigned long> primes = build_primes(max_prime);
    cout << "built primes" << endl;

    unsigned long largest_pandigital = 0;
    for (unsigned long p = 3; p < 987654321; p++) {
        if (ispandigital(p)) {
            cout << p;
            if (isprime(p, primes)) {
                cout << " and is prime!";
                largest_pandigital = p;
            }
            cout << endl;
        }
    }
    cout << largest_pandigital;
}
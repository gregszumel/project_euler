#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that 
the 6th prime is 13.

What is the 10 001st prime number?
*/

bool isprime(int n, list<int> primes){
  for (int p: primes) {
    if (n % p == 0) return false;  // we've found a divisor
    else if (sqrt(n) < p) return true;  // if divisor existed, would have found
  }
  return true;
}


int main() {
  list<int> primes;
  int i = 2;
  while(primes.size() < 10001){
    if (isprime(i, primes)) {
      primes.push_back(i);
    }
    i = i + 1;
  }
  cout << primes.back();
}
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/


// takes too long to build a prime list and check if prime, so we'll do 
// something faster -- building an array of primes.
int SPAN = 2000000;

int main() {
  // array of all potential primes, where 1 is a prime indicator
  int potentialprimes[SPAN];
  for (int i = 0; i < SPAN; i++) potentialprimes[i] = 1;
  potentialprimes[0] = 0; potentialprimes[1] = 0; // setting 0, 1 to non-prime

  // iterate through all potential primes, removing any multiples of said prime
  for (int prime_idx = 0; prime_idx < SPAN; prime_idx++){
    // if 0, it was found to be a multiple
    if (potentialprimes[prime_idx] == 0) continue;
    // if not a previous multiple, remove every multiple of prime less than 2m
    for (int multiple = 2; multiple * prime_idx < SPAN; multiple++){
      potentialprimes[prime_idx * multiple] = 0;
    }
  }

  // sum up all the primes found
  long prime_sum = 0;
  for (int i; i < SPAN; i++){
    if (potentialprimes[i] == 1) {
      prime_sum = prime_sum + i;
    }
  }

  cout << prime_sum << endl;  // 142913828922
  return 0;
}
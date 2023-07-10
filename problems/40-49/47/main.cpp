#include <iostream>
#include <list>

/*
The first two consecutive numbers to have two distinct prime factors are:

 14	=2×7	
 15	=3×5. 

The first three consecutive numbers to have three distinct prime factors are:

 
  644	= 2^2 ×7×23	
  645	=3×5×43	
  646	=2×17×19. 

Find the first four consecutive integers to have four distinct prime factors 
each. What is the first of these numbers?
*/

std::list<int> primefactors(std::list<int> primes, int x) {
    std::list<int> factors;
    for (int prime: primes) {
        if (x == 1) {break;}
        if (x % prime == 0) {
            factors.push_back(prime);
        }
        while (x % prime == 0) {
            x = x / prime;
        }
    }
    return factors;
}

int main () {
    bool found = false;
    int curr_num = 11;
    int streak_counter = 0;
    int nfactors;
    std::list<int> primes = {2, 3, 5, 7, 11};
    std::list<int> factors;
    factors = primefactors(primes, 15);
    // for (int factor : factors) std::cout << factor << ", ";
    // std::cout << std::endl;

    while (!found) {
        curr_num++;
        factors = primefactors(primes, curr_num);
        nfactors = factors.size();
        std::cout << curr_num << ": " << nfactors << std::endl;

        if (nfactors == 0) {primes.push_back(curr_num); streak_counter = 0;}
        else if (nfactors == 4) {
            streak_counter++;
            if (streak_counter == 4) {
                break;
            }
        }
        else {streak_counter = 0;}
    }
}
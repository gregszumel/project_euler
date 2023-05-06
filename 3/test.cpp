#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/


long divide_all_out(long x, int d) {
  while ((x % d) == 0){
    x = x / d;
  }
  return x;
}


int main() {
  long target = 600851475143;
  double target_sqrt = sqrtl(target);
  int last_prime = 0;
  for(int i = 2; i < target_sqrt; i++){
    if (target % i == 0){
      target = divide_all_out(target, i);
      last_prime = i;
    } else if (target == 1) break;
  }
  std::cout << last_prime << endl;
}

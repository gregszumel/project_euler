#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ...  + 10^2 = 385

The square of the sum of the first ten natural numbers is,

( 1 + 2 + .  .  .  + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
3025 − 385 = 2640

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int main() {
  long sq_of_sum = 0;
  long sum_of_sq = 0;

  for(int i = 0; i <= 100; i++){
    sq_of_sum += i;
    sum_of_sq += pow(i, 2);
    // std::cout << i << ", " << sq_of_sum << ", " << sum_of_sq << endl;
  }
  long answer = pow(sq_of_sum, 2) - sum_of_sq;
  std::cout << answer << endl;
}
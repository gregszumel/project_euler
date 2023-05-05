#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we 
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/ 

int main() {
  int total_sum = 1;

  for(int i=1; i < 1000; i++){
    if ((i % 3) == 0){
      total_sum = total_sum + i;
    } else if (i % 5 == 0)
    {
      total_sum = total_sum + i;
    }
    std::cout << total_sum << "\n";
  }
  return total_sum;
}

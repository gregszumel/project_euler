#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool palindrome(int potential_palindrome) {
  list<int> digits;
  int num_digits = int(log10(potential_palindrome) + 1);

  // collect the digits
  for(int i = 0; i < num_digits; i++){
    digits.push_back(potential_palindrome % 10);
    potential_palindrome /= 10;
  }

  // check if front equals back, returning true if all are and false otherwise
  while(digits.size() > 1){
    if (digits.front() == digits.back()) {
      digits.pop_back();
      digits.pop_front();
    } 
    else {
      return false;
    }
  } 
  return true;
}

int main() {
  int largest_palindrome = 0;
  // iterate through all potential combinations
  for (int i = 100; i < 1000; i++){
    for (int j = i + 1; j < 1000; j++){
      int num = i * j;
      // if i * j is a palindrome and its larger than the largest found, save it
      if (palindrome(num) && num > largest_palindrome) largest_palindrome = num;
    }
  }
  cout << largest_palindrome << endl;
}
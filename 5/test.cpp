#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 
10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the 
numbers from 1 to 20?

Prime factorizations of 1-20:
1  = 1
2  = 2
3  = 3
4  = 2^2
5  = 5
6  = 3 * 2
7  = 7
8  = 2^3
9  = 3^2
10 = 5 * 2
11 = 11
12 = 3 * 2^2
13 = 13
14 = 7 * 2
15 = 5 * 3
16 = 2^4
17 = 17
18 = 3^2 * 2
19 = 19
20 = 5 * 2^2

Take max power of each prime above, and multiply together:
1 * 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232792560
*/


int main() {
  long answer = pow(2, 4) * pow(3, 2) * 5 * 7 * 11 * 13 * 17 * 19;  // 232792560
  cout << answer << endl;
}
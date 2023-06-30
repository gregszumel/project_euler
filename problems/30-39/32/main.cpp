#include <iostream> 
#include <string>
#include <list>
using namespace std;

/* We shall say that an n-digit number is pandigital if it makes use of all the 
digits 1 to n exactly once; for example, the 5 -digit number, 15234 , is 1 
through 5 pandigital.  The product 7254 is unusual, as the identity, 39 × 186 =
7254 , containing multiplicand, multiplier, and product is 1 through 9 
pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can 
be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only 
include it once in your sum.
*/


// returns true if there are repeated digits
bool hasrepeats(int x) {
    string x_str = to_string(x);
    for (int i = 0; i < x_str.size(); i++) {
        for (int j = i+1; j < x_str.size(); j++){
            if (x_str[i] == x_str[j]) {
                return true;
            }
        }
    }
    return false;
}

// returns true if x and y don't overlap on digits and dont' contain zero
bool potential_pandigital(int x, int y) {
    if (hasrepeats(x) || hasrepeats(y)) return false;

    string x_str = to_string(x);
    string y_str = to_string(y);

    for (char x_digit: x_str) {
        if (x_digit == '0') return false;
        for (char y_digit: y_str) {
            if (x_digit == y_digit || y_digit == '0') return false;
        }
    }
    return true;
}


int ndigits(int x) {
    return floor(log10(x)) + 1;
}

// returns true if x, y, and z don't overlap on digits, don't contain zero, 
// and the length of all of them is equal to 9
bool true_pandigital(int x, int y, int z) {
    if (potential_pandigital(x, y) && 
        potential_pandigital(x, z) && 
        potential_pandigital(y, z)) {
            if (ndigits(x) + ndigits(y) + ndigits(z) == 9) {
                return true;
            }
        }
    return false;
}

//returns true if list contains x
bool contains(list<int> list, int x) {
    for (int l: list) { if (l == x) { return true; } }
    return false;
}

int main() {
    int sum = 0;
    list<int> products;
    for (int x = 2; x < 10000; x++) {
        for (int y = x; y < 10000; y++) {
            if (potential_pandigital(x, y)){
                int product = x * y;
                if (true_pandigital(x, y, product) && !contains(products, product)) {
                    cout << x << " * " << y << " = " << product << endl;
                    products.push_back(product);
                    sum += product;
                }
            }

        }
    }

    cout << sum << endl;
}
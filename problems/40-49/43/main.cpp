#include <iostream>
#include <list>
using namespace std;

/*
The number, 1406357289 , is a 0 to 9 pandigital number because it is made up of 
each of the digits 0 to 9 in some order, but it also has a rather interesting 
sub-string divisibility property.  Let d 1 be the 1 st digit, d 2 be the 2 nd 
digit, and so on. In this way, we note the following: 

d2 d3 d4 = 406 is divisible by 2
d3 d4 d5 = 063 is divisible by 3
d4 d5 d6 = 635 is divisible by 5
d5 d6 d7 = 357 is divisible by 7
d6 d7 d8 = 572 is divisible by 11
d7 d8 d9 = 728 is divisible by 13
d8 d9 d10 = 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
*/

// from a pandigital string, index to add, and a digit to add, adds the digit at the index
// and returns a new string
string getnextpandigital(string pandigital, int idx, int digit_to_add) {
    char next_pandigital_char[10];
    std::size_t length = pandigital.copy(next_pandigital_char, pandigital.size(), 0);
    next_pandigital_char[length] = '\0';
    string next_pandigital = (string) next_pandigital_char;
    next_pandigital.insert(idx, to_string(digit_to_add));
    return next_pandigital;
}


// given a list of pandigitals, creates a new list of all potential pandigitals
// with new digit _size_. Uses the initial list to build out the new list.
list<string> add_all_digit_permutations(list<string> pandigitals, int size){
    list<string> next_pandigitals;
    for (string pandigital: pandigitals) {
        for (int idx = 0; idx <= pandigital.size(); ++idx) {
            // cout << idx << ", " << pandigital.size() << endl;
            string next_pandigital = getnextpandigital(pandigital, idx, size);
            next_pandigitals.push_back(next_pandigital);
            // cout << next_pandigital << endl;
        }
    }
    return next_pandigitals;
}


// checks if the given pandigital satisfies the required property (see above)
bool valid_pandigital (string pandigital, list<int> primes) {
    int counter = 1;
    for (int prime: primes) { 
        string substring = pandigital.substr(counter, 3);
        int pandigital_int = stoi(substring);
        // cout << counter << " - " << substring << " - " << pandigital_int << endl;
        if ((pandigital_int % prime) != 0) {
            return false;
        }
        counter++;
    }
    return true;
}


int main() {
    unsigned long sum = 0; 
    list<int> primes = {2, 3, 5, 7, 11, 13, 17};
    list<string> pandigitals = {"0"};
    int size = 1;

    cout << "building all pandigitals" << endl;

    while (size < 10) {
        list<string> next_pandigitals = add_all_digit_permutations(pandigitals, size);
        pandigitals = next_pandigitals;
        size++;
    }

    cout << "checking pandigitals" << endl;

    for (string pandigital: pandigitals) {
        // cout << "---------" << pandigital << "---------" << endl;
        if (valid_pandigital(pandigital, primes))  {
            unsigned long panditial_long = stoul(pandigital);
            sum += panditial_long;
        }
    }
    cout << "sum of all valid pandigitals: " << sum << endl; // 16695334890
}


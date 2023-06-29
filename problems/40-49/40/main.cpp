#include <iostream> 
#include <string>
using namespace std;

/*
An irrational decimal fraction is created by concatenating the positive 
integers: 0.12345678910 1 112131415161718192021 ⋯

It can be seen that the 12 th digit of the fractional part is 1 .

If d n represents the n th digit of the fractional part, find the value of the 
following expression.  
d 1 × d 10 × d 100 × d 1000 × d 10000 × d 100000 × d 1000000
*/


// int ndigits (int x) {
//     return floor(log10(x)) + 1;
// }

// int main () {
//     int number = 0;
//     int digit_counter = 0;
//     int next_power = 0;
//     while (true) {
//         number += 1;
//         digit_counter += ndigits(number);

//         if (digit_counter >= pow(10, next_power)) {
//             // extract digit;
//             next_power += 1;
//         }
//     }
// }


int char_to_int(char x) {
    return (int) x - '0';
}

// lazy way, not great on space. 
int main () {
    string return_string = "";
    int number = 1;
    while (return_string.size() <= 1000000) {
        return_string.append(to_string(number));
        number += 1;
    }

    cout << return_string[0] << endl;
    cout << return_string[9] << endl;
    cout << return_string[99] << endl;
    cout << return_string[999] << endl;
    cout << return_string[9999] << endl;
    cout << return_string[99999] << endl;
    cout << return_string[999999] << endl;

    // can easily add up the results.
    int out = char_to_int(return_string[0]) * 
                char_to_int(return_string[9]) * 
                char_to_int(return_string[99]) * 
                char_to_int(return_string[999]) * 
                char_to_int(return_string[9999]) * 
                char_to_int(return_string[99999]) * 
                char_to_int(return_string[999999]); 
    cout << out << endl;
}
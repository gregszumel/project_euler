#include <iostream> 
#include <string>
using namespace std;


/* The fraction 49 / 98 is a curious fraction, as an inexperienced mathematician
in attempting to simplify it may incorrectly believe that 49 / 98 = 4 / 8 , 
which is correct, is obtained by cancelling the 9 s.

We shall consider fractions like, 30 / 50 = 3 / 5 , to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than
one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator.
*/

string cut_idx(string uncut_num, int idx) {
    string return_string = "";
    int counter = 0;
    for (char digit: uncut_num) {
        if (counter != idx) return_string += digit;
        counter++;
    }
    return return_string;
}

int main() {
    for (int numerator = 10; numerator < 100; numerator++) {
        for (int denominator = 10; denominator < 100; denominator++) {
            if (numerator == denominator) {continue;}
            string numerator_string = to_string(numerator);
            string denominator_string = to_string(denominator);
            for (char digit: numerator_string) {
                int n_digit_idx = numerator_string.find(digit);
                int d_digit_idx = denominator_string.find(digit);
                if (d_digit_idx > 0) {
                    if (digit == '0' && 
                        n_digit_idx == d_digit_idx && 
                        d_digit_idx == 1)  continue;

                    string n_cut = cut_idx(numerator_string, n_digit_idx);
                    string d_cut = cut_idx(denominator_string, d_digit_idx);
                    // cout << numerator << ", " << denominator << "|||";
                    // cout << n_cut << ", " << d_cut << endl;

                    double n_cut_f = stod(n_cut);
                    double d_cut_f = stod(d_cut);
                    double n_f = numerator;
                    double d_f = denominator;

                    if (n_cut_f / d_cut_f == n_f / d_f) cout << numerator << ", " << denominator << endl;
                }
            }
        }
    }
    // We get 
                // 64, 16 => 16/64 = 1/4
                // 65, 26 => 26/65 = 2/5
                // 95, 19 => 19/95 = 1/5
                // 98, 49 => 49/98 = 4/8
    // 1/4 * 2/5 * 1/5 * 1/2
    // 2/20 * 1/10
    // 2/200
    // 1/100
}
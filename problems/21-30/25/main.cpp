#include <iostream>
#include <list>
using namespace std;


class bigNum {
    public:
        list<int> number;
    

    bigNum add_to(bigNum x) {
        // leverages code from problem 13;
        bigNum newbignum;
        list<int> result;  // for storing the results
        int carry = 0; // for storing the carry digit
        std::list<int>::iterator it1 = number.end(); // iterators for the lists
        std::list<int>::iterator it2 = x.number.end();

        // iterate through each list at the same time, until one hits the end
        for(; it1 != number.begin() && it2 != x.number.begin();) {
            it1--; it2--;
            // add the two digits and the carry
            int intermediate_result = *it1 + *it2 + carry;
            // set the new carry to be the digit about 10
            carry = int(intermediate_result / 10);
            // the digit is the result of modding by 10
            int digit_result = intermediate_result % 10;
            // push the digit to the back of the list
            result.push_front(digit_result);
        }

        // if we haven't finish a list, then keep iterating through the list
        if(it1 != number.begin()){
            for(; it1 != number.begin();) {
                it1--;
                int intermediate_result = *it1 + carry;
                // cout << *it1 << " + " << carry << " = " << intermediate_result; 
                // cout << endl;
                carry = int(intermediate_result / 10);
                int digit_result = intermediate_result % 10;
                result.push_front(digit_result);
            }
        } 
        // since the first for loop iterates through at least one list entirely, 
        // we can only have num1 or num2 not completely empty, not both.
        else if (it2 != x.number.begin()) {
            for(; it2 != x.number.begin();) {
                it2--;
                int intermediate_result = *it2 + carry;
                // cout << *it2 << " + " << carry << " = " << intermediate_result; 
                // cout << endl;
                carry = int(intermediate_result / 10);
                int digit_result = intermediate_result % 10;
                result.push_front(digit_result);
            }
        }

        if (carry > 0) result.push_front(carry);

        newbignum.number = result;
        return newbignum;
    }


    // Takes a big number and adds it to itself x times. 
    // only for positive multiples and zero. 
    bigNum multiply_by(int x) {
        bigNum resultBigNum;
        list<int> result = {0};
        resultBigNum.number = result;

        if (x == 0) {
            return resultBigNum;
        }
        else if (x < 0) logic_error("not implemented");

        for (int i = 0; i < x; i++){
            resultBigNum = add_to(resultBigNum);
            // resultBigNum.print();
        } 

        return resultBigNum;
    }

    void print() {
        for (int digit: number) cout << digit;
    }


    int add_digits() {
        // adds the digits of the bigNum
        int result = 0;
        for (int digit: number) {
            result = result + digit;
        }
        return result;
    }

    int size() {
        return number.size();
    }

    list<int> copy_number() {
        list<int> copied_number;
        for (int digit: number) {
            copied_number.push_back(digit);
        }
        return copied_number;
    }

    bigNum copy() {
        bigNum copiedBigNum;
        copiedBigNum.number = copy_number();
        return copiedBigNum;
    }
};




int main() {
    int counter = 2;
    bigNum fib1, fib2, nextfib;
    fib1.number = {1}; fib2.number = {1};
    cout << "1: " << 1 << endl << "2: " << 1 << endl;
    while (fib2.size() < 1000) {
        counter++;
        nextfib = fib2.add_to(fib1);
        fib1 = fib2;
        fib2 = nextfib;
        cout << counter << ": " << nextfib.size() <<  endl;
    }
}
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
The number 3797 has an interesting property. Being prime itself, it is possible 
to continuously remove digits from left to right, and remain prime at each 
stage: 3797 , 797 , 97 , and 7 . 

Similarly we can work from right to left: 
3797 , 379 , 37 , and 3 .

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2 , 3 , 5 , and 7 are not considered to be truncatable primes.
*/

bool isprimediscovery(int n, int primearray[], int size) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i < size; i++) {
        int p = primearray[i];
        if (p != 1) continue;
        else if (n % i == 0) return false;
        else if (sqrt(n) < i)  return true;
    }
    return false;
}

bool isprimeconfirm(int n, int primearray[], int size) {
    // cout << "checking " << n << endl;
    return primearray[n] == 1;
}

bool isrltrunc(int n, int primearray[], int size) {
    // cout << "isrltrunc start with " << n << endl;
    if (isprimeconfirm(n, primearray, size)) {
        // cout << "prime " << endl;
        string n_str = to_string(n);
        // cout << n_str << endl;
        if (n_str.size() > 1) {
            string substring = n_str.substr(0, n_str.size()-1);
            // cout << "substring: " << substring << endl;
            int x = stoi(substring);
            // cout << "substring int: " << x << endl;
            return isrltrunc(x, primearray, size);
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool islrtrunc(int n, int primearray[], int size) {
    // cout << "islrtrunc start with " << n << endl;
    if (isprimeconfirm(n, primearray, size)) {
        // cout << "prime " << endl;
        string n_str = to_string(n);
        // cout << n_str << endl;
        if (n_str.size() > 1) {
            string substring = n_str.substr(1, n_str.size()-1);
            // cout << "substring: " << substring << endl;
            int x = stoi(substring);
            // cout << "substring int: " << x << endl;
            return islrtrunc(x, primearray, size);
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool istrunc(int n, int primearray[], int size) {
    return islrtrunc(n, primearray, size) && isrltrunc(n, primearray, size);
}


int main() {
    int sum = 0;
    int size = 1000000;
    int primes[size];
    for (int i = 0; i < size; i++) primes[i] = 0;
    primes[2] = 1; primes[3] = 1; primes[5] = 1; primes[7] = 1;

    for (int i = 11; i < size; i++) {
        if(isprimediscovery(i, primes, size)){
            cout << i << endl;
            primes[i] = 1;
        }
    }
    cout << "through first loop" << endl;

    for (int i = 11; i < size; i++) {
        // cout << i << endl;
        if (istrunc(i, primes, size)) {cout << i << endl; sum+=i;};
    }
    cout << "sum : " << sum << endl;
}
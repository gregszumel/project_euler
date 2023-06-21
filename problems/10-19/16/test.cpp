#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int running_sum=0;
    double x = 2;
    for (int i=1; i< 1000; i++) {
        x = 2 * x;
        // cout << i << ": " << x << endl;
    }

    string s = to_string(x);
    // cout << s << endl;

    for (int i = 0; i < s.length(); i++){
        int num = int(s[i]) - '0';
        if (num >= 0 && num < 10) {
            running_sum = running_sum + num;
        }
    }
    cout << running_sum << endl;  // 1366
}

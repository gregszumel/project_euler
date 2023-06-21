#include <iostream>
using namespace std;

/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/


int main() {
    int coin;
    int ncoins = 9;
    int ntargets = 200;
    int coins[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
    int targets[9][201];

    // init matrix
    for (int i = 0; i < ncoins; i++) {
        for (int j = 0; j < 201; j++){
            targets[i][j] = 0;
        }
    }

    for (int i = 0; i < ncoins; i++) {
        coin = coins[i];

        // handle top row case
        if (i == 0) {
            targets[0][0] = 1;
            continue;
        }

        for (int target_idx = 0; target_idx < ntargets+1; target_idx++) {
            if (target_idx == 0) { targets[i][target_idx] = 1; }
            else if (target_idx - coin < 0) {
                targets[i][target_idx] = targets[i-1][target_idx];
            } else {
                targets[i][target_idx] = targets[i-1][target_idx] + targets[i][target_idx-coin];
            }
        }
    }

    cout << targets[8][200] << endl;
}
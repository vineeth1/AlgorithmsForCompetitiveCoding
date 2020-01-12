#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    bool flag = (n < 0);

    vector<bool> binary(32, false);

    if (flag) {
        n++;
    }

    for (int i = 31; i >= 0; i--) {
        binary[i] = n % 2;
        n /= 2;
    }

    for (int i = 0; i < 32; i++) {
        if (flag) {
            binary[i] = ~binary[i];
        }
    }

    // Now binary holds the binary representation
}

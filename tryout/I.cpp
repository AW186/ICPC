#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdint.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n;
    cin >> n;
    string s;
    cin >> s;
    int carry = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (((count + carry) & 1) != (s[i] - '0')) {
            cout << 1;
            count++;
        } else {
            cout << 0;
        }
        carry += count;
        carry /= 2;
    }
    cout << endl;
    return 0;
}

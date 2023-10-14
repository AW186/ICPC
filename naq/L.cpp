#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n, low, high;
    cin >> n;
    cin >> low;
    cin >> high;
    bool hitmax = false;
    bool hitmin = false;
    for (int i = 0; i < n-1; i++) {
        int val;
        cin >> val;
        hitmin |= low == val;
        hitmax |= high == val;
        if (val > high) {
            cout << -1 << endl;
            return 0;
        }
        if (val < low) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (!(hitmax || hitmin)) {
        cout << -1 << endl;
    } else if (!hitmax) {
        cout << high << endl; 
    } else if (!hitmin) {
        cout << low << endl;
    } else {
        for (int i = low; i <= high; i++) {
            cout << i << endl;
        }
    }

}

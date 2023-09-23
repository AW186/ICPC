
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int solve() {
    int n;
    cin >> n;
    set<int> used;
    multiset<int> unused;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val >= 1 && val <= n && !used.count(val)) {
            used.insert(val);
        } else {
            unused.insert(val);
        }
    }
    auto uit = used.begin();
    auto nit = unused.begin();  
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (uit != used.end() && (*uit) == i) {
            uit++;
        } else if (((*nit) - 1) / 2 >= i) {
            res++;
            nit++;
        } else {
            return -1;
        }
    }
    return res;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cout << solve() << endl;
    }
}

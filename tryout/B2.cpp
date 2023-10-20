#include <cstdint>
#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <unordered_map>
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
    set<uint32_t> s;
    unordered_map<uint64_t, int> gears;
    vector<uint64_t> axles(n);
    uint64_t closest = 10000000000000000;
    uint64_t start = 0;
    cin >> axles[0];
    for (int i = 1; i < n; i++) {
        cin >> axles[i];
        if (axles[i] - axles[i-1] < closest) {
            closest = axles[i] - axles[i-1];
            start = i;
        }
    }
    int g;
    if (n == 1) {
        cin >> g;
        cout << g << endl;;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> g;
        gears[g]++;
        s.insert(g);
    }
    vector<uint64_t> res(n);
    for (auto it = s.begin(); it != s.end(); it++) {
        auto mgears = gears;
        int need = axles[start] - axles[start-1] - (*it);
        bool succeed = true;
        res[start] = *it;
        mgears[*it]--;
        for (int k = start - 1; k >= 0; k--) {
            if (!mgears[need]) {
                succeed = false;
                break;
            }
            res[k] = need;
            if (k == 0) break;
            mgears[need]--;
            need = axles[k] - axles[k - 1] - need;
        }
        need = axles[start + 1] - axles[start] - (*it);
        for (int k = start + 1; k < n; k++) {
            if (!mgears[need]) {
                succeed = false;
                break;
            }
            res[k] = need;
            if (k == n - 1) break;
            mgears[need]--;
            need = axles[k + 1] - axles[k] - need;
        }
        if (succeed) {
            for (int k = 0; k < n; k++) {
                cout << res[k] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}







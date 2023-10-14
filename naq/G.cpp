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
    int n, lines;
    cin >> n;
    cin >> lines;
    lines *= 5;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int sum = 0;
    int res = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        sum += p[i];
        if (sum > lines) break;
        res++;
    }
    cout << res << endl;
    
}

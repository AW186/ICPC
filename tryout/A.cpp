#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

void testcase() {
    string s;
    cin >> s;
    int size = s.size();
    vector<int> count(26);
    for (int i = 0; i < size; i++) {
        count[s[i] - 'a']++;
    }
    int unchange = 0;
    for (int i = 0; i < 26; i++) {
        unchange = max(unchange, count[i]);
    }
    cout << (size - unchange) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        testcase();
    }
    return 0;
}

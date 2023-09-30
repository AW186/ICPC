
#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

struct fraction {
    int upper;
    float lower;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    auto cmp = [](const fraction & f1, const fraction & f2) {
        return ((float)f1.upper / (float)f1.lower) < ((float)f2.upper / (float)f2.lower);
    };
    priority_queue<fraction, vector<fraction>, decltype(cmp)> pq(cmp);
    vector<int> foods(101);
    int people, food;
    cin >> people;
    cin >> food;
    int foodid;
    for (int i = 0; i < food; i++) {
        cin >> foodid;
        foods[foodid]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (foods[i]) pq.push(fraction{ foods[i], 0.5 });
    }
    int res = 0;
    for (int i = 0; i < people; i++) {
        auto node = pq.top();
        pq.pop();
        node.lower = (int)node.lower + 1;
        if (i == people-1) {
            res = node.upper / node.lower;
        }
        pq.push(node);
    }
    cout << res << endl;
}

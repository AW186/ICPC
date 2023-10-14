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

struct state {
    uint64_t bitmap[32];
};

#define SET(state, i) (state.bitmap[i / 64] |= (1 << (i % 64)))

int dfs(state const & node, deque<int> & circle, map<state, int> & dp, vector<int> const & src, vector<int> const & dst) {
    if (circle.empty()) return 0;
    if (dp[node]) return dp[node];
    int size = circle.size();
    int res = 5000000;
    for (int i = 0; i < size; i++) {
        int val = circle.front();
        circle.pop_front();
        state newNode = node;
        SET(newNode, val);
        res = min(res, dfs(newNode, circle, dp, src, dst));
    }
}

void bestCircle(deque<int> & circle, vector<int> const & src, vector<int> const & dst) {
    map<state, int> dp;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n;
    cin >> n;
    vector<int> p1(n + 1);
    vector<int> dst(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p1[i];
    }
    int val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        dst[val] = i;
    }
    vector<bool> visit(n + 1);
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        deque<int> circle;
        for (int k = i; !visit[k]; k = dst[p1[k]]) {
            deque.push_back(k);
        }
    }
}

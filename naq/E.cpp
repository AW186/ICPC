#include <cstdint>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdint.h>

using namespace std;


struct Node {
    int low;
    int high;
};

int dfs(uint64_t node, unordered_map<uint64_t, int> & visit, vector<Node> const & people, int depth) {
    if (visit[node]) return visit[node];
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<Node> people(n+1);
    unordered_map<uint64_t, int> visit;
    for(int i = 1; i <= n; i++) {
        cin >> people[i].low;
        cin >> people[i].high;
    }
    int teams = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (people[i].high >= i + 2 && people[i+2].low <= i) {
            teams++;
            i += 2;
        }
    }
    cout << teams << endl;
    
    //Code here
}











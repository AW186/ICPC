#include <functional>
#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int weight;
    bool covered;
};

vector<Edge> guf;

int find(int i) {
    cout << "find " << i << endl;
    if (guf[i].to == i) return i;
    return find(guf[i].to);
}

bool combine(int i, int j, int weight) {
    cout << "combine " << i << " " << j << endl;
    i = find(i);
    j = find(j);
    if (i == j) return false;
    if (i < j) {
        guf[i].to = j;
        guf[i].weight = weight;
    } else {
        guf[j].to = i;
        guf[j].weight = weight;
    }
    cout << "combine succeed" << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n, m;
    cin >> n;
    cin >> m;
    guf = vector<Edge>(n + 1);
    for (int i = 0; i <= n; i++) {
        guf[i].to = i;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < m; i++) {
        vector<int> v(3);
        cin >> v[1];
        cin >> v[2];
        cin >> v[0];
        pq.push(v);
    }
    int total = 0;
    int replace = 0;
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        if (combine(v[1], v[2], v[0])) {
            total += v[0];
        } else {
            int i = v[1];
            int j = v[2];
            int r = 0;
            while (i != j) {
                cout << "i " << i << " j " << j << endl;
                if (i > j) {
                    r = guf[j].covered ? r : max(r, v[0] - guf[j].weight);
                    j = guf[j].to;
                    guf[j].covered = true;
                } else {
                    r = guf[i].covered ? r : max(r, v[0] - guf[i].weight);
                    i = guf[i].to;
                    guf[i].covered = true;
                }
            }
            replace = max(r, replace);
        }
    }
    cout << (total + replace) << endl;
}










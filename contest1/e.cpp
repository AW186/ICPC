#include <set>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Node {
    int one;
    int two;
    bool hasTwo;
};

Node dfs(int node, vector<vector<int>> const & g, vector<int> const & pages) {
    if (g[node].empty()) {
        return Node { pages[node], 0, false };
    }
#define ADJ g[node]
#define MAX 100000000
    int min1 = MAX;
    int min2 = MAX;
    int two = MAX;
    bool hasTwo = ADJ.size() > 1;
    for (int i = 0; i < ADJ.size(); i++) {
        Node newNode = dfs(ADJ[i], g, pages);
        if (newNode.one < min1) {
            min2 = min1;
            min1 = newNode.one;
        } else {
            min2 = min(min2, newNode.one);
        }
        if (newNode.hasTwo) {
            hasTwo = true;
            two = min(two, newNode.two);
        }
    }
    if (ADJ.size() > 1) {
        int newTwo = min1 + min2;
        two = min(newTwo, two);
    }
    return Node {
        min1 + pages[node],
        two + pages[node],
        hasTwo
    };
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> pages(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    set<int> dependent;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        dependent.insert(b);
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dependent.count(i)) {
            g[0].push_back(i);
        }
    }
    Node res = dfs(0, g, pages);
    cout << res.two << endl;
    return 0;
}











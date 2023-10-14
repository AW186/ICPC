#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

struct Node {
    int rank;
    int tid;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int total, advc, lim;
    cin >> total;
    cin >> advc;
    cin >> lim;
    map<int, int> count;
    deque<Node> wlist;
    int tid, sid;
    auto cmp = [](const Node & n1, const Node & n2) {
        return n1.rank < n2.rank;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    int rank = total;
    for(int i = 0; i < total; i++) {
        cin >> tid;
        cin >> sid;
        if (++count[sid] > lim) {
            wlist.push_back( Node { rank--, tid} );
        } else {
            pq.push( Node { rank--, tid });
            if (--advc == 0) break;
        }
    }
    while(advc-- > 0 && !wlist.empty()) {
        pq.push(wlist.front());
        wlist.pop_front();
    }
    while(!pq.empty()) {
        cout << pq.top().tid << '\n';
        pq.pop();
    }
    return 0;
}

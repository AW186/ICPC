

#include <deque>
#include <iostream>
#include <unordered_map>

using namespace std;


int main(int argc, char* argv[]) {
    int a, b;
    cin >> a;
    cin >> b;
    //bfs
    deque<int> q;
    unordered_map<int, int> visit;
    q.push_back(a);
    while (!q.empty()) {
        int node = q.front();
        q.pop_front();
        int new1 = node * 2;
        int new2 = node * 10 + 1;
        if (new1 <= b && !visit.count(new1)) {
            q.push_back(new1);
            visit[new1] = node;
        }
        if (new2 <= b && !visit.count(new2)) {
            q.push_back(new2);
            visit[new2] = node;
        }
        if (new1 == b || new2 == b) break;
    }
    if (visit.count(b)) {
        cout << "YES" << endl;
        deque<int> path;
        path.push_front(b);
        for (int i = b; i != a; i = visit[i]) {
            path.push_front(visit[i]);
        }
        cout << path.size() << endl;
        while (!path.empty()) {
            cout << path.front() << " ";
            path.pop_front();
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;

}

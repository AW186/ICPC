
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    deque<int> path;
    path.push_front(b);
    while (b > a) {
        if (b % 2) {
            if (b % 10 != 1) {
                break;
            }
            b /= 10;
        } else {
            b /= 2;
        }
        path.push_front(b);
    }
    if (b == a) {
        cout << "YES" << endl;
        cout << (path.size()) << endl;
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




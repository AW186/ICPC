#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


class SegTree {
public:
    SegTree *l = NULL;
    SegTree *r = NULL;
    int n = 0;
    int covers = 0;
    SegTree(int n) {
        this->n = n;
    }
    bool add(int start, int end) {
        //cout << n << " " << start << " " << end << endl;
        if (end == n && start == 0) {
            bool res = covers == n;
            covers = n;
            return res;
        }
        int mid = n / 2;
        int res = true;
        int sum = 0;
        if (start < mid) {
            if (!this->l) this->l = new SegTree(mid);
            res &= this->l->add(start, min(mid, end));
        }
        if (end > mid) {
            if (!this->r) this->r = new SegTree(n - mid);
            res &= this->r->add(max(start, mid) - mid, end-mid);
        }
        sum += this->l ? l->covers : 0;
        sum += this->r ? r->covers : 0;
        this->covers = sum;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int n;
    cin >> n;
    SegTree *t = new SegTree(15);
    int l, r;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> l;
        cin >> r;
        if (t->add(l, r+1)) {
            cout << "added" << endl;
            auto start = s.upper_bound(l);
            auto end = s.lower_bound(r);
            if (start != end) {
                s.erase(start, end);
            }
            s.insert(l);
            s.insert(r);
        }
    }
    cout << t->covers << endl;

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << (*it) << " ";
        it++;
        cout << (*it) << endl;
    }
}







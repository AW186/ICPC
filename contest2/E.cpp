
#include <math.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class SegTree {
    int n;
    int count = 0;
    int leafLife = 0;
    SegTree *left = NULL;
    SegTree *right = NULL;
public:
    SegTree(int n) {
        this->n = n;
    }
    bool add(int a) {
        if (n == 1) {
            bool res = !(leafLife++);
            this->count += res;
            return res;
        }
        if (a < n / 2) {
            if (!this->left) {
                this->left = new SegTree(n / 2);
            }
            bool res = this->left->add(a);
            this->count += res;
            return res;
        } else {
            if (!this->right) {
                this->right = new SegTree(n - (n / 2));
            }
            bool res = this->right->add(a - n / 2);
            this->count += res;
            return res;
        }
    }
    bool remove(int a) {
        if (n == 1) {
            bool res = !(--leafLife);
            this->count -= res;
            return res;
        }
        if (a < n / 2) {
            bool res = this->left->remove(a);
            this->count -= res;
            return res;
        } else {
            bool res = this->right->remove(a - n / 2);
            this->count -= res;
            return res;
        }
    }
    bool attacked(int a, int b) {
        if (a == 0 && b == n - 1) {
            return n == count;
        }
        if (a < n / 2 && (!this->left || !this->left->attacked(a, min(b, n / 2 - 1)))) {
            return false;
        }
        if (b >= n / 2 && (!this->right || !this->right->attacked(max(a, n / 2) - n / 2, b - n / 2))) {
            return false;
        }
        return true;
    }
};
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;
    SegTree *x = new SegTree(n + 1);
    SegTree *y = new SegTree(n + 1);
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int a, b, c, d;
        cin >> a;
        cin >> b;
        switch(q) {
            case 1:
                x->add(a);
                y->add(b);
                break;
            case 2:
                x->remove(a);
                y->remove(b);
                break;
            case 3:
                cin >> c;
                cin >> d;
                bool attacked = x->attacked(a, c);
                attacked |= y->attacked(b, d);
                if (attacked) cout << "Yes" << endl;
                else cout << "No" << endl;
                break;
        }
    }
    return 0;
}

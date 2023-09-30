#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    int q;

    cin >> n;
    cin >> q;

    vector<int> xa;
    vector<int> ya;

    xa.resize(n + 1);
    ya.resize(n + 1);

    int qi;
    for(qi = 0; qi < q; ++qi){
        int cmd;
        cin >> cmd;
        int x1;
        int y1;
        int x2;
        int y2;
        if(cmd == 1 || cmd == 2){
            cin >> x1;
            cin >> y1;

            if(cmd == 1){
                xa[x1] = xa[x1] + 1;
                ya[y1] = ya[y1] + 1;
            }else{
                xa[x1] = xa[x1] - 1;
                ya[y1] = ya[y1] - 1;
            }
        }

        if(cmd == 3){
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;

            bool any = false;
            for(int x = x1; x <= x2; ++x){
                for(int y = y1; y <= y2; ++y){
                    if(ya[y] == 0 && xa[x] == 0){
                        any = true;
                        break;
                    }
                }
            }
            if(any){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }
    }

}
#include <deque>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main(){
    int a, b;

    cin >> a;
    cin >> b;

    int curr = b;

    vector<int> path;
    path.push_back(curr);

    while(curr > a){
        if(curr % 2 == 0){
            curr = curr / 2;
        }else{
            if((curr-1)%10 != 0){
                cout << "NO";
                return 0;
            }
            curr = (curr - 1)/10;
        }
        path.push_back(curr);
    }

    if(curr == a){
        cout << "YES\n";
        cout << path.size() << "\n";
        for(int i = (int)path.size() - 1; i >= 0; --i){
            cout << path[i] << " ";
        }
        return 0;
    }else{
        cout << "NO";
        return 0;
    }
}
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int can(vector<int> &arr){

    int n = (int)arr.size();

    int op = 0;

    vector<bool> matched;
    matched.resize(n + 1);
    vector<int> canUse;

    for(int i: arr){
        if(i <= n && !matched[i]){
            matched[i] = true;
        }else{
            canUse.push_back(i);
        }
    }


    sort(canUse.begin(), canUse.end());

    int canUsePtr = 0;

    for(int i = 1; i <=n; ++i){
        if(!matched[i]){
            if(canUsePtr >= (int)canUse.size()){
                return -1;
            }
            int candidate = canUse[canUsePtr];
            if(candidate % 2 == 0){
                candidate = (candidate / 2) - 1;
            }else{
                candidate = (candidate / 2);
            }
            if(candidate < i){
                return -1;
            }
            ++canUsePtr;
            ++op;
        }
    }

    return op;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int num;
        vector<int> data;

        cin >> num;
        data.reserve(num);

        int garbage;

        for(int j = 0; j < num; ++j){
            cin >> garbage;
            data.push_back(garbage);
        }

        cout << can(data) << "\n";
    }
}
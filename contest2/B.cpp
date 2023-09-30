//
// Created by jiahua.liu on 2023/9/29.
//

#include <iostream>
#include <deque>
#include <vector>
#include "algorithm"

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> remains;
    remains.resize(101);

    int gb;
    for(int i = 0; i < m; ++i){
        cin >> gb;
        remains[gb] = remains[gb] + 1;
    }

    std::sort(remains.begin(), remains.end());
    int r = 100;
    int l = 100 - n + 1;
    while(l < r){
        if(remains[l] + remains[l + 1] > remains[r]){
            break;
        }
        remains[r] = remains[r] - remains[l];
        l = l + 1;
        std::sort(remains.begin(), remains.end());
    }
    cout << remains[l] ;
}
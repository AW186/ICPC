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

    int day = remains[100];
    for(; day >= 1; --day){
        int fullfill = 0;
        for(int remain: remains){
            fullfill += remain / day;
        }
        if(fullfill >= n){
            cout << day;
            exit(0);
        }
    }
    cout << 0;
}

//
// Created by jiahua.liu on 2023/9/22.
//
#include <set>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;




typedef struct {
    int value;
    Candidate c;
} Candidate;

int main(){
    queue<Candidate> queue;

    int a, b;
    cin >> a;
    cin >> b;

    queue.push({a, -1});

    while(!queue.empty()){
        bool any = false;
        size_t sizeHolder = queue.size();
        Candidate target;
        for(size_t i = 0; i < sizeHolder; ++i){
            target = queue.front();

            if(target.value == b){

                return 0;
            }
            if(target.value < b){
                any = true;
            }

            queue.push(Candidate{target.value * 2, 1});
            queue.push(Candidate{target.value * 10 + 1, 2});

            queue.pop();
        }
        if(!any){
            cout << "NO";
        }
    }

    cout << "NO";
}
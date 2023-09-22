
#include <vector>
#include <set>
#include <unordered_map>
#include "iostream"


using namespace std;

int dfs(int curr, set<int> &learned, vector<int> const & weight, unordered_map<int, int> & edges){
    if(learned.find(curr) != learned.end()){
        return 0;
    }
    learned.insert(curr);
    if(edges.find(curr) == edges.end()){
        return weight[curr];
    }
    int depends;
    depends = edges[curr];
    return weight[curr] + dfs(depends, learned, weight, edges);
}


int main(){
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> weight(n + 1);
    unordered_map<int, int> edge;

    int tmp1, tmp2;

    set<int> finalClassSet;

    for(int i = 0; i < n; ++i){
        cin >> tmp1;
        weight[i + 1] = tmp1;
        finalClassSet.insert(i + 1);
    }

    for(int i = 0; i < m; ++i){
        cin >> tmp1;
        cin >> tmp2;
        edge[tmp2] = tmp1;
        finalClassSet.erase(tmp1);
    }

    vector<int> finalClass;
    finalClass.reserve(finalClassSet.size());
    for (const int element : finalClassSet) {
        finalClass.push_back(element);
    }

    int min = 100000000;

    int firstChosen, secondChosen;

    for(int firstChosenI = 0; firstChosenI < finalClass.size() - 1; ++firstChosenI){
        for(int secondChosenI = firstChosenI + 1; secondChosenI < finalClass.size(); ++secondChosenI){
            firstChosen = finalClass[firstChosenI];
            secondChosen = finalClass[secondChosenI];

            set<int> learned;
            int result = 0;
            result += dfs(firstChosen, learned, weight, edge);
            result += dfs(secondChosen, learned, weight, edge);
            if(result < min){
                min = result;
            }
        }
    }

    cout << min;
}

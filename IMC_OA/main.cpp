#include <bits/stdc++.h>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getResult' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arrival
 *  2. INTEGER_ARRAY direction
 */

struct Hiker {
    int id;
    int arrival;
    int direction;
};

vector<int> getResult(vector<int> arrival, vector<int> direction) {
    auto cmp = [](Hiker const & h1, Hiker const & h2) {
        return h1.arrival > h2.arrival;
    };
    priority_queue<Hiker, vector<Hiker>, decltype(cmp)> pq(cmp);
    int size = arrival.size();
    for (int i = 0; i < size; i++) {
        pq.push(Hiker { i, arrival[i], direction[i] });
    }
    vector<int> res(size);
    #define ASCD 0
    #define DSCD 1
    deque<Hiker> ascd;
    deque<Hiker> dscd;
    int time = 0;
    int prev = DSCD;
    while (!pq.empty() || !ascd.empty() || !dscd.empty()) {
        while (!pq.empty() && time == pq.top().arrival) {
            if (pq.top().direction) {
                dscd.push_back(pq.top());
            } else {
                ascd.push_back(pq.top());
            }
            pq.pop();
        }
        if (ascd.empty() && dscd.empty()) {
            time = pq.top().arrival;
            prev = DSCD;
            continue;
        }
        if (prev == DSCD) {
            if (dscd.empty()) {
                res[ascd.front().id] = time;
                ascd.pop_front();
                prev = ASCD;
            } else {
                res[dscd.front().id] = time;
                dscd.pop_front();
                prev = DSCD;
            }
        } else {
            if (!ascd.empty()) {
                res[ascd.front().id] = time;
                ascd.pop_front();
                prev = ASCD;
            } else {
                res[dscd.front().id] = time;
                dscd.pop_front();
                prev = DSCD;
            }
        }
        time++;
    }
    return res;
}








int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arrival_count_temp;
    getline(cin, arrival_count_temp);

    int arrival_count = stoi(ltrim(rtrim(arrival_count_temp)));

    vector<int> arrival(arrival_count);

    for (int i = 0; i < arrival_count; i++) {
        string arrival_item_temp;
        getline(cin, arrival_item_temp);

        int arrival_item = stoi(ltrim(rtrim(arrival_item_temp)));

        arrival[i] = arrival_item;
    }

    string direction_count_temp;
    getline(cin, direction_count_temp);

    int direction_count = stoi(ltrim(rtrim(direction_count_temp)));

    vector<int> direction(direction_count);

    for (int i = 0; i < direction_count; i++) {
        string direction_item_temp;
        getline(cin, direction_item_temp);

        int direction_item = stoi(ltrim(rtrim(direction_item_temp)));

        direction[i] = direction_item;
    }

    vector<int> result = getResult(arrival, direction);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


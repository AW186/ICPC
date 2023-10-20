#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int printout(vector<vector<char>> const & output, bool succeed) {
    cout << (succeed ? "Easy" : "Not easy") << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    vector<int> rows(9);
    vector<int> cols(9);
    vector<int> grids(9);
    vector<vector<char>> output(9, vector<char>(9));
#define ROW(i) (i / 9)
#define COL(i) (i % 9)
#define GRIDRC(r, c) ((r / 3) * 3 + c / 3)
#define GRID(i) (GRIDRC(ROW(i), COL(i)))
    int val;
    bool valid = true;
    int empty = 0;
    for (int i = 0; i < 81; i++) {
        cin >> val;
        output[ROW(i)][COL(i)] = val ? (val + '0') : '.';
        empty += !val;
        val = 1 << val;
        if (val != 1 && (rows[ROW(i)] & val ||
                cols[COL(i)] & val ||
                grids[GRID(i)] & val)) {
            valid = false;
        }
        rows[ROW(i)] |= val;
        cols[COL(i)] |= val;
        grids[GRID(i)] |= val;
    }
    if (!valid) return printout(output, false);
    int available[9];
    while (empty--) {
        int nosolution = true;
        for (int i = 0; i < 81; i++) {
            if (output[ROW(i)][COL(i)] != '.') continue;
            //rule 1
            int count = 0;
            int covers = rows[ROW(i)] | cols[COL(i)] | grids[GRID(i)];
            for (int guess = 1; guess <= 9; guess++) {
                if (covers & (1 << guess)) continue;
                available[count++] = guess;
            }
            //rule 2
            int choice = 0;
            if (count == 0) return printout(output, false);
            if (count == 1) choice = available[0];
            else {
                for (int j = 0; j < count; j++) {
                    int guess = available[j];
                    int isunique = true;
                    //unique in row
                    for (int place = 0; place < 9; place++) {
                        if (output[ROW(i)][place] != '.') continue;
                        if ((cols[place] | grids[GRIDRC(ROW(i), place)]) & (1 << guess)) continue;
                        isunique = false;
                        break;
                    }
                    if (isunique) { choice = guess; break; }
                    //unique in col
                    isunique = true;
                    for (int place = 0; place < 9; place++) {
                        if (output[place][COL(i)] != '.') continue;
                        if ((rows[place] | grids[GRIDRC(place, COL(i))]) & (1 << guess)) continue;
                        isunique = false;
                        break;
                    }
                    if (isunique) { choice = guess; break; }
                    //unique in col
                    isunique = true;
                    int gid = GRID(i);
#define G2R (((gid / 3) * 3) + place / 3)
#define G2C (((gid % 3) * 3) + (place % 3))
                    for (int place = 0; place < 9; place++) {
                        if (output[G2R][G2C] != '.') continue;
                        if ((rows[G2R] | cols[G2C]) & (1 << guess)) continue;
                        isunique = false;
                        break;
                    }
                    if (isunique) { choice = guess; break; }
                }
            }
            if (choice == 0) continue;
            output[ROW(i)][COL(i)] = choice + '0';
            choice = 1 << choice;
            rows[ROW(i)] |= choice;
            cols[COL(i)] |= choice;
            grids[GRID(i)] |= choice;
            nosolution = false;
            break;
        }
        if (nosolution) return printout(output, false);
    }
    printout(output, true);
}

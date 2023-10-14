#include <cstdint>
#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


struct Tile {
    uint16_t len;
    char dir;
};

struct Node {
    int x;
    int y;
};

#define E 0
#define S 1
#define W 2
#define N 3

int row;
int col;

int dir[4][2] {
    { 1, 0 },
    { 0, 1 },
    { -1, 0},
    { 0, -1}
};

int dfs(Node node, vector<vector<int>> & dp, vector<vector<Tile>> const & grid) {
    if (node.x == row - 1 && node.y == col - 1) return 0; 
    if (dp[node.x][node.y]) return dp[node.x][node.y];
    dp[node.x][node.y] = -1;
#define GRID(node) (grid[node.x][node.y])
    Node next = Node {
        node.x + GRID(node).len * dir[GRID(node).dir][0],
        node.y + GRID(node).len * dir[GRID(node).dir][1],
    };
    return 1 + dfs(next, dp, grid);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    cin >> row;
    cin >> col;
    vector<vector<Tile>> grid(row, vector<Tile>(col));
    for (int i = 0; i < row * col - 1; i++) {
        cin >> grid[i / col][i % col].len;
        cin >> grid[i / col][i % col].dir;
    }
    vector<vector<int>> dp(row, vector<int>(col));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            dfs(Node { r, c }, dp, grid);
        }
    }
    vector<int> max4col(row, 10000);
    vector<int> max4row(col, 10000);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (dp[r][c] == -1) continue;
            max4col[r] = min(max4col[r], dp[r][c]);
            max4row[c] = min(max4row[c], dp[r][c]);
        }
    }
    int path = 10000;
#define DP(node) (dp[node.x][node.y])
    for (Node n = Node { 0, 0 }; DP(n) > 0; n = Node {
        n.x + GRID(n).len * dir[GRID(n).dir][0],
        n.y + GRID(n).len * dir[GRID(n).dir][1],
    }) {
        
    }
}

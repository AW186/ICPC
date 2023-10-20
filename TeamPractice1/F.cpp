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
    int r;
    int c;
};

struct Optimal {
    int pos;
    uint32_t val;
};

#define E 0
#define S 1
#define W 2
#define N 3

int dirmap[4] = {
    'E',
    'S',
    'W',
    'N'
};

int row;
int col;

int dir[4][2] {
    { 0, 1 },
    { 1, 0 },
    { 0, -1},
    { -1, 0}
};

int dp[100][100];

#define GRID(node) (grid[node.r][node.c])
int dfs(Node node, vector<vector<Tile>> const & grid) {
    //cout << node.r << " " << node.c << endl;
    //cout << "to " << (char)dirmap[GRID(node).dir] << " with " << GRID(node).len << endl;
    if (node.r == row - 1 && node.c == col - 1) return 0; 
    if (dp[node.r][node.c]) return dp[node.r][node.c];
    dp[node.r][node.c] = -1;
    Node next = Node {
        node.r + GRID(node).len * dir[GRID(node).dir][0],
        node.c + GRID(node).len * dir[GRID(node).dir][1],
    };
    int res = dfs(next, grid);
    return dp[node.r][node.c] = (res >= 0 ? res + 1 : -1);
}

bool run(int i) {
    //Code here
    cin >> row;
    cin >> col;
    if (row == 0 || col == 0) return 0;
    char dirin;
    vector<vector<Tile>> grid(row, vector<Tile>(col));
    for (int i = 0; i < row * col - 1; i++) {
        cin >> grid[i / col][i % col].len;
        cin >> dirin;
        switch (dirin) {
            case 'E':
                grid[i / col][i % col].dir = E;
                break;
            case 'N':
                grid[i / col][i % col].dir = N;
                break;
            case 'W':
                grid[i / col][i % col].dir = W;
                break;
            case 'S':
                grid[i / col][i % col].dir = S;
                break;
            default:
                break;
        }
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            dp[r][c] = 0;
        }
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            dfs(Node { r, c }, grid);
        }
    }
    vector<Optimal> max4col(col, Optimal {0, (uint32_t)-1});
    vector<Optimal> max4row(row, Optimal {0, (uint32_t)-1});
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (dp[r][c] == -1) continue;
            if (max4col[c].val > dp[r][c]) max4col[c] = Optimal { r, (uint32_t)dp[r][c] };
            if (max4row[r].val > dp[r][c]) max4row[r] = Optimal { c, (uint32_t)dp[r][c] };
        }
    }
    uint32_t path = (uint32_t)dp[0][0];
#define DP(node) (dp[node.r][node.c])
    Node replace;
    Tile tile;
    int depth = 0;
    for (Node n = Node { 0, 0 }; DP(n) > 0; n = Node {
        n.r + GRID(n).len * dir[GRID(n).dir][0],
        n.c + GRID(n).len * dir[GRID(n).dir][1],
    }) {
        depth++;
        if (path > depth + max4col[n.c].val) {
            path = depth + max4col[n.c].val;
            replace = n;
            int pos = max4col[n.c].pos;
            if (pos - n.r > 0) {
                tile.dir = S;
                tile.len = pos - n.r;
            } else {
                tile.dir = N;
                tile.len = n.r - pos;
            }
        }
        if (path > depth + max4row[n.r].val) {
            path = depth + max4row[n.r].val;
            replace = n;
            int pos = max4col[n.r].pos;
            if (pos - n.c > 0) {
                tile.dir = E;
                tile.len = pos - n.c;
            } else {
                tile.dir = W;
                tile.len = n.c - pos;
            }
        }
    }
    cout << "Case " << i << ": ";
    if (path == (uint32_t)dp[0][0]) {
        if (dp[0][0] < 0) cout << "impossible" << endl;
        else cout << "none " << path << endl;
    } else {
        cout << replace.r << " " << replace.c << " " << tile.len << (char)dirmap[tile.dir] << " " << path << endl;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; run(i); i++) {
    }
}

#include <set>
#include <algorithm>
#include <map>
#include <deque>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Code here
    int rows, cols, passes;
    cin >> rows >> cols >> passes;
    vector<vector<int>> grid(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[j][i];
        }
    }
    vector<vector<vector<int>>> dp(cols, vector<vector<int>>(rows, vector<int>(passes + 1, -1)));
    for (int r = 0; r < rows; r++) {
        dp[0][r][0] = grid[0][r];
    }
#define G(c, r) ((c >= 0 && c < cols && r >= 0 && r < rows) ? grid[c][r] : -1)
#define E(c, r) G((c+1), (r)) 
#define W(c, r) G((c-1), (r)) 
#define N(c, r) G((c), (r-1)) 
#define S(c, r) G((c), (r+1)) 
#define VALID(c, r) (E(c, r) >= 0 && W(c, r) >= 0 && N(c, r) >= 0 && S(c, r) >= 0)
#define PASS(c, r) (VALID(c, r) && E(c, r) < G(c, r) && W(c, r) < G(c, r) && N(c, r) > G(c, r) && S(c, r) > G(c, r))

    for (int c = 1; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            if (grid[c][r] < 0) continue;
            for (int i = max(0, r-1); i <= min(r+1, rows-1); i++) {
                bool isPass = PASS(c, r);
                for (int pass = 0; pass <= passes; pass++) {
                    if (dp[c-1][i][pass] < 0) continue;
                    if (pass + isPass > passes) continue;
                    if (dp[c][r][pass + isPass] < 0) 
                        dp[c][r][pass + isPass] = dp[c-1][i][pass] + grid[c][r];
                    else 
                        dp[c][r][pass + isPass] = min(dp[c][r][pass + isPass], dp[c-1][i][pass] + grid[c][r]);
                }
            }
        }
    }
#ifdef DEBUG
    for (int pass = 0; pass <= passes; pass++) {
        cout << "Pass: " << pass << endl;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << dp[c][r][pass] << " ";
            }
            cout << endl;
        }
    }
#endif
    int res = dp[cols-1][0][passes];
    for (int r = 1; r < rows; r++) {
        if (dp[cols-1][r][passes] < 0) continue;
        res = min(dp[cols-1][r][passes], res);
    }
    if (res < 0) cout << "impossible" << endl;
    else cout << res << endl;

}

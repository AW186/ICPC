#include <bits/stdc++.h>

#define ll short

using namespace std;
//x, y, len, kinks, dir
vector<vector<vector<vector<vector<char>>>>> dp;
ll k;

bool possible(ll x, ll y, ll currX, ll currY, const string &s, ll curr, ll rem, const vector<vector<char>> &arr, ll r, ll c)
{
    if (rem < 0)
    {
        return false;
    }

    if (curr == s.size())
    {
        return rem == 0;
    }
    int dirid = (currX + 1) * 3 + (currY+1);
    if (dp[x][y][curr][rem][dirid]) {
        return dp[x][y][curr][rem][dirid] > 0;
    }
    vector<pair<ll, ll>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}};

    for (const pair<ll, ll> &dir : dirs)
    {
        if (x + dir.first < r && x + dir.first >= 0 &&
            y + dir.second < c && y + dir.second >= 0 &&
            arr[x + dir.first][y + dir.second] == s[curr])
        {
            ll amt = (dir.first == currX && dir.second == currY) ? 0 : -1;

            if (possible(x + dir.first, y + dir.second, dir.first, dir.second,
                         s, curr + 1, rem + amt, arr, r, c))
            {
                dp[x][y][curr][rem][dirid] = 1;
                return true;
            }
        }
    }
    dp[x][y][curr][rem][dirid] = -1;
    return false;
}

void solve()
{
    ll r;
    ll c;
    cin >> r >> c;
    vector<vector<char>> arr(r, vector<char>(c));
    for (vector<char> &v : arr)
    {
        for (char &c : v)
        {
            cin >> c;
        }
    }

    string s;
    cin >> k >> s;
    dp = vector<vector<vector<vector<vector<char>>>>>(r, vector<vector<vector<vector<char>>>>(
                c, vector<vector<vector<char>>>(s.size(), vector<vector<char>>(k + 1, vector<char>(9)))));

    vector<pair<ll, ll>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}};

    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            if (arr[i][j] != s[0])
            {
                continue;
            }

            for (const pair<ll, ll> &dir : dirs)
            {
                if (s.size() == 1 ||
                    (i + dir.first < r && i + dir.first >= 0 &&
                     j + dir.second < c && j + dir.second >= 0 &&
                     arr[i + dir.first][j + dir.second] == s[1]))
                {
                    if (possible(i, j, dir.first, dir.second, s, 1, k, arr, r, c))
                    {
                        cout << "YES";
                        exit(0);
                    }
                }
            }
        }
    }

    cout << "NO";
}

int main()
{
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

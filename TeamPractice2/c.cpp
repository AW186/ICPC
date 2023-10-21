#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;

    map<string, string> adj;
    map<string, ll> vis;
    map<string, ll> comp;
    for (ll i = 0; i < n; i++)
    {
        string a;
        string b;
        cin >> a >> a >> b;

        adj[a] = b;
        comp[a] = -1;
        comp[b] = -1;
    }

    ll sol = 0;
    ll c = 0;
    for (const pair<string, ll> &p : comp)
    {
        if (p.second == -1)
        {
            string curr = p.first;
            string next = adj[curr];

            comp[curr] = c;
            vis[curr] = 0;

            c++;

            while (next != "" && comp[next] == -1)
            {
                comp[next] = comp[curr];
                vis[next] = vis[curr] + 1;

                curr = next;
                next = adj[curr];
            }

            if (next != "" && comp[curr] == comp[next])
            {
                sol = max(sol, abs(vis[next] - vis[curr]) + 1);
            }
        }
    }

    if (sol == 0)
    {
        cout << "No trades possible";
    }
    else
    {
        cout << sol;
    }
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
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll find(const vector<ll> &arr, ll a)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        if (arr[i] == a)
        {
            return i;
        }
    }   

    return -1; 
}

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;

    vector<ll> arr(n, 0);
    iota(arr.begin(), arr.end(), 1);

    vector<pair<ll, ll>> games;
    for (ll i = 0; i < m; i++)
    {
        string a;
        string b;
        cin >> a >> b;

        a = a.substr(1);
        b = b.substr(1);

        games.push_back({stoi(a), stoi(b)});
    }

    for (pair<ll, ll> game : games)
    {
        ll a = find(arr, game.first);
        ll b = find(arr, game.second);
        if (a > b)
        {
            for (ll i = b; i < a; i++)
            {
                arr[i] = arr[i + 1];
            }

            arr[a] = game.second;
        }
    }

    for (ll i : arr)
    {
        cout << "T" << i << " ";
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
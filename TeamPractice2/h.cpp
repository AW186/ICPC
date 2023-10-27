#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve()
{
    ll s;
    ll n;
    cin >> s >> n;

    vector<ll> nt;
    vector<ll> t;
    for (ll i = 0; i < n; i++)
    {
        ll d;
        char tval;
        cin >> d >> tval;

        if (tval == 'y')
        {
            t.push_back(d);
        }
        else
        {
            nt.push_back(d);
        }
    }

    sort(nt.begin(), nt.end());

    vector<ll> days(3 * n, s);

    for (ll i : t)
    {
        days[min(3 * n - 1, i - 1)]--;
    }

    ll del = 0;
    for (ll i = days.size() - 1; i >= 0; i--)
    {
        if (days[i] < s - 1)
        {
            del += s - days[i] - 1;
            days[i] = s - 1;
        }
        else if (del > 0)
        {
            del--;
            days[i]--;
        }
    }

    if (del != 0)
    {
        cout << "no";
        exit(0);
    }

    for (ll i : nt)
    {
        days[min(3 * n - 1, i - 1)]--;
    }

    del = 0;
    for (ll i = days.size() - 1; i >= 0; i--)
    {
        if (days[i] < 0)
        {
            del += abs(days[i]);
        }
        else
        {
            del -= min(del, days[i]);
        }
    }

    if (del == 0)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
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
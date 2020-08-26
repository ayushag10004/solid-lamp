
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x % MOD + MOD) % MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld", &x)

ll mul(ll x, ll y)
{
    ll ans = 1;

    while (y > 0)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        y /= 2;
        x = (x * x) % MOD;
    }

    return ans;
};

/******************************************************************************************************/

int main()
{
    ll t;
    s(t);

    while (t--)
    {
        ll n, m, i, mid, ans = -1;
        s(n), s(m);
        map<ll, ll> mp;

        for (i = 1; i <= n; i++)
        {
            s(mid);
            mp[mid] = 1;
        }

        for (i = 1; i <= m; i++)
        {
            s(mid);
            if (mp.find(mid) != mp.end())
                ans = mid;
        }

        if (ans != -1)
            cout << "YES\n1 " << ans << "\n";
        else
            cout << "NO\n";
    }
    return 0;
}
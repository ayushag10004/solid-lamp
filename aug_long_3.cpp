
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

ll f[500005];
ll ncr(ll n, ll r)
{
    ll mid = M(f[r] * f[n - r]);
    mid = M(f[n] * mul(mid, MOD - 2));
    return mid;
}

int main()
{
    // freopen("input", "r", stdin);
    ll t;
    s(t);

    f[0] = 1;
    for (ll i = 1; i <= 500003; i++)
        f[i] = (f[i - 1] * i) % MOD;

    while (t--)
    {
        ll n, i, j, val;
        s(n);

        ll h[n + 5], dp[n + 5], ans[n + 5];
        memset(h, 0, sizeof h);
        memset(ans, 0, sizeof ans);

        for (i = 1; i <= n; i++)
        {
            s(val);
            ++h[val];
            dp[i] = 1;
        }

        priority_queue<pair<ll, ll> > pq;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= h[i]; j++)
                pq.push(_mp(-j, i));

        pair<ll, ll> pp;
        ll mid = 1, nn, rr,cnt;
        while (!pq.empty())
        {
            pp = pq.top();
            pq.pop();
            mid = M(mid * mul(dp[pp.ss], MOD - 2));
            nn = h[pp.ss];
            rr = abs(pp.ff);
            cnt = ncr(nn, rr);
            ans[pp.ss] = M(ans[pp.ss] + M(mid*cnt) );
            dp[pp.ss] = M(dp[pp.ss] + cnt);
            mid = M(mid * dp[pp.ss]);
        }

        for (i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

ll a[100005], bit[3][100005];
ll x[100005], y[100005];

void update(ll in, ll x, ll val)
{
    while (x < 100003)
    {
        bit[in][x] += val;
        x += x & (-x);
    }
    return;
}

ll query(ll in, ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += bit[in][x];
        x -= x & (-x);
    }
    return ans;
}

void go(ll sum)
{
    cout << (ll)ceil((ld)sum / 2) << "\n";
}

int main()
{
    ll n, i, diff;
    s(n);

    for (i = 1; i <= n; i++)
    {
        s(a[i]);
        diff = a[i] - a[i - 1];

        x[i] = x[i - 1];
        y[i] = y[i - 1];

        if (diff >= 0)
            x[i] += diff;
        else
            y[i] += diff;

        // update(1,i,x[i]);
        // update(2,i,y[i]);
    }

    go(x[n] + y[1]);

    ll q, l, r, xx;
    s(q);

    while (q--)
    {
        s(l);
        s(r);
        s(xx);

        diff = (a[l] + query(0, l)) - (a[l - 1] + query(0, l - 1));
        if (diff >= 0)
            update(1, l, -diff);
        else
            update(2, l, -diff);

        diff = (a[r + 1] + query(0, r + 1)) - (a[r] + query(0, r));
        if (diff >= 0)
            update(1, r + 1, -diff);
        else
            update(2, r + 1, -diff);

        update(0, l, xx);
        update(0, r + 1, -xx);

        diff = (a[l] + query(0, l)) - (a[l - 1] + query(0, l - 1));
        if (diff >= 0)
            update(1, l, diff);
        else
            update(2, l, diff);

        diff = (a[r + 1] + query(0, r + 1)) - (a[r] + query(0, r));
        if (diff >= 0)
            update(1, r + 1, diff);
        else
            update(2, r + 1, diff);

        go(x[n] + query(1, n) + y[1] + query(2, 1));
    }
    return 0;
}
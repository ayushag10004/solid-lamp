
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

int main()
{
    ll t, g = 1;
    s(t);

    while (t--)
    {
        ll n, k, i, ans = 0, st, end, a, b, sz, cnt;
        s(n);
        s(k);

        for (i = 1; i <= n; i++)
        {
            s(a);
            s(b);

            if (i == 1)
                end = a;

            if (end <= a)
            {
                sz = b - a;
                cnt = (ll)ceil((double)sz / k);
                ans += cnt;
                end = a + cnt * k;
            }
            else if (end <= b)
            {
                sz = b - end;
                cnt = (ll)ceil((double)sz / k);
                ans += cnt;
                end = end + cnt * k;
            }
        }

        cout << "Case #" << g << ": " << ans << "\n";
        ++g;
    }
    return 0;
}
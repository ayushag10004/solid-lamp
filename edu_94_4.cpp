
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

ll a[3005], h[3005], vv[3005];
int main()
{
    ll t;
    s(t);

    while (t--)
    {
        ll n, i, j, ans = 0, mid;
        s(n);

        memset(h, 0, sizeof h);
        for (i = 1; i <= n; i++)
            s(a[i]), ++h[a[i]];

        for (i = 1; i <= n; i++)
        {
            --h[a[i]];
            mid = 0;
            memset(vv, 0, sizeof vv);
            for (j = i + 1; j <= n; j++)
            {
                if (a[i] == a[j])
                    ans+=(mid-vv[a[i]]);
                
                mid-=vv[a[j]];
                ++vv[a[j]];
                mid+=(h[a[j]]-vv[a[j]]);

                // cout<<i<<" "<<j<<" "<<ans<<" "<<mid<<"\n";
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}

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

ll a[100005], dp[100005];
int main()
{
    ll t;
    s(t);

    while (t--)
    {
        ll n, i;
        s(n);

        for (i = 1; i <= n; i++)
            s(a[i]);

        dp[n + 1] = 0;

        for (i = n; i >= 1; i--)
        {
            if (dp[i + 1] == 0)
                dp[i] = 1;
            else
            {
                if (a[i] == 1)
                    dp[i] = 0;
                else
                    dp[i] = 1;
            }
        }

        if (dp[1])
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}
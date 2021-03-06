
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
        ll k, i, n;
        string a, b;
        cin >> a >> k;
        n = a.size();
        b = a;
        for (i = 0; i < n; i++)
            b[i] = '1';

        for (i = 0; i < n; i++)
            if (a[i] == '0')
            {
                if (i - k >= 0)
                    b[i - k] = '0';
                if (i + k < n)
                    b[i + k] = '0';
            }

        ll f = 1;
        for (i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                if (i - k >= 0 && b[i-k]=='1')
                    continue;
                if (i + k < n && b[i+k]=='1')
                    continue;

                f = 0;
                break;
            }
        }

        if(f)
            cout<<b<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
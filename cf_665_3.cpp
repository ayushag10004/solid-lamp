
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
ll a[100005],b[100005];
int main()
{
    ll t;
    s(t);

    while(t--)
    {
        ll n,i,mm=MOD,f=1;
        s(n);

        for(i=1;i<=n;i++)
        {
            s(a[i]);
            b[i] = a[i];
            mm = min(mm,b[i]);
        }

        sort(b+1,b+1+n);

        for(i=1;i<=n;i++)
        if(__gcd(a[i],mm)!=mm && a[i]!=b[i])
        {
            f = 0;
            break;
        }

        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
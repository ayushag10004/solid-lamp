
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

    while(t--)
    {
        ll a,b,c,x,y,z;
        s(a),s(b),s(c);
        s(x),s(y),s(z);

        ll ans = 0,d;
        d = min(c,y);
        ans+=d*2;
        c-=d;
        y-=d;

        d = min(c,z);
        c-=d;
        z-=d;

        d = min(a,z);
        a-=d;
        z-=d;

        d = min(z,b);
        ans -=d*2;
        cout<<ans<<"\n";
    }
    return 0;
}
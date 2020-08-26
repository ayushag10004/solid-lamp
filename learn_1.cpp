
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

ll x[1004],y[1004],h1[1004],h2[1004];
int main()
{
    ll n,m,i,mid,aa,bb,ans1=0,ans2=0;
    s(n);
    for(i=1;i<=n;i++)
        s(x[i]),s(y[i]),++h1[x[i]];

    s(m);
    vector < map<ll,ll> > mp(1003);
    for(i=1;i<=m;i++)
    {
        s(aa); s(bb);
        ++h2[aa];
        ++mp[aa][bb];
    }

    for(i=1;i<=1000;i++)
        ans1+=min(h1[i],h2[i]);

    for(i=1;i<=n;i++)
    {
        if(mp[x[i]][y[i]]>0)
        {
            ++ans2;
            --mp[x[i]][y[i]];
        }
    }

    cout<<ans1<<" "<<ans2<<"\n";

    return 0;
}
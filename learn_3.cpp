
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

vector< vector<ll> > vv;
ll vis[100005];

void  go(ll x)
{
  vis[x] = -1;

  ll size = vv[x].size(),i;
  for(i=0;i<size;i++)
  if(vis[vv[x][i]]!=-1)
    go(vv[x][i]);
  
  return;
}

int main()
{
    ll t;
    s(t);

    while(t--)
    {
      ll n,m,i,x,y;
      s(n); s(m);
      ll deg[n+1];
      memset(deg,0,sizeof deg);

      vv.clear();
      vv.resize(n+1);

      for(i=1;i<=n;i++)
        vis[i] = 1;
      
      for(i=1;i<=m;i++)
      {
        s(x); s(y);
        vv[x]._pb(y);
        ++deg[y];
        ++y;
      }

      vector< pair<ll,ll> > ss;
      for(i=1;i<=n;i++)
        ss._pb(_mp(deg[i],i));

      sort(ss.begin(),ss.end());
      for(i=1;i<=n;i++)
      if(vis[ss[i].ss]!=-1)
      {
        go(ss[i].ss);
        vis[ss[i].ss] = 1;
      }

      ll ans = 0;
      for(i=1;i<=n;i++)
      if(vis[i]!=-1)
        ++ans;

      cout<<ans<<"\n";
    }
    return 0;
}

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define MOD 1000000007
#define M(x) (x % MOD + MOD) % MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%d", &x)

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

set< pair<ll,ll> >  hstart, hend;
ll vstart[1000005], vend[1000005];

ll bit[1000006];
void update(ll x, ll val)
{
    while(x<1000003)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
    return;
}

ll query(ll x)
{
    ll ans = 0;
    while(x>0)
    {
        ans+=bit[x];
        x-=x&(-x);
    }
    return ans;
}

int main()
{
    ll n,m,i,x,y,z;
    long long int ans = 1;

    s(n); s(m);
    memset(vstart, -1, sizeof vstart);
    memset(vend, -1, sizeof vend);

    for(i=1;i<=n;i++)
    {
        s(x); s(y); s(z);
        hstart.insert(_mp(y,x));
        hend.insert(_mp(z,x));
        if(y==0 && z==1000000)
            ++ans;
    }

    for(i=1;i<=m;i++)
        s(x), s(vstart[x]), s(vend[x]);
    
    ll aa;
    pair<ll,ll> pp;
    for(i=0;i<1000000;i++)
    {
        while(!hstart.empty())
        {
            pp = *hstart.begin();
            if(pp.ff==i)
            {
                aa = pp.ss;
                update(aa,1);
                hstart.erase(pp);
            }
            else
                break;
        }

        if(vstart[i]!=-1)
        {  
            // cout<<vstart[i]<<" "<<vend[i]<<":  "<<ans<<"\n";
            if(vstart[i]==0 && vend[i]==1000000)
                ans+=(1+query(1000000));
            else
                ans+=(query(vend[i]) - query(vstart[i]-1));
            // cout<<ans<<"\n";
        }

        while(!hend.empty())
        {
            pp = *hend.begin();
            if(pp.ff==i)
            {
                aa = pp.ss;
                update(aa,-1);
                hend.erase(pp);
            }
            else
                break;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
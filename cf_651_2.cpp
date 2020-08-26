
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)
 
ll mul(ll x,ll y)
{ ll ans=1;
 
  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }
 
  return ans;
};
 
/******************************************************************************************************/
ll a[500005],vis[500005];
int main()
{
    ll n,k,i,ans=1,fin=0;
    s(n); s(k);

    set< pair<ll,ll> > ss;
    for(i=1;i<=n;i++)
    {
        s(a[i]);
        ss.insert(_mp(a[i],i));
    }

    pair<ll,ll> pp;

    while(!ss.empty())
    {
        pp = *ss.begin();
        ss.erase(pp);
        vis[pp.ss] = 1;

        if( (pp.ss-1 > 0 && vis[pp.ss-1]==0) && (pp.ss+1 <= n && vis[pp.ss+1]==0) )
            ans+=2;
        
        if(pp.ss==1 && vis[pp.ss+1]==0)
            ans+=1;
        
        if(pp.ss==n && vis[pp.ss-1]==0)
            ans+=1;
        
        fin = pp.ff;
        if(ans>=k)
            break;
    }

    cout<<fin<<"\n";
    return 0;
}
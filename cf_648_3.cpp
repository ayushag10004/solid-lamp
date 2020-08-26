
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
 
ll pos[200005];
int main()
{   
    ll n,i,x,ans=0,diff;
    s(n);

    for(i=1;i<=n;i++)
    {
        s(x);
        pos[x] = i;
    }

    map<ll,ll> mp;
    for(i=1;i<=n;i++)
    {
        s(x);
        if(i < pos[x])
            diff = i+n -pos[x];
        else
            diff = i - pos[x];
        
        ++mp[diff];
        ans=max(ans,mp[diff]);
    }

    cout<<ans<<"\n";
    return 0;
}
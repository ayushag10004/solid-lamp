
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

ll a[1030];
int main()
{
    ll t;
    s(t);
    while(t--)
    {
        ll n,i,j,ans=-1;
        s(n);

        set<ll> ss;
        for(i=1;i<=n;i++)
            s(a[i]),ss.insert(a[i]);
        
        set<ll> kk;
        for(i=1;i<1024;i++)
        {
            kk.clear();
            for(j=1;j<=n;j++)
                kk.insert(a[j]^i);
            
            if(kk==ss)
            {
                ans = i;
                break;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
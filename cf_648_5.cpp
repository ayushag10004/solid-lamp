
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
 
ll a[505];
int main()
{
    ll n,i,j,k,ans=0;
    s(n);

    for(i=1;i<=n;i++)
        s(a[i]);
    
    for(i=1;i<=n;i++)
    {
        ans = max(ans,a[i]);
        for(j=i+1;j<=n;j++)
        {
            ans = max(ans,a[i]|a[j]);
            for(k=j+1;k<=n;k++)
            {
                ans = max(ans,a[i]|a[j]|a[k]);
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}

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

ll a[200005];
int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,i,mm=-1,ans=0;
        s(n);

        for(i=1;i<=n;i++)
            s(a[i]);
        
        for(i=1;i<=n;i++)
        {
            if(a[i]>mm && ((i+1<=n && a[i]>a[i+1]) || i==n))
                ++ans;
            mm = max(mm,a[i]);
        }

        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;      
    }
    return 0;
}
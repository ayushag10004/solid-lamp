
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

ll a[1005];

int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,d,i;
        s(n); s(d);

        for(i=1;i<=n;i++)
            s(a[i]);

        for(i=n;i>=1;i--)
            d-=d%a[i];

        cout<<"Case #"<<g<<": "<<d<<"\n";
        ++g;
    }
    return 0;
}
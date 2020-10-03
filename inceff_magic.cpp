

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
ll a[500005],b[500005],c[500005];
int main()
{	
	ll n,i,ans=0;
	cin>>n;

	for(i=1;i<=n;i++)
		cin>>a[i];

	for(i=1;i<=n;i++)
		b[i] = max(a[i],a[i]+b[i-1]),ans=max(ans,b[i]);

	for(i=n;i>=1;i--)
		c[i] = max(a[i],a[i]+c[i+1]),ans=max(ans,c[i]);

	for(i=1;i<=n;i++)
		{
			aa = max(1LL*0,b[i-1]);
			bb = max(1LL*0,c[i+1]);

			ans = max(ans,a[i]*a[i]+aa+bb);
		}

	cout<<ans<<"\n";
						
	return 0;
}
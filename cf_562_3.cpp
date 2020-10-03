

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
ll a[300005],h[300005];
int main()
{	
	ll i,n,m;
	cin>>n>>m;

	for(i=1;i<=n;i++)
		cin>>a[i];

	ll lo = 0,hi = 2*m,mid,ans=0,f;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		f = 0;

		h[1] = a[1];

		if(h[1]!=0 && m-h[1]<=mid)
			h[1] = 0;

		for(i=2;i<=n;i++)
		if(h[i-1]<a[i])
		{
			h[i] = a[i];

			if(m-a[i]+h[i-1]<=mid)
				h[i] = h[i-1];	
		}
		else if(h[i-1]>a[i])
		{
			if(h[i-1]-a[i]<=mid)
				{	
					h[i] = h[i-1];
					continue;
				}
			else
			{
				f = 1;
				break;
			}
		}
		else
			h[i] = h[i-1];

		// cout<<mid<<"\n";
		// for(i=1;i<=n;i++)
		// 	cout<<h[i]<<" ";
		// cout<<"\n";

		if(f==1)
			lo = mid+1;
		else
			{
				ans = mid;
				hi = mid-1;
			}
	}

	cout<<ans<<"\n";
	return 0;
}
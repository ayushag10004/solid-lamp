

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

ll a[1000005],n;

ll check(ll l,ll r)
{
	ll i,last=0;

	for(i=1;i<=n;i++)
		if(l<=a[i] && a[i]<=r)
			continue;
		else if(last>a[i])
			return 0;
		else
			last = a[i];

	return 1;
}

ll aa[1000005],bb[1000005];

int main()
{
	ll x,i;
	cin>>n>>x;

	for(i=1;i<=n;i++)
		cin>>a[i];

	ll lo=1,hi=x,mid,lim1,lim2;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		if(check(mid+1,x+1))
		{
			lim1 = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}

	lo=1,hi=x,mid;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		if(check(0,mid-1))
		{
			lim2 = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}

	memset(h,-1,sizeof h);

	for(i=1;i<=n;i++)
		h[a[i]] = i;
	
	ll last = 0;
	for(i=1;i<=lim1;i++)
	{
		last = max(last,h[a[i]]);
		aa[i] = last;
	}

	memset(h,-1,sizeof h);

	for(i=n;i>=1;i--)
		h[a[i]] = i;
	
	ll last = x+1;
	for(i=n;i>=lim2;i--)
	{
		last = min(last,h[a[i]]);
		bb[i] = last;
	}
	// bb[x+1] = n+1;
	ll xx = min(lim1,lim2),yy=max(lim1,lim2);

	vector<ll> vv;

	for(i=lim2;i<=x;i++)
		vv._pb(bb[i]);

	sort(vv.begin(),vv.end());

	ll ans = 0;
	for(i=1;i<=lim1;i++)
	{	
		

	}

	return 0;
}
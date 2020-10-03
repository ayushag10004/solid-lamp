
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

ll a[100005],b[100005],c[100005],h[1000005];
int main()
{	
	ll n,i,j,x,val,cnt=0;
	s(n);

	for(i=1;i<=n;i++)
	{
		s(x);
		for(j=0;j<x;j++)
		{
			s(val);

			if(j==0)
			{
				a[i] = val;
				b[i] = val;
			}
			else
			{
				a[i] = min(a[i],val);
				b[i] = max(b[i],val);
			}

			if(a[i]<val)
				c[i] = 1;
		}

		if(c[i]==1)
			++cnt;
		else
			++h[a[i]];
	}

	for(i=1;i<=1000000;i++)
		h[i] += h[i-1];

	ll ans = 0;

	for(i=1;i<=n;i++)
	if(c[i])
		ans+=n;
	else
	{
		ans+=cnt;
		if(b[i])
			ans+=h[b[i]-1];
	}

	cout<<ans<<"\n";

	return 0;
}
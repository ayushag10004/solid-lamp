

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

ll a[1005],sum[1005];
int main()
{
	ll n,x,i,j;
	s(n); s(x);

	for(i=1;i<=n;i++)
	{
		s(a[i]);
		sum[i] = a[i] + sum[i-1];
	}

	double ans=sum[n],mid;

	for(i=1;i<=n;i++)
	{
		mid = sum[i-1];

		for(j=i;j<=n;j++)
		{
			mid+=(double)a[j]/x;
			// cout<<i<<" "<<j<<" "<<mid<<"\n";
			ans = min(ans,mid+sum[n]-sum[j]);
		}
	}

	cout<<fixed<<setprecision(5)<<ans<<"\n";

	return 0;
}
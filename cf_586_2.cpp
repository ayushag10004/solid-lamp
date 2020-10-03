

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

ll a[1005][1005];

int main()
{
	ll n,i,j,cc,bb,mid;
	s(n);

	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		s(a[i][j]);

	for(i=1;i<=n;i++)
	{
		bb = i+1;
		cc = i+2;

		if(i==n-1)
			cc = 1;
		else if(i==n)
			bb = 1,cc=2;

		mid = a[i][bb]*a[i][cc];
		mid = mid/a[bb][cc];
		cout<<(ll)sqrtl(mid)<<" ";
	}

	cout<<"\n";
	return 0;
}
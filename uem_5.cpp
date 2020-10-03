

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
ll dp[2005][2005],a[2005],b[2005];
int main()
{	
	ll n,m,i,j;
	s(n); s(m);

	for(i=1;i<=n;i++)
		s(a[i]);

	for(i=1;i<=m;i++)
		s(b[i]);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		if(__gcd(a[i],b[j])==1)
		{
			dp[i][j] = max( dp[i-1][j-1] + 1, max( dp[i-1][j],dp[i][j-1] ) );
		}
		else
			dp[i][j] = dp[i][j-1];	
	}

	cout<<dp[n][m]<<"\n";
	return 0;
}
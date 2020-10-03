
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 100000000000000007
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
ll dp[10005][2],a[10006],b[10005];
int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,c,aa;
		s(n); s(c);

		memset(dp,-1,sizeof dp);

		for(i=1;i<=n;i++)
			s(a[i]);

		for(i=1;i<=n;i++)
			s(b[i]);

		dp[0][0] = 0;

		for(i=1;i<=n;i++)
		{
			aa = MOD;

			if(dp[i-1][0]!=-1)
				aa = min(aa,dp[i-1][0]);

			if(dp[i-1][1]!=-1)
				aa = min(aa,dp[i-1][1]);

			dp[i][0] = aa + a[i];

			aa = MOD;

			if(dp[i-1][1]!=-1)
				aa = min(aa,dp[i-1][1] + c);

			if(dp[i-1][0]!=-1)
				aa = min(aa,dp[i-1][0] + c + c*b[i]);

			dp[i][1] = aa;			
		}

		cout<<n<<" "<<min(dp[n][0],dp[n][1])<<"\n";
	}
	return 0;
}
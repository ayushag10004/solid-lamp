

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 10000000000000007
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
ll dp[200005][2];
int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,a,b,i;
		s(n); s(a); s(b);

		string str;
		cin>>str;
		char ch;

		dp[0][0] = b;
		dp[0][1] = -1;

		for(i=1;i<=n;i++)
		{
			ch = str[i-1];

			if(ch=='0')
			{	
				dp[i][0] = dp[i][1] = MOD;

				if(dp[i-1][0]!=-1)
					{
						dp[i][0] = min(dp[i][0] , dp[i-1][0] + a + b);
						dp[i][1] = min(dp[i][1] , dp[i-1][0] + 2*a + 2*b);
					}

				if(dp[i-1][1]!=-1)
					{
						dp[i][0] = min(dp[i][0] , dp[i-1][1] + 2*a + b);
						dp[i][1] = min(dp[i][1] , dp[i-1][1] + a + 2*b);
					}

				if(dp[i][0]==MOD)
					dp[i][0] = -1;

				if(dp[i][1]==MOD)
					dp[i][1] = -1;				
			}	
			else
			{
				dp[i][0] = -1;
				dp[i][1] = dp[i-1][1] + a + 2*b;
			}
		}

		// for(i=0;i<=n;i++)
		// 	cout<<i<<"->"<<dp[i][0]<<" "<<dp[i][1]<<"\n";

		cout<<dp[n][0]<<"\n";
	}
	return 0;
}
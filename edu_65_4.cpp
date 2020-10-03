

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
ll dp[200005];
int main()
{	
	ll i,n,cnt=0,mx=0;
	string str;

	cin>>n>>str;
	stack <ll> ss;

	for(i=0;i<n;i++)
	{
		if(str[i]=='(')
		{
			ss.push(1);
			++cnt;
			dp[i] = cnt;
		}
		else
		{
			ss.pop();
			dp[i] = cnt;
			--cnt;
		}

		mx = max(mx,dp[i]);
	}

	for(i=0;i<n;i++)
		if(dp[i]<=mx/2)
			cout<<0;
		else
			cout<<1;

	cout<<"\n";	
	return 0;
}
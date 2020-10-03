

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

ll dp[100005];
int main()
{
	ll t;
	s(t);

	while(t--)
	{
		string str;
		ll n,i,q;
		s(n); s(q);
		cin>>str;

		for(i=0;i<n;i++)
		if(i+2<n && str[i]==str[i+1] || str[i]==str[i+2] || str[i+1]==str[i+2])
			dp[i] = i+2;
		else
			dp[i] = MOD;

		for(i=n-2;i>=0;i--)
			dp[i] = min(dp[i],dp[i+1]);

		while(q--)
		{
			ll l,r;
			s(l); s(r);
			--l;
			--r;

			if(dp[l]<=r)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}		
	}
	return 0;
}
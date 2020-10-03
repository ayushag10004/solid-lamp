

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
		ll n,k,i,val;
		s(n); s(k);

		multiset<ll> ss;
		ss.insert(0);

		for(i=1;i<=n;i++)
		{
			s(val);
			dp[i] = *ss.begin() + val;
			// cout<<i<<" "<<dp[i]<<"\n";
			ss.insert(dp[i]);

			if(i-k>=0)
				ss.erase(ss.find(dp[i-k]));
		}

		cout<<*ss.begin()<<"\n";	
	}	

	return 0;
}
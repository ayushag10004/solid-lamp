

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
vector < vector < ll > > v;
ll a[100005],dp[100005];

ll go(ll x,ll y,ll k)
{
	dp[x] = 0;

	ll size = v[x].size(),i,sum=a[x];

	for(i=0;i<size;i++)
		if(v[x][i]!=y)
		{
			sum+=go(v[x][i],x,k);

			if(dp[v[x][i]]<0)
				dp[x]+=dp[v[x][i]];
		}

	dp[x] = min(dp[x],k+sum);	
	return sum;	
}

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,x,y,k,sum;
		s(n); s(k);

		v.clear();
		v.resize(n+1);

		for(i=1;i<=n;i++)
			s(a[i]);

		for(i=1;i<n;i++)
		{
			s(x); s(y);

			v[x]._pb(y);
			v[y]._pb(x);
		}

		sum = go(1,0,k);
		printf("%d\n",sum-dp[1]);
		// cout<<sum-dp[1]<<"\n";
	}
	return 0;
}
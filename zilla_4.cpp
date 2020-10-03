

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

ll dfs(vector < vector < ll > > &v,ll x,ll y)
{
	ll size = v[x].size(),i,ans=4,f=0;

	for(i=0;i<size;i++)
		if(v[x][i] != y)
		{
			f = 1;
			ans = (ans * dfs(v,v[x][i],x) )%MOD;
		}

	if(f==0)
		return 1;

	return ans;
}

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,x,y,i;
		s(n);

		vector< vector < ll > > v(n+1);

		for(i=1;i<=n-2;i++)
		{
			s(x); s(y);

			v[x]._pb(y);
			v[y]._pb(x);
		}

		cout<<(4*dfs(v,1,0))%MOD<<"\n";
	}
	return 0;
}
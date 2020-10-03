

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

vector< vector<ll> > v;
ll vis[200005];

void go(ll x,ll a,ll b)
{	
	// cout<<x<<"----\n";

	if(x==a)
		return;

	if(x==b)
	{
		vis[x]=-2;
		return;
	}

	vis[x] = 1;

	ll i,size=v[x].size();

	for(i=0;i<size;i++)
	if(vis[v[x][i]]==-2)
	{
		vis[x] = -2;
		return;
	}
	else if(vis[v[x][i]]==-1)
	{
		go(v[x][i], a, b);

		if(vis[v[x][i]]==-2)
		{
			vis[x] = -2;
			return;
		}

		vis[x]+=vis[v[x][i]];
	}

	return;
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll n,m,a,b,i,x,y;
		s(n); s(m); s(a); s(b);

		v.clear();
		v.resize(n+1);

		for(i=1;i<=m;i++)
		{
			s(x); s(y);

			v[x]._pb(y);
			v[y]._pb(x);
		}

		ll ans1=0, ans2=0;

		for(i=1;i<=n;i++)
			vis[i] = -1;

		vis[a] = 0;
		for(i=0;i<v[a].size();i++)
		if(vis[v[a][i]]==-1)
		{
			go(v[a][i], a, b);

			if(vis[v[a][i]]!=-2)
				ans1+=vis[v[a][i]];
		}
		
		// for(i=1;i<=n;i++)
		// 	cout<<i<<"-->"<<vis[i]<<"\n";

		// cout<<ans1<<"\n";

		for(i=1;i<=n;i++)
			vis[i] = -1;

		vis[b] = 0;
		for(i=0;i<v[b].size();i++)
		if(vis[v[b][i]]==-1)
		{
			go(v[b][i], b, a);

			if(vis[v[b][i]]!=-2)
				ans2+=vis[v[b][i]];
		}

		// for(i=1;i<=n;i++)
		// 	cout<<i<<"-->"<<vis[i]<<"\n";

		// cout<<ans2<<"\n";

		cout<<ans1*ans2<<"\n";
	}
	
	return 0;
}
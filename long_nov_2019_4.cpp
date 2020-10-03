

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

ll bit[100005];

void update(ll x, ll val)
{
	while(x<100005)
	{
		bit[x]+=val;
		x+=(x&(-x));
	}

	return;
}

ll query(ll x)
{
	ll ans = 0;

	while(x>0)
	{
		ans+=bit[x];
		x-=(x&(-x));
	}

	return ans;
}

void dfs( vector< vector<ll> > &v, vector< ll > &pos, ll x, ll y, ll &in, ll &loop_cnt, vector< vector<ll> > &cycle, vector< ll > &rgt)
{
	ll size = v[x].size(),i,f=0;

	pos[x] = in;
	++in;

	for(i=0;i<size;i++)
		if(v[x][i]!=y || 1)
		{
			if(v[x][i]==y && f==0)
			{
				f == 1;
				continue;
			}

			if(pos[v[x][i]]!=0 && pos[v[x][i]]<=pos[x])
			{
				++loop_cnt;
				cycle[v[x][i]]._pb(x);
			}
			else if(pos[v[x][i]]==0)
			{
				dfs( v, pos, v[x][i], x, in, loop_cnt, cycle, rgt);
			}
		}

	rgt[x] = in-1;

	return;
}

void dfs1(vector< vector<ll> > &v, vector< ll > &pos, ll x, ll &ans, ll &loop_cnt, vector< vector<ll> > &cycle, vector< ll > &rgt, vector< ll > &vis)
{
	ll size = v[x].size(), size1 = cycle[x].size(), i;

	vis[x] = 1;
	ll upper_loops_cnt = 0;

	for(i=0;i<size;i++)
		if(vis[v[x][i]]==0)
			upper_loops_cnt = max(upper_loops_cnt, query(rgt[v[x][i]]) - query(pos[v[x][i]] - 1));

	ll x_node_loops = size1 + query(pos[x]) - query(pos[x]-1);

	if(upper_loops_cnt<2 && loop_cnt>0 && loop_cnt - x_node_loops - ( query(rgt[x]) - query(pos[x]) ) == 0)
		ans = min(ans,x);

	for(i=0;i<size1;i++)
		update(pos[cycle[x][i]],1);

	for(i=0;i<size;i++)
		if(vis[v[x][i]]==0)
			dfs1(v, pos, v[x][i], ans, loop_cnt, cycle, rgt, vis);

	for(i=0;i<size1;i++)
		update(pos[cycle[x][i]],-1);	
	
	return;
}

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,m,i,x,y;
		s(n); s(m);

		vector < vector < ll > > v(n+2);
		vector < vector < ll > > cycle(n+2);

		for(i=1;i<=m;i++)
		{
			s(x); s(y);
			v[x]._pb(y);
			v[y]._pb(x);
		}

		vector < ll > pos(n+2,0);
		vector < ll > rgt(n+2,0);
		ll in = 1, loop_cnt = 0, j;
		
		for(i=1;i<=n;i++)
			if(pos[i]==0)
			{
				 dfs(v, pos, i, 0, in, loop_cnt, cycle, rgt);
			}

		// for(i=1;i<=n;i++)
		// {
		// 	cout<<"lr-> "<<pos[i]<<": "<<rgt[i]<<"\n";
		// 	cout<<i<<": ";
		// 	for(j=0;j<cycle[i].size();j++)
		// 		cout<<cycle[i][j]<<" ";
		// 	cout<<"\n";
		// }

		// cout<<"loop_cnt: "<<loop_cnt<<"\n";

		vector < ll > vis(n+2,0);
		ll ans = MOD;

		for(i=1;i<=n;i++)
			if(vis[i]==0)
			{
				dfs1(v, pos, i, ans, loop_cnt, cycle, rgt, vis);
			}

		if(ans==MOD)
			ans = -1;

		cout<<ans<<"\n";
	}
	return 0;
}
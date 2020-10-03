

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
vector< vector < ll > > v(200005);
ll d[200005],w[200005],vis[200005],sum=0,rem=0;

ll go(ll x,ll st)
{	
	vis[x] = 1;

	if(d[x]==0)
	{
			rem = max(rem,w[x]);
			return w[x];
	}

	if(d[x]==1 && x!=st)
		{
			rem = max(rem,w[x]);
			return w[x];
		}

	ll size = v[x].size(),i,fin=0,mm=0,ee=0,mid;

	for(i=0;i<size;i++)
	if(vis[v[x][i]]==0)
	{
		++ee;
		mid = go(v[x][i],st);

		if(mid==-1)
			fin = -1;
		else
		    mm = max(mm,mid);
	}

	if(ee==0 || fin==-1 || d[x]>ee+1)
	{
		sum+=w[x];
		return -1;
	}

	rem = max(rem, w[x]+mm);
	return w[x] + mm;
}

int main()
{
	ll n,m,i,x,y;
	s(n); s(m);

	for(i=1;i<=n;i++)
		s(w[i]);

	for(i=1;i<=m;i++)
	{	
		s(x); s(y);
		v[x]._pb(y);
		v[y]._pb(x);

		++d[x]; ++d[y];
	}

	ll st;
	s(st);

	go(st,st);

	cout<<sum+rem<<"\n";

	return 0;
}
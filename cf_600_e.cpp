

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
const ll N = 100005;
ll bit[N];

void update(ll x,ll val)
{
	while(x>0)
		{
			bit[x] = min(bit[x], val);
			x-=(x&(-x));
		}

	return;
}

ll query(ll x)
{
	if(x==0)
		return 0;

	ll ans = MOD;
	while(x<N)
	{
		ans = min(ans, bit[x]);
		x+=(x&(-x));
	}

	return ans;
}

int main()
{
	ll n,m,i,x,y;
	set< pair< ll,ll > > ss;

	s(n); s(m);

	for(i=1;i<N;i++)
		bit[i] = MOD;

	for(i=1;i<=n;i++)
		{
			s(x); s(y);

			ss.insert(_mp(x,y));
		}

	pair<ll,ll> pp;

	ll pt, extra, mid;

	while(!ss.empty())
	{
		pp = *ss.begin();
		ss.erase(pp);

		for(i=1;i<=m;i++)
		{	
			if(pp.ff-i < 0)
				pt = 0;
			else 
				pt = pp.ff - i;
		
			mid = query(pt);

			if(mid!=MOD)
			{
				if(i-1<=pp.ss)
					update(	min(pp.ff + pp.ss, m), mid );
				else
				{
					extra = i-1 - pp.ss;
					update(	min(pp.ff + i-1, m), mid + extra );
				}
			}
		}
	}

	cout<<query(m)<<"\n";

	return 0;
}
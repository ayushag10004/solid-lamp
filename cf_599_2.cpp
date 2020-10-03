

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

void go(ll top, set<ll> &ss, vector< set<ll> > &v)
{
	set<ll> a,b;
	set<ll> :: iterator it;

	for(it = ss.begin(); it!=ss.end(); ++it)
	{
		if(v[top].find(*it)!=v[top].end())
			a.insert(*it);
		else
			b.insert(*it);
	}

	ss = a;
	for(it = b.begin(); it!=b.end(); ++it)
	{
		go(*it, ss, v);
	}

	return;
}

int main()
{
	ll n,m,x,y,i;
	s(n); s(m);

	vector < set < ll > > v(n+2);

	for(i=1;i<=m;i++)
	{
		s(x); s(y);
		v[x].insert(y);
		v[y].insert(x);
	}

	set<ll> ss;

	for(i=1;i<=n;i++)
		ss.insert(i);

	ll ans = 0,top;

	while(ss.size()>0)
	{
		++ans;
		top = *ss.begin();
		ss.erase(top);

		go(top, ss, v);
	}

	cout<<ans-1<<"\n";
	return 0;
}
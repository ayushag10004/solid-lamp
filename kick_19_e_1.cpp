

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
ll p[100005];

ll prnt(ll x)
{
	if(p[x]==-1 || p[x]==x)
	{
		p[x] = x;
		return x;
	}
	else
		return p[x] = prnt(p[x]);
}

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{
		ll n,m,i,x,y,px,py;
		s(n); s(m);

		for(i=1;i<=n;i++)
			p[i] = -1;

		for(i=1;i<=m;i++)
		{
			s(x); s(y);

			px = prnt(x);
			py = prnt(y);

			p[py] = px;
		}

		ll cnt = 0,ans=0;
		set<ll> s;
		map<ll,ll> mp;

		for(i=1;i<=n;i++)
		if(p[i]!=-1)
		{
			p[i] = prnt(i);
			++mp[p[i]];
			s.insert(p[i]);
		}
		else
			++cnt;

		ll cc = s.size();

		if(cnt>0)
			ans+=(2*(cnt-1)),++cc;

		if(cc>0)
			ans+=(2*(cc-1));			

		while(!s.empty())
		{
			cc = *s.begin();
			ans+=(mp[cc]-1);
			s.erase(cc);
		}

		printf("Case #%lld: %lld\n",g,ans);
		++g;
	}
	return 0;
}
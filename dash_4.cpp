

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

ll p[100005],sz[100005];

ll prnt(ll x)
{
	if(x==p[x])
		return x;
	else
		return p[x] = prnt(p[x]);
}

int main()
{
	ll n,k,i,aa,bb,cnt=0,x,y;
	s(n); s(k);

	for(i=1;i<=n;i++)
		p[i] = i,sz[i] = 1;

	for(i=1;i<=k;i++)
	{
		s(x); s(y);
		aa = prnt(x); bb = prnt(y);
		
		if(aa==bb)
			continue;

		p[bb] = aa;
		sz[aa]+=sz[bb];
	}

	for(i=1;i<=n;i++)
	{
		p[i] = prnt(i);

		if(p[i]==i)
			cnt+=(sz[i]-1);

		// cout<<i<<"--"<<p[i]<<"--"<<sz[i]<<"\n";
	}

	cout<<k-cnt<<"\n";
	
	return 0;
}
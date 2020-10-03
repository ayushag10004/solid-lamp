

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
	if(p[x]==x)
		return x;
	else
		return p[x] = prnt(p[x]);
}

int main()
{	
	ll n,m,k,i,x,y,aa,bb;
	cin>>n>>m>>k;

	for(i=1;i<=n;i++)
		p[i] = i,sz[i]=1;

	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		aa = prnt(x); 
		bb = prnt(y);

		p[bb] = aa;
		sz[aa]+=sz[bb];
	}

	// for(i=1;i<=n;i++)
	// 	cout<<i<<" "<<p[i]<<" "<<sz[i]<<"\n";

	ll node,pp,ed=0,mx=0;
	for(i=1;i<=k;i++)
	{
		cin>>node;
		pp = prnt(node);

		ed+=(sz[pp]*(sz[pp]-1))/2;
		mx = max(mx,sz[pp]);
		p[pp] = 0;
	}

	// cout<<ed<<" "<<mx<<" --\n";
	ll last = 0,cost = 0;
	for(i=1;i<=n;i++)
		if(p[i]==i)
			cost+=last*sz[i],ed+=last*sz[i],last+=sz[i],ed+=(sz[i]*(sz[i]-1))/2;

	// ll cost=0,pp1;
	
	// while(ss.size()>1)
	// {
	// 	pp = *ss.begin();
	// 	ss.erase(ss.find(pp));

	// 	pp1 = *ss.begin();
	// 	ss.erase(ss.find(pp1));

	// 	cost+=pp*pp1;
	// 	ed+=pp*pp1;
	// 	ss.insert(pp+pp1);
	// }	

	cout<<ed-m<<" "<<cost<<"\n";
	return 0;
}
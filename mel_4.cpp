

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
ll a[1005],h[1005];
int main()
{
	ll n,m,i;
	s(n); s(m);

	set<ll> ss;
	for(i=1;i<=m;i++)
		s(a[i]),ss.insert(a[i]);

	ll ans = MOD,pos,steps,cnt;

	for(i=1;i<n;i++)
	{
		memset(h,-1,sizeof h);

		pos = 1;
		steps = 0;
		cnt = 0;

		while(h[pos]==-1)
		{
			h[pos] = 1;
			steps+=1;

			if(ss.find(pos)!=ss.end())
				++cnt;

			pos+=i;

			if(pos>n)
				pos-=n;

			if(cnt==m)
				break;
		}

		// cout<<i<<steps<<cnt<<pos<<"\n";
		if(cnt==m)
			ans = min(ans,steps);
	}

	cout<<ans<<"\n";

	return 0;
}


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

ll a[2005];
int main()
{
	ll n,i;
	s(n);

	map<ll,ll> mp,mid;
	set<ll> ss;
	for(i=1;i<=n;i++)
		s(a[i]),++mp[a[i]],ss.insert(a[i]);

	ll ans = MOD,dis = ss.size(),cur,j;	

	if(dis==n)
	{
		cout<<0<<"\n";
		return 0;
	}

	for(i=1;i<=n;i++)
	{
		mid = mp;
		cur = dis;

		for(j=i;j<=n;j++)
		{
			--mid[a[j]];

			if(mid[a[j]]==0)
				--cur;

			if(n-(j-i+1)==cur)
				ans = min(ans,j-i+1);
		}	
	}

	cout<<ans<<"\n";
	return 0;
}
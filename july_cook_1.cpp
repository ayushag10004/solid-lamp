

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

ll cnt[100005][20],pos[100005];
int main()
{
	ll t;
	s(t);

	while(t--)
	{
		memset(cnt,0,sizeof cnt);

		ll n,i,val,j,ans=0,a,b;
		cin>>n;

		for(i=1;i<=n;i++)
		{
			cin>>val;
			pos[val] = 1;

			for(j=0;j<20;j++)
			if((val>>j)&1)
				cnt[i][j] = cnt[i-1][j] + 1;
			else
				cnt[i][j] = cnt[i-1][j];
		}

		set<ll> s;
		s.insert(0);
		s.insert(n+1);
		set<ll> :: iterator it,it1;

		for(i=1;i<=n;i++)
		{
			s.insert(pos[i]);
			it1 = it = s.find(pos[i]);
			
			--it1;
			++it;

			a = *it1;
			b = *it - 1;

			for(j=0;j<20;j++)
			if((i>>j)&1)
				ans+=(1<<j)*(cnt[b][j]-cnt[a][j]);
		}

		cout<<ans<<"\n";
	}

	return 0;
}
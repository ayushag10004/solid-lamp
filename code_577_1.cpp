

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

ll mm[1005];
int main()
{
	ll n,m,i,j,mx,ans=0;

	string ss[1005];

	cin>>n>>m;

	for(i=1;i<=n;i++)
		cin>>ss[i];

	for(i=0;i<m;i++)
		cin>>mm[i];

	for(j=0;j<m;j++)
	{
		vector<ll> vv(5,0);

		for(i=1;i<=n;i++)
			++vv[ss[i][j]-'A'];

		mx = 0;

		for(i=0;i<5;i++)
			mx = max(mx,vv[i]);

		ans+=mx*mm[j];
	}

	cout<<ans<<"\n";
	return 0;
}
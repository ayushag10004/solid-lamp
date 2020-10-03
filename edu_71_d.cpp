

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 998244353
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

ll f[300005],a[300005],b[300005];
int main()
{	
	ll n,i,x,y;
	cin>>n;

	f[0] = 1;
	for(i=1;i<=300002;i++)
		f[i] = (f[i-1]*i)%MOD;

	vector< pair<ll,ll> > v;

	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		++a[x];
		++b[y];

		v._pb(_mp(x,y));
	} 

	sort(v.begin(),v.end());

	ll ans = f[n],aa=1,bb=1;

	for(i=1;i<=n;i++)
	{
		aa = (aa*f[a[i]])%MOD;
		bb = (bb*f[b[i]])%MOD;
	}

	ans = M(ans-aa);
	ans = M(ans-bb);

	x = y = 0;
	v._pb(_mp(MOD,MOD));
	ll cnt = 0,cc=1;

	for(i=0;i<=n;i++)
	{	

		if(x>v[i].ff || y>v[i].ss)
		{
			cc = 0;
			break;
		}

		if(x==v[i].ff && y==v[i].ss)
			++cnt;
		else
		{
			cc = (cc*f[cnt])%MOD;
			cnt = 1;
			x = v[i].ff;
			y = v[i].ss;
		}
	}

	// cout<<cc<<"\n";
	ans = M(ans+cc);

	cout<<ans<<"\n";
	return 0;
}
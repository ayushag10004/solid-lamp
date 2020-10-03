

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
const ll N = 200005;
ll a[N], b[N], last[N];

ll prnt(ll x)
{
	// cout<<x<<" "<<a[x]<<"--\n";

	if(a[x]==x)
		return x;
	else
		return a[x] = prnt(a[x]);
}

int main()
{
	ll n,m,i,x,y,aa,bb;

	s(n); s(m);

	for(i=1;i<=n;i++)
		a[i] = b[i] = i;

	for(i=1;i<=m;i++)
	{
		s(x); s(y);

		aa = prnt(x); 
		bb = prnt(y);

		// cout<<aa<<" "<<bb<<"\n";
		if(aa==bb)
			continue;

		if(aa>bb)
			swap(aa,bb);

		a[bb] = aa;
		b[aa] = max(b[aa],b[bb]);
	}

	ll ans = 0, item = 0, mid = 0;

	for(i=1;i<=n;i++)
	{
		if(a[i]==i)
			++mid, ++last[b[i]], ++item;

		mid-=last[i];

		if(mid==0)
			{
				ans+=(item-1);
				item = 0;
			}

	}

	cout<<ans<<"\n";

	return 0;
}
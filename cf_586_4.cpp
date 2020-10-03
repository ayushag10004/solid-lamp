

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

ll get(ll n)
{
	ll ans = 0;

	while(n%2==0)
	{
		++ans;
		n/=2;
	}

	return ans;
}

ll a[200005],b[200005],h[100],mm=0,mp=-1;
int main()
{
	ll n,i;
	s(n);

	for(i=1;i<=n;i++)
	{
		s(a[i]);
		b[i] = get(a[i]);
		++h[b[i]];

		if(h[b[i]] > mm)
		{
			mm = h[b[i]];
			mp = b[i];
		}
	}

	cout<<n-mm<<"\n";

	for(i=1;i<=n;i++)
	if(b[i]!=mp)
		cout<<a[i]<<" ";

	cout<<"\n";
	
	return 0;
}
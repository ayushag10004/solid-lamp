

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
ll a[200005],b[200005];
int main()
{	
	ll n,m,i,ans=0;

	s(n); s(m);

	for(i=1;i<=n;i++)
		s(a[i]);

	sort(a+1,a+n+1);

	for(i=1;i<=n;i++)
	{
		b[i] = a[i];

		if(i-m>=0)
			b[i]+=b[i-m];
	}

	ll last = 0;

	for(i=1;i<=n;i++)
	{
		last+=b[i];

		cout<<last<<" ";
	}

	return 0;
}
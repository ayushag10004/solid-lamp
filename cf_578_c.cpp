

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

int main()
{
	ll n,m,q;
	cin>>n>>m>>q;

	ll gg = __gcd(n,m);
	ll aa = n/gg, bb = m/gg;

	while(q--)
	{
		ll xa,xb,ya,yb;
		cin>>xa>>xb;
		cin>>ya>>yb;

		ll uu,vv;
		
		if(xa==1)
			uu = (xb-1)/aa + 1;
		else 
			uu = (xb-1)/bb + 1;

		if(ya==1)
			vv = (yb-1)/aa + 1;
		else 
			vv = (yb-1)/bb + 1;

		if(uu==vv)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	return 0;
}
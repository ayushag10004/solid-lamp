

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
	ll n,a,x,b,y,i;
	cin>>n>>a>>x>>b>>y;

	while(1)
	{
		if(a==b)
		{
			cout<<"YES\n";
			return 0;
		}

		if(a==x || b==y)
		{
			cout<<"NO\n";
			return 0;
		}
		
		++a;

		if(a==n+1)
			a = 1;

		--b;

		if(b==0)
			b = n;
	}

	return 0;
}
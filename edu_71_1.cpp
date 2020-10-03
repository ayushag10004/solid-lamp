

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
	ll t,b,p,f,h,c;
	s(t);

	while(t--)
	{
		ll ans = 0,hh;
		
		cin>>b>>p>>f;
		cin>>h>>c;
		b/=2;

		if(h>=c)
		{
			hh = min(b,p);
			b-=hh;
			ans+=hh*h;

			hh = min(b,f);
			b-=hh;
			ans+=hh*c;
		}
		else
		{
			hh = min(b,f);
			b-=hh;
			ans+=hh*c;

			hh = min(b,p);
			b-=hh;
			ans+=hh*h;
		}	

		cout<<ans<<"\n";
	}

	return 0;
}
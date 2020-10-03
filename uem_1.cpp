

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
	ll t;
	s(t);

	while(t--)
	{
		ll x,y;
		s(x); s(y);

		ll c=0,d=0;

		while( d%x!=0 || ( c%(2*x)==0 && d%(2*x)==0 ) )
		{
			c+=x;
			d+=y;
		}

		c%=(2*x);
		d%=(2*x);


		if(c==x && d==0)
			cout<<"Alice\n";
		else if(c==0 && d==x)
			cout<<"Camila\n";
		else
			cout<<"Bob\n";

	}
	return 0;
}
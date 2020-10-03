

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
	ll i,val,aa,bb,ans=0;

	cout<<"? ";
	for(i=1;i<=100;i++)
	{
		val = i;
		val = val<<7;
		cout<<val<<" ";
	}

	cout<<endl;
	fflush(stdout);
	cin>>aa;

	cout<<"? ";
	for(i=1;i<=100;i++)
	{
		val = i;
		// val = val<<7;
		cout<<val<<" ";
	}

	cout<<endl;
	fflush(stdout);
	cin>>bb;
	
	aa = aa&((1<<7) - 1);
	bb = bb>>7;
	bb = bb<<7;

	cout<<"! "<<aa+bb<<endl;
	return 0;
}
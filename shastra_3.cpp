
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
	ans=(ans*x);
	y/=2;
	x=(x*x);
  }
 
  return ans;
};
 
/******************************************************************************************************/

ll regular_3(ll n)
{
	if(n==0)
		return 0;

	ll max_pow = 0,mid = 1;

	while(mid<=n/3)
	{
		++max_pow;
		mid*=3;
	}

	ll ans1 = mul(2,max_pow) - 1;
	return ans1 + 1 + regular_3(min(n-mid,mid-1));
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll n;
		s(n);

		cout<<regular_3(n)<<"\n";
	}

	return 0;
}
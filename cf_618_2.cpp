
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
 
ll a[200005];
int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll n,i;
		s(n);

		for(i=1;i<=2*n;i++)
			s(a[i]);

		sort(a+1,a+2*n+1);

		cout<<a[n+1]-a[n]<<"\n";
	}
	return 0;
}
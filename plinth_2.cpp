
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
	ll n,m,c,i,x,y,z,sum1=0,sum2=0,mid;
	s(n); s(m); s(c);

	for(i=1;i<=n;i++)
	{
		s(x); s(y); s(z);
		mid = m*x + c - y;

		if(mid>0)
			sum1+=z;
		else
			sum2+=z;
	}

	cout<<max(sum1,sum2)<<"\n";

	return 0;
}
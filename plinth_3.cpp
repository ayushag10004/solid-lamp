
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
		ll n,k,mid,ans=-1,i;
		s(n); s(k);

		mid = ((k+1)*k)/2;

		for(i=1;i*i<=n;i++)
		if(n%i==0)
		{	
			if(i>=mid)
				ans = max(ans,n/i);

			if(n/i>=mid)
				ans = max(ans,i);
		}

		cout<<ans<<"\n";
	}
	return 0;
}
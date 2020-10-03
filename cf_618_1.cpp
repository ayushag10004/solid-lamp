
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
		ll n,i,cnt=0,sum=0,val,ans=0;
		s(n);

		for(i=1;i<=n;i++)
		{
			s(val);
			sum+=val;

			if(val==0)
				++cnt;
		}

		ans+=cnt;
		sum+=cnt;

		if(sum==0)
			++ans;

		cout<<ans<<"\n";
	}
	return 0;
}
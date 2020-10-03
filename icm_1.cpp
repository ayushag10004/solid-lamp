
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
 
ll a[100005];
int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,x;
		s(n); s(x);

		for(i=1;i<=n;i++)
			s(a[i]);

		sort(a+1, a+1+n);

		set<ll> ss;
		set<ll> :: iterator it;
		ss.insert(x);

		for(i=n;i>=1;i--)
		{
			it = ss.lower_bound(a[i]);
			
			while(it!=ss.end())
			{
				ss.insert((*it)%a[i]);
				++it;
			}
		}

		ll ans = 0;

		for(it=ss.begin();it!=ss.end();++it)
		if(*it < a[1])
			++ans;
		else
			break;

		cout<<ans<<"\n";
	}
	return 0;
}
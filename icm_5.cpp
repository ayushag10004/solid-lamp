
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

ld dx = 0.000000001,b,c;
ld calc(ld x)
{
	ld aa,bb;
	aa = x*x + b*x + c;
	bb = sin(x);
	// cout<<x<<" -- "<<aa<<" "<<bb<<"\n";
	return (ld)aa/bb;
}

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	s(t);
	cout<<fixed<<setprecision(10);

	while(t--)
	{
		cin>>b>>c;
		ll cnt = 300;
		ld lo = dx, hi = (ld)11/7, mid, ans, val, val1;
		// cout<<calc(1.57)<<"\n";
		while(lo<=hi && cnt>0)
		{
			mid = (lo+hi)/2;
			val = calc(mid);
			val1 = calc(mid+dx);

			// cout<<mid<<"  -->  "<<val<<"  "<<val1<<"\n";
			
			if(val1>val)
				hi = mid-dx;
			else
				lo = mid+dx;
			
			ans = val;
			--cnt;
		}

		cout<<ans<<"\n";
	}

	return 0;
}


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
	ll t,c=1;
	s(t);

	while(t--)
	{
		ll n,p,i,sum=0,ans;
		s(n); s(p);

		for(i=1;i<=n;i++)
			s(a[i]);
		
		sort(a+1,a+1+n);

		for(i=1;i<=p;i++)	
			sum+=a[i];

		ans = p*a[p] - sum;

		for(i=p+1;i<=n;i++)
		{
			sum-=a[i-p];
			sum+=a[i];

			ans = min(ans,p*a[i] - sum);
		}

		cout<<"Case #"<<c<<": "<<ans<<"\n";
		++c;
	}
	
	return 0;
}
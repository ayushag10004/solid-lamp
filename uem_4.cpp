

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

ll f[1000005];
int main()
{	
	ll t,i;
	s(t);

	f[0] = 1;
	for(i=1;i<=1000000;i++)
		f[i] = (f[i-1]*i)%MOD;

	while(t--)
	{
		ll n,m,k,r,ans;
		s(n); s(m); s(k);

		if(m<n*k)
		{
			cout<<"0\n";
			continue;
		}

		m-=(n*k);
		r=n; 
		n+=m;

		   ans = M( f[n] * mul(f[r],MOD-2) );
		   ans = M( ans * mul(f[n-r],MOD-2) );

		 cout<<ans<<"\n";  
	}
	return 0;
}
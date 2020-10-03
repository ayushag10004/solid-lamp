

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

ll mul(ll x,ll y,ll z)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%z;
	y/=2;
	x=(x*x)%z;
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
		ll n,val,i,sum=0,ans,k,j,l;
		ll a[1005],b[1005],c[1005];
		
		for(j=0;j<n;j++)
			a[j] = b[j] = c[j] = 0;

		a[1] = 1;
		s(n);
		s(k);

		for(i=1;i<=n;i++)
		{
			s(val);
			++b[val%n];	
		}

		ll mid = 1;

		for(i=0;i<40;i++)
		{	
			if(mid>k)
				break;

			mid*=2;

			if((k>>i)&1)
			{
				for(j=0;j<n;j++)
					c[j] = 0;

				for(j=0;j<n;j++)
				for(l=0;l<n;l++)
					c[(j*l)%n]+=(a[j]*b[l])%MOD,c[(j*l)%n]%=MOD;

				for(j=0;j<n;j++)
					a[j] = c[j];
			}

			for(j=0;j<n;j++)
				c[j] = 0;

			for(j=0;j<n;j++)
			for(l=0;l<n;l++)
				c[(j*l)%n]+=b[j]*b[l]%MOD,c[(j*l)%n]%=MOD;

			for(j=0;j<n;j++)
				b[j] = c[j];
		}

		for(i=0;i<n;i++)
			sum+=(a[i]*i)%MOD;

		sum%=MOD;
		val = mul(n,MOD-2,MOD);
		val = mul(val,k,MOD);
		ans = (sum*val)%MOD;
		
		printf("%lld\n",ans);
	}
	return 0;
}
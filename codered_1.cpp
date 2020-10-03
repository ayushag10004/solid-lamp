

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

ll ncr[1005][1005];
int main()
{
	ll i,j;

	ncr[0][0] = 1;

	for(i=1;i<=1001;i++)
	for(j=0;j<=i;j++)
	{
		if(j<=i-1)
			ncr[i][j] = M(ncr[i][j] + ncr[i-1][j]);

		if(j-1>=0 && j-1<=i-1)
			ncr[i][j] = M(ncr[i][j] + ncr[i-1][j-1]);
	}

	ll t;
	s(t);

	while(t--)
	{
		ll a,b,c;

		s(a); s(b); s(c);

		ll c_mul = 0;

		for(i=1;i<=c;i++)
			c_mul = M(c_mul + ncr[c][i]);

		ll aa = 0,bb = 0,ans = 0;

		for(i=2;i<=a;i++)
		{	
			aa = 0;
			aa = M(aa + ncr[a][i]);
			bb = M(bb + ncr[b][i-1]);

			ans = M(ans + M( M(aa*bb) * c_mul));
		}

		cout<<ans<<"\n";
	}

	return 0;
}


/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000007
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
	ll n,k,i;
	cin>>n>>k;

	for(i=1;i<=n;i++)
		cin>>a[i];

	sort(a+1,a+n+1);

	a[n+1] = MOD;
	ll in = n/2 + 1,cnt=1;

	ll ans = a[in],op;

	for(i=in+1;i<=n+1;i++)
	{	
		op = cnt*(a[i]-a[i-1]);
		
		if(k >= op)
		{
			k-=op;
			ans = a[i];
		}
		else
		{
			ans = a[i-1] + k/cnt;
			break;
		}

		++cnt;
	}

	cout<<ans<<"\n";
	
	return 0;
}
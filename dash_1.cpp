

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

ll a[105];
int main()
{
	ll n,i,j;
	cin>>n;

	for(i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n);

	ll ans=0;

	for(i=0;i<n;i++)
	if(a[i]!=-1)
	{
		for(j=i+1;j<n;j++)
			if(a[j]%a[i]==0)
				a[j]=-1;

		++ans;
	}

	cout<<ans<<"\n";
	return 0;
}
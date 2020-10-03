

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

ll p[2000005];
int main()
{
	ll i,j;
	for(i=2;i<=2000002;i++)
	if(p[i]==0)
		for(j=2*i;j<=2000002;j+=i)
			p[j] = 1;

	for(i=2;i<=2000002;i++)
	if(p[i]==0)
		p[i] = p[i-1]+1;
	else
		p[i] = p[i-1];

	ll t,n,k;
	cin>>t;

	while(t--)
	{
		cin>>n>>k;
		cout<<mul(k%MOD,p[n])<<"\n";
	}

	return 0;
}
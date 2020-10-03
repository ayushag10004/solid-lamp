

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

ll p[1205];
int main()
{	
	ll i,j;

	for(i=2;i<1201;i++)
	if(p[i]==0)
		for(j=2*i;j<1201;j+=i)
			p[j] = 1;

	ll n;
	cin>>n;

	for(i=1201;i>1;i--)
	if(p[i]==0)
		p[i]=i;
	else
		p[i] = p[i+1];

	ll m = p[n];

	cout<<m<<"\n";

	for(i=1;i<n;i++)
		cout<<i<<" "<<i+1<<"\n";

	cout<<n<<" "<<1<<"\n";

	m-=n;

	for(i=1;i<=n;i++)
	if(i%4==1 && m>0)
	{	
		cout<<i<<" "<<i+2<<"\n";
		--m;
	}
	else if(i%4==2 && m>0)
	{
		cout<<i<<" "<<i+2<<"\n";
		--m;
	}
	
	return 0;
}
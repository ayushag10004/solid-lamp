

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

ll a[1000005],b[1000005];
int main()
{
	string s;
	cin>>s;

	ll n=s.size(),i;

	for(i=1;i<n;i++)
	if(s[i]=='v' && s[i-1]=='v')
		a[i] = a[i-1] + 1;
	else
		a[i] = a[i-1];

	for(i=n-2;i>=0;i--)
	if(s[i]=='v' && s[i+1]=='v')
		b[i] = b[i+1] + 1;
	else
		b[i] = b[i+1];

	ll ans=0;
	for(i=0;i<n;i++)
	if(s[i]=='o')
		ans+=a[i]*b[i];

	cout<<ans<<"\n";
	
	return 0;
}
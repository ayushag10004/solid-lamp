

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
ll h[50];
int main()
{	string str;	
	ll n,i,ans=0,a;

	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>str;
		++h[str[0]-'a'];
	}

	for(i=0;i<26;i++)
	{
		a = h[i]/2;
		ans+=(a*(a-1))/2;

		a = h[i]-a;
		ans+=(a*(a-1))/2;
	}

	cout<<ans<<"\n";

	return 0;
}

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

ll x[100005],y[100005];
int main()
{	
	ll n,i,aa,bb,in;
	s(n);

	for(i=1;i<=n;i++)
		s(x[i]), s(y[i]);

	if(n%2)
	{
		cout<<"NO\n";
		return 0;
	}

	for(i=1;i<=n/2;i++)
	{
		aa = x[i+1] - x[i];
		bb = y[i+1] - y[i];

		in = i+(n/2);
		aa += (in!=n)?(x[in+1]-x[in]):(x[1]-x[n]);
		bb += (in!=n)?(y[in+1]-y[in]):(y[1]-y[n]);

		if(aa!=0 || bb!=0)
		{
			cout<<"NO\n";
			return 0;
		}
	}

	cout<<"YES\n";
	return 0;
}
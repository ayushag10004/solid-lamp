

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
	ll n,m,i,ans=0,j;
	s(n); s(m);

	n+=m;

	for(i=2;i<=n;i++)
	if(p[i]==0)
	{
		ans+=1;

		for(j=i;j<=n;j+=i)
			p[j] = 1;
	}

	cout<<ans<<"\n";

	return 0;
}


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

ll p[20000005];

ll func(ll n)
{
	if(n<=0)
		return 0;

	memset(p,0,sizeof p);

	ll cnt = 1,mid,j,i;

	for(i=2;i<=10000000;i++)
	if(p[i]==0)
	{
		mid = 1;

		while(n%i==0)
		{
			n/=i;
			++mid;
		}

		cnt*=mid;

		for(j=i*2;j<=10000000;j+=i)
			p[j] = 1;
	}

	if(n>1)
	{
		ll root = (ll)sqrtl(n);

		if(root*root==n)
			cnt*=3;
		else
			cnt*=2;	
	}

	return cnt;
}

int main()
{
	ll a,aa,bb,ans=-1;
	s(a);

	if(a==1)
		ans=-1;
	else if(a>1)
	{
		aa = func(a);
	    bb = func(a-1);
	    ans = aa*2*bb;
	}
	else if(a<0)
	{
		aa = func(abs(a));
		bb = func(abs(a)+1);
		ans = aa*bb*2;
	}

	cout<<ans<<"\n";
	return 0;
}
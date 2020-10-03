

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

ll p[1000005];

int main()
{
	ll n,i,cnt=0,pm=-1,j;
	s(n);

	if(n==1)
	{
		cout<<1<<"\n";
		return 0;
	}

	for(i=2;i<=1000002;i++)
	if(p[i]==0)
	{
		if(n%i==0)
		{
			++cnt;
			pm = i;
			while(n%i==0)
				n/=i;
		}

		for(j=i;j<=1000002;j+=i)
			p[j] = 1;
	}

	if(n>1)
		++cnt,pm=n;

	if(cnt>1)
		cout<<1<<"\n";
	else
		cout<<pm<<"\n";
	
	return 0;
}
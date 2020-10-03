

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

ll a[400005];

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,g=1,s=0,b=0;
		s(n);

		for(i=1;i<=n;i++)
			s(a[i]);

		for(i=2;i<=n;i++)
		if(a[i-1]!=a[i])
			break;
		else
			++g;

		if(g+1<=n)
		{	
			++s;
			for(i=g+2;i<=n;i++)
			if(a[i-1]==a[i] || s<=g)
				++s;
			else
				break;
		}

		if(g+s+1<=n)
		{
			++b;
			for(i=g+s+2;i<=n;i++)
			if(a[i-1]==a[i] || b<=g)
				++b;
			else
				break;
		}

		if(g+s+b<=(n/2) && g<s && g<b)
		{	
			ll last = g+s+b;
			for(i=g+s+b+1;i<=(n/2);i++)
			if(i+1<=n && a[i]>a[i+1])
				last = i;

			b+=(last-(g+s+b));
			cout<<g<<" "<<s<<" "<<b<<"\n";
		}
		else
			cout<<"0 0 0\n";

	}
	return 0;
}
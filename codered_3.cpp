

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

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll a[100],b[100],i,n,p;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		
		s(n); s(p);

		for(i=0;i<n;i++)
			s(a[i]);

		for(i=1;i<70;i++)
		{
			if(i<n && a[i]>a[i-1]*2)
				a[i] = a[i-1]*2;
			else if(i>=n)
				a[i] = a[i-1]*2;
		
		// cout<<i<<" "<<a[i]<<"\n";
		}

		for(i=70;i>=0;i--)
			if(a[i+1]>0)
				a[i] = min(a[i],a[i+1]);

		for(i=0;i<70;i++)
		{
			b[i] = p%2;
			p/=2;
		}	
		// cout<<"---\n";

		// for(i=0;i<70;i++)
		// {
		// 	// if(i<n && a[i]>a[i-1]*2)
		// 	// 	a[i] = a[i-1]*2;
		// 	// else if(i>=n)
		// 	// 	a[i] = a[i-1]*2;
		
		// cout<<i<<" "<<a[i]<<"\n";
		// }		
		ll ans = 0,in = 0,fin = 2e18;

		for(i=70;i>=0;i--)
			if(a[i]>0 && b[i]==0)
				fin = min(fin,ans+a[i]);
			else if(a[i]>0 && b[i]==1)
				ans+=a[i];

			fin = min(fin,ans);
		// while(p>0)	
		// {
		// 	if(p&1)
		// 		ans+=a[in];

		// 	++in;
		// 	p/=2;
		// }

		cout<<fin<<"\n";
	}
	return 0;
}
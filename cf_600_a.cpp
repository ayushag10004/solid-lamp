

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

ll a[100005], b[100005];
int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,f=0,last = -1;
		s(n);

		for(i=1;i<=n;i++)
			s(a[i]);

		for(i=1;i<=n;i++)
			s(b[i]);

		for(i=1;i<=n;i++)
		if(b[i]<a[i])
		{
			f = 1;
			break;
		}
		else if(last==-1 && b[i]==a[i])
			continue;
		else if(last==-1 && b[i]>a[i])
		{
			last = b[i] - a[i];
		}
		else if(last>0)
		{	
			if(a[i]==b[i])
				last = -2;
			else if(b[i]-a[i] == last)
				continue;
			else
			{
				f = 1;
				break;
			}
		}
		else if(last==-2 && a[i]!=b[i])
		{
			f = 1;
			break;
		}

		if(f==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
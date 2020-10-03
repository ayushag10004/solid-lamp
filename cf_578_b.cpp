

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
ll h[1000];
int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,m,k,i,f=0,lim;
		cin>>n>>m>>k;

		for(i=1;i<=n;i++)
			cin>>h[i];

		for(i=1;i<n;i++)
		{
			lim = max((ll)0,h[i+1]-k);

			if(h[i]>=lim)
				m+=h[i]-lim;
			else
			{
				if(h[i]+m>=lim)
					m-=(lim-h[i]);
				else
				{
					f = 1;
					break;
				}
			}

		}

		if(f==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
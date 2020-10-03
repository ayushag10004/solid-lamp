

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
ll a[300005],b[300005],h[300005];
int main()
{	
	ll n,m,i,x;
	cin>>n>>m;

	for(i=1;i<=m;i++)
		cin>>a[i]>>b[i];

	x = a[1];
	ll cnt=0;
	memset(h,0,sizeof h);

	for(i=1;i<=m;i++)
		if(a[i]!=x && b[i]!=x)
		{
			++cnt;

			++h[a[i]];
			++h[b[i]];
		}

	for(i=1;i<=n;i++)
	if(h[i]==cnt)
	{
		cout<<"YES\n";
			return 0;
	}	

	x = b[1];
	cnt=0;
	memset(h,0,sizeof h);

	for(i=1;i<=m;i++)
		if(a[i]!=x && b[i]!=x)
		{
			++cnt;

			++h[a[i]];
			++h[b[i]];
		}

	for(i=1;i<=n;i++)
	if(h[i]==cnt)
	{
		cout<<"YES\n";
			return 0;
	}

	cout<<"NO\n";

	return 0;
}
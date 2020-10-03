

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
ll a[105];
int main()
{
	ll n,i,cnt=0,tot=0,pc=1;
	cin>>n;

	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];

		if(i>1 && a[1]>=a[i]*2)
			tot+=a[i],++pc;
	}	

	tot+=a[1];

	if(tot>cnt/2)
	{
		cout<<pc<<"\n"<<1<<" ";

		for(i=2;i<=n;i++)
		if(a[1]>=a[i]*2)
			cout<<i<<" ";
	}
	else
		cout<<0<<"\n";

	return 0;
}


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
	ll n,i,sum=0,mx=0,val;

	cin>>n;

	for(i=1;i<=n;i++)
	{
		cin>>val;
		sum+=val;
		mx=max(mx,val);
	}

	// cout<<sum<<" "<<mx<<"\n";
	
	if(sum%2==1 || mx>sum/2)
		cout<<"NO\n";
	else
		cout<<"YES\n";

	return 0;
}
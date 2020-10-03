

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

string str;

ll check(ll in,ll n,string pt)
{
	ll i,size=pt.size();

	if(in+size > n)
		return 0;

	for(i=in;i<in+size;i++)
		if(str[i]!=pt[i-in])
			return 0;

	return 1;
}

int main()
{	
	ll t;
	cin>>t;

	while(t--)
	{
		cin>>str;
		vector<ll> ans;
		ll n = str.size(),i;

		for(i=0;i<n;i++)
		if(check(i,n,"twone"))
		{
			ans._pb(i+2);
			i+=4;
		}
		else if(check(i,n,"two"))
		{
			ans._pb(i+1);
			i+=2;
		}
		else if(check(i,n,"one"))
		{
			ans._pb(i+1);
			i+=2;
		}

		cout<<ans.size()<<"\n";
		for(i=0;i<ans.size();i++)
			cout<<ans[i]+1<<" ";
		cout<<"\n";

	}
	
	return 0;
}
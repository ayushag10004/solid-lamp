

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

ll go(string s,ll ln)
{
	ll cnt=0,ans=0,n=s.size(),i;

	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
			++cnt;

		if(i>=ln)
			if(s[i-ln]=='1')
				--cnt;

		if(i+1>=ln && cnt*cnt+cnt==ln)
			++ans;
	}

	return ans;
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		string s;
		cin>>s;

		ll n=s.size(),i,ans=0;

		for(i=1;i*i+i<=n;i++)
			ans+=go(s,i*i+i);

		cout<<ans<<"\n";
	}

	return 0;
}


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

map < pair< pair<ll,ll> ,ll > ,ll > mp;

ll func(ll m,ll n,ll k)
{	
	if(mp.find(_mp(_mp(m,n),k))!=mp.end())
		return mp[_mp(_mp(m,n),k)];

	if(n<0)
		return 0;

	if(m==0 && n==0)
		return 1;

	if(m!=0 && n==0)
		return 0;

	if(m==0 && n!=0)
		return 0;

	if(m%k!=0)
		return 0;

	ll ans  = ( func(m/k,n,k) | func(m/k-1,n-1,k) | func(m/k-2,n-2,k) );
	mp[_mp(_mp(m,n),k)] = ans;

	return ans; 
}

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,m,k,i;
		s(n); s(k); s(m); s(i);

		if(k==1)
		{
			if(m==n)
				cout<<"yes\n";
			else
				cout<<"no\n";

			continue;
		}

		if(m%k!=0)
		{
			m-=1;
			n-=1;
		}

		if(func(m,n,k))
			cout<<"yes\n";
		else
			cout<<"no\n";

	}
	return 0;
}
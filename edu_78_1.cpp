
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
		string a,b;
		cin>>a>>b;

		ll i,f=0,j;
		vector<ll> h(26,0);

		for(i=0;i<a.size();i++)
			++h[a[i]-'a'];

		for(i=0;i<b.size();i++)
		{	
			vector<ll> v(26,0);
			for(j=i;j<b.size();j++)
			{
				++v[b[j]-'a'];

				if(h==v)
					f = 1;
			}
		}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

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
		string str;
		cin>>str;

		if(str.size()<4)
			cout<<"NO\n";
		else
		{	
			ll n = str.size();
			if(str[n-1]=='0' && str[n-2]=='0' && str[n-3]=='0' && str[n-4]=='1')
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}

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
	ll n,m,i;
	s(n); s(m);

	string s[n],t[m];

	for(i=0;i<n;i++)
		cin>>s[i];

	for(i=0;i<m;i++)
		cin>>t[i];

	ll q,year;
	cin>>q;

	while(q--)
	{
		s(year);
		--year;

		cout<<s[year%n]<<t[year%m]<<"\n";
	}
	return 0;
}
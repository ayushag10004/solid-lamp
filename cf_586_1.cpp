

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
	ll n,i,a=0,b=0;
	s(n);
	string str;
	cin>>str;

	for(i=0;i<n;i++)
		if(str[i]=='z')
			++a;
		else if(str[i]=='n')
			++b;

	for(i=0;i<b;i++)
		cout<<1<<" ";

	for(i=0;i<a;i++)
		cout<<0<<" ";

	cout<<"\n";

	return 0;
}
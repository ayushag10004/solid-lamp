
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

		ll sum=0,i,f=0,g=0,mid;

		for(i=0;i<str.size();i++)
		{
			mid = str[i]-'0';

			if(mid==0)
				f = 1;

			sum+=mid;

			if(mid%2==0)
				++g;
		}

		if(f && g>=2 && sum%3==0)
			cout<<"red\n";
		else
			cout<<"cyan\n";
	}
	return 0;
}
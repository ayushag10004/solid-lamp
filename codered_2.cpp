

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

string cc = "codered";

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		string str;
		// cin>>str;

		ll size,i,j=0;

		cin>>size>>str;

		for(i=0;i<size;i++)
		if(j<7 && str[i]==cc[j])
		++j;

		if(j==7)
		cout<<"yes\n";
		else
		cout<<"no\n";	
	}
	return 0;
}
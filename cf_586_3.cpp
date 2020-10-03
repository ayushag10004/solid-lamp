

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

ll h[30];
int main()
{
	string str;
	ll i,j,n,f;

	cin>>str;

	n = str.size();
	
	for(i=0;i<n;i++)
	{	
		f = 0;

		for(j=0;j<str[i]-'a';j++)
		if(h[j]==1)
			f = 1;

		if(f==1)
			cout<<"Ann\n";
		else
			cout<<"Mike\n";

		h[str[i]-'a'] = 1;
	}

	return 0;
}


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

ll a[50];
int main()
{
	ll n,i,in,j;
	cin>>n;

	string str;
	cin>>str;

	for(i=0;i<n;i++)
	if(str[i]=='L')
	{
		for(j=1;j<=10;j++)
		if(a[j]==0)
		{
			a[j] = 1;
			break;
		}
	}
	else if(str[i]=='R')
	{
		for(j=10;j>=1;j--)
		if(a[j]==0)
		{
			a[j] = 1;
			break;
		}
	}
	else
	{
		in = str[i]-'0';
		a[in+1] = 0;
	}

	for(i=1;i<=10;i++)
		cout<<a[i];

	cout<<"\n";

	return 0;
}
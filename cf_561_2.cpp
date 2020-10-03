

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
	ll n,j,u,i,st;
	cin>>n;
	char cc[5] = {'a','e','i','o','u'};
	
	for(i=5;i<=n;i++)
	if(n%i==0 && i<=n/i)
	{	
		ll nn=n/i,mm=i;

		for(u=0;u<nn;u++)
		{
			st = u%5;
			for(j=0;j<mm;j++)
			{
				cout<<cc[st];
				++st;
				st%=5;
			}
		}

		return 0;
	}
	
	cout<<-1<<"\n";	
	return 0;
}
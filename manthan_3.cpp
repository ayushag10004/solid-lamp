

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
	ll n;
	s(n);

	ll dd[4] = {0,1,2,3};

	ll st = 0,rst,mid,j,i;

	for(i=0;i<n;i++)
	{	
		rst = st;
		for(j=0;j<n;j++)
		{
			mid = rst*4;

			if(j%2 && i%2)
				mid+=3;
			else if(j%2 && i%2==0)
				mid+=1;
			else if(j%2==0 && i%2)
				mid+=2;

			cout<<mid<<" ";

			if(j%2==1)
				++rst;
		}

		cout<<"\n";
		if(i%2==1)
			st+=n/2;
	}

	return 0;
}
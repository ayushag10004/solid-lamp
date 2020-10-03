
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
	ll r,c,i,j;
	s(r); s(c);

	if(r==1 && c==1)
		cout<<"0\n";
	else if(r==1 && c>1)
	{
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				cout<<j+1<<" ";
			cout<<"\n";
		}	
	}
	else if(r>1 && c==1)
	{
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				cout<<i+1<<" ";
			cout<<"\n";
		}	
	}
	else
	{
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				cout<<i*(r+j)<<" ";
			cout<<"\n";
		}	
	}

	return 0;
}
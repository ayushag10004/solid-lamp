
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
 
ll a[50],aa[100005];
int main()
{	
	ll n,i,j,val;
	s(n);

	for(i=1;i<=n;i++)
	{
		s(aa[i]);

		val = aa[i];
		for(j=0;j<40;j++)
		{
			a[j]+=(val%2);
			val/=2;
		}
	}

	ll mm = -1,in = -1,mid,tmp;

	for(i=1;i<=n;i++)
	{
		val = aa[i];
		mid = 0;
		tmp = 1;

		for(j=0;j<40;j++)
		{	
			if(val%2 && a[j]==1)
				mid+=tmp;

			val/=2;
			tmp*=2;
		}

		if(mid>mm)
		{
			mm = mid;
			in = i;
		}
	}

	cout<<aa[in]<<" ";
	
	for(i=1;i<=n;i++)
		if(i!=in)
			cout<<aa[i]<<" ";

	cout<<"\n";

	return 0;
}
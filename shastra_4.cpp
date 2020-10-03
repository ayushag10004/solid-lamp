
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

ll a[1000005],b[1000005],p[1000005],c[1000005],d[1000005]; 
int main()
{	
	a[1] = b[1] = 1;
	ll i,j,mid,pr,cnt;

	for(i=2;i<=1000005;i++)
	if(p[i]==0)	
	{
		for(j=i;j<=1000005;j+=i)
		if(p[j]==0)
			p[j] = i;
	}

	for(i=2;i<=1000002;i++)
	{	
		a[i] = i;
		b[i] = 1;

		mid = i;
		while(mid!=1)
		{
			pr = p[mid];
			cnt = 0;

			while(mid%pr==0)
				++cnt,mid/=pr;

			b[i] = b[i]*(cnt+1);
			a[i] = a[i]/pr;
			a[i] = a[i]*(pr-1);
		}
	}

	for(i=1;i<=1000000;i++)
	{
		c[i] = c[i-1];
		d[i] = d[i-1];

		if(a[i]>b[i])
			++c[i];

		if(a[i]<b[i])
			++d[i];

		// if(i<50)
		// 	cout<<i<<"-> "<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<"\n";
	}

	ll t;
	s(t);

	while(t--)
	{
		ll n,mid;
		s(n);

		mid = min(n,(ll)1000000);

		cout<<c[mid] + n - mid<<" "<<d[mid]<<"\n";
	}
	return 0;
}
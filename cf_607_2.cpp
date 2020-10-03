

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

char a[70][70];

ll check0(ll r,ll c)
{
	ll i,j;

	for(i=1;i<=r;i++)
	for(j=1;j<=c;j++)
		if(a[i][j]=='A')
			return 0;

	return 1;
}

ll check1(ll r,ll c)
{
	ll i,j;

	for(i=1;i<=r;i++)
	for(j=1;j<=c;j++)
		if(a[i][j]=='P')
			return 0;

	return 1;
}

ll check2(ll r,ll c)
{
	ll i,j,f;

	f = 0;
	for(j=1;j<=c;j++)
		if(a[1][j]=='P')
			f = 1;

	if(f==0)
		return 1;

	f = 0;
	for(j=1;j<=c;j++)
		if(a[r][j]=='P')
			f = 1;

	if(f==0)
		return 1;

	f = 0;
	for(j=1;j<=r;j++)
		if(a[j][1]=='P')
			f = 1;

	if(f==0)
		return 1;

	f = 0;
	for(j=1;j<=r;j++)
		if(a[j][c]=='P')
			f = 1;

	if(f==0)
		return 1;
	
	return 0;
}

ll check3(ll r,ll c)
{
	ll i,j,f;

	for(i=1;i<=r;i++)
	{
		f = 0;
		for(j=1;j<=c;j++)
			if(a[i][j]=='P')
				f = 1;

		if(f==0)
			return 1;
	}

	for(i=1;i<=c;i++)
	{
		f = 0;
		for(j=1;j<=r;j++)
			if(a[j][i]=='P')
				f = 1;

		if(f==0)
			return 1;
	}

	if(a[1][1]=='A' || a[1][c]=='A' || a[r][1]=='A' || a[r][c]=='A')
		return 1;

	return 0;
}

ll check4(ll r,ll c)
{
	ll i,j,f;

	f = 0;
	for(j=1;j<=c;j++)
		if(a[1][j]=='A' || a[r][j]=='A')
			f = 1;

	if(f==1)
		return 1;

	f = 0;
	for(j=1;j<=r;j++)
		if(a[j][1]=='A' || a[j][c]=='A')
			f = 1;

	if(f==1)
		return 1;

	return 0;
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll r,c,i,j;

		cin>>r>>c;
		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			cin>>a[i][j];

		if(check0(r,c))
		{
			cout<<"MORTAL\n";
			continue;
		}

		if(check1(r,c))
		{
			cout<<"0\n";
			continue;
		}

		if(check2(r,c))
		{
			cout<<"1\n";
			continue;
		}

		if(check3(r,c))
		{
			cout<<"2\n";
			continue;
		}

		if(check4(r,c))
		{
			cout<<"3\n";
			continue;
		}

		cout<<"4\n";
	}
	
	return 0;
}
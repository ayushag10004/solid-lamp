

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

ll a[100][100],b[100][100];
int main()
{
	ll n,m,i,j;
	cin>>n>>m;

	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		cin>>a[i][j];

	ll cnt = 0;

	for(i=1;i<n;i++)
	for(j=1;j<m;j++)
	if(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==4)
	{
		++cnt;
		b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
	}

	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(a[i][j]!=b[i][j])
	{
		cout<<-1<<"\n";
		return 0;
	}

	cout<<cnt<<"\n";

	for(i=1;i<n;i++)
	for(j=1;j<m;j++)
	if(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==4)
	{
		cout<<i<<" "<<j<<"\n";
		// ++cnt;
		// b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
	}
	return 0;
}
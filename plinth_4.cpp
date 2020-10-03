
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
ll dp[1000005][2];
vector < vector<ll> > v(1000005);

void go(ll x,ll y)
{
	ll size = v[x].size(),i,f=0,sum=0;
	dp[x][1] = 1;
	set<ll> ss;

	for(i=0;i<size;i++)
	if(v[x][i]!=y)
	{
		f = 1;
		go(v[x][i],x);
		sum+=dp[v[x][i]][1];
		ss.insert(-dp[v[x][i]][1]+dp[v[x][i]][0]);
	}

	if(f==1)
		dp[x][0] = sum + *ss.rbegin();

	dp[x][1] = max(dp[x][1],dp[x][0]);
	return;
}

int main()
{	
	ll n,i,x,y;
	s(n);

	for(i=1;i<n;i++)
	{
		s(x); s(y);
		v[x]._pb(y);
		v[y]._pb(x);
	}

	go(1,0);

	cout<<dp[1][1]<<"\n";
	return 0;
}
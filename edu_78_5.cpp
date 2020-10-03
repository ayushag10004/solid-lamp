
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

vector< vector < ll > > v(500005);
vector< vector < ll > > vv(500005);
vector< ll > fin;

void go(ll x, ll p)
{
	ll size = v[x].size(),i;

	for(i=0;i<size;i++)
	if(v[x][i]!=p)
		go(v[x][i],x);

	fin._pb(x);

	for(i=size-1;i>=0;i--)
	if(v[x][i]!=p)
		fin._pb(v[x][i]);

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

	fin._pb(1);
	go(1,0);

	for(i=0;i<2*n;i++)
		vv[fin[i]-1]._pb(i+1);

	for(i=0;i<n;i++)
		cout<<vv[i][0]<<" "<<vv[i][1]<<"\n";

	return 0;
}
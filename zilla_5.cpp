

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

#define in(x) x-'a'
/******************************************************************************************************/

ll seg[28][1000000];
ll lft[100005],rgt[100005];
vector< vector < ll > > v(100005);
char lbl[100005];

int main()
{
	ll n,q,i,x,y;
	s(n); s(q);

	for(i=1;i<n;i++)
	{
		s(x); s(y);

		v[x]._pb(y); 
		v[y]._pb(x);
	}

	for(i=1;i<=n;i++)
		cin>>ch[i];

	

	return 0;
}
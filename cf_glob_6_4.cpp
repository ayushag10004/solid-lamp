
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
 
ll a[100005];

int main()
{	
	ll n,m,i,x,y,z;
	s(n); s(m);

	for(i=1;i<=m;i++)
	{
		s(x); s(y); s(z);
		a[x]-=z;
		a[y]+=z;
	}

	vector <ll> neg,pos;

	for(i=1;i<=n;i++)
	if(a[i]<0)
		neg._pb(i),a[i]*=-1;
	else if(a[i]>0)
		pos._pb(i);

	vector< pair< pair<ll,ll>,ll > >ans;

	ll in1 = 0, in2 = 0, mid;

	while(in1<neg.size() && in2<pos.size())
	{
		x = neg[in1];
		y = pos[in2];
		mid = min(a[x],a[y]);

		a[x]-=mid;
		a[y]-=mid;

		ans._pb(_mp(_mp(x,y),mid));

		if(a[x]==0)
			++in1;

		if(a[y]==0)
			++in2;
	}

	cout<<ans.size()<<"\n";

	for(i=0;i<ans.size();i++)
		cout<<ans[i].ff.ff<<" "<<ans[i].ff.ss<<" "<<ans[i].ss<<"\n";

	return 0;
}
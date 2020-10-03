
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 100000000000000007
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

ll per[200005],cost[200005],seg[1000000],pen[1000000];

void update(ll ind,ll a,ll b,ll x,ll y,ll val)
{	
	if(pen[ind]!=0)
	{
		seg[ind]+=pen[ind];

		if(a!=b)
		{
			pen[ind*2]+=pen[ind];
			pen[ind*2+1]+=pen[ind];
		}

		pen[ind] = 0;
	}

	if(b<x || y<a)
		return;

	if(x<=a && b<=y)
	{
			seg[ind]+=val;
	
			if(a!=b)
			{
				pen[ind*2]+=val;
				pen[ind*2+1]+=val;
			}
		
		return;
	}

	ll mid = (a+b)/2;
	update(ind*2,a,mid,x,y,val);
	update(ind*2+1,mid+1,b,x,y,val);

	seg[ind] = min(seg[ind*2],seg[ind*2+1]);
	return;
}

int main()
{	
	ll n,i;
	s(n);

	// for(i=0;i<1000000;i++)
	// 	pen[i] = MOD;

	map<ll,ll> mp,in;
	for(i=1;i<=n;i++)
		s(per[i]),in[per[i]] = i;

	for(i=1;i<=n;i++)
		s(cost[i]),mp[per[i]] = cost[i];

	for(i=1;i<n;i++)
		update(1,1,n-1,i,n-1,cost[i]);

	ll mid=0,pos,fin=MOD;

	for(i=0;i<=n;i++)
	{	
		mid += mp[i];
		pos = in[i];

		if(1<=pos && pos<n)
			update(1,1,n-1,pos,n-1,-2*mp[i]);

		// cout<<i<<"->"<<mid<<" "<<seg[1]<<"\n";
		fin = min(fin,mid+seg[1]);
	}

	cout<<fin<<"\n";
	return 0;
}
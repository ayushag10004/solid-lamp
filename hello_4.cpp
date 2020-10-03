
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
	ll n,i,x,y,a,b;
	map<ll,vector< pair<ll,ll> > > astart,aend,bstart,bend;
	set<ll> ss,ss1;

	s(n);

	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>a>>b;

		astart[x]._pb(_mp(a,b));
		aend[y]._pb(_mp(a,b));
		bstart[a]._pb(_mp(x,y));
		bend[b]._pb(_mp(x,y));
		ss.insert(x);
		ss.insert(y);
		ss1.insert(a);
		ss1.insert(b);
	}

	ll pt;
	multiset<ll> aa,bb;
	set<ll> :: iterator it;

	for(it=ss.begin();it!=ss.end();++it)
	{
		pt = *it;

		if(astart.find(pt)!=astart.end())
		{
			for(i=0;i<astart[pt].size();++i)
				aa.insert(astart[pt][i].ff),bb.insert(astart[pt][i].ss);
		}

		if(!aa.empty() && !bb.empty() && *bb.begin()<*aa.rbegin())
		{
			cout<<"NO\n";
			return 0;
		}

		if(aend.find(pt)!=aend.end())
		{
			for(i=0;i<aend[pt].size();++i)
				aa.erase(aa.find(aend[pt][i].ff)),bb.erase(bb.find(aend[pt][i].ss));
		}
	}

	aa.clear();
	bb.clear();

	for(it=ss1.begin();it!=ss1.end();++it)
	{
		pt = *it;

		if(bstart.find(pt)!=bstart.end())
		{
			for(i=0;i<bstart[pt].size();++i)
				aa.insert(bstart[pt][i].ff),bb.insert(bstart[pt][i].ss);
		}

		if(!aa.empty() && !bb.empty() && *bb.begin()<*aa.rbegin())
		{
			cout<<"NO\n";
			return 0;
		}

		if(bend.find(pt)!=bend.end())
		{
			for(i=0;i<bend[pt].size();++i)
				aa.erase(aa.find(bend[pt][i].ff)),bb.erase(bb.find(bend[pt][i].ss));
		}
	}

	cout<<"YES\n";
	return 0;
}
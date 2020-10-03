
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
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,val;
		s(n);

		set< pair<ll,ll> > ss; 

		for(i=1;i<=n;i++)
		{
			s(val);
			ss.insert(_mp(val,i));
		}

		vector <pair<ll,ll> > vv;
		pair <ll,ll> pp,top;

		pp.ff = -1;

		while(!ss.empty())
		{
			top = *ss.begin();
			ss.erase(top);

			if(pp.ff==-1)
			{
				pp = top;
				continue;
			}

			if(pp.ff*2>=top.ff)
			{
				vv._pb(_mp(min(pp.ss,top.ss),max(pp.ss,top.ss)));
				pp.ff=-1;
				continue;
			}

			pp = top;
		}

		sort(vv.begin(),vv.end());

		cout<<vv.size()*2<<"\n";

		for(i=0;i<vv.size();i++)
			cout<<vv[i].ff<<" "<<vv[i].ss<<"\n";

	}
	return 0;
}
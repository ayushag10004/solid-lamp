

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
	ll n,i,last = 0,x;
	set<ll> ss,kk;
	vector<ll> v;

	s(n);

	for(i=1;i<=n;i++)
	{
		s(x);

		if(x>0)
		{
			if(ss.find(x)!=ss.end() || kk.find(x)!=kk.end())
			{
				cout<<-1<<"\n";
				return 0;
			}

			ss.insert(x);
			kk.insert(x);
		}
		else
		{
			if(ss.find(-x)==ss.end())
			{
				cout<<-1<<"\n";
				return 0;
			}

			ss.erase(-x);
		}

		if(ss.size()==0)
		{
			v._pb(i-last);
			last = i;
			kk.clear();
		}

	}

	if(!ss.empty())
	{
		cout<<-1<<"\n";
		return 0;
	}
	
	cout<<v.size()<<"\n";

	for(i=0;i<v.size();i++)
		cout<<v[i]<<" ";

	return 0;
}
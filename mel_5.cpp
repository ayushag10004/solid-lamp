

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
vector < pair<ll,ll> > v[1005];
ll a[1005];

int main()
{
	ll n,i,j,mid,val,fin=0;
	s(n);

	for(i=1;i<=n;i++)
		s(a[i]);

	vector< pair<ll,ll> > :: iterator it;

	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			mid = a[i]^a[j];
			val = 1;

			if(v[j].size()>0)
			{
				it = upper_bound(v[j].begin(),v[j].end(),_mp(mid,(ll)MOD));

				if(it!=v[j].begin())
				{
					--it;
					val += (*it).ss;
				}
			}

			v[i]._pb(_mp(mid,val));
			fin = max(fin,val);
		}

		sort(v[i].begin(),v[i].end());

		for(j=1;j<v[i].size();j++)
			v[i][j].ss = max(v[i][j].ss,v[i][j-1].ss);
	}

	cout<<fin+1<<"\n";
	return 0;
}
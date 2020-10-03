

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

ll n,m,size;
vector < pair<ll, pair<ll,ll> > > vv;
pair<ll, pair<ll,ll> > pp;

ll go(vector<ll> &pos, vector<ll> &hs, ll sum, ll in,ll cnt)
{
	if(in==size)
		return sum;

	ll i;

	for(i=in;i<size;i++)
	{
		pp = vv[i];
		rr = pp.ss.ff;
		cc = pp.ss.ss;

		for(j=1;j<=n;j++)
			if(hs[j]==0)
			{
				if(pos[cc]==0)
				{
					pos[cc] = j;
					sum+=pp.ff;

					
				}	
				else
				{

				}
			}
	}

	return -1;
}

int main()
{
	ll t,i,j,val;
	s(t);

	while(t--)
	{
		s(n); s(m);
		vv.clear();

		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
				s(val); 
				vv._pb(_mp(val,_mp(i,j)));
			}

		size = vv.size();
		sort(vv.begin(),vv.end());
		vector<ll> pos(m+1,0),hs(n+1,0);

		cout<<go(pos,hs,0,0,0)<<"\n";	
	}
	return 0;
}
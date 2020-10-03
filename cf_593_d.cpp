

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

vector < set < ll > > rr(100005),cc(100005);

int main()
{
	ll n,m,k,i,j;
	s(n); s(m); s(k);

	for(i=1;i<=k;i++)
	{
		s(x); s(y);

		rr[x].insert(y);
		cc[y].insert(x);
	}

	ll xx = 1,yy = 1;
	ll rmin=0,rmax=n+1,cmin=0,cmax=m+1;
	ll dd = 1;

	while(1)
	{
		if(dd==1)
		{
			uu = rr[xx].upper_bound(yy);
			
			if(uu!=rr[xx].end() && *uu<cmax)
			{
				for(i=xx;i<rmax;i++)
					for(j=*uu;j<cmax;j++)
						if(rr[i].find(j)==rr[i].end())
						{
							cout<<"No\n";
							return 0;
						}
				
				yy = uu-1;
				cmax = uu;
			}
			else
			{
				yy = cmax-1;
			}

			++rmin;
			dd = 2;
		}
		else if(dd==2)
		{
			uu = cc[yy].upper_bound(xx);
			
			if(uu!=cc[yy].end() && *uu<rmax)
			{
				for(i=*uu;i<rmax;i++)
					for(j=cmin+1;j<cmax;j++)
						if(rr[i].find(j)==rr[i].end())
						{
							cout<<"No\n";
							return 0;
						}
				
				xx = uu-1;
				rmax = uu;
			}
			else
			{
				xx = rmax-1;
			}

			--cmax;
			dd = 3;	
		}
		else if(dd==3)
		{
			uu = rr[xx].upper_bound(yy);
			
			if(uu!=rr[xx].begin())
				--uu;
			
			if(uu!=rr[xx].end() && *uu<cmax)
			{
				for(i=xx;i<rmax;i++)
					for(j=*uu;j<cmax;j++)
						if(rr[i].find(j)==rr[i].end())
						{
							cout<<"No\n";
							return 0;
						}
				
				yy = uu-1;
				cmax = uu;
			}
			else
			{
				yy = cmax-1;
			}

			++rmin;
			dd = 2;
		}
	}
	return 0;
}
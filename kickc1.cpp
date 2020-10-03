

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
ll x[305],y[305],tx[305],ty[305];
int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{
		ll n,q,i;
		s(n); s(q);

		for(i=1;i<=q;i++)
			s(x[i]),s(y[i]);

		ll lo = 0,hi = n,mid,ans,it,f,in;

		while(lo<=hi)
		{
			mid = (lo+hi)/2;

			it = q;
			// cout<<mid<<"\n";

			for(i=1;i<=q;i++)
				tx[i] = x[i],ty[i] = y[i];

			while(it>0)
			{	
				// cout<<it<<"-->\n";
				ll cnt[305];
				memset(cnt,0,sizeof cnt);	

				set< pair<ll,ll> > open,close;
				set<ll> pts,curr;

				for(i=1;i<=q;i++)
				if(tx[i]!=-1)
				{
					open.insert(_mp(tx[i],i));
					close.insert(_mp(ty[i],i));
					pts.insert(tx[i]);
					pts.insert(ty[i]);
				}	

				ll pt=0,last_pt=0;
				pair<ll,ll> pp;

				while(!pts.empty())
				{	
					last_pt = pt;
					pt = *pts.begin();
					pts.erase(pt);

					if(curr.size()==1)
					{	
						in = *curr.begin();
						cnt[in]+=(pt-last_pt-1);	
					}

					while(!open.empty())
					{
						pp = *open.begin();

						if(pp.ff==pt)
						{
							curr.insert(pp.ss);
							open.erase(pp);
						}
						else
							break;
					}

					if(curr.size() == 1)
					{
						++cnt[*curr.begin()];
					}

					while(!close.empty())
					{
						pp = *close.begin();

						if(pp.ff==pt)
						{
							curr.erase(pp.ss);
							close.erase(pp);
						}
						else
							break;
					}
				}

				f = 0;

				// for(i=1;i<=q;i++)
				// cout<<tx[i]<<" "<<ty[i]<<"**"<<cnt[i]<<"\n";

				for(i=1;i<=q;i++)
				if(tx[i]!=-1 && cnt[i]>=mid)
				{
					tx[i] = ty[i] = -1;
					f = 1;
					break;
				}	

				if(f==0)
					break;

				--it;
			}

			if(f==1)
				ans = mid,lo = mid+1;
			else
				hi = mid-1;
		}

		cout<<"Case #"<<g<<": "<<ans<<"\n";
		++g;
	}
	return 0;
}
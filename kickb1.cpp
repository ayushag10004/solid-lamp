

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
char cc[255][255];
ll dp[255][255];
int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{	
		memset(dp,-1,sizeof dp);
		ll r,c,i,j;
		s(r); s(c);

		queue< pair<ll,ll> > qq;
		pair<ll,ll> pp;

		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)	
		{
			cin>>cc[i][j];

			if(cc[i][j]=='1')
			{
				dp[i][j] = 0;
				qq.push(_mp(i,j));
			}
		}

		ll dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0},xx,yy;

		while(!qq.empty())
		{
			pp = qq.front();
			qq.pop();

			for(i=0;i<4;i++)
			{
				xx = pp.ff+dx[i];
				yy = pp.ss+dy[i];
				
				if(1<=xx && xx<=r && 1<=yy && yy<=c && (dp[xx][yy]==-1 || dp[xx][yy]>dp[pp.ff][pp.ss]+1))
				{
					dp[xx][yy] = dp[pp.ff][pp.ss]+1;
					qq.push(_mp(xx,yy));
				}
			}

		}

		set< pair<ll, pair<ll,ll> > > sss;

		for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			sss.insert(_mp(dp[i][j],_mp(i,j)));	

		// for(i=1;i<=r;i++)
		// {
		// 	for(j=1;j<=c;j++)
		// 		cout<<dp[i][j]<<" . ";
		// 	cout<<"\n";
		// }

		vector< pair<ll,ll> > vv;
		pair<ll,pair<ll,ll> > ppp;

		while(!sss.empty())
		{	
			ppp = *sss.begin();
			sss.erase(ppp);
			vv._pb(ppp.ss);
		}

		ll lo = 0,hi = 90000,mid,ans,sz = vv.size();
		ll px = vv[sz-1].ff, py = vv[sz-1].ss;
		ll lim = dp[px][py],rdist,dist,f,tx,ty,k;

		while(lo<=hi)
		{
			mid = (lo+hi)/2;

			if(mid>=lim)
				ans=mid,hi=mid-1;
			else
			{
				for(i=px-mid;i<=px+mid;i++)
				if(1<=i && i<=r)	
				{
					rdist = mid - abs(i-px);
					
					for(j=py-rdist;j<=py+rdist;j++)
					if(1<=j && j<=c)
					{
						f = 0;

						for(k=sz-1;k>=0;k--)
						{
							tx = vv[k].ff,ty = vv[k].ss;

							if(dp[tx][ty]>mid)
							{
								dist = abs(tx-i) + abs(ty-j);

								if(dist>mid)
								{
									f = 1;
									break;
								}
							}
							else
								break;
						}

						if(f==0)	
						{
							ans = mid,hi=mid-1;
							break;
						}
					}

					if(f==0)
						break;
				}

				if(f==1)
					lo = mid+1;
			}
		}

		cout<<"Case #"<<g<<": "<<ans<<"\n";
		++g;
	}
	return 0;
}
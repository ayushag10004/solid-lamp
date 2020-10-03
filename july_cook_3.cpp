

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

ll ed[100005][3],pp[100005][2],fin[100005];

ll prnt(ll x)
{
	if(pp[x][0]==0)
	{
		pp[x][0] = x;
		pp[x][1] = 1;
		return x;
	}

	if(pp[x][0]==x)
		return x;
	else
		return pp[x][0] = prnt(pp[x][0]);
}

ll pt(ll x)
{
	return (x*(x-1))/2;
}

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,x,y,z,in,mid,pr1,pr2,j,k;
		s(n);
		memset(fin,0,sizeof fin);

		vector < vector<ll> > v(100005);

		for(i=1;i<n;i++)
		{
			cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

			v[ed[i][2]]._pb(i);
		}

		for(i=1;i<=100001;i++)
		{	
			mid = 0;

			for(j=i;j<=100001;j+=i)
			if(v[j].size()>0)
			{
				for(k=0;k<v[j].size();k++)
				{
					in = v[j][k];

					pr1 = prnt(ed[in][0]);
					pr2 = prnt(ed[in][1]);

					if(pr1!=pr2)
					{
						mid-=pt(pp[pr1][1]);
						mid-=pt(pp[pr2][1]);

						pp[pr2][0] = pr1;
						pp[pr1][1] += pp[pr2][1];
						mid+=pt(pp[pr1][1]);
					}

				}
			}

			fin[i] = mid;

			for(j=i;j<=100001;j+=i)
			if(v[j].size()>0)
			{
				for(k=0;k<v[j].size();k++)
				{
					in = v[j][k];

					pp[ed[in][0]][0] = pp[ed[in][0]][1] = 0;
					pp[ed[in][1]][0] = pp[ed[in][1]][1] = 0;
				}
			}
		}

		ll ans = 0;

		for(i=100001;i>=1;i--)
		{
			for(j=i*2;j<=100001;j+=i)
				fin[i]-=fin[j];

			ans+=i*fin[i];
		}

		cout<<ans<<"\n";
	}
	return 0;
}
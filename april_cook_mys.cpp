

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

vector< vector<ll> > v;
ll sz[200005],n;

ll dfs(ll x,ll y)
{
	ll size = v[x].size(),i,ch=x,ch1=-1;
	sz[x] = 1;

	for(i=0;i<size;i++)
		if(v[x][i]!=y && v[x][i]!=-1)
		{
			ch1 = max(ch1,dfs(v[x][i],x));
			sz[x]+=sz[v[x][i]];

			if(sz[v[x][i]]>n/2)
				ch = -1;
		}

	if(n-sz[x]>n/2)
		ch = -1;

	return max(ch,ch1);	
}

ll dfs1(ll x,ll y)
{
	ll size=v[x].size(),i,cnt=1;

	for(i=0;i<size;i++)
		if(v[x][i]!=y && v[x][i]!=-1)
			cnt+=dfs1(v[x][i],x);

	return cnt;		
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll x,y,i;
		s(n);

		v.clear();
		v.resize(n+1);
		for(i=1;i<n;i++)
		{	
			s(x); s(y);
			v[x]._pb(y);
			v[y]._pb(x);
		}

		ll qans = 1,cent,mid,fin=-1,size;

		while(1)
		{
			cent = dfs(qans,0);
			cout<<1<<" "<<cent<<"\n";
			cin>>mid;

			if(mid==-1)
			{
				fin = cent;
				break;
			}

			size = v[mid].size();

			for(i=0;i<size;i++)
				if(v[mid][i]==cent)
				{
					v[mid][i] = -1;
					break;
				}

			n = dfs1(mid,0);	
			qans = mid;	
			fflush(stdout);
		}

		cout<<2<<" "<<fin<<"\n";
		cin>>mid;
		fflush(stdout);
	}
	return 0;
}

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

ll p[1005],n;

ll prnt(ll x)
{
	if(p[x]==x)
		return x;
	else
		return p[x] = prnt(p[x]);
}

void go(vector < pair<ll,ll> > &v)
{
	ll size = v.size(),i,f=0;
	vector< vector<ll> > vv(n+1);
	set<ll> ver,ver1;
	map<ll,ll> mp;
	cout<<"go----\n";

	for(i=0;i<size;i++)
	{
		cout<<v[i].ff<<" "<<v[i].ss<<"\n";
		vv[v[i].ff]._pb(v[i].ss);
		vv[v[i].ss]._pb(v[i].ff);
		ver.insert(v[i].ff);
		ver.insert(v[i].ss);
	}

	ver1 = ver;
	queue<ll> qq;
	ll top,in,size1,mid;

	while(!ver.empty())
	{
		top = *ver.begin();
		ver.erase(top);
		cout<<"top->"<<top<<"\n";
		if(mp.find(top)!=mp.end())
			continue;

		mp[top] = 0;
		qq.push(top);

		while(!qq.empty())
		{
			in = qq.front();
			qq.pop();
			cout<<"in "<<in<<"\n";
			size1 = vv[in].size();

			for(i=0;i<size1;i++)
			{	
				mid = vv[in][i];

				if(mp.find(mid)!=mp.end())
				{
					if(mp[mid]!=mp[in]^1)
					{
						f = 1;
						break;
					}

					continue;
				}

				mp[mid] = mp[in]^1;
				qq.push(mid);
			}

			if(f==1)
				break;
		}

		if(f==1)
			break;
	}

	ll xx,yy;

	if(f==1)
	{	
		cout<<"yes\n";
		for(i=0;i<size;i++)
		{
			xx = prnt(v[i].ff);
			yy = prnt(v[i].ss);

			if(xx!=yy)
				p[yy] = xx;
		}

		return;
	}

	ll last0 = -1, last1 = -1;
	
	while(!ver1.empty())
	{
		mid = *ver1.begin();
		ver1.erase(mid);

		if(mp[mid]==0 && last0 == -1)
			{
				last0 = mid;
				continue;
			}

	   if(mp[mid]==1 && last1 == -1)
			{
				last1 = mid;
				continue;
			}

		if(mp[mid]==0)
		{
			xx = prnt(last0);
			yy = prnt(mid);

			if(xx!=yy)
				p[yy] = xx;
		}	
		else if(mp[mid]==1)
		{
			xx = prnt(last1);
			yy = prnt(mid);

			if(xx!=yy)
				p[yy] = xx;
		}	

	}

	return;
}

int main()
{	
	ll i,j,x[1005],y[1005],dd;
	s(n);

	for(i=1;i<=n;i++)
	{
		p[i] = i;
		s(x[i]); s(y[i]);
	}		

	map < ll, vector< pair<ll,ll> > > mp;

	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	{
		dd = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
		mp[dd]._pb(_mp(i,j));
	}

	map < ll, vector< pair<ll,ll> > > :: iterator it;

	for(it=mp.begin();it!=mp.end();++it)
		{
			cout<<"dist "<<it->ff<<"\n";
			go(it->ss);	

		}

	vector<ll> ans;

	for(i=1;i<=n;i++)
	{
		p[i] = prnt(i);

		if(p[i]==1)
			ans._pb(i);
	}

	cout<<ans.size()<<"\n";

	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";

	cout<<"\n";
	return 0;
}
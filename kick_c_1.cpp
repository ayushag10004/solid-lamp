

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
	ll t,g=1;
	cin>>t;

	while(t--)
	{
		ll n,r,c,i,x,y,xx,yy;
		cin>>n>>r>>c>>x>>y;

		vector < set<ll> > rs(r+1),re(r+1),cs(c+1),ce(c+1);
		rs[x].insert(y);
		re[x].insert(y);
		cs[y].insert(x);
		ce[y].insert(x);
		set<ll> :: iterator it;
		string str;
		cin>>str;

		for(i=0;i<n;i++)
		{
			if(str[i]=='S')
			{	
				// it = rs[x].begin();

				// while(it!=rs[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = re[x].begin();

				// while(it!=re[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = cs[y].begin();

				// while(it!=cs[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = ce[y].begin();

				// while(it!=ce[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"--------------------------------------------\n";

				it = ce[y].lower_bound(x);
				xx = *it + 1;
				yy = y;

				if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					ce[yy].erase(xx-1);
					cs[yy].erase(xx+1);
				}
				else if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].erase(xx-1);
					ce[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					cs[yy].erase(xx+1);
					cs[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].insert(xx);
					cs[yy].insert(xx);
				}


				if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					re[xx].erase(yy-1);
					rs[xx].erase(yy+1);
				}
				else if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].erase(yy-1);
					re[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					rs[xx].erase(yy+1);
					rs[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].insert(yy);
					rs[xx].insert(yy);
				}
			}
			else if(str[i]=='N')
			{	
				// it = rs[x].begin();

				// while(it!=rs[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = re[x].begin();

				// while(it!=re[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = cs[y].begin();

				// while(it!=cs[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = ce[y].begin();

				// while(it!=ce[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"--------------------------------------------\n";

				it = cs[y].upper_bound(x);
				--it;
				xx = *it - 1;
				yy = y;

				if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					ce[yy].erase(xx-1);
					cs[yy].erase(xx+1);
				}
				else if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].erase(xx-1);
					ce[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					cs[yy].erase(xx+1);
					cs[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].insert(xx);
					cs[yy].insert(xx);
				}


				if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					re[xx].erase(yy-1);
					rs[xx].erase(yy+1);
				}
				else if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].erase(yy-1);
					re[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					rs[xx].erase(yy+1);
					rs[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].insert(yy);
					rs[xx].insert(yy);
				}
			}
			else if(str[i]=='E')
			{	
				// it = rs[x].begin();

				// while(it!=rs[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = re[x].begin();

				// while(it!=re[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = cs[y].begin();

				// while(it!=cs[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = ce[y].begin();

				// while(it!=ce[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"--------------------------------------------\n";

				it = re[x].lower_bound(y);
				yy = *it + 1;
				xx = x;

				// cout<<xx<<"**"<<yy<<"\n";
				if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					ce[yy].erase(xx-1);
					cs[yy].erase(xx+1);
				}
				else if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].erase(xx-1);
					ce[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					cs[yy].erase(xx+1);
					cs[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].insert(xx);
					cs[yy].insert(xx);
				}


				if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					re[xx].erase(yy-1);
					rs[xx].erase(yy+1);
				}
				else if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].erase(yy-1);
					re[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					rs[xx].erase(yy+1);
					rs[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].insert(yy);
					rs[xx].insert(yy);
				}
			}
			else if(str[i]=='W')
			{	
				// it = rs[x].begin();

				// while(it!=rs[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = re[x].begin();

				// while(it!=re[x].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = cs[y].begin();

				// while(it!=cs[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"\n";

				// it = ce[y].begin();

				// while(it!=ce[y].end())
				// {
				// 	cout<<*it<<" ";
				// 	++it;
				// }

				// cout<<"--------------------------------------------\n";

				it = rs[x].upper_bound(y);
				--it;
				yy = *it - 1;
				xx = x;

				if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					ce[yy].erase(xx-1);
					cs[yy].erase(xx+1);
				}
				else if(ce[yy].find(xx-1)!=ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].erase(xx-1);
					ce[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)!=cs[yy].end())
				{
					cs[yy].erase(xx+1);
					cs[yy].insert(xx);
				}
				else if(ce[yy].find(xx-1)==ce[yy].end() && cs[yy].find(xx+1)==cs[yy].end())
				{
					ce[yy].insert(xx);
					cs[yy].insert(xx);
				}


				if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					re[xx].erase(yy-1);
					rs[xx].erase(yy+1);
				}
				else if(re[xx].find(yy-1)!=re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].erase(yy-1);
					re[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)!=rs[xx].end())
				{
					rs[xx].erase(yy+1);
					rs[xx].insert(yy);
				}
				else if(re[xx].find(yy-1)==re[xx].end() && rs[xx].find(yy+1)==rs[xx].end())
				{
					re[xx].insert(yy);
					rs[xx].insert(yy);
				}
			}

			// cout<<"--"<<xx<<" "<<yy<<"\n";
			x = xx;
			y = yy;
		}

		cout<<"Case #"<<g<<": "<<x<<" "<<y<<"\n";
		++g;
	}
	return 0;
}


/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000000007
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

ll rmin[200005],rmax[200005],amin[200005],amax[200005],lft[200005],rgt[200005];
int main()
{
	ll n,m,k,q,i,val,lim=0,aa,bb,x,y;
	cin>>n>>m>>k>>q;

	for(i=1;i<=k;i++)
	{
		cin>>x>>y;

		if(rmin[x]==0)
			rmin[x] = y;

		if(rmax[x]==0)
			rmax[x] = y;

		lim = max(lim,x);

		rmin[x] = min(rmin[x],y);
		rmax[x] = max(rmax[x],y);
	}

	for(i=1;i<=q;i++)
		{
			cin>>val;
			lft[val] = val;
			rgt[val] = val;
		}

	for(i=1;i<=m;i++)
	if(lft[i]==0)
		lft[i] = lft[i-1];

	for(i=m;i>=1;i--)
	if(rgt[i]==0)
		rgt[i] = rgt[i+1];

	// for(i=1;i<=m;i++)
	// 	cout<<i<<" "<<lft[i]<<" "<<rgt[i]<<"\n";

	if(rmin[1]==0)
		rmin[1] = rmax[1] = 1;
	else
		{
			amin[1] = rmax[1] - 1 + rmax[1] - rmin[1];
			amax[1] = rmax[1] - 1;
		}

	// cout<<1<<"->"<<rmin[1]<<" "<<amin[1]<<" : "<<rmax[1]<<" "<<amax[1]<<"\n";
		
	for(i=2;i<=lim;i++)
	if(rmin[i]==0)
	{
		rmin[i] = rmin[i-1];
		rmax[i] = rmax[i-1];
		amin[i] = amin[i-1] + 1;
		amax[i] = amax[i-1] + 1;
		// cout<<i<<"->"<<rmin[i]<<" "<<amin[i]<<" : "<<rmax[i]<<" "<<amax[i]<<"\n";
	}
	else
	{	
		amin[i] = amax[i] = MOD;

		aa = lft[rmin[i-1]];
		bb = rgt[rmin[i-1]];
		
		// cout<<aa<<" "<<bb<<"\n";
		if(aa!=0)
		{	
			// cout<<"aa1\n";
			amax[i] = min(amax[i], 1 + abs(rmin[i-1] - aa) + abs(rmin[i] - aa) + rmax[i] - rmin[i] + amin[i-1]);
			amin[i] = min(amin[i], 1 + abs(rmin[i-1] - aa) + abs(rmax[i] - aa) + rmax[i] - rmin[i] + amin[i-1]);
		}

		if(bb!=0)
		{	
			// cout<<"aa2\n";
			amax[i] = min(amax[i], 1 + abs(rmin[i-1] - bb) + abs(rmin[i] - bb) + rmax[i] - rmin[i] + amin[i-1]);
			amin[i] = min(amin[i], 1 + abs(rmin[i-1] - bb) + abs(rmax[i] - bb) + rmax[i] - rmin[i] + amin[i-1]);
		}

		aa = lft[rmax[i-1]];
		bb = rgt[rmax[i-1]];
		// cout<<aa<<" "<<bb<<"\n";
		if(aa!=0)
		{	
			// cout<<"aa3\n";
			amax[i] = min(amax[i], 1 + abs(rmax[i-1] - aa) + abs(rmin[i] - aa) + rmax[i] - rmin[i] + amax[i-1]);
			amin[i] = min(amin[i], 1 + abs(rmax[i-1] - aa) + abs(rmax[i] - aa) + rmax[i] - rmin[i] + amax[i-1]);
		}

		if(bb!=0)
		{	
			// cout<<"aa4\n";
			amax[i] = min(amax[i], 1 + abs(rmax[i-1] - bb) + abs(rmin[i] - bb) + rmax[i] - rmin[i] + amax[i-1]);
			amin[i] = min(amin[i], 1 + abs(rmax[i-1] - bb) + abs(rmax[i] - bb) + rmax[i] - rmin[i] + amax[i-1]);
		}

		// cout<<i<<"->"<<rmin[i]<<" "<<amin[i]<<" : "<<rmax[i]<<" "<<amax[i]<<"\n";
	}

	cout<<min(amin[lim],amax[lim])<<"\n";
	return 0;
}
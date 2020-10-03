

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

ll bit[100005],bit1[100005],q[100005][3];

void update(ll x,ll val)
{
	while(x<=100003)
	{
		bit[x]+=val;
		x+=(x&(-x));
	}

	return;
}

ll query(ll x)
{
	ll ans = 0;

	while(x>0)
	{
		ans+=bit[x];
		x-=(x&(-x));
	}

	return ans;
}

void update1(ll x,ll val)
{
	while(x<=100003)
	{
		bit1[x]+=val;
		x+=(x&(-x));
	}

	return;
}

ll query1(ll x)
{
	ll ans = 0;

	while(x>0)
	{
		ans+=bit1[x];
		x-=(x&(-x));
	}

	return ans;
}

ll check_pos(ll in)
{	
	// cout<<in<<"********\n";
	ll lo=0,hi=100002,mid,ans,cnt;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		cnt = query(mid);

		if(cnt<in)
			lo = mid+1;
		else if(cnt>in)
			hi = mid-1;
		else
			ans = mid,hi=mid-1;
	}

	// cout<<in<<"--------"<<ans<<"\n";
	return ans;
}

int main()
{	
	ll n,i;
	cin>>n;

	set<ll> ss;
	map<ll,ll> mp;

	for(i=1;i<=n;i++)
	{
		cin>>q[i][1]>>q[i][2];
		ss.insert(q[i][2]);
	}

	ll in=1,mid;

	while(!ss.empty())
	{
		mid = *ss.begin();
		ss.erase(mid);
		mp[mid] = in;
		++in;
	}

	ll nn,ans1,ans2,xx;

	for(i=1;i<=n;i++)
	{
		if(q[i][1]==1)
			update(mp[q[i][2]],1),update1(mp[q[i][2]],q[i][2]);
		else if(q[i][1]==2)
			update(mp[q[i][2]],-1),update1(mp[q[i][2]],-q[i][2]);
		else
		{
			mid = q[i][2];
			update(mp[mid],-1);
			update1(mp[mid],-mid);

			nn = query(100002);

			ans1=0;
			if(query(mp[mid]-1)>0)
			{	
				in = check_pos((nn/2)+1);
				xx = (query1(in)-query1(in-1));
				ans1 = mid;
				ans1 += 2*(query1(100002)-query1(in)-query1(in-1));

				if(nn%2==1)
					ans1-=xx;
				else
					ans1+=xx;

				// cout<<i<<"--> left "<<in<<" "<<ans1<<"\n";
			}

			ans2=0;
			if(query(100002)-query(mp[mid])>0)
			{
				if(nn%2)
					in = check_pos((nn/2)+1);
				else
					in = check_pos((nn/2));

				xx = (query1(in)-query1(in-1));
				ans2 =  - mid;
				ans2 += 2*(query1(100002)-query1(in)-query1(in-1));
				
				if(nn%2==1)
					ans2+=xx;
				else
					ans2-=xx;

				// cout<<i<<"--> right "<<in<<" "<<ans2<<"\n";
			}

			cout<<max(ans1,ans2)<<"\n";	
			update(mp[mid],1);
			update1(mp[mid],mid);
		}
	}

	return 0;
}
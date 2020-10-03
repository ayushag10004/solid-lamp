

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

ll bit[100005];

void update(ll x)
{
	while(x<100004)
	{
		bit[x]+=1;
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

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{	
		memset(bit,0,sizeof bit);
		
		ll n,i,x,lo,hi,mid,cnt,ans;
		s(n);

		cout<<"Case #"<<g<<": ";

		for(i=1;i<=n;i++)
		{
			s(x);

			update(x);

			lo = 1, hi = i, ans = -1;	

			while(lo<=hi)
			{
				mid = (lo+hi)/2;

				cnt = i - query(mid-1);

				if(cnt>=mid)
				{
					ans = mid;
					lo = mid + 1;
				}
				else
					hi = mid-1;
			}

			cout<<ans<<" ";
		}
		
		cout<<"\n";
		++g;
	}
	return 0;
}
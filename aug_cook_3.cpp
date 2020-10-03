

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

  if(y>50)
  	y = 50;

  while(y>0)
  { if(y&1)
	ans=(ans*x);
	y/=2;
	x=(x*x);
  }

  return ans;
};

/******************************************************************************************************/

ll compute(ll in,ll diff)
{
	ll fin = 0,mm=1,mid=0;

	while(diff>0 && in>0)
	{
		--in;
		mid+=mm*(diff%2);
		diff/=2;
		mm*=2;
	}

	fin = diff;

	if(mid>0)
		++fin;

	return fin;
}

ll p[100005],ans[100005];
const ll lim = mul(2,50);

int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,q,i;
		s(n); s(q);

		for(i=1;i<=n;i++)
			s(p[i]);

		sort(p+1, p+n+1);

		ll last = 0, diff, extra;
		for(i=1;i<=n;i++)
		{
			diff = p[i]+1 - last;

			// cout<<i<<" "<<last<<"->"<<p[i]<<": "<<diff<<"\n";

			if(diff<=0)
				{
					ans[i] = ans[i-1];
					last = 2*(last - p[i]);
				}
			else
				{
					extra = compute(i-1,diff);
					// cout<<extra<<"\n";
					ans[i] = ans[i-1] + extra;
					last = last + mul(2,i-1)*extra;
					// cout<<last<<"\n";
					last = 2*(last - p[i]);
				}

			if(last>lim)
				last = lim;
		}

		// for(i=0;i<=n;i++)
		// 	cout<<ans[i]<<" ";

		// cout<<lim<<"\n";
		
		while(q--)
		{	
			ll x,in;
			s(x);

			in = upper_bound(ans,ans+n+1,x)-ans;
			cout<<in-1<<"\n";
		}
	}

	return 0;
}


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

ll a[2005],bit[2005];

void update(ll x)
{
	// cout<<"aaadd\n";
	while(x<2001)
	{
		bit[x]+=1;
		x+=x&(-x);
	}
	// cout<<"bhaag\n";
	return;
}

ll query(ll x)
{
	ll ans = 0;

	while(x>0)
	{
		ans+=bit[x];
		x-=x&(-x);
	}

	return ans;
}

ll get_element(ll in)
{
	ll lo = 1,hi = 2000,mid,ans;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		if(query(mid)>=in)
		{
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}

	return ans;
}
int main()
{
	ll t;
	s(t);

	while(t--)
	{
		ll n,i,j,k;
		s(n); s(k);

		for(i=1;i<=n;i++)
			s(a[i]);

		ll sz,m,in,ans=0,cnt,mid;

		for(i=1;i<=n;i++)
		{
			memset(bit,0,sizeof bit);

			for(j=i;j<=n;j++)
			{
				// ++h[a[j]];

				// cout<<i<<" "<<j<<"---> \n";
				update(a[j]);
				sz = j-i+1;

				m = k/sz;

				if(k%sz!=0)
				++m;

				in = k/m;

				// cout<<sz<<" "<<m<<" "<<in<<"\n";
				if(k%m!=0)
				++in;

				// cout<<"aa\n";
				mid = get_element(in);
				// cout<<"bb\n";		
				cnt = query(mid)-query(mid-1);

				// cout<<sz<<" "<<m<<" "<<in<<" "<<mid<<" "<<cnt<<"\n";
				if(query(cnt) - query(cnt-1)>0)
					++ans;
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}
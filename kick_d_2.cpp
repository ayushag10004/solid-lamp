

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

ll a[100005],cnta[100005],b[100005],cntb[100005],pp[100005],fina[100005],finb[100005],ans[100005];
char c[100005];

ll go_anti(ll pos,ll len,ll n)
{
	if(len<=n-pos)
	{
		if(cnta[pos+len]-cnta[pos-1]>0)
			return 1;

		return 0;
	}

	if(cnta[n]-cnta[pos-1]>0)
		return 1;

	len = len - (n-pos);

	if(len>n)
		len = n;

	if(cnta[len]>0)
		return 1;

	return 0;
}

ll go_clock(ll pos,ll len,ll n)
{
	if(len<=n-pos)
	{
		if(cntb[pos+len]-cntb[pos-1]>0)
			return 1;

		return 0;
	}

	if(cntb[n]-cntb[pos-1]>0)
		return 1;

	len = len - (n-pos);

	if(len>n)
		len = n;

	if(cntb[len]>0)
		return 1;

	return 0;
}

int main()
{
	ll t,cs=1;
	s(t);

	while(t--)
	{
		ll n,g,m,i,pos;
		char ch;
		s(n); s(g); s(m);

		for(i=0;i<=n+3;i++)
			a[i] = cnta[i] = b[i] = cntb[i] = fina[i] = finb[i] = 0;

		for(i=1;i<=g;i++)
		{
			s(pos); cin>>ch;
			c[i] = ch;
			pp[i] = pos;

			if(ch=='A')
				++a[pos];
			else
				++b[pos];
		}

		for(i=1;i<=n;i++)
		{
			cnta[i] = cnta[i-1];

			if(a[i]>0)
				++cnta[i];

			cntb[i] = cntb[i-1];

			if(b[i]>0)
				++cntb[i];
		}

		ll lo,mid,hi,pos1,len,aa;

		for(i=1;i<=n;i++)
		{
			lo = 0,hi = m;
			ans[i] = -1;

			while(lo<=hi)
			{
				mid = (lo+hi)/2;

				pos = ((i-1)+mid)%n + 1;
				pos1 = ((i-1)-mid)%n;
				pos1 = (pos1+2*n)%n;
				len = m-mid;
				pos1 = ((pos1-len)%n + 2*n)%n + 1;

				if(go_anti(pos,len,n) || go_clock(pos1,len,n))
				{
					ans[i] = mid;
					lo = mid+1;
				}
				else
					hi = mid-1;
			}

			if(ans[i]!=-1)
			{
				aa = (i-1 + ans[i])%n + 1;
				++fina[aa];

				aa = ((i-1 - ans[i])%n + 2*n)%n + 1;
				++finb[aa];
			}
		}

		// for(i=0;i<=n;i++)
		// 	cout<<i<<"->"<<a[i]<<" "<<cnta[i]<<" "<<fina[i]<<"\n";

		// for(i=0;i<=n;i++)
		// 	cout<<i<<"-->"<<b[i]<<" "<<cntb[i]<<" "<<finb[i]<<"\n";

		// for(i=0;i<=n;i++)
		// 	cout<<i<<"-*>"<<ans[i]<<"\n";

		printf("Case #%lld: ",cs);
		++cs;
		for(i=1;i<=g;i++)
		{
			if(c[i]=='A')
				printf("%lld ",fina[pp[i]]);
			else
				printf("%lld ",finb[pp[i]]);
		}

		printf("\n");
	}
	return 0;
}
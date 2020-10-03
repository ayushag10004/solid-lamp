

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

ll a[200005],b[200005],c[200005];

int main()
{
	ll n,i;
	s(n);

	for(i=1;i<=n;i++)
		s(a[i]);

	for(i=n+1;i<=2*n;i++)
		a[i] = a[i-n];

	deque < ll > dq;

	for(i=1;i<=2*n;i++)
	{
		while(!dq.empty() && a[dq.front()]>2*a[i])
		{
			b[dq.front()] = -1;
			c[dq.front()] = i - dq.front();
			dq.pop_front();
		}

		while(!dq.empty() && a[dq.back()]<=a[i])
		{
			b[dq.back()] = i;
			c[dq.back()] = i - dq.back();
			dq.pop_back();
		}

		dq.push_back(i);		
	}

	for(i=1;i<=n;i++)
	if(b[i]==-1)
	{
		b[i+n] = -1;
		c[i+n] = c[i];
	}

	for(i=2*n;i>=1;i--)
	if(b[i]!=-1 && b[i]!=0)
	{
		if(b[b[i]]!=0)
			c[i]+=c[b[i]];
		else
			b[i] = 0;
	}

	// for(i=1;i<=2*n;i++)
	// {
	// 	cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<c[i]<<"\n";
	// }

	for(i=1;i<=n;i++)
	if(b[i]==0)
		cout<<-1<<" ";
	else
		cout<<c[i]<<" ";

	return 0;
}
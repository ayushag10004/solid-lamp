

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

ll fin[200005],a[200005],sum[200005];
int main()
{	
	memset(fin,-1,sizeof fin);
	ll n,i,mid;
	s(n);

	stack<ll> st;

	for(i=1;i<=n;i++)
		{
			s(a[i]);

			if(a[i]==0)
				st.push(i);
		}

	ll strt = 1,top,j;
	while(!st.empty())
	{
		top = st.top();
		st.pop();

		fin[top] = strt;

		for(j=top+1;j<=n;j++)
		if(fin[j]==-1)
		{
			sum[j]+=strt;

			if(sum[j]==a[j])
				st.push(j);
		}

		++strt;
	}

	for(i=1;i<=n;i++)
		printf("%lld ",fin[i]);

	printf("\n");

	return 0;
}
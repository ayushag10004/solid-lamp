

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
ll dp[1000][1000],a[500005];
ll lim = 720;
int main()
{	
	ll q,ch,x,y,i,ans;
	s(q);

	while(q--)
	{
		s(ch); s(x); s(y);

		if(ch==1)
		{
			a[x]+=y;

			for(i=1;i<=lim;i++)
			{
				dp[i][x%i]+=y;
			}
		}
		else
		{
			if(x>lim)
			{
				ans = 0;

				for(i=y;i<=500000;i+=x)
					ans+=a[i];

				printf("%lld\n",ans);
			}
			else
				printf("%lld\n",dp[x][y]);
		}
	}
	return 0;
}
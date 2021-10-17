
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

ll cnt[100005];
int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		memset(cnt,0,sizeof cnt);
		ll n,i,val;
		s(n);

		for(i=1;i<=n;i++)
		{
			s(val);

			if(val%2==0)
				++cnt[i];
		}

		for(i=1;i<=n;i++)
			cnt[i]+=cnt[i-1];

		ll q,l,r;
		s(q);

		while(q--)
		{
			s(l); s(r);

			if(cnt[r]-cnt[l-1]>0)
				cout<<"EVEN\n";
			else
				cout<<"ODD\n";
		}
	}

	return 0;
}

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

ll f[250005];
int main()
{	
	ll n,m,i,ans=0,cnt,prm	;
	cin>>n>>m;

	f[0] = 1;
	for(i=1;i<250004;i++)
		f[i] = (i*f[i-1])%m;

	for(i=1;i<=n;i++)
	{
		cnt = n-i+1;
		prm = (f[i]*f[cnt])%m;
		prm = (cnt*prm)%m;
		ans = (ans+prm)%m;	
	}

	cout<<ans<<"\n";
	return 0;
}
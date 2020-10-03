
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

ll dp[1005][1005],nr[1005][1005],f[2005];
int main()
{	
	ll n,k,i,mid,cnt,aa,bb,nn;
	s(n); s(k);
	nn = n;
	map<ll,ll> mp;
	set<ll> ss;
	
	f[0] = 1;
	for(i=1;i<=2000;i++)
		f[i] = (i*f[i-1])%MOD;

	for(i=1;i<=n;i++)
	{
		s(mid);
		++mp[mid];
		ss.insert(mid);
	}

	n = mp.size();
	// cout<<n<<"\n";
	dp[0][0] = 1;

	for(i=1;i<=n;i++)
	{	
		mid = *ss.begin();
		ss.erase(mid);
		cnt = mp[mid];

		for(aa=0;aa<=cnt;aa++)
		for(bb=aa;bb<=k;bb++)
		{	
			mid = M(f[cnt]*mul(f[cnt-aa],MOD-2));
			// cout<<cnt<<" "<<aa<<"->"<<mid<<"++\n";
			dp[i][bb] = M(dp[i][bb] + M(mid*dp[i-1][bb-aa]));
		}
	}

	mid = dp[n][k];
	// cout<<mid<<"--\n";
	n = nn;
	for(i=n-k+1;i<=n;i++)
		mid = M(mid*mul(i,MOD-2));

	cout<<mid<<"\n";

	return 0;
}
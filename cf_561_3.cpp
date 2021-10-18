

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

int main()
{	
	ll n,i,cnt=0,val;
	cin>>n;
	vector<ll> v;

	for(i=1;i<=n;i++)
	{
		cin>>val;
		if(val==0)
			++cnt;
		else
			v._pb(abs(val));
	}

	sort(v.begin(),v.end());

	ll ans = (cnt*(cnt-1))/2;
	// ans+=(cnt*(n-cnt));

	ll size = v.size();

	for(i=0;i<size;i++)
	{
		val = upper_bound(v.begin(),v.end(),2*v[i]) - v.begin();
		ans+=(val-1-i);
	}

	cout<<ans<<"\n";
	return 0;
}
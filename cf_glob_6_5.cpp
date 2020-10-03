
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
 
ll a[200005],b[200005];

ll go(ll goal,ll cnt)
{
	return goal - min(goal,cnt);
}

int main()
{	
	ll n,i,q,x,y,z,zz,sum=0;
	s(n);

	for(i=1;i<=n;i++)
		s(a[i]),sum+=a[i];

	map< pair<ll,ll> , ll > mp;

	s(q);
	while(q--)
	{
		s(x); s(y); s(z);

		if(mp.find(_mp(x,y)) != mp.end())
		{
			zz = mp[_mp(x,y)];
			sum-=go(a[zz],b[zz]);
			--b[zz];
			sum+=go(a[zz],b[zz]);
			mp.erase(_mp(x,y));
		}
		
		if(z!=0)
		{
			mp[_mp(x,y)] = z;
			sum-=go(a[z],b[z]);
			++b[z];
			sum+=go(a[z],b[z]);
		}

		// for(i=1;i<=n;i++)
		// 	cout<<b[i]<<" ";
		// cout<<"--- ";
		cout<<sum<<"\n";


	}
	return 0;
}
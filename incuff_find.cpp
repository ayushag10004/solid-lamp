

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
	ll n,k,x,i,val;
	cin>>n>>x>>k;

	string str;
	cin>>str;

	vector< set<ll> > a(n);
	vector< ll > v (n,0);

	for(i=0;i<n;i++)
	{	
		// cin>>val;
		val = str[i] - '0';
		a[i/x].insert(val);
		v[i/x] = a[i/x].size();
	}

	// for(i=0;i<=(n-1)/x;i++)
	// 	cout<<v[i]<<"\n";

	ll cnt,in;
	--k;

	while(k>0)
	{	
		cnt = 1;
		for(i=(n-1)/x;i>=0;i--)
		if(v[i]>0)
		{
			if(k/cnt<v[i])
			{
				in = k/cnt;
                k%=cnt;
                
				while(in>0)
					a[i].erase(a[i].begin()),--in;
				
				break;
			}
            
			cnt*=v[i];
		}
	}

	for(i=0;i<=(n-1)/x;i++)
		cout<<*a[i].begin();

	cout<<"\n";

	return 0;
}
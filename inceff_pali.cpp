

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000009
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

ll a[100005];
int main()
{	
	ll n,k,i,cnt,mid,aa,j;
	cin>>n>>k;
	
	a[1] = k;
	a[2] = k;
	a[3] = k*(k-1);
	ll sum = 0;

	for(i=4;i<=n;i++)
	{
		cnt = (i+1)/2;
		mid = mul(k,cnt);
		// cout<<mid<<"\n";

		if(i%2==0)
			sum=M(sum+a[i/2]);
		else
			sum=M(sum*k);

		mid=M(mid-sum);

		if(i%2==1)
			mid=M(mid-a[(i+1)/2]);

		a[i] = mid;

		// cout<<i<<" "<<k<<" "<<a[i]<<"\n";
	}

	cout<<a[n]<<"\n";
	return 0;
}
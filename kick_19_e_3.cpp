

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

ll p[100005],rr[100005];

bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return true; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

ll isPrime1(ll x,ll l)
{
	if(x<=50000)
		return p[x];
	else
		return rr[x-l];
}

ll go(ll l,ll r)
{	
	memset(rr,0,sizeof rr);
	memset(p,0,sizeof p);
	
	ll i,j,in;

	for(i=2;i<=50000;i++)
	if(p[i]==0)
	{
		in = l/i;
		if(l%i!=0)
			++in;

		for(j=in*i;j<=r;j+=i)
			rr[j-l] = 1;

		for(j=2*i;j<=50000;j+=i)
			p[j] = 1;
	}

	ll cnt = 0,cc,mid;

	// for(i=0;i<r-l+1;i++)
	// 	cout<<l+i<<" "<<isPrime1(i+l,l)<<" "<<"\n";

	for(i=l;i<=r;i++)
	if(i%2==1)
	{	
		if(isPrime1(i,l)==0)
			++cnt;
	}
	else
	{
		cc = 0;
		mid = i;
		while(mid%2==0)
		{
			++cc;
			mid/=2;
		}

		if(cc==1)
		{
			++cnt;
			continue;
		}

		if(cc==3 && mid==1)
		{
			++cnt;
			continue;
		}

		if(cc==2 && isPrime1(mid,l)==0)
		{
			++cnt;
			continue;
		}
	}

	return cnt;
}

int main()
{	
	ll t,g=1;
	s(t);

	while(t--)
	{
		ll l,r;
		s(l); s(r);

		cout<<"Case #"<<g<<": "<<go(l,r)<<"\n";
		++g;
	}
	return 0;
}

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
const ll N = 20005;
ll p[N];
int main()
{	
    ll i,j;
    for(i=2;i<N;i++)
        if(!p[i])
        for(j=i*i;j<N;j+=i)
            p[j] = 1;

	ll t;
	s(t);

	while(t--)
	{
		ll n,sum=0,a[105];
        s(n);

        for(i=1;i<=n;i++)
            s(a[i]),sum+=a[i];

        if(p[sum])
        {
            cout<<n<<"\n";
            for(i=1;i<=n;i++)
                cout<<i<<" ";
        } else {
            cout<<n-1<<"\n";
            ll pivot=-1;
            for(i=1;i<=n;i++)
                if(p[sum-a[i]])
                {
                    pivot = i;
                    break;
                }

            for(i=1;i<=n;i++)
            if(pivot!=i)
                cout<<i<<" ";
        }

        cout<<"\n";
	}
	return 0;
}
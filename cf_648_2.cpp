
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

ll a[505];
int main()
{
    ll t;
    s(t);

    while(t--)
    {
        ll n,i,x,cnt0=0,cnt1=0,ans=0;
        s(n);

        for(i=1;i<=n;i++)
            s(a[i]);
        
        for(i=1;i<=n;i++)
        {
            s(x);
            if(x==0)
                ++cnt0;
            if(x==1)
                ++cnt1;
        }

        if(cnt0>0 && cnt1>0)
            cout<<"Yes\n";
        else
        {   
            for(i=1;i<=n;i++)
            if(a[i-1]>a[i])
            {
                ans = 1;
                break;
            }

            if(ans)
                cout<<"No\n";
            else
                cout<<"Yes\n";
         }
    }
    return 0;
}
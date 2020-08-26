
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

ll base(ll x)
{
    while(x%2==0)
        x/=2;
    
    return x;
}

ll cnt(ll x)
{
    ll ans = 0;
    while(x%2==0)
    {
        ++ans;
        x/=2;
    }

    return ans;
}

int main()
{
    ll t;
    s(t);

    while(t--)
    {
        ll a,b,aa,bb,diff,ans;
        s(a); s(b);

        if(base(a)==base(b))
        {
            aa = cnt(a);
            bb = cnt(b);

            diff = abs(bb-aa);
            ans = diff/3;
            if(diff%3!=0)
                ++ans;

            cout<<ans<<"\n";
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
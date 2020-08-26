
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x % MOD + MOD) % MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld", &x)

ll mul(ll x, ll y)
{
  ll ans = 1;

  while (y > 0)
  {
    if (y & 1)
      ans = (ans * x) % MOD;
    y /= 2;
    x = (x * x) % MOD;
  }

  return ans;
};

/******************************************************************************************************/

ll a[5005];

ll go(ll x,ll y)
{
    // cout<<x<<" "<<y<<"\n";

    if(x==y)
        return (a[x]>0)?1:0;
    
    ll mm=MOD,i,ans=0;
    for(i=x;i<=y;i++)
        mm = min(mm,a[i]);

    for(i=x;i<=y;i++)
        a[i]-=mm;

    ll st = -1,en=-1;
    for(i=x;i<=y;i++)
    {
        if(a[i]>0 && st==-1)
            st = i;

        if(a[i]>0)
            en = i;

        if((a[i]==0 || i==y) && st!=-1)
            mm+=go(st,en);

        if(a[i]==0)
            st=-1,en=-1;
    }

    return min(y-x+1,mm);
}

int main()
{   
    ll n,i;
    s(n);

    for(i=1;i<=n;i++)
        s(a[i]);
    
    cout<<go(1,n)<<"\n";
    return 0;
}
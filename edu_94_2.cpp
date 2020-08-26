
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

int main()
{
    ll t;
    s(t);

    while(t--)
    {
        ll a,b,ca,cb,s,w,i,mid,ans=0;
        cin>>a>>b>>ca>>cb>>s>>w;

        if(s>w)
        {
            swap(s,w);
            swap(ca,cb);
        }

        for(i=0;i<=ca && i*s<=a;i++)
        {
            mid = i*s;
            ll aa = a-mid;

            ll cca = ca - i;
            ll ccb = cb - (aa/w);
            
            mid = min(cca,b/s);
            ll bb = b - mid*s;
            ans = max(ans, i+(aa/w)+mid+min(ccb,bb/w));
        }

        cout<<ans<<"\n";
    }
    return 0;
}
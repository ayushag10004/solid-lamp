
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

ll a[1005][1005];
int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,i,j,rr,cc,cnt,ans=0;
        s(n);

        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            s(a[i][j]);
        
        for(i=1;i<=n;i++)
        {
            rr = 1, cc = i;
            cnt = 0;
            while(rr<=n && cc<=n)
            {
                cnt+=a[rr][cc];
                ++rr; ++cc;
            }        

            ans = max(ans, cnt);
        }

        for(i=2;i<=n;i++)
        {
            rr = i, cc = 1;
            cnt = 0;
            while(rr<=n && cc<=n)
            {
                cnt+=a[rr][cc];
                ++rr; ++cc;
            }        

            ans = max(ans, cnt);
        }

        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;
    }
    return 0;
}
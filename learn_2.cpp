
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

ll a[100005];
int main()
{        
    ll q;
    s(q);
    cout<<fixed<<setprecision(5);

    while(q--)
    {
        ll n,u,i,iter=40;
        s(n); s(u);

        for(i=1;i<=n;i++)
            s(a[i]);

        ld lo=0, hi = 100000,mid,ans=0,energy,aa;

        while(iter--)
        {
            mid = (lo+hi)/2;
            // cout<<mid<<"\n";
            energy = 0;

            for(i=1;i<=n;i++)
            if(energy > (ld)u)
                break;
            else
            {
                aa = a[i] + mid;
                energy += (aa*aa*aa);
            }
            
            if(energy <= u)
                lo = mid;
            else
                hi = mid;
        }

        cout<<hi<<"\n";
    }
    return 0;
}
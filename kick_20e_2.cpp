
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
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,a,b,c;
        s(n);s(a);s(b);s(c);

        ll aa=a-c, bb=b-c,rem,i;
        vector<ll> ans;

        if(aa+bb+c<=n)
        {
            rem = n - (aa+bb+c);
            if(aa+bb>0)
            {
                    if(aa>0)
                    {
                        for(i=1;i<=aa;i++)
                            ans._pb(n-1);
                        
                        for(i=1;i<=rem;i++)
                            ans._pb(n-2);

                        for(i=1;i<=c;i++)
                            ans._pb(n);

                        for(i=1;i<=bb;i++)
                            ans._pb(n-1);
                    }
                    else if(bb>0)
                    {
                        for(i=1;i<=aa;i++)
                            ans._pb(n-1);

                        for(i=1;i<=c;i++)
                            ans._pb(n);

                        for(i=1;i<=rem;i++)
                            ans._pb(n-2);

                        for(i=1;i<=bb;i++)
                            ans._pb(n-1);
                    }
            }
            else if(aa+bb==0)
            {
                if(rem==0)
                for(i=1;i<=n;i++)
                    ans._pb(n);
                else if(c>1)
                {
                    ans._pb(n);
                    for(i=1;i<=rem;i++)
                        ans._pb(n-1);
                    for(i=1;i<c;i++)
                        ans._pb(n);
                }
            }
        }

        for(i=0;i<ans.size();i++)
        if(ans[i]<=0)
        {
            ans.clear();
            break;
        }

        cout<<"Case #"<<g<<": ";
        if(ans.size()==0)
            cout<<"IMPOSSIBLE";
        else
            for(i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
        
        cout<<"\n";
        ++g;
    }
    return 0;
}
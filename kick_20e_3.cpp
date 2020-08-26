
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

ll enj[100005],rem[100005];

ll bit[100006];
void update(ll x, ll val)
{
    while(x<100003)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
    return;
}

ll query(ll x)
{
    ll ans = 0;
    while(x>0)
    {
        ans+=bit[x];
        x-=x&(-x);
    }
    return ans;
}

int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,i,sum=0,ans=0,dd=0;
        s(n);
        memset(bit,0,sizeof bit);

        for(i=1;i<=n;i++)
        {
            s(enj[i]); s(rem[i]);
            update(i,enj[i]);
            sum+=enj[i];
        }

        set<pair<ll,ll> > safe;
        set<ll> bad;

        for(i=1;i<=n;i++)
        {
            if(sum-enj[i]>=rem[i])
                safe.insert(_mp(sum-enj[i]-rem[i],i));
            else
                bad.insert(i);
        }

        ll rem = 0,top,cnt=0,mid;
        pair<ll,ll> pp;
        while(!bad.empty())
        {
            top = *bad.begin();
            bad.erase(top);

            mid = query(n) + query(top-1);
            if(mid>ans)
            {
                ans = mid;
                dd = cnt;
            }
            ++cnt;
            // ans = max(ans, query(n) + query(top-1));
            update(top,-enj[top]);
            rem+=enj[top];
            // cout<<top<<": "<<rem<<"\n";
            
            while(!safe.empty())
            {
                pp = *safe.begin();
                // cout<<pp.ff<<"--"<<pp.ss<<"\n";
                if(pp.ff<rem)
                {
                    bad.insert(pp.ss);
                    safe.erase(pp);
                }
                else
                    break;
            }
        }

        cout<<"Case #"<<g<<": ";
        if(safe.size()!=0)
            cout<<n-safe.size()<<" INDEFINITELY\n";
        else
            cout<<dd<<" "<<ans<<"\n";

        ++g;
    }
    return 0;
}
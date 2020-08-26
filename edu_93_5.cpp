
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
    ll t, sum = 0, qsum = 0, cnt = 0;
    s(t);

    set<ll> a, b;
    set<pair<ll, ll>> ss;
    set<pair<ll, ll>> all;
    pair<ll, ll> pp;
    set< pair<ll,ll> > :: iterator it;

    while (t--)
    {
        ll x, y;
        s(x);
        s(y);
        sum += y;

        if (x == 0)
        {
            if (y > 0)
            {
                a.insert(y);
                ss.insert(_mp(y, 0));
                qsum += y;
                pp = *ss.begin();
                ss.erase(pp);
                qsum -= pp.ff;
                if (pp.ss == 1)
                    --cnt;
            }
            else
            {
                y = abs(y);
                if (ss.find(_mp(y, 0)) != ss.end())
                {
                    ss.erase(_mp(y, 0));
                    qsum -= y;
                    it = all.find(_mp(y, 0));
                    if (it != all.begin())
                    {
                        --it;
                        ss.insert(*it);
                        qsum+=(*it).ff;
                        cnt+=(*it).ss;
                    }
                }
                a.erase(y);
            }
        }
        else
        {
            if (y > 0)
            {
                b.insert(y);
                ss.insert(_mp(y, 1));
                qsum += y;
                pp = *ss.begin();
                ss.erase(pp);
                qsum -= pp.ff;
                if (pp.ss == 1)
                    --cnt;
            }
            else
            {
                y = abs(y);
                if (ss.find(_mp(y, 0)) != ss.end())
                {
                    ss.erase(_mp(y, 0));
                    qsum -= y;
                    it = all.find(_mp(y, 0));
                    if (it != all.begin())
                    {
                        --it;
                        ss.insert(*it);
                        qsum+=(*it).ff;
                        cnt+=(*it).ss;
                    }
                }
                a.erase(y);
            }
        }
        

        if (y > 0)
            all.insert(_mp(y, x));
        else
            all.erase(_mp(abs(y), x));
    }
    return 0;
}
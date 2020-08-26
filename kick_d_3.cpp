
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

vector<vector<ll>> vv;
vector<queue<ll>> qqa;
vector<queue<ll>> qqb;

ll lvl[500005], a, b, ha[500005], hb[500005];

void dfs(ll x, ll level)
{
    ll size = vv[x].size(), i;
    ++lvl[level];

    for (i = 0; i < size; i++)
        dfs(vv[x][i], level + 1);

    return;
}

ll dfs1(ll x, ll level)
{
    ll size = vv[x].size(), i, ans = 0;

    for (i = 0; i < size; i++)
        ans += dfs1(vv[x][i], level + 1);

    ll aa = 1, bb = 1;
    while (!qqa[level].empty())
    {
        aa += ha[qqa[level].front()];
        qqa[level].pop();
    }

    while (!qqb[level].empty())
    {
        bb += hb[qqb[level].front()];
        qqb[level].pop();
    }

    ha[x] = aa;
    hb[x] = bb;

    if (level - a > 0)
        qqa[level - a].push(x);

    if (level - b > 0)
        qqb[level - b].push(x);

    ans += aa * bb;
    // cout<<x<<"--->"<<aa<<" "<<bb<<" :: "<<ans<<"\n";
    return ans;
}

int main()
{
    ll t, g = 1;
    s(t);

    while (t--)
    {
        ll n, i, pp, ans = 0;
        s(n);
        s(a);
        s(b);

        memset(lvl, 0, sizeof lvl);
        memset(ha, 0, sizeof ha);
        memset(hb, 0, sizeof hb);

        vv.clear();
        vv.resize(n + 1);
        qqa.clear();
        qqa.resize(n + 1);
        qqb.clear();
        qqb.resize(n + 1);

        for (i = 2; i <= n; i++)
        {
            s(pp);
            vv[pp]._pb(i);
        }

        dfs(1, 1);

        ll mid, cnt1 = 0, cnt2 = 0;
        for (i = 1; i <= n; i++)
        {
            mid = i / a;
            if (i % a != 0)
                ++mid;

            cnt1 += lvl[i] * mid;
            // cout<<i<<"-> a :"<<lvl[i]<<":"<<mid<<"\n";

            mid = i / b;
            if (i % b != 0)
                ++mid;

            cnt2 += lvl[i] * mid;
            // cout<<i<<"-> b :"<<lvl[i]<<":"<<mid<<"\n";
        }
        ans = n * (cnt1 + cnt2);
        // cout<<"-- "<<ans<<" "<<cnt1<<" "<<cnt2<<"\n";

        ans -= dfs1(1, 1);
        cout << fixed << setprecision(8);
        cout << "Case #" << g << ": " << (ld)ans / (n * n) << "\n";
        ++g;
    }
    return 0;
}

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

vector<vector<ll> > v;
vector<ll> ways;
ll n;

ll dfs(ll x, ll y)
{
    ll size = v[x].size(), i, s = 1;

    for (i = 0; i < size; i++)
        if (v[x][i] != y)
        {
            s += dfs(v[x][i], x);
        }

    if (s != n)
        ways._pb(s * (n - s));

    return s;
}

int main()
{
    ll t;
    s(t);

    while (t--)
    {
        ll i, x, y;
        s(n);

        v.clear();
        ways.clear();
        v.resize(n + 1);

        for (i = 1; i < n; i++)
        {
            s(x);
            s(y);
            v[x]._pb(y);
            v[y]._pb(x);
        }

        dfs(1, 0);
        sort(ways.begin(), ways.end());

        ll m, mid;
        vector<ll> pp;
        s(m);
        for (i = 1; i <= m; i++)
        {
            s(mid);
            pp._pb(mid);
        }

        sort(pp.begin(), pp.end());
        stack<ll> st;

        for (i = 0; i < m; i++)
            st.push(pp[i]);

        ll aa, bb, ans = 0;
        while (st.size() > n - 1)
        {
            aa = st.top();
            st.pop();
            bb = st.top();
            st.pop();
            st.push(M(aa * bb));
        }

        for (i = n - 2; i >= 0; i--)
        {
            mid = 1;
            if (!st.empty())
            {
                mid = st.top();
                st.pop();
            }
            ans = M(ans + M(ways[i] * mid));
        }

        cout << ans << "\n";
    }
    return 0;
}
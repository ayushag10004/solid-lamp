
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

    while (t--)
    {
        ll n, i, mid;
        s(n);

        string a, b;
        cin >> a >> b;

        deque<ll> dq;
        for (i = 0; i < n; i++)
            dq.push_back(a[i] - '0');

        vector<ll> ans;
        ll rev = 0, last, start;

        for (i = n - 1; i >= 0; i--)
        {
            mid = b[i] - '0';

            if (rev == 0)
            {
                last = dq.back();

                if (last == mid)
                    dq.pop_back();
                else
                {
                    start = dq.front();

                    if (!start ^ mid)
                        ans._pb(1);

                    ans._pb(dq.size());
                    dq.pop_front();
                    rev ^= 1;
                }
            }
            else
            {
                last = dq.front() ^ 1;

                if (last == mid)
                    dq.pop_front();
                else
                {
                    start = dq.back() ^ 1;

                    if (!start ^ mid)
                        ans._pb(1);

                    ans._pb(dq.size());
                    dq.pop_back();
                    rev ^= 1;
                }
            }
        }

        cout << ans.size() << " ";
        for (i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
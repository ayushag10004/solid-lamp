
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

ll rr[205], gg[205], bb[205];
ll dp[205][205][205];
int main()
{
  ll r, g, b, i;
  memset(dp, -1, sizeof dp);

  s(r);
  s(g);
  s(b);

  for (i = 1; i <= r; i++)
    s(rr[i]);

  for (i = 1; i <= g; i++)
    s(gg[i]);

  for (i = 1; i <= b; i++)
    s(bb[i]);

  sort(rr + 1, rr + r + 1, greater<int>());
  sort(gg + 1, gg + g + 1, greater<int>());
  sort(bb + 1, bb + b + 1, greater<int>());

  queue<vector<ll> > qq;
  vector<ll> vv(3, 0);
  vector<ll> top;
  qq.push(vv);
  ll ans = 0, x, y, z, mid;
  dp[0][0][0] = 0;

  while (!qq.empty())
  {
    top = qq.front();
    qq.pop();
    x = top[0], y = top[1], z = top[2];
    // cout<<x<<" "<<y<<" "<<z<<": "<<dp[x][y][z]<<"\n";
    ans = max(ans, dp[x][y][z]);

    if (x + 1 <= r && y + 1 <= g)
    {
      mid = dp[x][y][z] + rr[x + 1] * gg[y + 1];

      if (mid > dp[x + 1][y + 1][z])
      {
        vv[0] = x + 1, vv[1] = y + 1, vv[2] = z;
        dp[x + 1][y + 1][z] = mid;
        qq.push(vv);
      }
    }

    if (x + 1 <= r && z + 1 <= b)
    {
      mid = dp[x][y][z] + rr[x + 1] * bb[z + 1];

      if (mid > dp[x + 1][y][z + 1])
      {
        vv[0] = x + 1, vv[1] = y, vv[2] = z + 1;
        dp[x + 1][y][z + 1] = mid;
        qq.push(vv);
      }
    }

    if (z + 1 <= b && y + 1 <= g)
    {
      mid = dp[x][y][z] + bb[z + 1] * gg[y + 1];

      if (mid > dp[x][y + 1][z + 1])
      {
        vv[0] = x, vv[1] = y + 1, vv[2] = z + 1;
        dp[x][y + 1][z + 1] = mid;
        qq.push(vv);
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
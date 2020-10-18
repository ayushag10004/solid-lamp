
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

ll distance(ll n, ll x, ll y)
{
  if (x > y)
    swap(x, y);

  return min(y - x, n + x - y);
}

int main()
{
  ll t, g = 1;
  s(t);

  while (t--)
  {
    ll w, n, i, ans = 0, lt = 0, rt = 0, x;
    s(w);
    s(n);

    priority_queue<ll, vector<ll>, greater<ll> > left1, right1;
    queue<ll> left, right;
    set<ll> ss;

    ll mid = n / 2;
    for (i = 1; i <= w; i++)
    {
      s(x);
      // cout<<x<<"--\n";
      ss.insert(x);

      if (x <= 1 + mid)
      {
        right1.push(x);
        rt += (x - 1);
      }
      else
      {
        left1.push(x);
        lt += (n - x + 1);
      }
    }

    while (!left1.empty())
    {
      left.push(left1.top());
      // cout << left1.top() << "  l\n";
      left1.pop();
    }

    while (!right1.empty())
    {
      right.push(right1.top());
      // cout << right1.top() << "  r\n";
      right1.pop();
    }

    ans = lt + rt;
    ll pt = 1, pt1, dis, rc, rd, ad, cnt, ld,qq;

    while (!ss.empty())
    {
      pt1 = *ss.begin();
      ss.erase(pt1);

      if (pt1 == 1)
        continue;

      // cout << pt << " " << pt1 << "::" << lt << " " << rt << "\n";

      dis = pt1 - pt;
      rc = right.size();

      while (!left.empty())
      {
        x = left.front();
        if (pt1 <= x)
          ld = x - pt1;
        else
          ld = n + x - pt1;
        ad = distance(n, pt1, x);
        // cout << x << " " << ld << " " << ad << "^^\n";
        if (ld == ad)
        {
          left.pop();
          right.push(x);
          lt -= distance(n, pt, x);
          rt += distance(n, pt1, x);
        }
        else
          break;
      }

      lt += (left.size() * dis);

      // cout << lt << " " << rt << "**\n";

      cnt = 0;
      qq = right.size();
      while (qq--)
      {
        x = right.front();
        if (x == pt)
        {
          right.pop();
          ad = distance(n, pt1, x);
          ld = n + pt - pt1;
          if (ld > ad)
          {
            left.push(x);
            lt += distance(n, pt1, x);
          }
          else
          {
            right.push(x);
            rt += distance(n, pt1, x);
          }
          ++cnt;
        }
        else
          break;
      }

      rc -= cnt;
      rt -= (rc * dis);
      ans = min(ans, lt + rt);
      pt = pt1;

      // cout << lt << " " << rt << " ** " << cnt << "\n";
    }

    cout << "Case #" << g << ": " << ans << "\n";
    ++g;
  }
  return 0;
}
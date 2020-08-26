
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
// k->1 , x-> 10^18
// k->2 , x-> 63950

ll kSpecial(ll x,ll k)
{
    


}
// func 0 to x -> k

int main()
{ 
    ll lt,rt,k;
    s(lt); s(rt);   // lt-> 153    rt-> 63950
    s(k);           // k-> 2

    ll ans = kSpecial(rt,k) - kSpecial(lt-1,k);
//    0...rt - 0...(lt-1)  == lt....rt
    cout<<ans;
    return 0;
}
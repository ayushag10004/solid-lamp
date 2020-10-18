
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

int main()
{
    ll t,g=1;
    s(t);

    string kick = "KICK", start = "START";
    while(t--)
    {
        string str;
        cin>>str;

        ll ans=0,cnt=0,i,j,n=str.size(),flag;

        for(i=0;i<n;i++)
        {
            flag = 1;

            for(j=0;j<5;j++)
            if(i+j<n && str[i+j]==start[j])
                continue;
            else
                flag = 0;
            
            if(flag)
                ans+=cnt;

            flag = 1;
            for(j=0;j<4;j++)
            if(i-3+j>=0 && str[i-3+j]==kick[j])
                continue;
            else
                flag = 0;

            if(flag)
                ++cnt; 
        }

        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;
    }
    return 0;
}
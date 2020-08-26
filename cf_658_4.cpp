
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)
 
ll mul(ll x,ll y)
{ ll ans=1;
 
  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }
 
  return ans;
};
 
/******************************************************************************************************/

ll a[4005],dp[4005][4005];
int main()
{
    ll t;
    s(t);
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;

    while(t--)
    {
        ll n,i,j;
        s(n);
        
        set< pair<ll,ll> > ss;

        for(i=1;i<=2*n;i++)
        {
            s(a[i]);
            ss.insert(_mp(a[i],i));
        }

        vector<ll> vv;
        vv._pb(-1);
        pair<ll,ll> top;
        ll last,in, size;

        while(!ss.empty())
        {
            top = *ss.rbegin();
            in = top.ss;
            last = ss.size();

            for(i=last;i>=in;i--)
                ss.erase(_mp(a[i],i));
            
            size = last - in + 1;
            vv._pb(size);
            // cout<<size<<"--\n";
        }

        size = vv.size();
        for(i=1;i<vv.size();i++)
        {   
            for(j=0;j<=2*n;j++)
                dp[i][j] = dp[i-1][j];

            for(j=0;j<=2*n;j++)
            if(dp[i-1][j])
                dp[i][j+vv[i]] = 1;
        }

        if(dp[vv.size()-1][n])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
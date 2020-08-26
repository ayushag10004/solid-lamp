
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

ll dp[10005][5],a[10005];
int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,i,j,k;
        s(n);
        memset(dp, 0,sizeof dp);
        
        for(i=1;i<=n;i++)
            s(a[i]);
        
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=4;j++)
            {
                dp[i][j] = MOD;

                for(k=1;k<j;k++)
                    if(a[i-1]<a[i])
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+1);

                for(k=j;k<=j;k++)
                    if(a[i-1]==a[i])
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+1);

                for(k=j+1;k<=4;k++)
                    if(a[i-1]>a[i])
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+1);
            }
        }

        ll ans = MOD;
        for(i=1;i<=4;i++)
            ans = min(ans, dp[n][i]);
            
        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;      
    }
    return 0;
}
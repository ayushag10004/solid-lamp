
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 998244353
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

ll dp[3005][3005];

int main()
{	
	string s,t;
    cin>>s>>t;
    
    ll m=s.size(), n=t.size(),i,j,x,y,z,ans=0;
    
    for(i=0;i<n;i++)
    if(t[i]==s[0])
    {    
         dp[0][i] = 2;
         if(n==1)
            ans = 2;
    }
    dp[0][n] = 2;

    for(i=1;i<m;i++)
    {
        for(j=0;j<=n;j++)
        if(dp[i-1][j])
        {   
            x = j, y = min(j+i-1,n), z = dp[i-1][j];
            if(x==n && y==n)   
                dp[i][n] = (2*z)%MOD;

            if(x>0 && s[i]==t[x-1])
                dp[i][x-1] = (dp[i][x-1] + z)%MOD;

            if(x<n)
                if((y<n-1 && s[i]==t[y+1]) || y>=n-1)
                    dp[i][x] = (dp[i][x] + z)%MOD;
        }

        if(i+1>=n)
            ans = (ans + dp[i][0])%MOD;
    }

    cout<<ans<<"\n";
	return 0;
}
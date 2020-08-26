
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
	ans=(ans*x);
	y/=2;
	x=(x*x);
  }
 
  return ans;
};
 
/******************************************************************************************************/

vector< vector<ll> > v(100005);
ll dp[100005][2][2],deg[100005];

void dfs(ll x,ll y)
{
    ll size = v[x].size(),i,f=0;

    for(i=0;i<size;i++)
    if(v[x][i]!=y)
    {
        node = v[x][i];

        if(deg[node]==1)
        {   
            f = 1;
            dp[node][0][0] = dp[node][0][1] = 0; 
        }
        else
            dfs(node, x);
        
    }

    if(f==1)
    {
        dp[x][1][0] = dp[x][1][1] = 1;

        for(i=0;i<size;i++)
        if(v[x][i]!=y && deg[v[x][i]]>1)
        {
            node = v[x][i];

            mid = MOD;
            if(dp[node][0][0]>0)
                mid = min(mid, dp[node][0][0]);
            
            if(dp[node][1][0]>0)
                mid = min(mid, max(2, dp[node][1][0]));

            dp[x][1][0] = max(dp[x][1][0], mid);
            
            mid = 0;
            if(dp[node][0][0]>0)
                mid = max(mid, dp[node][0][0]);
            
            if(dp[node][1][0]>0)
                mid = min(mid, max(2, dp[node][1][0]));

            dp[x][1][0] = max(dp[x][1][0], mid);
        }
    }
    else
    {
        
    }
    
    return;
}

int main()
{	
    ll n,i,x,y;
    cin>>n;
    memset(dp, -1, sizeof dp);

    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        ++deg[x];
        ++deg[y];
        v[x]._pb(y);
        v[y]._pb(x);
    }
	
    for(i=1;i<=n;i++)
    if(deg[i]>1)
    {
        root = i;
        break;
    }
    dfs(root,0);


	return 0;
}
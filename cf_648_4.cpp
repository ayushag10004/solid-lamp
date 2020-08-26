
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
 
char a[55][55];
ll vis[55][55];
ll dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

void block(ll x,ll y,ll n,ll m)
{
    ll xx,yy;
    for(ll i=0;i<4;i++)
    {
        xx = x+dx[i];
        yy = y+dy[i];

        if(1<=xx && xx<=n && 1<=yy && yy<=m && a[xx][yy]!='B' && a[xx][yy]!='G')
            a[xx][yy] = '#';
    }

    return;
}

void go(ll x,ll y,ll n,ll m)
{   
    // cout<<x<<"-"<<y<<"\n";
    if(a[x][y]=='#')
    {
        vis[x][y] = 0;
        return;
    }

    vis[x][y] = 1;

    ll xx,yy;
    for(ll i=0;i<4;i++)
    {
        xx = x+dx[i];
        yy = y+dy[i];

        if(1<=xx && xx<=n && 1<=yy && yy<=m && vis[xx][yy]==-1)
            go(xx,yy,n,m);
    }
}

int main()
{
    ll t;
    s(t);

    while(t--)
    {
        memset(vis,-1,sizeof vis);
        ll n,m,i,j;
        s(n); s(m);

        // cout<<"1\n";
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
        // cout<<"2\n";
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i][j]=='B')
            block(i,j,n,m);
        // cout<<"3\n";
        go(n,m,n,m);
        // cout<<"4\n";
        ll ans = 1;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i][j]=='G' && vis[i][j]<=0)
            ans = 0;
        else if(a[i][j]=='B' && vis[i][j]==1)
            ans = 0;

        if(ans)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

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

ll dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
ll a[55][55];
int main()
{
    ll t;
    s(t);

    while(t--)
    {
        ll n,m,i,j,k,xx,yy,cnt=0,f;
        s(n); s(m);

        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            s(a[i][j]);

        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {   
            f = 0;
            for(k=0;k<4;k++)
            {
                xx = i+dx[k];
                yy = j+dy[k];
                f=0;

                if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]==1)
                    f = 1;
            }

            if(f==0)
                    ++cnt;
        }

        if(f%2)
            cout<<"Ashish\n";
        else
            cout<<"Vivek\n";
    }
    return 0;
}
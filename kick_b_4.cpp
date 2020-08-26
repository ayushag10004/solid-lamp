
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

ll n,m;

ld go(ll x,ll y)
{
    ll aa = x - 1, bb = y - 1, cc = n - x, dd = m - y, i;
    long double ans=1,tot=1;
    for(i=1;i<=aa+bb;i++)
    {
        ans*=i;
        if(i<=aa)
            ans/=i;
        if(i<=bb)
            ans/=i;
    }

    for(i=1;i<=cc+dd;i++)
    {
        ans*=i;
        if(i<=cc)
            ans/=i;
        if(i<=dd)
            ans/=i;
    }

    for(i=1;i<=n-1+m-1;i++)
    {
        tot*=i;
        if(i<=n-1)
            tot/=i;
        if(i<=m-1)
            tot/=i;
    }

    return (ld)ans/tot;
}

int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {   
        ll i,j,l,u,r,d;
        s(m); s(n);
        s(l); s(u);
        s(r); s(d);

        ld ans = 1,mid;

        if(u>1)
        for(i=l;i<=r;i++)
        {
            mid = go(u-1, i);
            cout<<u-1<<" "<<i<<"->"<<mid<<"\n"; 
            if(i<m)
                ans-=0.5*mid;
            else
                ans-=mid;
        }

        if(l>1)
        for(i=u;i<=d;i++)
        {
            mid = go(i, l-1);

            if(i<n)
                ans-=0.5*mid;
            else
                ans-=mid;
        }

        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;
    }
    return 0;
}
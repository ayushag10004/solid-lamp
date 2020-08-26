
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

int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        ll n,i,q,st,in,qq;
        s(n); s(q);
        qq=q;
        vector<ll> a(n);

        for(i=1;i<n;i++)
            s(a[i]);
        vector<ll> ans;

        while(q--)
        {
            s(st); s(in);
            vector<ll> vv;
            vv = a;
            

        }

        cout<<"Case #"<<g<<": ";
        for(i=0;i<qq;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";

        ++g;      
    }
    return 0;
}
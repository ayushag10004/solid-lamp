
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

ll p[100005];
ll prnt(ll x)
{
    if(p[x]==x)
        return x;
    else
        return p[x] = prnt(p[x]);
}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
        ll n,m,x,y,z,a,b;
        s(n),s(m);
        vector< vector<ll> > v(n+1);
        for(ll i=1;i<=n;i++)
            p[i] = i;
        
        for(ll i=1;i<=m;i++)
        {
            s(x); s(y); s(z);

            a = prnt(x);
            b = prnt(z);

            if(a!=b)
            {
                p[b] = a;
                v[x]._pb(z);
            }
        }

        for(ll i=2;i<=n;i++)
        {
            p[i] = prnt(i);
            if(p[i]==i)
                v[1]._pb(i);
        }

        for(ll i=1;i<=n;i++)
        for(ll j=0;j<v[i].size();j++)
        cout<<i<<" "<<v[i][j]<<"\n";
	}
	return 0;
}
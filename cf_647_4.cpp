
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

vector< vector<ll> > v(500005);
ll vis[500005],wgt[500005];

ll mex(set <ll> &ss)
{
    ll i;
    for(i=1;;i++)
    if(ss.find(i)==ss.end())
        return i;
    
    return 0;
}

int main()
{   
    ll n,m,i,x,y,size;
    s(n); s(m);

    for(i=1;i<=m;i++)
    {
        s(x); s(y);
        v[x]._pb(y);
        v[y]._pb(x);
    }

    set< pair<ll,ll> > ss;
    for(i=1;i<=n;i++)
    {
        s(wgt[i]);
        ss.insert(_mp(wgt[i],i));
    }

    pair<ll,ll> pp;
    vector<ll> ans;
    set<ll> mm;
    while(!ss.empty())
    {
        pp = *ss.begin();
        ss.erase(pp);
        
        size = v[pp.ss].size();
        mm.clear();
        for(i=0;i<size;i++)
        if(vis[v[pp.ss][i]])
            mm.insert(wgt[v[pp.ss][i]]);
        
        // cout<<pp.ss<<" "<<mex(mm)<<" "<<mm.size()<<"\n"; 
        if(mex(mm)==pp.ff)
            ans._pb(pp.ss),vis[pp.ss]=1;
        else
        {
            cout<<"-1\n";
            return 0;
        }
    }

    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
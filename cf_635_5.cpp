
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

vector<ll> _push(ll a,ll b,ll c)
{
    vector<ll> v;
    v._pb(a);
    v._pb(b);
    v._pb(c);

    return v;
}

vector< vector<ll> > v1;
vector< vector<ll> > v2;
map < pair<ll,ll>,ll > mp;
vector<ll> mid;
map < pair<ll,ll>,ll > :: iterator it;

int main()
{	
	string s,t;
    cin>>s>>t;
    
    ll m=s.size(), n=t.size(),i,j,x,y,z,ans=0;
    
    for(i=0;i<n;i++)
    if(t[i]==s[0])
    {    mid = _push(i,i,2);
         v1._pb(mid);
         if(n==1)
            ans = 2;
    }
    v1._pb(_push(n,n,2));
    
    for(i=1;i<m;i++)
    {
        mp.clear();
        v2.clear();
        for(j=0;j<v1.size();j++)
        {
            x = v1[j][0], y = v1[j][1], z = v1[j][2];
            if(x==n && y==n)
            {
                mp[_mp(n,n)]=2*z;
                mp[_mp(n,n)]%=MOD;
            }

            if(x>0)
            {
                if(s[i]==t[x-1])
                {
                    mp[_mp(x-1,y)]+=z;
                    mp[_mp(x-1,y)]%=MOD;
                }
            }

            if(x<n)
            {
                if(y<n-1 && s[i]==t[y+1])
                {
                    mp[_mp(x,y+1)]+=z;
                    mp[_mp(x,y+1)]%=MOD;
                }
                else if(y>=n-1)
                {
                    mp[_mp(x,min(y+1,n))]+=z;
                    mp[_mp(x,min(y+1,n))]%=MOD;   
                }
            }
        }

        for( it=mp.begin();it!=mp.end(); ++it)
            {   
                mid = _push(it->ff.ff, it->ff.ss, it->ss);
                if(mid[0]==0 && mid[1]>=n-1)
                {
                    ans+=mid[2];
                    ans%=MOD;
                }
                v2._pb(mid);
            }
            // break;
        v1 = v2;
    }

    cout<<ans<<"\n";
	return 0;
}
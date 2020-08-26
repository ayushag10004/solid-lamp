
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
        ll x,y,i,ans=-1,dis;
        s(x); s(y);

        string str;
        cin>>str;
        
        for(i=0;i<=str.size();i++)
        {
            if(i>0)
            {
                if(str[i-1]=='N')
                    ++y;
                else if(str[i-1]=='S')
                    --y;
                else if(str[i-1]=='E')
                    ++x;
                else
                    --x;
            }

            dis = abs(x) + abs(y);
            
            if(dis<=i)
            {
                ans = i;
                break;
            }
        }   

        cout<<"Case #"<<g<<": ";
        if(ans==-1)
            cout<<"IMPOSSIBLE\n";
        else
            cout<<ans<<"\n";

        ++g;
    }
    return 0;
}
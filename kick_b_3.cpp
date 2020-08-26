
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000
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

ll a[5005];

int main()
{
    ll t,g=1;
    s(t);

    while(t--)
    {
        string str;
        cin>>str;
        // cout<<"yes\n";
        ll co=0,ro=0,in=0,mid,i,j;

        for(i=0;i<str.size();i++)
        {
            if(str[i]>='2' && str[i]<='9')
            {   
                ++in;
                a[in] = str[i] - '0';
            }
            else if(str[i]==')')
                --in;
            else if(str[i]!='(')
            {
                mid = 1;
                for(j=1;j<=in;j++)
                    mid = (mid*a[j])%MOD;
                
                if(str[i]=='N')
                    ro-=mid;
                else if(str[i]=='S')
                    ro+=mid;
                else if(str[i]=='W')
                    co-=mid;
                else if(str[i]=='E')
                    co+=mid;
                
                ro = M(ro);
                co = M(co);
                // cout<<in<<" "<<mid<<"\n";
                // cout<<str[i]<<"->>"<<ro<<" "<<co<<"\n";
            }
        }
        cout<<"Case #"<<g<<": "<<co+1<<" "<<ro+1<<"\n";
        ++g;
    }
    return 0;
}
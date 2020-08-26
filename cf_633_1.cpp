
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

ll get_max_2(ll n)
{
    ll ans = 0;
    while(n>0)
    {
        n/=2;
        ++ans;
    }

    return ans;
}   

int main()
{	
	ll t,g=1;
	s(t);

	while(t--)
	{
        ll n,i,ans=0,mm,val;
        s(n);

        for(i=1;i<=n;i++)
        {
            s(val);

            if(i==1)
                mm = val;
            else
            {   
                if(val<mm)
                    ans = max(ans, get_max_2(mm-val));
                mm = max(mm,val);
            }
        }

        cout<<ans<<"\n";
	}
	return 0;
}
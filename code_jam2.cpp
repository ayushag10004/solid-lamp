
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

    return ans-1;
}

vector < pair<ll,ll> > v;

ll go(ll n)
{
    ll dir = 1,cur = get_max_2(n),des,i;  
    // while(n-mul(2,cur)<cur)
    //     --cur;

    while(n>0)
    {
        des = get_max_2(n);
        if(cur==des &&  n-mul(2,cur)>=cur)
        {
            if(dir==1)
                for(i=1;i<=cur+1;i++)
                    v._pb(_mp(cur+1,i));
            else
                for(i=cur+1;i>=1;i--)
                    v._pb(_mp(cur+1,i));

            dir^=1;
            n-=mul(2,cur);
        }
        else
        {
            if(dir==1)
                v._pb(_mp(cur+1, 1));
            else
                v._pb(_mp(cur+1, cur+1));
            
            --n;
        }
        
        --cur;
    }

    if(cur==-1 && n==0)
        return 1;
    
    return 0;
}

int main()
{	
	ll t,g=1;
	s(t);

	while(t--)
	{
        ll n,i;
		cin>>n;
        
        cout<<"Case #"<<g<<":\n";

        if(n<=500)
        for(i=1;i<=n;i++)
            cout<<i<<" 1"<<"\n";
        else
        {
            cout<<"1 1\n2 1\n3 2\n";
            for(i=3;i<=499;i++)
                cout<<i<<" 1"<<"\n";
        }

        ++g;
	}
	return 0;
}
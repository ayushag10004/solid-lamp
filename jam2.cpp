
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

ll getLast(ll x)
{   
    ll ans = -1;
    while(x>0)
    {
        ans = x%10;
        x/=10;
    }

    return ans;
}

ll sizeX(ll x)
{   
    ll ans = 0;
    while(x>0)
    {
        x/=10;
        ++ans;
    }

    return ans;
}

ll h1[30],h2[30],h3[30];

int main()
{
    ll t,g=1;
    s(t);
    
    while(t--)
    {
        ll u,i,j,x,ch=0,last,ss;
        s(u);

        memset(h1,0,sizeof h1);
        memset(h2,0,sizeof h2);
        memset(h3,0,sizeof h3);

        string str,ans;

        for(i=0;i<26;i++)
            h3[i] = 50;
        
        for(i=1;i<=10000;i++)
        {   
            s(x); cin>>str;
            for(j=0;j<str.size();j++)
                h1[str[j]-'A'] = 1;
            
            ++h2[str[0]-'A'];

            last = getLast(x);

            if(last>0)
            {
                ss = sizeX(x);
                if(ss>str.size())
                    last = 9;
                
                h3[str[0]-'A'] = min(h3[str[0]-'A'], last);
            }
            // cout<<i<<"->"<<x<<"  "<<str<<"\n";   
        }
        
        // for(i=0;i<26;i++)
        //     cout<<(char)(i+'A')<<" "<<h1[i]<<" "<<h2[i]<<" "<<h3[i]<<"\n";

        // cout<<"\n";

        if(x>0){
            for(i=9;i>=1;i--)
            {
                for(j=0;j<26;j++)
                if(h3[j]>=i && h3[j]!=50 && h3[j]!=-1)
                {
                    ans+=(j + 'A');
                    h3[j] = -1;
                    break;
                }
            }

            for(i=0;i<26;i++)
            if(h1[i]==1 && h3[i]==50)
                ans+=(i+'A');

            reverse(ans.begin(), ans.end());
        }
        else
        {
            set<ll> qq;
            set< pair<ll,ll> > dd;
            for(i=0;i<26;i++)
            if(h1[i]==1 && h2[i]>=1)
                dd.insert(_mp(h2[i], i));
            
            while(dd.size()>0)
            {
                ans+=(*dd.begin()).second + 'A';
                dd.erase(*dd.begin());
            }

            reverse(ans.begin(), ans.end());
            string fin;
            for(i=0;i<26;i++)
            if(h1[i]==1 && h2[i]==0)
                fin+=(i+'A'),qq.insert(i);
            ans = fin+ans;
            // while(ans.size()<10)
            // {
            //     for(i=0;i<26;i++)
            //     if(qq.find(i)==qq.end())
            //     {
            //         ans=(i+'A') + ans;
            //         qq.insert(i);
            //         break;
            //     }
            // }

            // reverse(ans.begin(), ans.end());
        }
        
        cout<<"Case #"<<g<<": "<<ans<<"\n";
        ++g;
    }
    return 0;
}
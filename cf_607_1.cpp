

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
	ll t;
	s(t);

	while(t--)
	{
		ll x,i,j;
		string str;

		cin>>x>>str;

		ll ans = str.size(),rep,len,size;

		for(i=1;i<=x;i++)
		{	
			rep = str[i-1]-'0';
			len = M(ans - i);

			if(str.size()<x)
			{
				size = str.size();
				if(rep>=2)
				{	
					for(j=i;j<size;j++)
						str+=str[j];
				}	

				if(rep>=3)
				{	
					for(j=i;j<size;j++)
						str+=str[j];
				}
			}

			if(rep>=2)
				ans+=len;

			if(rep>=3)
				ans+=len;

			ans%=MOD;
		}

		cout<<ans<<"\n";
	}
	
	return 0;
}


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

ll h[200005][27];

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{	
		ll n,q,i,j;
		s(n); s(q);

		string str;
		cin>>str;

		ll size = str.size(),ans=0;

		for(i=0;i<size;i++)
		{
			for(j=0;j<26;j++)
			if(str[i]-'A'!=j)	
				h[i+1][j] = h[i][j];
			else
				h[i+1][j] = h[i][j] + 1;
		}

		ll l,r,cnt;
		while(q--)
		{	
			s(l); s(r);
			--l;
			cnt = 0;

			for(j=0;j<26;j++)
			if((h[r][j]-h[l][j])%2==1)
				++cnt;	

			if(cnt<=1)
				++ans;
		}

		cout<<"Case #"<<g<<": "<<ans<<"\n";
		++g;
	}
	return 0;
}
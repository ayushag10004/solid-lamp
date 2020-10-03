

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
	ll t,n,i;
	s(t);

	string str;

	while(t--)
	{
		s(n);
		cin>>str;

		vector<ll> aa(10,-1),bb(10,-1);

		for(i=0;i<n;i++)
		{
			if(aa[str[i]-'0']==-1)
				aa[str[i]-'0']=i;
		}

		for(i=n-1;i>=0;i--)
		{
			if(bb[str[i]-'0']==-1)
				bb[str[i]-'0']=i;
		}

		ll last = -1,f=0;

		for(i=0;i<10;i++)
		if(aa[i]!=-1 && last<aa[i])
			{
				last = bb[i];
			}
		else if(aa[i]!=-1)
			{
				f = i;
				break;
			}
		
		ll last1=-1,last2=-1,g=0;
		for(i=0;i<n;i++)
		{
			if(str[i]-'0'<f && str[i]-'0'<last1)
			{
				g = 1;
				break;
			}
			else if(str[i]-'0'<f)
				last1 = str[i]-'0';
			
			if(str[i]-'0'>=f && str[i]-'0'<last2)
			{
				g = 1;
				break;
			}
			else if(str[i]-'0'>=f)
				last2 = str[i]-'0';
		}

		if(g==1)
			cout<<"-";
		else
			for(i=0;i<n;i++)
				if(str[i]-'0'<f)
					cout<<1;
				else
					cout<<2;

		cout<<"\n";
	}
	return 0;
}
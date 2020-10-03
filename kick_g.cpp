

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

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{
		ll n,m,i,j,val,mid,mmul;
		s(n); s(m);

		ll bit[100],mm[100],fin[100];
		memset(bit,0,sizeof bit);
		memset(mm,0,sizeof mm);
		memset(fin,0,sizeof fin);

		for(i=1;i<=n;i++)
		{
			s(val);

			for(j=0;j<70;j++)
			{
				if(val&1)
					++bit[j];

				val/=2;
			}
		}

		val = 1;
		for(j=0;j<62;j++)
		{
			if(j==0)
				mm[j] = min(bit[j],n-bit[j]);
			else
				mm[j] = min(bit[j],n-bit[j])*val + mm[j-1];

			// cout<<j<<"->"<<mm[j]<<" "<<bit[j]<<"\n";
			val*=2;
		}

		val = 0;
		mmul = mul(2,52);
		for(j=52;j>=0;j--)
		{	
			// cout<<j<<" "<<val<<" "<<fin[j+1]<<"\n";
			
			mid = (n-bit[j])*mmul + val;

			if(j>0)
				mid+=mm[j-1];

			if(mid<=m)
				{
					fin[j] = 1;
					val+=(n-bit[j])*mmul;
					mmul/=2;
					continue;
				}

			mid = (bit[j])*mmul + val;

			if(j>0)
				mid+=mm[j-1];

			if(mid<=m)
				{
					fin[j] = 0;
					val+=(bit[j])*mmul;
					mmul/=2;
					continue;
				}

			fin[60] = -1;
			break;
		}	

		if(fin[60]==-1)
			{	
				cout<<"Case #"<<g<<": -1\n";
				continue;
			}

		mid = 0;
		val = 1;
		for(j=0;j<61;j++)
		{
			mid+=fin[j]*val;
			val*=2;
		}

		cout<<"Case #"<<g<<": "<<mid<<"\n";		
		++g;
	}	
	return 0;
}
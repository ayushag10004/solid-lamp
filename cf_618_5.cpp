
/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */
 
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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

ll a[1000005];
int main()
{	
	ll n,i,last;
	s(n);

	for(i=1;i<=n;i++)
		s(a[i]);

	stack< pair<ll, ld> > st;
	pair< ll, ld > pp;
	ld mid;

	for(i=n;i>=1;i--)
	{
		mid = (ld)a[i];
		last = i;

		while(!st.empty())
		{
			pp = st.top();

			if(pp.ss<mid)
			{
				mid = (ld) ( (last-i+1)*mid + (pp.ff-last)*pp.ss )/(pp.ff-i+1);
				last = pp.ff;
				st.pop();
			}
			else
				break;
		}

		st.push(_mp(last,mid));	
	}

	ll in = 1;
	cout<<fixed<<setprecision(12);

	while(!st.empty())
	{
		pp = st.top();
		for(i=in;i<=pp.ff;i++)
			cout<<pp.ss<<"\n";
		in = pp.ff+1;
		st.pop();
	}

	return 0;
}
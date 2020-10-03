

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
const ld lim = 1e-14;
ll a[3000005],n;

ll chck(ld x)
{
	ld mid = x*(n+1);

	if(mid<lim)
		return 0;
	else
		return 1;
}

int main()
{	
	// cout<<fixed<<setprecision(15)<<lim<<"\n";

	ll i,j,size,last_x;
	cin>>n;

	for(i=0;i<=n;i++)
		cin>>a[i];
	
	vector< pair<ll,ld> > aa,bb;
	aa._pb(_mp(0,1));

	ld cf1,cf2,last_cf,new_cf1,new_cf2;
	for(i=1;i<=n;i++)
	{
		bb.clear();
		size = aa.size();
		
		cf1 = (ld)1/(a[i]+1);
		cf2 = (ld)a[i]/(a[i]+1);

		last_x = -1;
		last_cf = 0;

		for(j=0;j<size;j++)
		{
			new_cf1 = (ld)aa[j].ss*cf1; // aa[j].ff
			new_cf2 = (ld)aa[j].ss*cf2; // aa[j].ff+1

			if(last_x = aa[j].ff)
			{
				new_cf1+=(ld)last_cf;
				bb.pop_back();
			}

			if(chck(new_cf1))
				{	
					bb._pb(_mp(aa[j].ff,new_cf1));
					last_x = aa[j].ff;
					last_cf = new_cf1;
				}

			if(chck(new_cf2))
				{
					bb._pb(_mp(aa[j].ff+1,new_cf2));
					last_x = aa[j].ff+1;
					last_cf = new_cf2;
				}	
		}

		aa = bb;
	}

	ld ans = 0;

	size = aa.size();

	for(i=0;i<size;i++)
		ans+=(ld)(aa[i].ff+1)*aa[i].ss;

	cout<<fixed<<setprecision(15)<<ans<<"\n";

	return 0;
}